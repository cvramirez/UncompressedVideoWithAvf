#ifndef __OcTimersAndTimingDefs__
#define __OcTimersAndTimingDefs__

/*!

(1) kOcRateHz and rate = 4.0 means, 4.0 x 1 cycle per second, thus the calculated play rate is 4.0 frames per second.
(2) kOcRateSeconds and rate = 0.5 display frames at 0.5 second intervals. Seconds rate is the inverse of Hz rate.
(3) kOcRateMovie and rate = 0.75 will calculate play rate at 3/4 the rate indicated as the "normal rate" in the movie
     metadata.  If the movie normally plays at 60Hz, then the calculated play rate will be 45Hz.
(4) kOcRateDisplay and rate = 0.5 will calculate play rate at half the screen rate.  Having rate = 1.0, will play at
     exactly the screen rate, and having rate > 1, will produce frame drops.
(5) kOcRateVsync and rate = 2 will calculate play rate at one frame per 2 display vertical refresh / redraw periods.
*/
typedef NSString* OcRateType;

static OcRateType const kOcRateHz = @"Hz";
static OcRateType const kOcRateSeconds = @"Seconds";
static OcRateType const kOcRateMovie = @"Movie";
static OcRateType const kOcRateDisplay = @"Display";
static OcRateType const kOcRateVsync = @"Vsync";
#endif
