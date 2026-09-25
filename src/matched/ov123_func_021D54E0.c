/*
 * function: func_021D54E0
 * address:  0x021D54E0
 * packet:   pkt_ov123_021D54E0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02051C6C  0x02051C6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02051C6C(void *);

void func_021D54E0(u8 *p)
{
    if (*(void **)(p + 0x1c)) {
        func_02051C6C(*(void **)(p + 0x1c));
        *(u32 *)(p + 0x1c) = 0;
    }
}
