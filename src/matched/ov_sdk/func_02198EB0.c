/*
 * function: func_02198EB0
 * address:  0x02198EB0
 * packet:   pkt_02198EB0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * libmatch places DSPi_WaitForPipe (TwlSDK/libdsp dsp_pipe.o) here, but the
 * call site is func_020061E4, not OS_SleepThread (0x020857B0), and the pool
 * word is the small constant 0x7B7, not DSPiBlockingQueue's absolute address:
 * the overlay stores bss pointers base-relative, so the pool word carries the
 * bss offset.  Reproduced as the literal constant the image holds.  The
 * second call is to the 0xb variant (func_02198E60) of the sync helper.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02198E60  0x02198E60  thumb
 */

extern void func_020061E4(unsigned int arg);
extern void func_02198E60(void *pipe);

void func_02198EB0(void *pipe)
{
    func_020061E4(0x7B7);
    func_02198E60(pipe);
}
