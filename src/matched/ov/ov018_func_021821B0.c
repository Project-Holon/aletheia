/*
 * function: EVENT_COMM_COMMON_CreateOfferAnswerEvent
 * address:  0x021821B0
 * packet:   pkt_ov018_021821B0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_020122C0  0x020122C0  thumb
 *   EVENT_COMM_COMMON_OfferAnswerEventMain  0x02182214  thumb  ov018
 *   func_020124E8  0x020124E8  thumb
 *   func_020084F8  0x020084F8  thumb
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x30];
    u8 f30[8];
    u8 pad38[8];
    u16 f40;
    u8 f42;
    u8 pad43;
    u16 f44;
} Task;

typedef struct {
    u8 pad00[0x14];
    u16 f14;
    u16 f16;
    u8 pad18[0x28 - 0x18];
    u8 f28;
} Src;

struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void EVENT_COMM_COMMON_OfferAnswerEventMain();
extern void *func_020124E8(struct Obj *p);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
extern void EVENT_COMM_COMMON_InitMsgBox(Task *, void *);

void *EVENT_COMM_COMMON_CreateOfferAnswerEvent(void *a, Src *b)
{
    void *s;
    void *t;
    Task *p;
    u16 *q;
    void *t0;

    t0 = GAMESYSTEM_GetGameData(a);
    q = &b->f14;
    s = GAME_DATA_GetMyStatus(t0);
    t = func_020122C0(a, 0, EVENT_COMM_COMMON_OfferAnswerEventMain, 0x54);
    p = func_020124E8(t);
    func_020084F8(s, (u32)p->f30, 8);
    p->f40 = q[1];
    p->f42 = q[0];
    p->f44 = b->f28;
    EVENT_COMM_COMMON_InitMsgBox(p, a);
    return t;
}
