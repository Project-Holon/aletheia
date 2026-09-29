/*
 * function: func_021735FC
 * address:  0x021735FC
 * packet:   pkt_ov011_021735FC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02039414  0x02039414  arm
 *   func_02173590  0x02173590  thumb  ov011
 *   func_0217778C  0x0217778C  thumb  ov014
 */

typedef unsigned char u8;

typedef struct {
    u8 kind;
    u8 a : 4;
    u8 b : 4;
    u8 c : 1;
    u8 d : 5;
    u8 e : 2;
} Hdr;

extern int func_0203D1B4(void);
extern int func_02039414(void);
extern void func_02173590(int a, Hdr *p, int c);
extern void func_0217778C(void);

int func_021735FC(int a, Hdr *p)
{
    if (p->a != func_0203D1B4() || p->c != func_02039414()) {
        func_02173590(a, p, -1);
        func_0217778C();
        return 1;
    }
    return 0;
}
