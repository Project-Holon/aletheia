/*
 * function: func_021EDC0C
 * address:  0x021EDC0C
 * packet:   pkt_ov170_021EDC0C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04: same size (300), all calls/branches/pool match. Residue 8 instructions: the
 *   locals ty and v (u16 fill value) swap stack slots (original ty=sp+0x10, v=sp+0xc; compiled
 *   the reverse) and one `adds r2,r2,r7` operand order in the address sum. Tried: declaration
 *   order of ty/v/i, v as u32 (much worse), v inline in the call, v block-scoped, init order
 *   of ty and y (ty first matches the first store), ty+=2,y++ increment order (matches),
 *   operand orders of the (hy*4 + hx) sum.
 *
 * 2026-10-04 (wD2 lane 02): improved from 8 to 7 differing instructions: `((i >> 3) << 2) + (tx >> 3)` fixes the add operand order
 * (the `* 4` form compiled to adds r2,r7,r2). Residue: ty and v swap spill slots (original ty=sp+0x10, v=sp+0xc).
 * Declaration order of ty/v/i/t does not move the slots (tested seven placements); v inline, u16 t, and moving the ty
 * initialisation out of the for header all make it worse.
 *
 * symbols:
 *   func_02007A18  0x02007A18  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02082A48  0x02082A48  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02007A18(void *save, u32 box, u32 slot);
extern u32 func_02017DBC(void *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const void *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02017DE4(void *p, u32 f);
extern void func_02082A48(u32 value, void *dest, u32 size);

void func_021EDC0C(int **a, u32 box, u8 *dest)
{
    void *e;
    u32 sv;
    u8 y, x, tx, ty;
    u16 v;
    u8 i;
    u32 sp, t;
    u16 form;
    for (ty = 11, y = 0; y < 5; ty += 2, y++) {
        tx = 10;
        for (x = 0; x < 6; tx += 2, x++) {
            e = func_02007A18((void *)(*a)[1], box, x + y * 6);
            sv = func_02017DBC(e);
            sp = func_02017E88(e, 5, 0);
            if (func_02017E88(e, 0xa9, 0)) {
                if (func_02017E88(e, 0x4c, 0) == 0) {
                    void *pd;
                    form = func_02017E88(e, 0x6f, 0);
                    pd = func_0201ADE4((u16)sp, form, 0x4c);
                    t = (u16)func_0201AE1C(pd, 0x21);
                    func_0201AE14(pd);
                } else {
                    t = (sp == 490) ? 1 : 8;
                }
                t = (u16)(t + 16);
                v = (t << 8) | t;
                for (i = ty; i < ty + 2; i++)
                    func_02082A48(v, dest + ((((i & 7) << 3) + ((((i >> 3) << 2) + (tx >> 3)) << 6)) + (tx & 7)), 2);
            }
            func_02017DE4(e, sv);
        }
    }
}
