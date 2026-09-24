/*
 * function: func_021C04A4
 * address:  0x021C04A4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *
 * The same re-arm and stamp as func_021C01A0 with selector 0xA1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021B9B64(char *p);
extern int func_021BA928(void *p);
extern void func_021BA828(void *p);

int func_021C04A4(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32 *)(p + 0x1CC) = 0xA1;
    }

    return v;
}
