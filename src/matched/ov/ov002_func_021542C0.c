/*
 * function: EVENT_WIFIBATTLEMATCH_Main
 * address:  0x021542C0
 * packet:   pkt_ov002_021542C0
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov003 EVENT_WIFIBATTLEMATCH_Main and ov004
 * EVENT_WORLDTRADE_Main.  The second argument to GAMESYSTEM_CallProc is pooled 0xC7 (199),
 * a linker overlay id for ov199; the third, 0x02213C4C, lies in its window.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov199_id       0x000000C7  data   a1
 *   d_02213C4C     0x02213C4C  data   ov199  a4
 *   d_02154460     0x02154460  data   ov002  a4
 */

typedef unsigned int u32;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned char  u8;
struct IcaAnime;
extern u32 GAME_COMM_GetKind(void *obj);
typedef unsigned short u16;
struct Evt;
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 a0, u32 a1);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

extern char ov199_id[];
extern char d_02213C4C[];
extern char d_02154460[];

u32 EVENT_WIFIBATTLEMATCH_Main(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[1];
    u32 *p;

    switch (*mode) {
    case 0:
        if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)a0)) == 0) {
            args[0] = GFL_USE_GetBgmNo();
            GFL_USE_FadeOutBgm(6);
            (*mode)++;
        }
        break;
    case 1:
        if (args[7])
            GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)a0, args[2], 0, 0));
        (*mode)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(a0, args[2]));
        (*mode)++;
        break;
    case 3:
        p = func_02030734(4, 0x14, 1, d_02154460, 0x86);
        args[3] = (u32)p;
        p[2] = args[4];
        p[0] = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)a0);
        p[1] = args[6];
        p[3] = args[5];
        GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)ov199_id, d_02213C4C, (void *)args[3]);
        (*mode)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) == 0) {
            func_020307B0((void *)args[3]);
            (*mode)++;
        }
        break;
    case 5:
        (*mode)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)a0));
        GFL_USE_CancelChangeAndPlayBgm(args[0], 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        (*mode)++;
        break;
    case 7:
        if (args[7])
            GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)a0, args[2], 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
