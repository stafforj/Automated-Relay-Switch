# Automated-Relay-Switch

 _An arduino-controlled normally-open relay for automatically switching AC voltage supply on and off at user-defined time intervals and durations. Included are the build notes. Part of the Open Science Framework repository [Open2DM](https://osf.io/evupy/)_

### Background \& Motivation

_This is part of the [Open2DM](https://osf.io/evupy/) labware project._

For our group's research on synthesing two-dimensional materials (e.g., Graphene, MoS2, h-BN, etc.), we required a shear mixing process to operate at  discrete on-off time intervals. We also required our tests to finish after specific processing times (test duration). These processes are operated for hours in some instances, and implementing a simple form of automation reduces the manual efforts for the researcher. 

This repository provides the build details and code for creating a relay that can automatically switch between a default Normally-Open (NO) state to a closed circuit, supplying AC from the wall socket (240V) to the device.

Although this was our motivation, it is worth highlighting that the relay can be used for any application where there is a need to switch AC in a controlled way (e.g., lighting, motors, etc.). The limitations for the chosen application are a maximum of 20A and 220VAC for this Normally-Open (NO) state.     


### Disclaimer!

Working with AC can be dangerous. Make sure to take all precautions when making modifications and ensure everything is unplugged and grounded.

## Potential Changes

List of changes and whether they have been implemented.

- [ ] The wiring into and out of the DIN enclosure could be tidied up using suitable bulkhead fittings or rubber grommets.
