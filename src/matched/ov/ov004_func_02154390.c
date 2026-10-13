/*
 * function: EVENT_WORLDTRADE_Main
 * address:  0x02154390
 * packet:   pkt_ov004_02154390
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov003 EVENT_WORLDTRADE_Entry.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0x87 (135): a linker overlay id for
 * ov135, and the third, 0x02202BAC, lies in ov135's window.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov135_id       0x00000087  data   a1
 *   d_02202BAC     0x02202BAC  data   ov135  a4
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
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 a0, u32 a1);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

extern char ov135_id[];
extern char d_02202BAC[];

u32 EVENT_WORLDTRADE_Main(void *obj, u32 *mode, u32 *args)
{
    switch (*mode) {
    case 0:
        if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)args[1])) == 0)
            *mode = 1;
        break;
    case 1:
        if (args[20])
            GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)args[1], args[2], 0, 0));
        args[0] = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        *mode = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(args[1], args[2]));
        *mode = 3;
        break;
    case 3:
        GAMESYSTEM_CallProc((struct IcaAnime *)args[1], (u32)ov135_id, d_02202BAC, &args[3]);
        *mode = 4;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)args[1]) == 0) {
            GFL_USE_CancelChangeAndPlayBgm(args[0], 0xFFFF);
            GFL_USE_FadeInBgmFull(0x3C);
            GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)args[1]));
            *mode = 5;
        }
        break;
    case 5:
        if (args[20])
            GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)args[1], args[2], 0, 0, 1, 0, 0));
        *mode = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}
