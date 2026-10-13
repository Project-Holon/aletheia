/*
 * function: FIELD_FLASH_Apply
 * address:  0x021C7E30
 * packet:   pkt_ov021_021C7E30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FIELD_FLASH_GetTweenSize  0x021C7EEC  thumb  ov021
 *   FIELD_FLASH_GetTweenAlpha  0x021C7EF4  thumb  ov021
 *   FLD_WIPE_3DOBJ_Draw  0x021C8078  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern u32 FIELD_FLASH_GetTweenSize(u8 *p);
extern u8 FIELD_FLASH_GetTweenAlpha(u8 *p);
extern void FLD_WIPE_3DOBJ_Draw(u32 h, u32 a, u32 b);
void FIELD_FLASH_Apply(M *m)
{
    u32 a;
    if (m != 0) {
        a = FIELD_FLASH_GetTweenSize(m->sub);
        FLD_WIPE_3DOBJ_Draw(m->f0, a, FIELD_FLASH_GetTweenAlpha(m->sub));
    }
}
