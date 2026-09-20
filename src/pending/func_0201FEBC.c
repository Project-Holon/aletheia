/*
 * function: func_0201FEBC
 * address:  0x0201FEBC
 * packet:   pkt_0201FC5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201FEBC.c \
 *       --func func_0201FEBC --addr 0x0201FEBC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32  func_0201FA04(void *p);
extern u32  func_0201C4E4(u32 a);
extern void func_02045334(u32 a);
extern void func_0201FEF4(void *p);

u32 func_0201FEBC(u8 *p)
{
    u32 r = func_0201FA04(p);
    u32 t = func_0201C4E4(*(u32 *)(p + 0x18));

    if (*(u32 *)(p + 0x20) == 0 && t != 0) {
        func_02045334(*(u32 *)(p + 4));
        *(u32 *)(p + 0x20) = 1;
    }
    if (r != 0xffffffff) {
        func_0201FEF4(p);
    }
    return r;
}

