/*
 * function: CallbackForJpeg
 * address:  0x02707558
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Event callback ahead of AESi_InitRand: the argument order is swapped
 * into OS_SignalEvent (AESi_CalcMac passes it with the event as context).
 */

typedef unsigned int u32;
typedef struct OSEvent OSEvent;
extern void OS_SignalEvent(OSEvent *ev, u32 mask);

static void CallbackForJpeg(u32 mask, OSEvent *ev)
{
    OS_SignalEvent(ev, mask);
}
