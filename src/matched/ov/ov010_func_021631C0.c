/*
 * function: func_021631C0
 * address:  0x021631C0
 * packet:   pkt_ov010_021631C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082C60  0x02082C60  arm
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
    int g;
    int h;
    u8 i;
} S;

extern void func_02082C60();
extern int func_0216D7E4();
extern int func_0216D7DC();
extern int func_021AB0F0();
extern int func_021AB0F8();
extern int func_0216E3C4();
extern void func_0216D67C();
extern void func_0216D534();
extern int func_02188CD0();
extern int func_021ABE28();

void func_021631C0(int a, S *s)
{
    func_02082C60(s, 0, 0x1c);
    s->a = func_0216D7E4(a);
    s->b = func_0216D7DC(a);
    if (s->b != -1) {
        s->d = func_021AB0F0();
        s->f = func_021AB0F8(s->b);
    }
    if (s->a != -1) {
        s->c = func_021AB0F0(s->a);
        s->e = func_021AB0F8(s->a);
    }
    s->g = func_0216E3C4(a);
    func_0216D67C(a);
    func_0216D534();
    s->h = func_02188CD0();
    s->i = func_021ABE28();
}
