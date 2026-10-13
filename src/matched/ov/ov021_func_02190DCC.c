/*
 * function: FIELD_MSGBG_CreateSysWin
 * address:  0x02190DCC
 * packet:   pkt_ov021_02190DCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   FIELD_MSGBG_InitCursor  0x021927C0  thumb  ov021
 *   FIELD_MSGBG_SetupSysFrame  0x02192F74  thumb  ov021
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
 *   FIELD_MSGBG_CreateWindow  0x021930C0  thumb  ov021
 *   FIELD_MSGBG_LoadMenuGraphicsLower  0x02193144  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct Obj2 {
    u32 id;
    u32 f04;
    u32 f08;
    u32 b;
    u32 f10;
    Fx *owner;
    u32 sub[2];
} Obj2;

extern char d_021DDA50[];

struct G;
struct W;
extern void FIELD_MSGBG_SetupSysFrame(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void FIELD_MSGBG_InitCursor(struct G *g, struct Fx *a);
extern void FIELD_MSGBG_LoadMenuGraphicsLower(u32 heap);
extern void FIELD_MSGBG_SetBlend(u32 v);
extern int FIELD_MSGBG_CreateWindow(int a, int unused, int b, int c, u16 d, u16 e, u16 f);

Obj2 *FIELD_MSGBG_CreateSysWin(Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f)
{
    Obj2 *r;

    a->f06 = 0xe;
    FIELD_MSGBG_SetupSysFrame((struct W *)a);
    r = func_02030734(a->f00, 0x20, 1, d_021DDA50, 0x8FF);
    r->owner = a;
    r->b = b;
    r->id = FIELD_MSGBG_CreateWindow(a->f04, a->f00, c, d, e, f, a->f06);
    r->f10 = (u32)STRBUF_Create(0xA0, a->f00);
    FIELD_MSGBG_InitCursor((struct G *)r->sub, a);
    FIELD_MSGBG_LoadMenuGraphicsLower(a->f00);
    FIELD_MSGBG_SetBlend(1);
    return r;
}
