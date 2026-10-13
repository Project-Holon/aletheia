/*
 * function: MOVE_POKEMON_TeleportEventMain
 * address:  0x0215EE68
 * packet:   pkt_ov010_0215EE68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   EVENT_MAPCHANGE_CreateSituationWarpEvent  0x02184F40  thumb  ov020
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
extern void *EVENT_MAPCHANGE_CreateSituationWarpEvent(void *p);
struct S0201235C;
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int MOVE_POKEMON_TeleportEventMain(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = (void *)SCRIPT_SYS_CallScriptEvent(a, 0x2719, 0, 0, 0x15);
        SCRIPT_WORK_SetParams((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        GAME_EVENT_ChangeEvent(a, EVENT_MAPCHANGE_CreateSituationWarpEvent(c->f8));
        break;
    }
    return 0;
}
