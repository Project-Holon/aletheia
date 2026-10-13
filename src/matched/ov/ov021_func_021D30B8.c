/*
 * function: EVENT_GAME_MANUAL_Create
 * address:  0x021D30B8
 * packet:   pkt_ov021_021D30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02030734  0x02030734  arm
 *   EVENT_GAME_MANUAL_Main  0x021D310C  thumb  ov021
 *   d_021DE698     0x021DE698  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct W {
    void *a;
    void *b;
    void **c;
    u16 *d;
} W;

struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 EVENT_GAME_MANUAL_Main(u32 a, u32 *st, u32 *p);
extern char d_021DE698[];

void *EVENT_GAME_MANUAL_Create(void *a, u16 *b)
{
    void *r7;
    void *s4;
    void *s8;
    W *w;

    r7 = GAMESYSTEM_GetGameData(a);
    s4 = GAMESYSTEM_GetFieldMap(a);
    s8 = func_020122C0(a, 0, EVENT_GAME_MANUAL_Main, 0x10);
    w = func_020124E8(s8);
    w->a = a;
    w->b = s4;
    w->d = b;
    w->c = func_02030734(4, 8, 0, d_021DE698, 0x4a);
    *w->c = r7;
    return s8;
}
