/*
 * function: func_021B86E8
 * address:  0x021B86E8
 * packet:   pkt_ov071_021B86E8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    int h[2];
    struct {
        int h;
        unsigned char on;
    } e[2];
} P;

void func_021B86E8(int unused, P *p)
{
    extern int func_020450F0(int, int, int, int, int, int, int);
    extern void func_02045334(int);
    extern void func_02045374(int);
    extern void func_020409B4(unsigned int index);
    int i;

    p->h[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334(p->h[0]);
    func_02045374(p->h[0]);
    p->h[1] = func_020450F0(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    func_02045334(p->h[1]);
    func_02045374(p->h[1]);
    for (i = 0; i < 2; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}
