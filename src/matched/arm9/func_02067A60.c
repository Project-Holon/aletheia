/*
 * function: NNS_G2dInitRndCore
 * address:  0x02067A60
 * packet:   pkt_02067A60
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MIi_CpuClear16  0x02082A48  arm
 *
 * Constructor: clear 0x70 bytes, then seven field stores (0x24, 0x30, 0x28 in
 * image order; the +4/+8 pair merges into `stmib`).  The kept-constants tell
 * (docs/FRONTEND-PINS.md): the image passes the clear's zero as an immediate
 * (`mov r0, #0` at 0x02067A6C) and rematerialises it after the call
 * (`mov r1, #0` at 0x02067A78) under `push {r4, lr}`; 1.1p1 keeps one zero
 * live across the call in r4 and needs `push {r3, r4, r5, lr}` (42 bytes out,
 * docs/notes/pkt_02066E30.c.txt).  Under ../2.0/sp2 the same C is 64 bytes,
 * 0 mismatches.  Sole caller: src/matched/NNS_G2dInitRenderer.c (+0x08).
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct S {
    u32 f00, f04, f08, f0c;
    u32 f10[5];
    u32 f24, f28, f2c, f30;
    u32 pad[15];
} S;
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);

void NNS_G2dInitRndCore(S *p)
{
    MIi_CpuClear16(0, p, 0x70);
    p->f00 = 0;
    p->f04 = 2;
    p->f08 = 0;
    p->f0c = 0;
    p->f24 = 0;
    p->f30 = 1;
    p->f28 = 0;
}
