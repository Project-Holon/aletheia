/*
 * function: FLDEFF_SPLASH_ExitBoardObj
 * address:  0x021C4AE8
 * packet:   pkt_ov021_021C4AE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 *
 * symbols:
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 *p;
    u32 f4;
    u16 id;
} S;

struct BbActSys;
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);

void FLDEFF_SPLASH_ExitBoardObj(void *a, S *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)x, s->id, 1);
}
