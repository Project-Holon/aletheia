/*
 * function: IRC_BATTLE_ENTRY_Create
 * address:  0x021559E4
 * packet:   pkt_ov010_021559E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRC_BATTLE_ENTRY_Main  0x02155478  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 */
#include "../include/Obj05876.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Task {
    void *f00;
    void *f04;
    u8 pad08[0x30];
    void *f38;
    void *f3c[4];
    u8 pad4c[4];
} Task;

struct Ctx;
extern int IRC_BATTLE_ENTRY_Main(void *proc, int *seq, struct Ctx *ctx);
struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Party;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GAME_EVENT_Change(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Party *POKEPARTY_Create(u32 heap);

void *IRC_BATTLE_ENTRY_Create(void *a, int b, void *c, int d)
{
    Task *t;
    int i;

    if (d != 0)
        c = func_020122C0(a, 0, IRC_BATTLE_ENTRY_Main, 0xE8);
    else
        GAME_EVENT_Change(c, (int)IRC_BATTLE_ENTRY_Main, 0xE8);
    t = func_020124E8(c);
    ((struct Obj05876 *)t)->f4C = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(a));
    t->f04 = GAMESYSTEM_GetGameData(a);
    t->f00 = a;
    for (i = 0; i < 4; i++)
        t->f3c[i] = POKEPARTY_Create(4);
    t->f38 = POKEPARTY_Create(4);
    return c;
}
