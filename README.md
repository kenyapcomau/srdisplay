# Shift register display

These are the Kicad design files for the shift register display described in my [Hackaday project](https://hackaday.io/project/168654-an-uninnovative-linear-led-display)

## Versioning

Working release January 2020

## Notes

srdisplay.ino is an Arduino sketch to test the display.

At assembly time you should choose between sourcing current to the LEDs by installing the Source/Sink soldered jumper. If sinking is chosen, the LEDs should be installed in reverse polarity to the silkscreen legend.

If you do not wish to drive /OE for PWM brightness control from the controller, you should jumper it to ground.

## Authors

* **Ken Yap**

## License

See the [LICENSE](LICENSE.md) file for license rights and limitations (MIT).
