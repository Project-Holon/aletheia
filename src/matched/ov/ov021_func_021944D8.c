/*
 * function: FIELD_COMM_ACTOR_Move
 * address:  0x021944D8
 * packet:   pkt_ov021_021944D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FIELD_COMM_ACTOR_ConvertDir  0x021945A0  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 */

typedef unsigned short u16;

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int FIELD_COMM_ACTOR_ConvertDir(int x);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FLDMMDL_SetDrawStatus(void *a, int v);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);

void FIELD_COMM_ACTOR_Move(void *a)
{
    int v[3];
    int *r4;
    int r6;
    int *p;
    int s;
    int t;

    r4 = FLDMMDL_GetMoveProcWork(a);
    FLDMMDL_SetDirDispCheckPause((int)a, FIELD_COMM_ACTOR_ConvertDir(*(u16 *)r4[0]));
    r6 = 0;
    FLDMMDL_GetPos(a, (struct VecFx32 *)v);
    p = (int *)r4[1];
    if (v[0] != p[0] || v[1] != p[1] || v[2] != p[2]) {
        FLDMMDL_InitPosition(a, (int *)r4[1], FLDMMDL_GetDirDisp(a));
        r6 = 3;
        if (*(u16 *)(r4[3] + 6) != 0) {
            s = FLDMMDL_GetObjCode(a);
            if (s == 1 || s == 4) {
                int sum = 0;
                p = (int *)r4[1];
                t = v[0] - p[0];
                if (t < 0)
                    t = -t;
                sum += t;
                t = v[2] - p[2];
                if (t < 0)
                    t = -t;
                sum += t;
                if (sum >= 0x4000)
                    r6 = 10;
            }
        }
    }
    FLDMMDL_SetDrawStatus(a, r6);
    if (r4[2] != 0)
    {
        int f = 0;

        if (*(int *)r4[2] == 1)
            f = 1;
        FLDMMDL_SetStatusBitVanish(a, f);
    }
}
