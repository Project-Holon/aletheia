/*
 * function: ENCEFF_NameCutInEventMain
 * address:  0x021F53C8
 * packet:   pkt_ov073_021F53C8
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   FLD3D_CI_StartNameSequence  0x021C1DCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   ENCEFF_NameCutInFadeOutEventMain  0x021F5488  thumb  ov073
 */
typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
struct Evt;
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_GetWork(u32 *p);
extern void *FIELDMAP_GetFld3dCi(u8 *p);
extern int FLD3D_CI_StartNameSequence(int a, char *b, int c, int d);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern int ENCEFF_NameCutInFadeOutEventMain(void *task, int *st);

int ENCEFF_NameCutInEventMain(void *task, int *st)
{
    void *t;
    void *v;
    int *w;
    int r;

    t = GAME_EVENT_GetGameSystem(task);
    v = GAMESYSTEM_GetFieldMap(t);
    w = (int *)ENCEFF_GetWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)v)));
    switch (*st) {
    case 0:
        FADE_Start(4, 0, 0x10, 0);
        *st = *st + 1;
    case 1:
        if (FADE_IsActive() == 0) {
            FADE_Start(4, 0x10, 0, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            w[0] = w[0] + 1;
            if (w[0] < 2) {
                FADE_Start(4, 0, 0x10, 0);
                *st = 1;
            } else {
                r = FLD3D_CI_StartNameSequence((int)t, FIELDMAP_GetFld3dCi((u8 *)v), w[1], w[2]);
                if (r != 0) {
                    GAME_EVENT_CallEvent(task, (struct Evt **)r);
                } else {
                    r = (int)func_020122C0(t, task, (void *)ENCEFF_NameCutInFadeOutEventMain, 0);
                    GAME_EVENT_CallEvent(task, (struct Evt **)r);
                }
                *st = *st + 1;
            }
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
