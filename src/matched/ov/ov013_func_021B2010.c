/*
 * function: func_021B2010
 * address:  0x021B2010
 * packet:   pkt_ov013_021B2010
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B60D8  0x021B60D8  data  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_021B29A4  0x021B29A4  arm  ov013
 *   func_021B2958  0x021B2958  arm  ov013
 */

struct Sess {
    unsigned char pad[0xc];
    int fc;
    int f10;
};

extern struct Sess g_021B60D8;
extern void func_021B2848(void *a, void *b, unsigned int c);
extern int func_021B29A4(void *a, void *b);
struct N;
extern int func_021B2958(struct N *p);

int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int r = 0xff;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (g_021B60D8.fc == 1)
        return -3;
    if (b >= 5)
        return -3;
    buf[4] = r;
    func_021B2848(a, buf, b & 0xff);
    if (func_021B29A4(a, buf) == 0)
        return 0xfc - r;
    if (g_021B60D8.f10 == 1 && b == 0) {
        if (func_021B2958(a) == 0)
            return 0xfc - r;
    }
    return 0;
}
