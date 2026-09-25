/*
 * function: func_021B6100
 * address:  0x021B6100
 * packet:   pkt_021B6100
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned int u32;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern char *func_0203159C(void *a, void *b, u32 c);
extern void func_02082BCC(void *p, u32 v, u32 n);

int func_021B6100(char *p, u32 b, u32 c)
{
    char *r;

    func_0203064C(1, 0x7f, 0x80000);
    r = func_0203159C(p, (void *)0x605c, 0x7f);
    func_02082BCC(r, 0, 0x605c);
    *(u32 *)r = c;
    *(u32 *)(r + 0x605c - 4) = 0;
    return 1;
}
