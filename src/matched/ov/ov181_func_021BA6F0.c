/*
 * function: func_021BA6F0
 * address: 0x021BA6F0
 * packet: pkt_ov181_021BA6F0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display register stores 04000050, 04000052, 04001050, 04001052.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void func_0207D63C(unsigned, int, int, int, int);
extern void *func_02045770(void *);
struct CharBuf { u8 *pixels; u16 width, height, tileSize; };
extern void func_02043B5C(struct CharBuf *, u8);
int func_021BA6F0(char *p)
{
    int a, b;
    switch (*(u8 *)(p + 0x2ce)) {
    case 0:
        if (*(u8 *)(p + 0x2cf) & 1) func_0207D63C(0x04000050, 2, 0x21, 16, 0);
        if (*(u8 *)(p + 0x2cf) & 2) func_0207D63C(0x04001050, 2, 0x21, 16, 0);
        ++*(u8 *)(p + 0x2ce);
    case 1:
        if (*(u8 *)(p + 0x2d2) == 1) *(s8 *)(p + 0x2d0) += 16;
        else *(s8 *)(p + 0x2d0) += 4;
        b = *(s8 *)(p + 0x2d0);
        if (b > 16) { a = 0; b = 16; }
        else a = 16 - b;
        if (*(u8 *)(p + 0x2cf) & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (*(u8 *)(p + 0x2cf) & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (*(s8 *)(p + 0x2d0) >= 16) {
            if (*(u8 *)(p + 0x2cf) & 1) func_02043B5C(func_02045770(*(void **)(p + 0x2bc)), 0);
            if (*(u8 *)(p + 0x2cf) & 2) func_02043B5C(func_02045770(*(void **)(p + 0x2c4)), 0);
            *(u8 *)(p + 0x2cc) = *(u8 *)(p + 0x2cf);
            *(u8 *)(p + 0x2d0) = 0;
            ++*(u8 *)(p + 0x2ce);
        }
        break;
    case 2:
        if (*(u8 *)(p + 0x2cf) & 1) *(volatile u16 *)0x04000050 = 0;
        if (*(u8 *)(p + 0x2cf) & 2) *(volatile u16 *)0x04001050 = 0;
        *(u8 *)(p + 0x2cf) = 0;
        *(u8 *)(p + 0x2ce) = 0;
        return 0;
    }
    return 1;
}
