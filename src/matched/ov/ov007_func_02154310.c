/*
 * function: EVENT_BSUBWAY_COMM_EventMain
 * address:  0x02154310
 * packet:   pkt_ov007_02154310
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov004 EVENT_WORLDTRADE_Main; the task
 * callback EVENT_BSUBWAY_COMM_CreateEvent installs.  Second argument to GAMESYSTEM_CallProc is
 * pooled 0x74 (116), a linker overlay id; the third lies in ov116.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   ov116_id       0x00000074  data   a1
 *   d_021D83A4     0x021D83A4  data   ov116  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Ctx;
struct Evt;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32   GAMESYSTEM_GetGameComm(const struct Ctx *a0);
typedef unsigned char  u8;
struct IcaAnime;
extern u32 func_02026454(void *obj);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

extern char ov116_id[];
extern char d_021D83A4[];

u32 EVENT_BSUBWAY_COMM_EventMain(void *obj, u32 *mode, u32 *args)
{
    u32 h = args[1];
    void *x = GAMESYSTEM_GetFieldMap((void *)h);

    switch (*mode) {
    case 0:
        if (func_02026454((void *)((int)GAMESYSTEM_GetGameComm((const struct Ctx *)h))) == 0)
            (*mode)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)h, (int)x, 0, 0));
        (*mode)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(h, (int)x));
        (*mode)++;
        break;
    case 3:
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov116_id, d_021D83A4, args);
        (*mode)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (args[2] == 0)
                *(u16 *)args[3] = 1;
            else
                *(u16 *)args[3] = 0;
            (*mode)++;
        }
        break;
    case 5:
        GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)h));
        (*mode)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)h, (int)x, 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}
