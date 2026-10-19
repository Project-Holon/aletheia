/*
 * function: EVENT_WIFI_PROC_Create
 * address:  0x0215FBF4
 * packet:   pkt_ov010_0215FBF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   EVENT_WIFI_PROC_EventMain  0x0215FA54  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern u32 FIELDMAP_GetSubscreen(u8 *p);
struct Desc;
struct Ctx;
struct Big;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GAME_EVENT_Change(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
struct Work;
extern int EVENT_WIFI_PROC_EventMain(void *evt, u32 *state, struct Work *w);

/* record behind the descriptor: owner, its context, the context's head */
struct Rec {
    int   owner;
    void *ctx;
    void *head;
};

struct Desc *EVENT_WIFI_PROC_Create(int a0, int a1, struct Desc *a2, int a3)
{
    struct Rec *p;
    void *ctx;

    FIELDMAP_GetSubscreen((u8 *)a1);
    if (a3 != 0) {
        a2 = func_020122C0((void *)a0, 0, (void *)EVENT_WIFI_PROC_EventMain, 0x34);
    } else {
        GAME_EVENT_Change((char *)a2, (int)EVENT_WIFI_PROC_EventMain, 0x34);
    }
    p = (struct Rec *)func_020124E8((struct Obj *)a2);
    ctx = GAMESYSTEM_GetGameData((const struct Ctx *)a0);
    p->ctx = ctx;
    p->head = GAME_DATA_GetSaveControl((struct Big *)ctx);
    p->owner = a0;
    return a2;
}
