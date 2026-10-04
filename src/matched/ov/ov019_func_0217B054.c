/*
 * function: func_0217B054
 * address:  0x0217B054
 * packet:   pkt_ov019_0217B054
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0217AFB0  0x0217AFB0  thumb  ov019
 *   func_02188CE0  0x02188CE0  thumb  ov021
 *   func_0217F958  0x0217F958  thumb  ov019
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 */

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern u32 func_02188CE0(u8 *p);
extern void func_0217F958(char *p, u32 key);
extern void func_0216CF2C(void *);
extern void MI_CpuFill8(void *p, int v, int n);

void func_0217B054(void **a, int b, void *c)
{
    void *h;
    void *r;

    h = func_0201210C(((void **)a[0])[3]);
    r = func_0217AFB0(a, (u8 *)b, c);
    if (h != 0 && r != 0)
        func_0217F958((char *)func_02188CE0(h), (u32)r);
    func_0216CF2C(r);
    MI_CpuFill8(c, 0, 12);
}
