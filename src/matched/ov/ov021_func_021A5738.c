/*
 * function: func_021A5738
 * address:  0x021A5738
 * packet:   pkt_ov021_021A5738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A5390  0x021A5390  thumb  ov021
 *   func_021A5708  0x021A5708  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x14];
    u16 saved;
    u8 flag;
} Obj021A5738;

int func_021A5390(Obj021A5738 *p);
void func_021A5708(Obj021A5738 *p);

void func_021A5738(Obj021A5738 *p, int a)
{
    u16 s;

    if (func_021A5390(p) == 1) {
        s = p->saved;
        func_021A5708(p);
        if (a == 1) {
            p->saved = s;
            p->flag = 1;
        }
    }
}
