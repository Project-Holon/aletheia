/*
 * function: FIELD_TILE_MOVE_SlideStartStep
 * address:  0x021C8D3C
 * packet:   pkt_ov021_021C8D3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_TILE_MOVE_GetSlideStepAcmd  0x021C8CF8  thumb  ov021
 *   FIELD_TILE_MOVE_GetBumpAcmd  0x021C8D08  thumb  ov021
 *   FIELD_TILE_MOVE_SlidePlayBumpSe  0x021C8DF4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern int FIELD_TILE_MOVE_GetBumpAcmd(u32 a);
extern int FIELD_TILE_MOVE_GetSlideStepAcmd(u32 a);
extern void FLDMMDL_SetAcmd(u32 a, u32 b);
extern void FIELD_TILE_MOVE_SlidePlayBumpSe(P *p);
void FIELD_TILE_MOVE_SlideStartStep(P *p)
{
    if (p->f14 != 0) {
        FLDMMDL_SetAcmd(p->fC, FIELD_TILE_MOVE_GetBumpAcmd((u32)p));
        FIELD_TILE_MOVE_SlidePlayBumpSe(p);
        p->f18 = 1;
        return;
    }
    if (p->f10 != 0)
        FLDMMDL_SetAcmd(p->fC, FIELD_TILE_MOVE_GetSlideStepAcmd((u32)p));
}
