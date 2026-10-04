/*
 * function: func_021CF54C
 * address:  0x021CF54C
 * packet:   pkt_021CF54C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_020307B0(void *p);

void func_021CF54C(u8 *p)
{
    u32 v = *(u32 *)(p + 28);
    if (v != 0) {
        func_020307B0((void *)v);
        *(u32 *)(p + 28) = 0;
    }
}
