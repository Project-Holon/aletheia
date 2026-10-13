/*
 * function: NNS_G3dGeFlushBuffer
 * address:  0x0206DB80
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNnsG3dGeState       0x0214BAB4  data
 *   NNS_G3dGeWaitSendDL    0x0206DBDC  arm
 *   MIi_CpuSend32    0x02082AA8  arm
 *
 * Drains the block described by the global pair at 0x0214BAB4: word 1
 * non-zero means a transfer is still in flight, so wait for it; then word 0's
 * object has its payload (object + 4) filled with 0x04000400 over count*4
 * bytes and its count zeroed.
 *
 * PIN ../2.0/sp2, the address-rematerialisation tell (docs/FRONTEND-PINS.md).
 * The original loads the pool word at 0x0206DBD4 THREE times -- `ldr r0,
 * [pc, #0x48]` at +0004, `ldr r0, [pc, #0x34]` at +0018 and `ldr r0,
 * [pc, #0xc]` at +0040 -- and its prologue is `push {r3, lr}`, i.e. not one
 * callee-saved register is spent.  1.1p1 -O4,p instead materialises the
 * address once into r4 across the MIi_CpuSend32 call, growing the push to
 * `push {r4, lr}` and shortening the tail by one load: 88 bytes against the
 * original's 92, 23 concrete bytes out (the residue docs/notes/
 * pkt_0206DB80.c.txt recorded).  No spelling of the C moves it under 1.1p1:
 * volatile on the array elements, a named local for the head pointer and the
 * fully spelled-out `g[0][0]` form all give the same r4.  Under the pin the
 * same C is 92 bytes, 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGeFlushBuffer.c \
 *       --func NNS_G3dGeFlushBuffer --addr 0x0206DB80 --cc ../2.0/sp2 --arm
 */

typedef unsigned int u32;

extern u32 *gNnsG3dGeState[2];
extern void NNS_G3dGeWaitSendDL(void);
extern void MIi_CpuSend32(void *dst, u32 c, u32 n);

void NNS_G3dGeFlushBuffer(void)
{
    if (gNnsG3dGeState[1] != 0)
        NNS_G3dGeWaitSendDL();
    if (gNnsG3dGeState[0] != 0 && gNnsG3dGeState[0][0] != 0) {
        MIi_CpuSend32(gNnsG3dGeState[0] + 1, 0x04000400, gNnsG3dGeState[0][0] * 4);
        gNnsG3dGeState[0][0] = 0;
    }
}
