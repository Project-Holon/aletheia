/*
 * function: FLDMMDL_ACMD_HideOffInit
 * address:  0x02198F68
 * packet:   pkt_ov021_02198F68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_MOVE_GetHideEffect  0x0219BF48  thumb  ov021
 *   FLDEFF_HIDE_RequestEnd  0x021D04A4  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern u32 FLDMMDL_InitMoveCmdWork(u32, u32);
extern int FLDMMDL_MOVE_GetHideEffect(u32 a);
extern void FLDEFF_HIDE_RequestEnd(void *a);
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_HideOffInit(u32 a)
{
    u32 t;

    FLDMMDL_InitMoveCmdWork(a, 4);
    t = FLDMMDL_MOVE_GetHideEffect(a);
    if (t != 0) {
        FLDEFF_HIDE_RequestEnd((void *)t);
    }
    {
        Vec v = { 0, 0, 0 };
        FLDMMDL_SetDrawOffset(a, &v);
    }
    FLDMMDL_SetMoveBit((void *)a, 160);
    FLDMMDL_ClearMoveBit((char *)a, (2 << 14));
    FLDMMDL_IncAcmdSeq(a);
    return 0;
}
