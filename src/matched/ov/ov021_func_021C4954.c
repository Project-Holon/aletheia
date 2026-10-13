/*
 * function: FLDEFF_RIPPLE_UpdateObj
 * address:  0x021C4954
 * packet:   pkt_ov021_021C4954
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Notifies the owner when the field-object query succeeds (EXACT*:
 * follower).
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 *p;
    u16 id;
} S;

typedef unsigned char  u8;
extern u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out);
extern void FIELD_EFFECT_DeleteObject(void *a);

void FLDEFF_RIPPLE_UpdateObj(void *a, S *s)
{
    u32 tmp;

    if (BILLBOARD_ACT_GetEntryLastCommand((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        FIELD_EFFECT_DeleteObject(a);
}
