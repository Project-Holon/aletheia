/*
 * function: func_0203D01C
 * address:  0x0203D01C
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203C3B4  0x0203C3B4  arm
 *   func_0203B2D0  0x0203B2D0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void func_0203C3B4(void);
extern void func_0203B2D0(u32 a);

void func_0203D01C(void)
{
    u8 *s = func_0203D788();

    switch (s[0x65]) {
    case 1:
    case 2:
        func_0203C3B4();
        return;
    case 0:
    case 5:
        func_0203B2D0(*(u16 *)(s + 0x56));
        return;
    default:
        return;
    }
}
