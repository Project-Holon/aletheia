/*
 * function: EVENT_COMM_COMMON_StartMsgEvent
 * address:  0x021828B8
 * packet:   pkt_ov018_021828B8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   EVENT_COMM_COMMON_MsgEventMain  0x02182920  thumb  ov018
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02034714  0x02034714  arm
 *   d_02183B4C     0x02183B4C  data   a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x10];
    void *f10;
    u8 pad14[0x42 - 0x14];
    u8 f42;
    u8 pad43[0x78 - 0x43];
    u8 f78[0x20];
} Src;

typedef struct {
    u8 pad00[0x9C];
    u16 f9C;
} Dst;

typedef unsigned int   u32;
struct Obj;
struct WordSet;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void GAME_EVENT_Change(char *p, int a1, int a2);
extern void EVENT_COMM_COMMON_MsgEventMain();
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(void *, void *, int);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02183B4C[];

void EVENT_COMM_COMMON_StartMsgEvent(void *a, Src *b, u16 *c)
{
    u8 *v;
    Dst *p;

    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(a))));
    GAME_EVENT_Change(a, (int)EVENT_COMM_COMMON_MsgEventMain, 0xAC);
    p = func_020124E8(a);
    func_02082D44(b, p, 0x98);
    if (v != 0) {
        p->f9C = c[b->f42];
        func_0201F02C(b->f10, 0, b->f78);
    } else {
        func_02034714(d_02183B4C, 0, d_02183B4C);
    }
}
