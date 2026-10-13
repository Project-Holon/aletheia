/*
 * function: SCRCMD_CountOtherOtIdsTaskMain
 * address:  0x021CF844
 * packet:   pkt_ov021_021CF844
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task body started by SCRCMD_StartCountOtherOtIdsTask: a three-state counter walk.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_CountPartyOtherOtIds  0x021CF8E4  thumb  ov021
 *   SCRCMD_CountBoxOtherOtIds  0x021CF940  thumb  ov021
 *   SCRCMD_CountBattleBoxOtherOtIds  0x021CF9AC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u32 f00;
    int f04;
    u16 *f08;
    int f0c;
} Work;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int SCRCMD_CountPartyOtherOtIds(void *a, void *src, int c);
extern int SCRCMD_CountBoxOtherOtIds(void *a, void *src, void *b, int *c);
extern int SCRCMD_CountBattleBoxOtherOtIds(void *a, void *heap, int x, int y);

int SCRCMD_CountOtherOtIdsTaskMain(void *a, int *task, Work *w)
{
    int *out;
    int flag = 0;
    void *sys;
    int i;

    sys = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(a));
    switch (*task) {
    case 0:
        SCRCMD_CountPartyOtherOtIds((void *)w->f00, sys, (int)(&w->f0c));
        (*task)++;
        break;
    case 1: {
        int base = w->f04;
        out = &w->f0c;
        for (i = flag; i < 2; i++) {
            SCRCMD_CountBoxOtherOtIds((void *)w->f00, sys, (void *)(base + i), out);
            w->f04++;
            if (w->f04 >= 0x18) {
                (*task)++;
                break;
            }
        }
        break;
    }
    case 2:
        SCRCMD_CountBattleBoxOtherOtIds((void *)w->f00, sys, flag, (int)(&w->f0c));
        flag = 1;
        break;
    }
    if (w->f0c >= 0x32) {
        flag = 1;
    }
    if (flag) {
        *w->f08 = w->f0c;
        return 1;
    }
    return 0;
}
