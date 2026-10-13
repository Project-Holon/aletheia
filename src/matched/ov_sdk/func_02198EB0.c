/*
 * function: FLDMMDL_ACMD_AnimeDash6FStartSe
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
 * second call is to the 0xb variant (FLDMMDL_ACMD_AnimeDash6FStart) of the sync helper.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   FLDMMDL_ACMD_AnimeDash6FStart  0x02198E60  thumb
 */

extern void func_020061E4(unsigned int arg);
extern void FLDMMDL_ACMD_AnimeDash6FStart(void *pipe);

void FLDMMDL_ACMD_AnimeDash6FStartSe(void *pipe)
{
    func_020061E4(0x7B7);
    FLDMMDL_ACMD_AnimeDash6FStart(pipe);
}
