/*
 * function: func_0217FD04
 * address: 0x0217FD04
 * packet: pkt_ov019_0217FD04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216DA30 0x0216DA30 thumb ov010
 *   func_0217FCC0 0x0217FCC0 thumb ov019
 *   func_0217FCA4 0x0217FCA4 thumb ov019
 */

typedef unsigned int u32;
struct E { u32 a,b,c,d; unsigned short h; };
extern int func_0216DA30(u32 a);
extern void func_0217FCC0(struct E *e);
extern void func_0217FCA4(struct E *e);
void func_0217FD04(struct E *p)
{
    int i;
    for (i=0;i<10;i++) {
        struct E *e=&p[i];
        if (e->d != 0) {
            if (func_0216DA30(e->a) == 1) func_0217FCC0(e);
            else func_0217FCA4(e);
        }
    }
}
