/*
 * function: FIELD_PLAYER_CORE_RunFormSteps
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
 *   gFieldPlayerFormStepTables  0x021D89C4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x30];
    short step;
    u16 done;
} Obj021A3C6C;

typedef int (*Step021A3C6C)(Obj021A3C6C *p);

extern Step021A3C6C *const gFieldPlayerFormStepTables[];

u16 FIELD_PLAYER_CORE_RunFormSteps(Obj021A3C6C *p, int idx)
{
    Step021A3C6C *tbl;

    if (p->done == 0) {
        tbl = gFieldPlayerFormStepTables[idx];
        while (tbl[p->step](p) == 1)
            ;
    }
    return p->done;
}
