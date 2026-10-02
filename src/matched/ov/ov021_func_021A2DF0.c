/*
 * function: func_021A2DF0
 * address:  0x021A2DF0
 * packet:   pkt_ov021_021A2DF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CA4  0x02188CA4  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021A35BC  0x021A35BC  thumb
 *   func_021A35F0  0x021A35F0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_02188CA4();
extern void *func_02188CB4(unsigned char *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_021A35BC();
extern void func_021A35F0();

void func_021A2DF0(u32 a)
{
    u8 *p = func_02188CA4(a);
    void *q = func_02188CB4((void *)a);

    if (*(u32 *)(p + 0xC) == 0) {
        u32 x = func_020362DC();
        u32 y = func_0203630C();
        u32 f = 0;

        if (func_021A35BC(q) == 1)
            f |= 1;
        func_021A35F0(q, x, y, f);
    }
}
