/*
 * function: func_0220C834
 * address: 0x0220C834
 * packet: pkt_ov197_0220C834
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF (158 bytes, structure matches). Original keeps r4 = 0x5A4 (the size argument) alive
 *   and derives every field offset from it (adds r1,r4; subs r1,#0x72/#0x74 per store, final subs r4,#0x71
 *   for the 0x533 store). Here the compiler loads 0x533 from the pool and consumes r4 destructively in
 *   the arms. Tried: raw u8* offsets, a typed struct with fields at 0x530/0x532/0x533/0x540/0x542/0x5A0
 *   (identical output). Not tried: sharing the size constant as a named local used in an offset sum.
 * symbols:
 *   d_0220E0E0 0x0220E0E0 data a1
 *   func_02030734 0x02030734 arm
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_0220C914 0x0220C914 thumb ov197
 *   func_0200829C 0x0200829C thumb
 *   func_020082B0 0x020082B0 thumb
 *   func_020082B4 0x020082B4 thumb
 *   func_0220B9A4 0x0220B9A4 thumb ov197
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_0220E0E0[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_021F86D4(void);
extern void *func_021F86E0(void);
extern void *func_02030DA8(void *, u32, void *, u32);
extern void func_0220C914(void);
extern void func_0200829C(u32, u32, void *, void *);
extern u16 func_020082B0(u32);
extern u8 func_020082B4(u32);
extern void func_0220B9A4(u8 *);

void func_0220C834(u8 *arg)
{
    u8 *p;
    u8 *q;
    int z;
    int i;
    int v;
    p = func_02030734(*(u16 *)(arg + 0xc), 0x5A4, 1, d_0220E0E0, 0xB1);
    q = func_02030DA8(func_021F86D4(), (u32)func_0220C914, p, 0x64);
    *(u8 **)p = arg;
    *(void **)(p + 8) = func_021F86E0();
    z = 0;
    *(int *)(p + 0x5A0) = z;
    if (*(int *)(*(u8 **)p + 8) == 1) {
        p[0x532] = 1;
        p[0x530] = 1;
    } else if (*(int *)(*(u8 **)p + 8) == 3) {
        p[0x532] = 1;
        p[0x530] = z;
        z = 2;
    } else {
        p[0x532] = z;
        p[0x530] = z;
    }
    p[0x533] = z;
    if (*(int *)(*(u8 **)p + 8) != 1) {
        for (i = 0; i < 4; i++) {
            u8 *r = *(u8 **)p;
            func_0200829C(*(u32 *)(r + 0x1c), (u16)i, r + 0x30 + i * 2, r + 0x38 + i * 2);
        }
        *(u16 *)(p + 0x540) = func_020082B0(*(u32 *)(*(u8 **)p + 0x1c));
        p[0x542] = func_020082B4(*(u32 *)(*(u8 **)p + 0x1c));
        func_0220B9A4(p);
    } else {
        for (i = 0; i < 4; i++) {
            *(u16 *)(*(u8 **)p + i * 2 + 0x30) = 0;
            *(u16 *)(*(u8 **)p + i * 2 + 0x38) = 0;
        }
    }
}
