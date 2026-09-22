# COS214PRAC5

# Students + student no.s
Shanya Nair - u25061845
Lesedi Shelile -u25110455
Rochaan Verster - u25045785

## General Idea: 
A system that coordinates a response when there is some sort of emergency. And we can use command for different actions ,e.g dispatch medical team. 
Mediator can be communication between the different teams and services. We could have a response coordinator class as the mediator.
Fascade can give the operator class or something a simple operation like activateEmergencyProtocol()  instead of handling and registering an incident, dispatching teams etc. 
For the additional patterns we could have Observer to maybe notify different people in our system . state to maybe show the current status of the emergency. Like active, contained, resolved etc. We could also possibly use strategy so we can respond to different emergencies eg. A fire response or medical emergency response.
Adapter could be used for response teams, like the medical team and the fire brigade have diferent interafces but make an adapter for response teams. so the medical team can set up a first aid station while the fire brigade might make a blockade, but each response team would do their separate tasks when the common interface function like EmergencyProtocol() and each class calls their own different Emergency Protocol functions

