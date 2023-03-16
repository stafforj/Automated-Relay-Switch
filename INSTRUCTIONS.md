# Build Instructions and Notes

### Operating Principles

The core components in the build are the relay and microcontroller. The relay on the control board is an electromagnetic switch. Sending 5VDC to the relay energises the internal coil, mechanically switching its state from Normally-Open (NO) to a closed circuit $^*$. This process is automated using a programmable microcontroller which sends a 5VDC signal to the relay at specific times. All the circuitry has been placed within an enclosure to prevent access to the high AC voltages involved.

$^*$ _Note that the relay used in this build can also be wired for a Normally-Closed state if required (with lower current limits of 10A)._ 


## Bill of Materials

|Name               |QTY|Description                           |
|:------------------|:-:|:-------------------------------------|
|[DIN enclosure](https://uk.rs-online.com/web/p/cases-for-arduino/8607599)|1  |DIN enclosure for Arduino UNO with transparent window. |
|[Arduino](https://uk.rs-online.com/web/p/arduino/7154081)|1  |Arduino UNO microcontroller|
|[Relay Control Kit](https://www.sparkfun.com/products/13815)|1  |Beefcake relay control kit for high current AC switching.|
|[Axial fan](https://uk.farnell.com/sunon/mc30060v2-0000-a99/fan-30x30x6-9mm-5vdc/dp/1924848)|1  |For actively cooling the electronics inside the enclosure.|
|3-core cable|1  |Length depending on requirements for the relay switch. 1.5 mm$^2$ copper cores, or selected based on current requirements.|
|3-pin plug|1  |For connecting to mains AC supply.|
|3-pin socket|1 |For receiving the 3-pin plug of the device that will be controlled.|
|Jumper wire cables|3  |100-200mm length. For connecting Arduino pins to relay pcb.|
|M4 Screws|4  |10 mm long, for mounting fan to enclosure.|
|M3 standoffs and screws|2  |10 mm long, for mounting the relay pcb above the Arduino UNO.|
|Misc.|   | <ul><li>Wiring and heat shrink</li><li>Soldering Iron and solder</li><li>Glue</li><li>Electrical hand drill and drill bits</li><li>Masking tape</li></ul>|

## Modifications

The only modification required is to the DIN enclosure. This is to provide cooling to the electronics, particularly if the relay is controlling a high current load (~ 10-20A) for long periods (> 2 mins) at a time. Holes were drilled on either side of the enclosure to allow air to pass through and across the relay board. The choice of perforated walls with small (~ 3 - 5mm diameter) holes allows air to flow through while preventing the risk of users contacting the AC circuit inside the box. A miniature axial fan (30mm x 30mm x 7mm, $Q_{max} = 3.7$ CFM) was mounted to the inside of the enclosure with the outlet against the perforated enclosure wall. To prevent hot air leaking back into the enclosure at the fan outlet, masking tape (the blue coloured tape in the images) was placed around the fan housing and against the enclosure wall. The fan operates in "pull-mode" in this arrangement, drawing in cool external air that heats up and is then expelled from the outlet. Two large holes (~ 12 mm) were also driled in each side of the enclosure to facilitate the routing of the AC cable. 

![Modifications for air cooling](./Images/enclosure-perforations.png)


## Wiring

### Relay to Arduino

The relay control board requires +5VDC, GND and a signal (4-6VDC) to actuate the switch. The +5VDC and GND are connected to the pins of the Ardunio using yellow and orange cables in the image below. Pin 13 of the Arduino is connected to the signal pin of the relay control board (green cable) and used to deliver a 5VDC signal for actuating the switch.

![DC connections between Relay and Arduino](./Images/internals-DC.png)

### AC supply to Relay

The three wires from the AC cable (live - brown, neutral - blue, GND - yellow/green) are routed through the enclosure. The live wire is connected to the pins of the relay control board and inserted in the NO configuration.

![AC connections to Relay](./Images/internals-AC.png)

### Cooling fan

The cooling fan operates on 5VDC and 0.36W of power. This results in 72mA of current required from the power supply, which allows for running it directly off the Arduino 5VDC supply pin ($I_{max}\approx800$mA). The red (+5VDC) and black (GND) cables from the axial fan are connected to the relay control board pins which take 5VDC and GND off the Arduino UNO. In this arrangement, the fan rotates when the Arduino is powered on (either through the USB or power supply). Although heat is generated discontinuously through the relay action, providing continuous air cooling within the enclosure is preferred for reliable temperature regulation.  

![DC connections between Fan and Relay PCB/Arduino](./Images/internals-fan.png)




## Arduino Code

The arduino code for uploading to the Arduino UNO microcontrolled is located in `/Code/relay-switch.ino`. This contains a routine which turns the relay from the default open circuit (Normally-Open) to closed circuit where the outlet plug will be energised with AC from the source (in our case, single-phase 240VAC at the wall socket).


```
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
```



