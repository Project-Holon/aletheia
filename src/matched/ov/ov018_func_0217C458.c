/*
 * function: INTRUDE_FIELD_CreateOfferInfoEvent
 * address:  0x0217C458
 * packet:   pkt_ov018_0217C458
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb  ov018
 *   INTRUDE_COMM_SetState  0x02174E14  thumb  ov011
 *   INTRUDE_FIELD_EventOfferInfo  0x0217C4D0  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Desc;

typedef struct {
    int w[13];
} B52;

typedef struct {
    u16 h0;
    u16 pad2;
    void *w4;
    u8 pad8[0x30];
    B52 b38;
    u8 pad6c[0x18];
    u8 b84;
    u8 pad85[3];
} Obj;

struct Obj;
extern u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *, int, int);
extern void EVENT_COMM_COMMON_InitMsgBox();
extern void INTRUDE_COMM_SetState(u8 *p, int a);
extern void INTRUDE_FIELD_EventOfferInfo();

struct Desc *INTRUDE_FIELD_CreateOfferInfoEvent(void *a0, void *a1, u8 *a2, int a3)
{
    B52 *src;
    Obj *o;
    struct Desc *x;

    src = (B52 *)INTRUDE_COMM_GetActiveSessionRequest(a2 + 0x1AC);
    func_020120F4(a0);
    x = func_020122C0(a0, 0, INTRUDE_FIELD_EventOfferInfo, 0x88);
    o = func_020124E8((struct Obj *)x);
    MI_CpuFill8(o, 0, 0x88);
    o->h0 = a3;
    o->w4 = a1;
    o->b38 = *src;
    o->b84 = 1;
    EVENT_COMM_COMMON_InitMsgBox((u8 *)o + 8, a0);
    INTRUDE_COMM_SetState(a2, 5);
    return x;
}
