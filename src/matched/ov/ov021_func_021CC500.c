/*
 * function: FLD_TRADE_CreateEvent
 * address:  0x021CC500
 * packet:   pkt_ov021_021CC500
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FLD_TRADE_EventMain  0x021CC390  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Task {
    void *f0;
    void *f4;
    void *f8;
    u8 fC;
    u8 fD;
    u8 padE[0x58 - 0xE];
    u32 f58;
} Task;

struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int FLD_TRADE_EventMain(u32 a, u32 b, u32 c);

void *FLD_TRADE_CreateEvent(void *a, u32 b, u32 c)
{
    void *t;
    void *x;
    void *h;
    Task *p;

    t = GAMESYSTEM_GetGameData(a);
    x = GAME_DATA_GetMyParty(t);
    h = func_020122C0(a, 0, (void *)FLD_TRADE_EventMain, 0x5c);
    p = func_020124E8(h);
    p->f0 = a;
    p->f4 = t;
    p->f8 = x;
    p->fC = b;
    p->fD = c;
    p->f58 = 0;
    return h;
}
