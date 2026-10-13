/*
 * function: FLDMMDL_ACMD_AnimeDash4FStartSe
 * address:  0x02198E98
 * packet:   pkt_02198E98
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
 * bss offset.  Reproduced as the literal constant the image holds.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   FLDMMDL_ACMD_AnimeDash4FStart  0x02198E44  thumb
 */

extern void func_020061E4(unsigned int arg);
extern void FLDMMDL_ACMD_AnimeDash4FStart(void *pipe);

void FLDMMDL_ACMD_AnimeDash4FStartSe(void *pipe)
{
    func_020061E4(0x7B7);
    FLDMMDL_ACMD_AnimeDash4FStart(pipe);
}
