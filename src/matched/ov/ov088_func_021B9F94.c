/*
 * function: func_021B9F94
 * address:  0x021B9F94
 * packet:   pkt_ov088_021B9F94
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02012FE4  0x02012FE4  thumb
 */

extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern int *func_0203159C(int, int, int);
extern void func_02082BCC(void *, int, int);
extern int func_020070A4(void);
extern int func_02008730(int);
extern int func_0200C0F0(int);
extern int func_02009210(int);
extern int func_02012FE4(int);

int func_021B9F94(int a)
{
    int *p;
    func_0203064C(1, 0xb, 0x80000);
    p = func_0203159C(a, 0x150, 0xb);
    func_02082BCC(p, 0, 0x150);
    p[0] = func_020070A4();
    p[1] = func_02008730(p[0]);
    p[2] = func_0200C0F0(p[0]);
    p[3] = func_02009210(p[0]);
    p[4] = func_02012FE4(p[0]);
    return 1;
}
