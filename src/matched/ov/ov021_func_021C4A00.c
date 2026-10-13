/*
 * function: FLDEFF_SPLASH_UnloadBoardImage
 * address:  0x021C4A00
 * packet:   pkt_ov021_021C4A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets flag 1 on the field object (tail call).
 *
 * symbols:
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 obj;
    u16 id;
} S;

struct BbActSys;
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);

void FLDEFF_SPLASH_UnloadBoardImage(S *s)
{
    BILLBOARD_ACT_DeleteSlots((struct BbActSys *)s->obj, s->id, 1);
}
