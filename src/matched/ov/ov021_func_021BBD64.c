/*
 * function: FLDEFF_FOOTMARK_DeleteResource
 * address:  0x021BBD64
 * packet:   pkt_ov021_021BBD64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm  arm9
 */

typedef unsigned short u16;

typedef struct {
    int pad0;
    int f4;
    u16 h8[0x1A];
} Obj;

typedef unsigned int   u32;
struct BbActSys;
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);

void FLDEFF_FOOTMARK_DeleteResource(Obj *p)
{
    int i;

    for (i = 0; i < 0x1A; i++) {
        BILLBOARD_ACT_DeleteSlots((struct BbActSys *)p->f4, p->h8[i], 1);
    }
}
