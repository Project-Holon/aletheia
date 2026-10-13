/*
 * function: EVENT_TRAINER_EYE_GetPlayerDistance
 * address:  0x021AE198
 * packet:   pkt_ov021_021AE198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   EVENT_TRAINER_EYE_CheckSight  0x021AE348  thumb  ov021
 *   EVENT_TRAINER_EYE_IsPathBlocked  0x021AE7A8  thumb  ov021
 */

typedef short s16;

typedef unsigned int   u32;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void FLDMMDL_GetGridNowPos(int a, int *b);
extern int EVENT_TRAINER_EYE_CheckSight(int idx, int a, const s16 *p, const s16 *q);
extern int EVENT_TRAINER_EYE_IsPathBlocked(u32 a, u32 dir, int n, void *p);

int EVENT_TRAINER_EYE_GetPlayerDistance(int a, int b, int c, int d)
{
    int q[2];
    int p[2];
    int h;
    int r;

    h = (int)FLDMMDL_SysSearchObjId(FLDMMDL_GetMmdlSys((void *)a), 0xff);
    if (h == 0)
        return -1;
    FLDMMDL_GetGridNowPos(h, p);
    FLDMMDL_GetGridNowPos(a, q);
    r = EVENT_TRAINER_EYE_CheckSight(b, (s16)c, (const s16 *)q, (const s16 *)p);
    if (r != -1) {
        if (EVENT_TRAINER_EYE_IsPathBlocked(a, b, r, (void *)d) == 1)
            r = -1;
    }
    return r;
}
