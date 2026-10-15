/*
 * function: EVENT_GSYNC_Main
 * address:  0x021542C0
 * packet:   pkt_ov000_021542C0
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode (25 states), same family as ov003 EVENT_GSYNC_Main.
 * Pooled small words 0x7B/0x10/0x73/0xAA are linker overlay ids
 * (ov123/ov016/ov115/ov170) handed with a table in that overlay's window.
 * 0x04000208 (IME) and 0x04000304 (POWCNT) are cast hardware constants.
 *
 * 2026-10-04 (wave D2 lane 14): re-checked, still MATCH* with 59 of 60 sites resolved; only
 * ov170_id (+0394) is open. Needs the OVERLAY_ID_CONSUMERS entry below (tools/match.py), not source.
 *
 * Blocker (MATCH, every concrete byte right, 59 of 60 sites resolved): the
 * pool word 0x000000AA (ov170_id, +0x394) has no witness.  It is the id
 * argument (r1) of GAME_EVENT_CallProc, which is not in OVERLAY_ID_CONSUMERS;
 * GAME_EVENT_CallProc (EXACT, arm9) stores its r1 as item[0], and its state
 * machine GAME_EVENT_CallProcSeq (EXACT) passes item[0] to GAMESYSTEM_CallProc's id
 * parameter, so adding 0x02012444 with register 1 to OVERLAY_ID_CONSUMERS
 * in tools/match.py would resolve it as `overlay_id` (integrator's call).
 * No cut helps: the only pool word holding 0xAA is this function's own.
 *
 * symbols:
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_ClearSndHeap  0x02005C18  thumb
 *   GFL_USE_InitSound  0x02005B24  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009304  0x02009304  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0200873C  0x0200873C  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   ov123_id       0x0000007B  data   a1
 *   ov016_id       0x00000010  data   a1
 *   ov115_id       0x00000073  data   a1
 *   ov170_id       0x000000AA  data   a1
 *   d_021DA674     0x021DA674  data   ov123  a4
 *   d_021DA838     0x021DA838  data   ov123  a4
 *   d_021D77B8     0x021D77B8  data   ov016  a4
 *   gNetSaveMainProc     0x021D6338  data   ov115  a4
 *   gNetSaveRetryProc     0x021D654C  data   ov115  a4
 *   d_021EF78C     0x021EF78C  data   ov170  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef volatile u16   vu16;

struct Big;
struct BigObj;
struct Ctx;
struct Evt;
struct IcaAnime;
struct Obj;
struct Sub02008700Obj;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void  MI_CpuFill8(void *p, int c, int n);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u16 GFL_USE_GetBgmNo(void);
extern void  GFL_USE_ClearSndHeap(void);
extern void  GFL_USE_InitSound(void);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 a0, u32 a1);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_02009304(const struct Sub02009210Obj *obj);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern int func_020079A0(void *save);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern u32 func_0200FB24(void);
extern void  GFL_NET_ERR_RequestScreen(void);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern char ov123_id[];
extern char ov016_id[];
extern char ov115_id[];
extern char ov170_id[];
extern char d_021DA674[];
extern char d_021DA838[];
extern char d_021D77B8[];
extern char gNetSaveMainProc[];
extern char gNetSaveRetryProc[];
extern char d_021EF78C[];

#define F(o)  (*(u32 *)(args + (o)))
#define H(o)  (*(u16 *)(args + (o)))
#define B(o)  (*(u8 *)(args + (o)))

u32 EVENT_GSYNC_Main(void *obj, u32 *mode, char *args)
{
    u32 h = F(0x0);
    u32 v = (u32)ICA_ANIME_GetField20((const struct Ctx *)h);
    int r;

    switch (*mode) {
    case 0:
        GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)h, v, 0, 0));
        (*mode)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(h, v));
        F(0x2c8) = 0;
        *mode = 2;
        break;
    case 2:
        MI_CpuFill8(args + 0xc, 0, 0x44);
        F(0x50) = 0;
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov123_id, d_021DA674, args);
        (*mode)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (F(0x1c8) == 2)
                *mode = 16;
            else if (F(0x1c8) == 3)
                *mode = 5;
            else
                *mode = 10;
        }
        break;
    case 5:
        (*mode)++;
        break;
    case 6:
        F(0x1d4) = GFL_USE_GetBgmNo();
        GFL_USE_ClearSndHeap();
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov016_id, d_021D77B8, args);
        (*mode)++;
        break;
    case 7:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0)
            *mode = 14;
        break;
    case 14:
        {
            vu16 *ime = (vu16 *)0x04000208;
            u16 old = *ime;
            *ime = 1;
            (void)old;
        }
        GFL_USE_InitSound();
        GFL_USE_CancelChangeAndPlayBgm(F(0x1d4), 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        *mode = 15;
        break;
    case 15:
        F(0x2c8) = 1;
        *mode = 2;
        break;
    case 10:
        GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)h));
        (*mode)++;
        break;
    case 11:
        GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)h, v, 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 12:
        if (F(0x1cc)) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            GFL_USE_FadeInBgmFull(0x3C);
            F(0x1cc) = 0;
        }
        (*mode)++;
        break;
    case 13:
        return 1;
    case 16:
        r = func_02009304((const struct Sub02009210Obj *)func_02009448(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C((const struct Ctx *)h))));
        if (func_020079A0((void *)GAME_DATA_GetBoxManager(ICA_ANIME_GetField1C((const struct Ctx *)h))) == 0 && r == 0) {
            F(0x1c8) = 4;
            *mode = 19;
        } else {
            F(0x26c) = 0;
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            F(0x1cc) = 1;
            (*mode)++;
        }
        break;
    case 17:
        F(0x268) = (u32)(args + 0x54);
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov115_id, gNetSaveMainProc, args + 0x258);
        (*mode)++;
        break;
    case 18:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (F(0x274) == 1) {
                *mode = 10;
            } else {
                if (func_02009304((const struct Sub02009210Obj *)func_02009448((void *)F(0x8))) == 0) {
                    F(0x1c8) = 3;
                    *mode = 19;
                } else {
                    F(0x1c8) = 0;
                    *mode = 19;
                }
            }
        }
        break;
    case 19:
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov123_id, d_021DA838, args);
        (*mode)++;
        break;
    case 20:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (F(0x1c8) == 1) {
                F(0x2c8) = 0;
                *mode = 2;
            } else if (F(0x1c8) == 5) {
                *mode = 21;
            } else if (F(0x1c8) == 4) {
                *mode = 21;
            } else if (F(0x1c8) == 7) {
                F(0x26c) = 1;
                *mode = 17;
            } else {
                *mode = 23;
            }
        }
        break;
    case 21:
        F(0x29c) = (u32)ICA_ANIME_GetField1C((const struct Ctx *)h);
        F(0x2a0) = GAME_DATA_GetBoxManager((const struct BigObj *)F(0x29c));
        F(0x2a4) = (u32)GAME_DATA_GetMyParty((const struct BigObj *)F(0x29c));
        F(0x2a8) = (u32)GAME_DATA_GetMyItem((const struct BigObj *)F(0x29c));
        F(0x2ac) = (u32)func_02012944((void *)F(0x29c));
        F(0x2b4) = (u32)func_0200873C(GAME_DATA_GetSaveControl((struct Big *)F(0x29c)));
        F(0x2bc) = (u32)(args + 0x1d8);
        F(0x2b8) = 0;
        F(0x2c0) = 5;
        GAME_EVENT_CallProc(obj, (u32)ov170_id, (u32)d_021EF78C, (u32)(args + 0x29c));
        (*mode)++;
        break;
    case 22:
        if (func_0200FB24()) {
            GFL_NET_ERR_RequestScreen();
            GFL_NET_ERR_ShowScreen(0);
            F(0x26c) = 1;
            *mode = 17;
        } else {
            u8 a, b;
            a = B(0x2c6);
            H(0x1d0) = a;
            b = B(0x2c7);
            H(0x1d2) = b;
            if (a == 0xff && b == 0xff) {
                *mode = 23;
            } else {
                if (F(0x1c8) == 4)
                    F(0x1c8) = 2;
                else
                    F(0x1c8) = 1;
                *mode = 19;
            }
        }
        break;
    case 23:
        F(0x280) = (u32)ICA_ANIME_GetField1C((const struct Ctx *)h);
        F(0x284) = 1;
        F(0x288) = 0;
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov115_id, gNetSaveRetryProc, args + 0x280);
        (*mode)++;
        break;
    case 24:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)h);
            *(vu16 *)0x04000304 |= 0x8000;
            F(0x2c8) = 0;
            *mode = 2;
            if (F(0x1cc)) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPlayerParam(0);
                GFL_USE_FadeInBgmFull(0x3C);
                F(0x1cc) = 0;
            }
        }
        break;
    }
    return 0;
}
