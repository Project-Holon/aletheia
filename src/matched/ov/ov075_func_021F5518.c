/*
 * function: ENCEFF_ScreenTexEventMain
 * address:  0x021F5518
 * packet:   pkt_ov075_021F5518
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state proc; its states 1-3 are ENCEFF_ScreenTexFlashEventMain's states 4-6, and the
 * shape follows ov073's ENCEFF_NameCutInEventMain.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_RequestScreenCapture  0x021F54A0  thumb  ov075
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   FIELDMAP_GetDrawMode  0x021899F0  thumb  ov021
 *   GX_GetBankForTex  0x02080C44  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02080294  0x02080294  arm
 *   ENCEFF_GetScreenTexParam  0x021F54E0  thumb  ov075
 *   func_02040588  0x02040588  arm
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    int f0;
    u32 f4;
    int f8;
    u32 fC;
    int f10;
    u32 f14;
    u8 pad18[0xC];
    u32 f24;
    int (*f28)(void *sys);
} Work;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void ENCEFF_RequestScreenCapture(char *p);
extern void BG_SYS_SetVisibleLayer(int idx, u16 val);
extern u32 FIELDMAP_GetDrawMode(u8 *p);
extern u16 GX_GetBankForTex(void);
extern void func_02080B98(void);
extern void func_02080294(u32 bank);
extern u32 ENCEFF_GetScreenTexParam(void);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void FIELDMAP_SetDrawMode(u8 *p, u32 v);
struct Evt;
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_GetWork(u32 *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int ENCEFF_ScreenTexEventMain(void *task, int *st, Work *w)
{
    void *t;
    void *v;
    u32 bank;
    int r;

    t = GAME_EVENT_GetGameSystem(task);
    v = GAMESYSTEM_GetFieldMap(t);
    switch (*st) {
    case 0:
        ENCEFF_RequestScreenCapture((char *)w);
        *st = *st + 1;
        break;
    case 1:
        if (w->f10 != 0) {
            BG_SYS_SetVisibleLayer(0, 0);
            BG_SYS_SetVisibleLayer(2, 3);
            w->fC = FIELDMAP_GetDrawMode((u8 *)v);
            bank = GX_GetBankForTex();
            w->f4 = bank;
            w->f8 = 0;
            if ((bank & 8) == 0) {
                w->f4 = bank | 8;
                w->f8 = 1;
            }
            func_02080B98();
            func_02080294(w->f4);
            w->f14 = ENCEFF_GetScreenTexParam();
            *st = *st + 1;
        }
        break;
    case 2:
        func_02040588(2, 1);
        func_02040588(0, 1);
        FIELDMAP_SetDrawMode((u8 *)v, 2);
        r = w->f28(t);
        w->f24 = ENCEFF_GetWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)v)));
        GAME_EVENT_CallEvent(task, (struct Evt **)r);
        *st = *st + 1;
        break;
    case 3:
        if (w->f8 == 1) {
            w->f4 &= ~8;
            func_02080294(w->f4);
        }
        FIELDMAP_SetDrawMode((u8 *)v, w->fC);
        return 1;
    }
    return 0;
}
