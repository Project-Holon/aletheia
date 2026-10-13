/*
 * function: BTLV_GAUGE_SetSlotBarsVisible
 * address:  0x02208D50
 * packet:   pkt_ov094_02208D50
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the flag word at 0x440 is a bitfield struct (bit 4 read as
 * lsls #27 / lsrs #31); a plain u32 with `(f >> 4) & 1` gives lsrs/ands
 * and a different register assignment.
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
typedef unsigned int u32;

typedef struct {
    int f00;                /* 0x40 in the work area */
    int h04;                /* 0x44 */
    int h08;                /* 0x48 */
    char pad0c[0x40 - 0x0c];
    int state;              /* 0x80 */
    char pad44[0x80 - 0x44];
} Row;

typedef struct {
    char pad00[0x40];
    Row r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 hi : 11;
    } flags;                /* 0x440 */
} W;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void BTLV_GAUGE_SetSlotBarsVisible(W *w, int i, int b)
{
    if ((w->r[i].state == 2 || w->r[i].state == 3) && b == 1 && (i & 1) == 0) {
        CLACT_SetActorDrawEnable((struct Obj *)w->r[i].h04, w->flags.b4);
        CLACT_SetActorDrawEnable((struct Obj *)w->r[i].h08, w->flags.b4 ? 0 : 1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)w->r[i].h04, b);
        CLACT_SetActorDrawEnable((struct Obj *)w->r[i].h08, b);
    }
}
