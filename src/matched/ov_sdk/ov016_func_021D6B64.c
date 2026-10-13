/*
 * function: DWCi_TPlGet
 * address:  0x021D6B64
 * packet:   pkt_ov016_021D6B64
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TPlGet (libdwcutil.TWL.HYB.a input.o)
 *
 * symbols:
 *   gInputStatics     0x021DE688  data
 */

typedef struct tagCOORD {
    unsigned short x, y;
} COORD;

typedef struct TpData {
    unsigned char pad0[0x28];
    COORD a;
    COORD b;
    unsigned char pad1[8];
    unsigned char flag : 1;
} TpData;

typedef struct FoldState {
    unsigned char fold;
    TpData *tp;
} FoldState;

extern FoldState gInputStatics;

int DWCi_TPlGet(COORD *c)
{
    TpData *t;
    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    t = gInputStatics.tp;
    if (!t->flag) {
        *c = t->b;
        return 0;
    }
    *c = t->a;
    return 1;
}
