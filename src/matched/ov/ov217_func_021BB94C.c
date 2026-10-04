/*
 * function: func_021BB94C
 * address:  0x021BB94C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB978  0x021BB978  thumb  ov217
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *
 * Same guard shape as 021BA158 on the +0x158 word, handing the +0x18
 * handle to func_021BB978.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ring;
extern int func_021BB978(char *p, int a1);
extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E64();
void func_021BB94C(u32 a0)
{
    if (*(u32*)(((u8*)a0) + 344) != 0) {
    if (func_021C0E64(*(u32*)(((u8*)a0) + 24)) == 0) {
    func_021BB978((char *)a0, func_021C0E54((struct Ring *)(*(u32*)(((u8*)a0) + 24))));
    }
    }
}
