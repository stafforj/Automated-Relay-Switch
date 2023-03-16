# Build Instructions and Notes

### Operating Principles

The approach is an extension of what is described...


## Bill of Materials

|Name               |QTY|Description                           |
|:------------------|:-:|:-------------------------------------|
|[DIN enclosure](https://uk.rs-online.com/web/p/cases-for-arduino/8607599)|1  |DIN enclosure for Arduino UNO with transparent window. |
|[Arduino](https://uk.rs-online.com/web/p/arduino/7154081)|1  |Arduino UNO microcontroller|
|[Relay Control Kit](https://www.sparkfun.com/products/13815)|1  |Beefcake relay control kit for high current AC switching.|
|[Axial fan](https://uk.farnell.com/sunon/mc30060v2-0000-a99/fan-30x30x6-9mm-5vdc/dp/1924848)|1  |For actively cooling the electronics inside the enclosure.|
|M4 Screws|4  |10 mm long, for mounting fan to enclosure.|
|M3 standoffs and screws|2  |10 mm long, for mounting the relay pcb above the Arduino UNO.|
|Misc.|   | <ul><li>Wiring and heat shrink</li><li>Soldering Iron and solder</li><li>Glue</li><li>Electrical hand drill and 3-5mm drill bits</li><li>Masking tape</li></ul>|

## Modifications

The only modification required is to the DIN enclosure. This is to provide cooling to the electronics, particularly if the relay is controlling a high current load (~ 10-20A) for long periods (> 2 mins) at a time. Holes were drilled on either side of the enclosure to allow air to pass through and across the relay board. The choice of perforated walls with small (~ 3 - 5mm diameter) holes allows air to flow through while preventing the risk of users contacting the AC circuit inside the box. A miniature axial fan (30mm x 30mm x 7mm, $Q_{max} = 3.7$ CFM) was mounted to the inside of the enclosure with the outlet against the perforated enclosure wall. To prevent hot air leaking back into the enclosure at the fan outlet, masking tape (the blue coloured tape in the images) was placed around the fan housing and against the enclosure wall. The fan operates in "pull-mode" in this arrangement, drawing in cool external air that heats up and is then expelled from the outlet.  

![Modifications for air cooling](./Images/enclosure-perforations.png)


## Wiring

### Relay to Arduino

To be completed

![DC connections between Relay and Arduino](./Images/internals-DC.png)

### AC supply to Relay

To be completed

![AC connections to Relay](./Images/internals-AC.png)

### Cooling fan

To be completed

![DC connections between Fan and Relay PCB/Arduino](./Images/internals-fan.png)




## Arduino Code

The arduino code for uploading to the Arduino UNO microcontrolled is located in `/Code/relay-switch.ino`. This contains a routine which turns the relay from the default open circuit (Normally-Open) to closed circuit where the outlet plug will be energised with AC.


```
void UpdateCount() {
  COUNT++;
}
```



