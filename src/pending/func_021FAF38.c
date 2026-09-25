/*
 * function: func_021FAF38
 * address:  0x021FAF38
 * packet:   pkt_021FAF38
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  MATCH (func_0201134C is reached only from this range; label has no outside branch)
 *
 * symbols:
 *   func_0201134C  0x0201134C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_0201134C(void *);

int func_021FAF38(void *a, u8 *p)
{
    int v = func_0201134C(*(void **)(p + 4));
    if (*(u32 *)(p + 0x10) >= (u32)v)
        return 0;
    *(u16 *)(p + 0x14) = (u16)(v - *(u32 *)(p + 0x10));
    return 1;
}
