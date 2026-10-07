/*
 * function: func_021F37B8
 * address:  0x021F37B8
 * packet:   pkt_ov060_021F37B8
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021F399C  0x021F399C  thumb  ov060
 */

extern int *func_021897BC(char *p, int idx);
extern int func_02188D2C(int *p);
typedef struct { int a, b, c; } V;
extern void func_021F399C(unsigned char *o, void *p, V *v);

void func_021F37B8(char *p, V *v)
{
    unsigned char *o;
    void *s;
    o = (unsigned char *)func_021897BC(p, 0);
    s = (void *)func_02188D2C((int *)p);
    func_021F399C(o, s, v);
}
