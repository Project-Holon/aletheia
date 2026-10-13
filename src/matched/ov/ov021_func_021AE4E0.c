/*
 * function: EVENT_TRAINER_EYE_StepWaitPlayer
 * address:  0x021AE4E0
 * packet:   pkt_ov021_021AE4E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
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
extern int FLDMMDL_CheckEndAcmd(void *a0);
typedef unsigned short u16;
extern u16 FLDMMDL_GetMoveCode(void *p);

int EVENT_TRAINER_EYE_StepWaitPlayer(Task *p)
{
    if (FLDMMDL_CheckEndAcmd(FIELD_PLAYER_GetMmdl(p->f34)) == 0)
        return 0;
    p->state = 3;
    switch (FLDMMDL_GetMoveCode(p->f08)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        p->state = 7;
        break;
    }
    return 1;
}
