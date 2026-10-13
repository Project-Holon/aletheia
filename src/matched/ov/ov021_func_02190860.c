/*
 * function: FIELD_MSGBG_CreateMenuFuncPalette
 * address:  0x02190860
 * packet:   pkt_ov021_02190860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x14-byte handle, builds a 0x34-byte template (FIELD_MSGBG_MakeListHeader
 * plus the caller's words) and creates the object with BMP_MENULIST_Create.
 * `const` on b is what interleaves its field loads with the r->c store.
 *
 * symbols:
 *   FIELD_MSGBG_SetupSysFrame  0x02192F74  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   FIELD_MSGBG_MakeListHeader  0x02190B2C  thumb  ov021
 *   FIELD_MSGBG_CreateWindow  0x021930C0  thumb  ov021
 *   FIELD_MSGBG_AddMsgPrint  0x021904EC  thumb  ov021
 *   FIELD_MSGBG_GetMsgPrintUtil  0x0219067C  thumb  ov021
 *   FIELD_MSGBG_GetMsgPrintQue  0x02190678  thumb  ov021
 *   BMP_MENULIST_Create  0x0201FF30  thumb
 *   BMP_MENULIST_ResetCursorTile  0x02020CF8  thumb
 *   FIELD_MSGBG_LoadMenuGraphicsLower  0x02193144  thumb  ov021
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
 *   FIELD_MSGBG_LoadMenuGraphicsUpper  0x02193170  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00126.h"
#include "../include/Obj07430.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u8  pad10[0xc];
    u32 w1c;
    u8  pad20[4];
    u32 w24;
    u32 w28;
    u32 w2c;
    u32 w30;
} Tmpl;

typedef struct {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

extern char d_021DDA50[];

struct Dst;
struct Obj;
struct Src;
struct W;
extern void FIELD_MSGBG_SetupSysFrame(struct W *w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_MSGBG_MakeListHeader(struct Dst *d, const struct Src *s);
extern int FIELD_MSGBG_CreateWindow(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
struct Obj;
struct Slot;
extern struct Slot *FIELD_MSGBG_AddMsgPrint(u32 *p, u32 a, u32 b);
extern u8 *FIELD_MSGBG_GetMsgPrintUtil(u8 *p);
extern u32 FIELD_MSGBG_GetMsgPrintQue(u8 *p);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern void BMP_MENULIST_ResetCursorTile(struct Obj *p, int heap);
extern void FIELD_MSGBG_LoadMenuGraphicsLower(u32 heap);
extern void FIELD_MSGBG_SetBlend(u32 v);
extern void FIELD_MSGBG_LoadMenuGraphicsUpper(u32 heap);

Handle *FIELD_MSGBG_CreateMenuFuncPalette(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i)
{
    Tmpl t;
    u8 k;
    Handle *r;

    k = a[1];
    FIELD_MSGBG_SetupSysFrame((struct W *)a);
    if (f == 0xe) {
        k = a[2];
    }
    r = func_02030734(a[0], 0x14, 1, d_021DDA50, 0x606);
    FIELD_MSGBG_MakeListHeader((struct Dst *)(&t), (const struct Src *)b);
    r->owner = a;
    r->c = c;
    r->id = FIELD_MSGBG_CreateWindow(k, a[0], *(const u16 *)&((struct Obj07430 *)b)->f14, *(const u16 *)&((struct Obj07430 *)b)->f16,
                          *(const u16 *)&((struct Obj07430 *)b)->f18, *(const u16 *)&((struct Obj07430 *)b)->f1A, f);
    r->slot = (u32)FIELD_MSGBG_AddMsgPrint((u32 *)a, 0, r->id);
    t.w24 = 0;
    t.w28 = (u32)FIELD_MSGBG_GetMsgPrintUtil((u8 *)r->slot);
    t.w2c = FIELD_MSGBG_GetMsgPrintQue((u8 *)r->slot);
    t.w30 = ((struct Obj00126 *)a)->f8;
    t.w0c = r->id;
    t.w00 = c;
    t.w08 = h;
    t.w04 = g;
    t.w1c = i;
    r->obj = (u32)BMP_MENULIST_Create((struct Src *)(&t), d, e, a[0]);
    BMP_MENULIST_ResetCursorTile((struct Obj *)r->obj, a[0]);
    if (f == 0xe) {
        FIELD_MSGBG_LoadMenuGraphicsLower(a[0]);
        FIELD_MSGBG_SetBlend(1);
    } else {
        FIELD_MSGBG_LoadMenuGraphicsUpper(a[0]);
    }
    return r;
}
