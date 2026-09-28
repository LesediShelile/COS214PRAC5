# COS214PRAC5

# CampusGuard
Emergency Response Coordination System

## Team Members
Shanya Nair - u25061845
Lesedi Shelile - u25110455
Rochaan Verster - u25045785

## Build (Local)
```
make all
```

## Run (Local)
```
./CampusGuard
```

## Run with GDB
```
gdb ./CampusGuard
```
#Further gdb instructions: 
```
instr1
instr2
```

## Docker Build and Run
```
docker compose up --build
```

## Clean
```
make clean
```

## Design Overview

CampusGuard coordinates an emergency response across four collaborating
response components: `SecurityTeam`, `MedicalTeam`, `FacilitiesStaff` and
`AccessControlUnit`, all coordinated through a `ResponseMediator` so none of
them know about each other directly.

Operator actions are represented as **Command** objects
(`DispatchCommand`, `EvacuateCommand`, `AlertCommand`, `CancelCommand`,
`LockdownCommand`), issued through a `CommandInvoker` and executed by
`IncidentResponseReceiver`, which applies the request to an `Incident` and
asks the `ResponseMediator` to coordinate the response.

The **Mediator** (`ResponseMediator`) coordinates the four response
components without them knowing about each other. A meaningful example:
an evacuation instruction to one colleague causes the mediator to
automatically unlock exit routes through a different colleague
(`AccessControlUnit`), without a separate operator instruction.

The **Adapter** (`LegacyAccessAdapter`) integrates a pre-existing legacy
door-control system (`LegacyAccessControlSystem`) that only understands
numeric zone codes and status codes, translating it into the
`AccessControlService` interface CampusGuard's domain code actually wants
to use (named locations, clear verbs). Requests for unregistered zones are
rejected and reported sensibly rather than silently ignored.

The **Facade** (`EmergencyOperationsFacade`) gives an operator a single call
-- `activateEmergencyProtocol()` -- that coordinates dispatch, lockdown and
alerting in one step, and `standDown()`, which coordinates evacuation,
unlocking and cancellation. All of the underlying Command/Mediator
operations remain independently callable (and are, in `main.cpp`).

Two additional GoF patterns:

- **State** (`IncidentState` and its concrete `ReportedState`,
  `ActiveState`, `EvacuationState`, `ResolvedState`, `CancelledState`)
  represents an incident's lifecycle. This avoids a status flag with
  scattered if/else logic, and lets terminal states (`Resolved`,
  `Cancelled`) refuse further action polymorphically
  (`IncidentState::isFinal()`) instead of a type check.
- **Observer** (`IncidentObserver`, implemented by all four response
  components) lets every response component react automatically whenever
  an `Incident`'s status changes, without the `Incident` needing to know
  which concrete components exist.

## Patterns Interacting

`main.cpp` runs two end-to-end scenarios. Scenario 2 (chemical spill) is
driven entirely through the Facade: one `activateEmergencyProtocol()` call
triggers Command execution, which triggers a State change and Observer
notification, and Mediator coordination that reaches the Adapter -- five of
the six patterns collaborating in a single call.

## Engineering Notes

- Every polymorphic base class (`Command`, `IncidentState`,
  `IncidentObserver`, `AccessControlService`) has a virtual destructor.
- `CommandInvoker` owns and deletes the single `Command*` it currently
  holds; `Incident` owns and deletes its `IncidentState*`.
- See `docs/GDB_AND_VALGRIND.md` for the GDB investigation and Valgrind
  evidence (0 leaks, 0 errors across the full run).
