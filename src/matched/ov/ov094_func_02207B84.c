/*
 * function: func_02207B84
 * address:  0x02207B84
 * packet:   pkt_ov094_02207B84
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02207EA8  0x02207EA8  thumb  ov094
 */

typedef unsigned int u32;
typedef struct {
    char pad[0x70];
    u32 a : 8;
    u32 b : 8;
    u32 c : 12;
    u32 d : 1;
    u32 e : 3;
    char pad2[0x80 - 0x74];
} E;
typedef struct {
    char pad[0x40];
    E e[1];
} W;

extern void func_02207EA8(E *e, int c);

void func_02207B84(W *p, int i, int c)
{
    p->e[i].b = 0;
    p->e[i].d = 1;
    func_02207EA8(&p->e[i], c);
}
