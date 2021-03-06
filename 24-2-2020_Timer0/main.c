/*
 * Tasks:
 * 1) Timer0 (Normal Mode)
 * 2) Toggle a led every 1 second using INTOVF (interrupt overflow)
 * 3)generate PWM using Timer0 -> takes 3 arguments : On period(msec), Total period(msec), Peak of signal(mv)
 *
 * clk=8MHz
 * Time of one tick = 1/clk = 1/8000000 = 0.125 usec
 * prescalar= 64
 * clk/prescalar = 8000000/64 = 125000
 * Time of one tick(prescalar) = 1/125000 = 8 usec
 * timer register resolution = 8 bits ,so it makes 256 ticks to overflow
 * Time of overflow = 2^resolution * time of one tick = 2^8 * 8 = 256*8 = 2048 usec
 * desired time in this application = 1 msec
 * 1 msec = 1000 usec which is < 2048
 * 1000/8 = desired time/time of one tick = 125 ticks
 * preload value = 256-125 = 131
 *
 *PWM:
 *
 *
 *
 *
 *
 * */
