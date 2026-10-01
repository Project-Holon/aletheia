/*
 * function: func_021A3C6C
 * address:  0x021A3C6C
 * packet:   pkt_ov021_021A3C6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021D89C4  0x021D89C4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x30];
    short step;
    u16 done;
} Obj021A3C6C;

typedef int (*Step021A3C6C)(Obj021A3C6C *p);

extern Step021A3C6C *const data_021D89C4[];

u16 func_021A3C6C(Obj021A3C6C *p, int idx)
{
    Step021A3C6C *tbl;

    if (p->done == 0) {
        tbl = data_021D89C4[idx];
        while (tbl[p->step](p) == 1)
            ;
    }
    return p->done;
}
