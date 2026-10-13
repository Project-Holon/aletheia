/*
 * function: EVENT_RESEARCH_RADAR_TopTaskMain
 * address:  0x02166F9C
 * packet:   pkt_ov010_02166F9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   ov217_id  0x000000D9  data
 *   gResearchTopProcData  0x021C3FE0  data  ov217
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
struct IcaAnime;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_020307B0(void *p);
extern char ov217_id[];
extern char gResearchTopProcData[];

int EVENT_RESEARCH_RADAR_TopTaskMain(void *a, int *st, int *p)
{
    int p0 = p[0];
    int p1 = p[1];
    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent(a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)p0, p1, 0, 0));
        *st = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent(a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(p0, p1));
        *st = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc((struct IcaAnime *)p0, (u32)ov217_id, gResearchTopProcData, (void *)p[2]);
        *st = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent(a, (struct Evt **)((int)FIELD_STATUS_CreateFieldOpenEvent((void *)p0)));
        *st = 4;
        break;
    case 4:
        GAME_EVENT_CallEvent(a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)p0, p1, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        func_020307B0((void *)p[2]);
        return 1;
    }
    return 0;
}
