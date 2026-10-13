/*
 * function: DSPi_ShutdownCallback
 * address:  0x027052FC
 * packet:   pkt_027052FC
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libdsp dsp_process.o (hidden function between DSP_StopDSPComponent and
 * DSPi_PreSleepCallback).  Loops: while the poll call returns nonzero, run the
 * handler.
 *
 * symbols:
 *   DSP_FindProcess  0x02705ED0  arm
 *   DSP_QuitProcess  0x02705E04  arm
 */

extern int DSP_FindProcess(int arg);
extern void DSP_QuitProcess(void);

void DSPi_ShutdownCallback(void)
{
    int i = 0;

    for (;;) {
        if (DSP_FindProcess(i) == 0) {
            return;
        }
        DSP_QuitProcess();
    }
}
