/*
 * function: GIMMICK_INIT_RestorePlateDoorsState
 * address:  0x021F3768
 * packet:   pkt_ov037_021F3768
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   GIMMICK_WORK_GetProgress  0x0200B3A8  thumb
 *   gGimmick38SwitchPlates     0x021F3840  data ov037 a1
 *   gGimmick38DoorPlates     0x021F3834  data a1
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, unsigned int b);
typedef unsigned int   u32;
struct Rec94;
extern u8 *GIMMICK_WORK_GetProgress(struct Rec94 *p, u32 a1);
extern signed char gGimmick38SwitchPlates[][2];
extern unsigned char gGimmick38DoorPlates[][2];

void GIMMICK_INIT_RestorePlateDoorsState(unsigned int a0, unsigned short **a1)
{
    unsigned int t = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)a0));
    int *p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)t, 6);
    unsigned short *q = (short unsigned int *)GIMMICK_WORK_GetProgress((struct Rec94 *)t, 6);
    int i;
    int j;
    int k;

    for (i = 0; i < 8; i++) {
        if (q[i] != 0) {
            p[i] = 1;
            *a1[i] = 1;
            for (j = 0; j < 2; j++) {
                k = gGimmick38SwitchPlates[i][j];
                if (k != -1)
                    p[8 + k] = 1;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            if (p[8 + gGimmick38DoorPlates[i][j]] == 0)
                break;
        }
        if (j == 2)
            p[18 + i] = 1;
    }
    p[24] = 1;
}
