/*
 * function: func_02023964
 * address:  0x02023964
 * packet:   pkt_02023964
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02022EA0  0x02022EA0  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02022F0C  0x02022F0C  thumb
 *   func_02022E20  0x02022E20  thumb
 *   func_02022E88  0x02022E88  thumb
 *
 * The setup of the 0x334-byte scanline wipe object (struct WipeScan in
 * docs/families/wipe_sub.h): clears it through func_02022EA0, fills both
 * 0xC0-row tables with 1 or 0 by the descriptor's +6 halfword, stamps ten
 * words at +0x30c..+0x330 in the image's (non-ascending) order, installs
 * the scanline callback through func_02022F0C and arms the window.
 *
 * The 2026-09-20 note was two bytes long because it called
 * func_02022F0C(a0, desc, a3): the image passes (a6, w, a7) -- the
 * sp+0x40 and sp+0x44 stack arguments around the object, matching
 * func_02022F0C's own (u32, u8 *, u32) parameter list.  With that call
 * corrected the rest of the note's body compiles byte for byte.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc {
    u32 f00;
    u16 f04;
    u16 f06;
};

extern void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void func_02022F0C(u32 a0, u8 *a1, u32 a2);
extern void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6, u32 a7, u32 a8, u32 a9);
extern int func_02022E88(int a0, int a1, int a2, int a3);

void func_02023964(u8 *w, struct Desc *d, u32 a2, u32 a3, u32 a4, u32 a5,
                   u32 a6, u32 a7)
{
    func_02022EA0(w, a4, 1, 0, 0);

    if (d->f06 == 0) {
        MI_CpuFill8(w, 1, 0xC0);
        MI_CpuFill8(w + 0xC0, 1, 0xC0);
    } else {
        MI_CpuFill8(w, 0, 0xC0);
        MI_CpuFill8(w + 0xC0, 0, 0xC0);
    }

    *(u32 *)(w + 0x30C) = d->f00;
    *(u32 *)(w + 0x310) = d->f04;
    *(u32 *)(w + 0x324) = d->f06;
    *(u32 *)(w + 0x328) = a7;
    *(u32 *)(w + 0x314) = a2;
    *(u32 *)(w + 0x318) = 0;
    *(u32 *)(w + 0x31C) = a3;
    *(u32 *)(w + 0x320) = 0;
    *(u32 *)(w + 0x32C) = a5;
    *(u32 *)(w + 0x330) = a6;

    func_02022F0C(a6, w, a7);

    if (d->f06 == 1) {
        func_02022E20(a5, 0x20, 0x3F, 0, a4, 0, 0, 0, 0, d->f06);
    } else {
        func_02022E20(a5, 0x3F, 0x20, 0, a4, 0, 0, 0, 0, d->f06);
    }

    func_02022E88(a5, 1, a4, *(u32 *)(w + 0x324));
}
