/*
 * function: GFL_NET_COMMAND_AddCommandTable
 * address:  0x0203A574
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _pCommandWork   0x021469D8  data
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
} Ent;

extern Ent *_pCommandWork;

void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d)
{
    Ent *p = _pCommandWork;
    int i;

    if (p == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (p[i].fC == 0 || p[i].fC == a) {
            p[i].fC = a;
            _pCommandWork[i].f0 = b;
            _pCommandWork[i].f4 = c;
            _pCommandWork[i].f8 = d;
            return;
        }
    }
}
