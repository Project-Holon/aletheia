/*
 * function: FIELD_MSGBG_CreateMsgWinPalette
 * address:  0x02190680
 * packet:   pkt_ov021_02190680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   FIELD_MSGBG_AddMsgPrint  0x021904EC  thumb  ov021
 *   FIELD_MSGBG_SetupSysFrame  0x02192F74  thumb  ov021
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
 *   FIELD_MSGBG_CreateWindow  0x021930C0  thumb  ov021
 *   FIELD_MSGBG_LoadMenuGraphicsLower  0x02193144  thumb  ov021
 *   FIELD_MSGBG_LoadMenuGraphicsUpper  0x02193170  thumb  ov021
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

typedef struct Obj {
    u32 id;
    u32 slot;
    Fx *owner;
} Obj;

extern char d_021DDA50[];

struct W;
extern void FIELD_MSGBG_SetupSysFrame(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int FIELD_MSGBG_CreateWindow(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
struct Slot;
extern struct Slot *FIELD_MSGBG_AddMsgPrint(u32 *p, u32 a, u32 b);
extern void FIELD_MSGBG_LoadMenuGraphicsLower(u32 heap);
extern void FIELD_MSGBG_SetBlend(u32 v);
extern void FIELD_MSGBG_LoadMenuGraphicsUpper(u32 heap);

Obj *FIELD_MSGBG_CreateMsgWinPalette(Fx *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g)
{
    u8 k;
    Obj *r;

    k = a->f02;
    FIELD_MSGBG_SetupSysFrame((struct W *)a);
    if (g == 0xe) {
        k = a->f04;
    }
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x483);
    r->owner = a;
    r->id = FIELD_MSGBG_CreateWindow(k, a->f00, c, d, e, f, g);
    r->slot = (u32)FIELD_MSGBG_AddMsgPrint((u32 *)a, b, r->id);
    if (g == 0xe) {
        FIELD_MSGBG_LoadMenuGraphicsLower(a->f00);
        FIELD_MSGBG_SetBlend(1);
    } else {
        FIELD_MSGBG_LoadMenuGraphicsUpper(a->f00);
    }
    return r;
}
