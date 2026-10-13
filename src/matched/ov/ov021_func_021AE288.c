/*
 * function: EVENT_TRAINER_EYE_GetSightDistance
 * address:  0x021AE288
 * packet:   pkt_ov021_021AE288
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_TRAINER_EYE_GetSightType  0x021AE79C  thumb  ov021
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   EVENT_TRAINER_EYE_CheckSight  0x021AE348  thumb  ov021
 *   EVENT_TRAINER_EYE_IsPathBlocked  0x021AE7A8  thumb  ov021
 */

typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
extern int EVENT_TRAINER_EYE_GetSightType(u32 a);
extern int FLDMMDL_GetParam(char *a0, int a1);
extern void FLDMMDL_GetGridNowPos(int a, int *b);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int EVENT_TRAINER_EYE_CheckSight(int idx, int a, const s16 *p, const s16 *q);
extern int EVENT_TRAINER_EYE_IsPathBlocked(u32 a, u32 dir, int n, void *p);

int EVENT_TRAINER_EYE_GetSightDistance(int a, int b, int c, u16 *d)
{
    int q[2];
    int p[2];
    int r4, r7, sc;
    u16 r5;

    r4 = EVENT_TRAINER_EYE_GetSightType(b);
    if ((u16)(r4 + 0xffff) <= 1) {
        r5 = 0;
        r7 = (s16)FLDMMDL_GetParam((char *)b, 0);
        FLDMMDL_GetGridNowPos(b, q);
        FLDMMDL_GetGridNowPos(c, p);
        if (r4 == 1) {
            sc = FLDMMDL_GetDirDisp((void *)b);
            r4 = EVENT_TRAINER_EYE_CheckSight(sc, r7, (const s16 *)q, (const s16 *)p);
            if (r4 != r5 - 1 && EVENT_TRAINER_EYE_IsPathBlocked(b, sc, r4, (void *)a) == 0) {
                *d = sc;
                return r4;
            }
        } else {
            do {
                r4 = EVENT_TRAINER_EYE_CheckSight(r5, r7, (const s16 *)q, (const s16 *)p);
                if (r4 != -1 && EVENT_TRAINER_EYE_IsPathBlocked(b, r5, r4, (void *)a) == 0) {
                    *d = r5;
                    return r4;
                }
                r5++;
            } while (r5 < 4);
        }
    }
    return -1;
}
