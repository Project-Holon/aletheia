/*
 * function: func_021B8B08
 * address:  0x021B8B08
 * packet:   pkt_ov071_021B8B08
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Six-window twin of func_021B86E8.
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    int h[6];
    struct {
        int h;
        unsigned char on;
    } e[6];
} P;

void func_021B8B08(int unused, P *p)
{
    extern int func_020450F0(int, int, int, int, int, int, int);
    extern void func_02045334(int);
    extern void func_02045374(int);
    extern void func_020409B4(int);
    int i;

    p->h[0] = func_020450F0(4, 2, 0, 0x1e, 3, 0xd, 1);
    func_02045334(p->h[0]);
    func_02045374(p->h[0]);
    p->h[1] = func_020450F0(4, 2, 5, 0x1e, 2, 0xd, 1);
    func_02045334(p->h[1]);
    func_02045374(p->h[1]);
    p->h[2] = func_020450F0(4, 2, 8, 0x1e, 2, 0xd, 1);
    func_02045334(p->h[2]);
    func_02045374(p->h[2]);
    p->h[3] = func_020450F0(4, 2, 0xe, 0x1e, 4, 0xd, 1);
    func_02045334(p->h[3]);
    func_02045374(p->h[3]);
    p->h[4] = func_020450F0(4, 2, 0x10, 0x1e, 2, 0xd, 1);
    func_02045334(p->h[4]);
    func_02045374(p->h[4]);
    p->h[5] = func_020450F0(4, 2, 0x12, 0x1e, 2, 0xd, 1);
    func_02045334(p->h[5]);
    func_02045374(p->h[5]);
    for (i = 0; i < 6; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(4);
}
