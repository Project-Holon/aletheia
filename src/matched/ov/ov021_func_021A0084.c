/*
 * function: FLDMMDL_DRAW_DrawEffect
 * address:  0x021A0084
 * packet:   pkt_ov021_021A0084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   FLDMMDL_ACMD_CheckAnimePaused  0x02197C9C  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_G3DOBJ_GetObjCtrl  0x0219D49C  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectTrans  0x021C6664  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectHidden  0x021C6678  thumb  ov021
 *   FIELD_G3DOBJ_LoopAnimeFrame  0x021C66EC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *FLDMMDL_GetDrawProcWork(void *p);
extern u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern int FLDMMDL_CheckStatusBitVanish(void *a0);
extern int FLDMMDL_ACMD_CheckAnimePaused(u32 a);
extern void FIELD_G3DOBJ_SetObjectTrans(u32, u32, u32 *);
extern void FIELD_G3DOBJ_SetObjectHidden(u32, u32, u32);
extern int FIELD_G3DOBJ_LoopAnimeFrame(u32 *a, int idx, int v);

void FLDMMDL_DRAW_DrawEffect(u32 a)
{
    u32 f;
    u32 q;
    u32 buf[3];
    u16 *p;

    p = FLDMMDL_GetDrawProcWork((void *)a);
    q = FLDMMDL_G3DOBJ_GetObjCtrl(a);
    FLDMMDL_ACMD_GetDrawPos((u8 *)a, (s32 *)buf);
    FIELD_G3DOBJ_SetObjectTrans(q, *p, buf);
    f = 0;
    if (FLDMMDL_CheckStatusBitVanish((void *)a) == 1) f = 1;
    FIELD_G3DOBJ_SetObjectHidden(q, *p, f);
    if (FLDMMDL_ACMD_CheckAnimePaused(a) == 0) {
        FIELD_G3DOBJ_LoopAnimeFrame((u32 *)q, *p, 0x1000);
    }
}
