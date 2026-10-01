/*
 * function: func_0218D0D8
 * address:  0x0218D0D8
 * packet:   pkt_ov021_0218D0D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02022040  0x02022040  thumb
 *
 * 2026-10-01: MATCH, capped only by the call to func_02022040 (arm9, Thumb,
 * unlabelled, no witness outside this function). It is a ~64+ byte RGB555
 * pixel converter (luma weights 76/151/29 over a lookup table); filing it
 * as an arm9 witness would lift this to EXACT.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02046F48(void *p);
extern void *func_0206E964(void *p);
extern void func_02022040(void *src, u32 size, void *dst);

int func_0218D0D8(void *a, void *b)
{
    u8 *p = func_0206E964(func_02046F48(a));
    if (p != 0) {
        u32 size = *(u16 *)(p + 0x30) << 3;
        u32 off = *(u32 *)(p + 0x38);
        if (b != 0)
            func_02022040(p + off, size >> 1, b);
        return 1;
    }
    return 0;
}
