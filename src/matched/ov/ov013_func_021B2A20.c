/*
 * function: func_021B2A20
 * address:  0x021B2A20
 * packet:   pkt_ov013_021B2A20
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   d_021B4C0C  0x021B4C0C  data  a4
 */

typedef unsigned char u8;

typedef struct N {
    int a;
    u8 id;
    u8 pad[15];
    struct N *next;
} N;

typedef struct {
    int x;
    N *head;
    int pad[9];
    int flag;
    u8 id;
} G;

extern int d_021B60D8[];
extern G d_021B4BE0;
extern N d_021B4C0C;

N *func_021B2A20(int id)
{
    N *n;

    n = d_021B4BE0.head;
    if (d_021B60D8[4] == 2) {
        if (d_021B4BE0.flag != 0 && d_021B4BE0.id == id)
            return &d_021B4C0C;
        return 0;
    }
    while (n) {
        if (n->a != 0 && n->id == id)
            return n;
        n = n->next;
    }
    return 0;
}
