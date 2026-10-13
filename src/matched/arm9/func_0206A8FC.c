/*
 * function: func_0206A8FC
 * address:  0x0206A8FC
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_renderState       0x02148B4C  data
 *   g_02148B50       0x02148B50  data
 *   g_renderStateDrawParams       0x02148B98  data
 *   g_02148BC8       0x02148BC8  data
 *   g_renderStateIdentityMtx       0x02148C08  data
 *   g_02148C44       0x02148C44  data
 *   func_0206DDA4    0x0206DDA4  arm
 *   func_0207B0A4    0x0207B0A4  arm
 *
 * The "enter this rig mode" entry point of the 0x02148B4C register block, and
 * the big sibling of src/matched/func_0206A884.c: nine registrations against
 * the same table helper func_0206DDA4, one of them (0x10) with a one-word
 * out-parameter whose address is taken and one (0x17) reading a twelve-byte
 * record that func_0207B0A4 fills, then bit 0 of the "initialised subsystems"
 * flag word at g_renderState + 0xFC is set and bit 1 cleared.  The 0x34-byte
 * frame is the 13-word scratch array: w[0] is the 0x10 call's out-parameter,
 * w[1..12] the record.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md), the
 * same tell and the same family as src/matched/func_0206A700.c and
 * src/matched/func_0206AAD4.c.  The image materialises every call's small
 * constants FRESH at each site -- `mov r0, #0x19` / `mov r2, #0xc` at
 * 0x0206A91C/0x0206A920, `mov r2, #0xf` at 0x0206A92C, `mov r2, #1` at
 * 0x0206A944 -- and keeps the frame at a bare `stmdb sp!, {lr}`
 * (`00 40 2d e9`).  dsi/1.1p1 -O4,p CSEs 0x19, 0xc and 1 into callee-saved
 * r4/r5/r6 and rebuilds 0x1b19 as `add r0, r4, #0x1b00`, which needs
 * `push {r3, r4, r5, r6, lr}` and gives 236 bytes against the original's 224,
 * 175 concrete bytes out.  Under the pin the same C is 224 bytes,
 * 0 mismatches, all 16 relocation sites resolving.
 *
 * TWO READINGS OF THE POOL that cost this function most of its time, both
 * fixed by resolving every `ldr [pc]` to its pool word rather than reading the
 * loads in order (the pool is shared: 0x0206A9CC is loaded TWICE, at
 * 0x0206A928 and 0x0206A94C, and 0x0206A9D0 twice, at 0x0206A968 and
 * 0x0206A9A0, so there are ten loads over eight words):
 *   1. func_0207B0A4's first argument is g_renderStateIdentityMtx, the SAME object the
 *      0x1b19 registration uses, not g_02148BC8.
 *   2. the 0xE registration takes g_renderState[0x1f] as its value and
 *      g_02148BC8 + 4 as its pointer; the two objects are the other way round
 *      from the order the loads appear in.
 * The `+ 4` must be spelled through a `char *` cast: as `g_02148BC8 + 1` the
 * front end folds the offset into the pool word and drops the image's
 * `add r1, r1, #4` at 0x0206A974, costing four bytes and shifting the tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A8FC.c \
 *       --func func_0206A8FC --addr 0x0206A8FC --arm --cc ../2.0/sp2
 */

typedef unsigned int u32;

extern u32  g_renderState[];
extern u32  g_02148B50[];
extern u32  g_renderStateDrawParams[];
extern u32  g_02148BC8[];
extern u32  g_renderStateIdentityMtx[];
extern u32  g_02148C44[];
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0207B0A4(void *a, void *b);

void func_0206A8FC(void)
{
    u32 w[13];

    func_0206DDA4(0x1610, g_02148B50, 0x11);
    func_0206DDA4(0x19, g_renderStateDrawParams, 0xC);
    func_0206DDA4(0x1b19, g_renderStateIdentityMtx, 0xF);
    w[0] = 2;
    func_0206DDA4(0x10, &w[0], 1);
    func_0207B0A4(g_renderStateIdentityMtx, &w[1]);
    func_0206DDA4(0x17, &w[1], 0xC);
    func_0206DDA4(g_renderState[0x1f], (char *)g_02148BC8 + 4, 0xE);
    func_0206DDA4(0x15, 0, 0);
    func_0206DDA4(0x2a, g_02148C44, 1);
    g_renderState[0x3f] = (g_renderState[0x3f] | 1) & ~2u;
}
