/*
 * function: FIELD_PLAYER_NOGRID_AdvanceSpin
 * address:  0x021A6B50
 * packet:   pkt_ov021_021A6B50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetDirDisp  0x0216D5D8  thumb
 *   gFieldPlayerNogridSpinDirs  0x021D8AB0  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

extern void FLDMMDL_SetDirDisp(int a, int b);
extern const u8 gFieldPlayerNogridSpinDirs[][4];

void FIELD_PLAYER_NOGRID_AdvanceSpin(P *p, int a)
{
    if (p->b0) {
        p->h2 = (p->h2 + 1) % 4;
        FLDMMDL_SetDirDisp(a, gFieldPlayerNogridSpinDirs[p->b1][p->h2]);
    }
}
