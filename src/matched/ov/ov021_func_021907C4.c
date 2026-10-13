/*
 * function: FIELD_MSGBG_CreateInfoMsgWin
 * address:  0x021907C4
 * packet:   pkt_ov021_021907C4
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
 *   FIELD_MSGBG_CreateSysFrameWindow  0x02192B20  thumb  ov021
 *   FIELD_MSGBG_SetupSysFrame  0x02192F74  thumb  ov021
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
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
extern u32 FIELD_MSGBG_CreateSysFrameWindow(u8 a, u8 b, u8 c, u8 d, u32 e);
struct Slot;
extern struct Slot *FIELD_MSGBG_AddMsgPrint(u32 *p, u32 a, u32 b);
extern void FIELD_MSGBG_SetBlend(u32 v);

Obj *FIELD_MSGBG_CreateInfoMsgWin(Fx *a, u32 b, u32 c, u32 d, u16 e, u16 f)
{
    Obj *r;

    a->f06 = 0xe;
    FIELD_MSGBG_SetupSysFrame((struct W *)a);
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x560);
    r->owner = a;
    r->id = FIELD_MSGBG_CreateSysFrameWindow(c, d, e, f, a->f00);
    r->slot = (u32)FIELD_MSGBG_AddMsgPrint((u32 *)a, b, r->id);
    FIELD_MSGBG_SetBlend(1);
    return r;
}
