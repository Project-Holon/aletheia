/*
 * function: EVENT_POKE_STATUS_CreatePokeSelectStatusEvent
 * address:  0x0215A168
 * packet:   pkt_ov010_0215A168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_02030734  0x02030734  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   EVENT_POKE_STATUS_PokeSelectEvent  0x0215A214  thumb  ov010
 *   d_021728CC  0x021728CC  data
 */

typedef unsigned int u32;

struct Blk37;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned short u16;
struct BigObj;
struct Ctx;
struct Obj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_0201AA18(void *p);
extern void EVENT_POKE_STATUS_PokeSelectEvent(void);
extern const char d_021728CC[];

typedef unsigned char u8;

void *EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(int a, int b, int c)
{
    void *h = GAMESYSTEM_GetGameData((const struct Ctx *)a);
    void *l = GAME_DATA_GetMyParty(h);
    int m = (int)func_0200CA1C(h);
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x90);
    u32 *s;
    void *r;
    u32 *q;
    p[0] = (u32)l;
    p[0x34 / 4] = 0x19;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    s = func_02030734(4, 0x28, 1, d_021728CC, 0x97);
    s[0] = (u32)l;
    s[2] = (u32)h;
    ((u8 *)s)[0xc] = 1;
    ((u8 *)s)[0xd] = 1;
    ((u8 *)s)[0xe] = func_0201AA18(l);
    ((u8 *)s)[0x10] = 0;
    s[0x18 / 4] = func_0200CA38((struct Blk37 *)m);
    s[0x20 / 4] = 0;
    r = func_020122C0((void *)a, 0, EVENT_POKE_STATUS_PokeSelectEvent, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = (u32)GAMESYSTEM_GetFieldMap((void *)a);
    q[2] = (u32)p;
    q[3] = (u32)s;
    q[4] = b;
    q[5] = c;
    return r;
}
