/*
 * function: func_021F3980
 * address:  0x021F3980
 * packet:   pkt_ov059_021F3980
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 */

extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void func_020307B0(void *p);
extern void func_021897A0(unsigned char *p, int id);
extern void func_021BE418(unsigned char *p, unsigned short i);

void func_021F3980(unsigned char *p)
{
    void *s;
    int *o;
    s = (void *)func_02188D2C((int *)p);
    o = func_021897BC((char *)p, 1);
    func_020307B0((void *)o[9]);
    func_021897A0(p, 1);
    func_021BE418(s, 0);
}
