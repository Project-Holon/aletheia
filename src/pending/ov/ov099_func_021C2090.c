/*
 * function: func_021C2090
 * address: 0x021C2090
 * packet: pkt_ov099_021C2090
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-04 wave D3 lane 18: DIFF, compiled 396 bytes vs 404, whole body differs from the prologue.
 * Logic read from the listing: state at p+0x8F4 (1 -> clear, flag = 1, call func_020414AC(7)); loop i over 8 slots, idx = i + row(p+0x8EC)*8 + 1; mode = byte p[0x8CB+idx] ? (func_02009864(p->f4, idx-1, 9) != 0) : 2; sel = idx == p[0x8ED] 
 * 
 *  idx == p[0x8F3]; slot = idx == p[0x8ED] ? p[0x8EE] : 0; redraw when flag == 1 or sel; func_021C2224 then (mode != 2) func_021C2274 + func_02045374 + func_021C22E8, else the clear loop (func_02045770, func_02043B5C(.,0), func_02045334 over the slot object and 2 sub objects at p+0x918+i*8+j*4). End: func_02041B6C(7), (6), func_02043598(2,1), (8,1). Pool words verified against the listing.
 * Residue: original keeps i in [sp+0x1c] and flag in [sp+0x18], mode in r7, slot in r5, idx in r4, p in r6, and spills (i/4)*16 to [sp+8], (i%4)*6 to [sp+0xc], p+i*4 to [sp+0x10], p+i*8 to [sp+0x14], and the 0x918 constant to [sp+0x20]; frame 0x24 with 4 saved registers. Compiled keeps i in r7 and spills mode, with push r3 and frame 0x28.
 * Tried: declaring i before flag (no change). Next: make p+i*4 and p+i*8 explicit locals declared in that order, express the pool constant 0x8F8/0x918 as a local, and make mode more used than i.
 * func_021C2274 is called with 5 arguments here (p, obj, idx, slot, i) though its matched C reads 3; func_021C22E8 takes (p, window, idx, slot, x, y).
 * symbols:
 *   func_02009864 0x02009864 thumb
 *   func_021C2224 0x021C2224 thumb ov099
 *   func_021C2274 0x021C2274 thumb ov099
 *   func_021C22E8 0x021C22E8 thumb ov099
 *   func_020414AC 0x020414AC arm
 *   func_02045374 0x02045374 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02043598 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02009864(void *obj, u32 i, u32 field);
extern void func_021C2224(char *p, u32 a1, u32 a2, u32 mode, u8 slot);
extern void func_021C2274(char *p, void *window, int id, int slot, int i);
extern void func_021C22E8(char *p, void *window, int id, int flag, int x, int y);
extern void func_020414AC(u32 a);
extern void func_02045374(void *a);
extern void *func_02045770(void *a);
extern void func_02043B5C(void *a, u8 v);
extern void func_02045334(void *a);
extern void func_02041B6C(u32 bit);
extern void func_02043598(u32 mask, u32 enable);

void func_021C2090(char *p)
{
    int i;
    int flag;
    int idx;
    int mode;
    int slot;
    int sel;
    int px;
    int py;

    if (*(int *)(p + 0x8F4) == 1) {
        *(int *)(p + 0x8F4) = 0;
        flag = 1;
        func_020414AC(7);
    } else {
        flag = 0;
    }
    for (i = 0; i < 8; i++) {
        idx = i + *(u8 *)(p + 0x8EC) * 8 + 1;
        if (*(u8 *)(p + 0x8CB + idx) != 0) {
            if (func_02009864(*(void **)(p + 4), idx - 1, 9) == 0) {
                mode = 0;
            } else {
                mode = 1;
            }
        } else {
            mode = 2;
        }
        px = i / 4;
        py = i % 4;
        if (idx == *(u8 *)(p + 0x8ED)) {
            slot = *(u8 *)(p + 0x8EE);
        } else {
            slot = 0;
        }
        if (idx == *(u8 *)(p + 0x8ED) || idx == *(u8 *)(p + 0x8F3)) {
            sel = 1;
        } else {
            sel = 0;
        }
        if (flag == 1 || sel == 1) {
            py = py * 6;
            px = px * 16;
            func_021C2224(p, (u8)px, (u8)py, (u8)mode, (u8)slot);
            if (mode != 2) {
                void *w = *(void **)(p + i * 4 + 0x8F8);
                func_021C2274(p, w, idx, slot, i);
                func_02045374(w);
                func_021C22E8(p, p + 0x918 + i * 8, idx, slot, px, py);
            } else {
                int j;
                void *w = *(void **)(p + i * 4 + 0x8F8);
                func_02043B5C(func_02045770(w), 0);
                func_02045334(w);
                for (j = 0; j < 2; j++) {
                    void *q = *(void **)(p + i * 8 + j * 4 + 0x918);
                    func_02043B5C(func_02045770(q), 0);
                    func_02045334(q);
                }
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(6);
    func_02043598(2, 1);
    func_02043598(8, 1);
}
