/*
 * function: SndexSleepAndExitCallback
 * address:  0x02704D64
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WaitIirFilterSetting  0x02704D74  arm twl
 *   ResetTempVolume  0x02704E04  arm twl
 */

typedef unsigned int u32;

extern void WaitIirFilterSetting(void);
extern void ResetTempVolume(void);

void SndexSleepAndExitCallback(void) {
    WaitIirFilterSetting();
    ResetTempVolume();
}
