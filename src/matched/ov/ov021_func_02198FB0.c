/*
 * function: FLDMMDL_ACMD_HideOffMove
 * address:  0x02198FB0
 * packet:   pkt_ov021_02198FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_MOVE_GetHideEffect  0x0219BF48  thumb  ov021
 *   FLDEFF_HIDE_IsFinished  0x021D04C4  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_MOVE_SetHideNoEffect  0x0219BF54  thumb  ov021
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern u32 *d_021DDBD4;
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern int FLDMMDL_MOVE_GetHideEffect(u32 a);
extern int FLDEFF_HIDE_IsFinished(u32 a);
extern u32 FIELD_EFFECT_DeleteObject(u32);
extern void FLDMMDL_MOVE_SetHideEffect(int a, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_MOVE_SetHideNoEffect(int a0);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_HideOffMove(u32 a)
{
    u32 *p;
    u32 r;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    {
        Vec v = { 0, 0, 0 };
        v.y = d_021DDBD4[p[0]];
        FLDMMDL_SetDrawOffset(a, &v);
        r = FLDMMDL_MOVE_GetHideEffect(a);
        if (r != 0) {
            if (FLDEFF_HIDE_IsFinished(r) == 1) {
                FIELD_EFFECT_DeleteObject(r);
                FLDMMDL_MOVE_SetHideEffect(a, 0);
            }
        }
        p[0] = p[0] + 2;
        if (p[0] < 16) {
            return 0;
        }
        v.y = 0;
        FLDMMDL_SetDrawOffset(a, &v);
    }
    FLDMMDL_SetMoveBit((void *)a, 1344);
    FLDMMDL_MOVE_SetHideNoEffect(a);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
