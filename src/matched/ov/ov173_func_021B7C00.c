/*
 * function: func_021B7C00
 * address:  0x021B7C00
 * packet:   pkt_ov173_021B7C00
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B63AC  0x021B63AC  thumb  ov173
 *   func_021B7ADC  0x021B7ADC  thumb  ov173
 *   func_0203D34C  0x0203D34C  arm
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021B63AC(u8 *p);
extern void func_021B7ADC(void *, int, int);
extern void func_0203D34C(u32 a, u32 b);

int func_021B7C00(void *p)
{
    unsigned char v;

    func_021B63AC(p);
    func_021B7ADC(p, (unsigned char)(*(unsigned short *)(*(int *)p + 0x14)), 3);
    func_0203D34C(1, 0x4f);
    v = *(unsigned char *)((char *)p + 0x192);
    if (v == 0) {
        v = *(unsigned char *)((char *)p + 0x191);
    } else {
        v = 4;
    }
    *(unsigned char *)(*(int *)p + 0x1b) = v;
    *(int *)((char *)p + 0x1b0) = 7;
    return 0;
}
