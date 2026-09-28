/*
 * function: func_02060FA4
 * address:  0x02060FA4
 * packet:   pkt_02060FA4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_020606D0  0x020606D0  arm
 *
 * Frame-heap init ('FRMH' tag 0x46524D48): the common heap header through
 * func_020606D0, then the two cursors copied from the block bounds and the
 * state word cleared.  The load/store interleave tell of the 2.0 front end
 * (docs/FRONTEND-PINS.md, pkt_02060480 family): the image writes
 * ldr/mov/str/ldr/mov/str/str at 0x02060FC4..0x02060FDC; 1.1p1 hoists both
 * loads above the stores (17 bytes out, docs/notes/pkt_02060FA4.c.txt).
 * Under ../2.0/sp2 the same C is 68 bytes, 0 mismatches.
 */

typedef unsigned int u32;

typedef struct Obj {
    u32 f00[6];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
} Obj;

extern void func_020606D0(Obj *o, u32 tag, void *p, u32 a, u32 b);

Obj *func_02060FA4(Obj *o, u32 a1, u32 a2)
{
    func_020606D0(o, 0x46524D48, (char *)o + 0x30, a1, a2);
    o->f24 = o->f18;
    o->f28 = o->f1c;
    o->f2c = 0;
    return o;
}
