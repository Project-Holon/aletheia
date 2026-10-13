/*
 * function: EVENT_TRAINER_EYE_StepPlayerFaceTrainer
 * address:  0x021AE66C
 * packet:   pkt_ov021_021AE66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 */

typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_GetGridNowX(void *x);
extern int FLDMMDL_GetGridNowZ(void *x);
typedef unsigned short u16;
extern u16 FLDMMDL_MOVE_GetDirFromPoints(int x0, int y0, int x1, int y1);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *a, int b);

int EVENT_TRAINER_EYE_StepPlayerFaceTrainer(Task *p)
{
    void *r4 = FIELD_PLAYER_GetMmdl(p->f34);
    int r6 = FLDMMDL_GetGridNowX(r4);
    int r7 = FLDMMDL_GetGridNowZ(r4);
    int t = FLDMMDL_GetGridNowX(p->f08);

    r6 = FLDMMDL_MOVE_GetDirFromPoints(r6, r7, t, FLDMMDL_GetGridNowZ(p->f08));
    if (r6 != FLDMMDL_GetDirDisp(r4) && (p->f24 == 0 || p->f1C == 2)) {
        if (FLDMMDL_CheckPossibleAcmd((int)r4) == 1) {
            FLDMMDL_SetAcmd(r4, FLDMMDL_ACMD_ConvertCodeByDir(r6, 0));
            p->state = 0xf;
        }
    } else {
        p->state = 0x10;
    }
    return 0;
}
