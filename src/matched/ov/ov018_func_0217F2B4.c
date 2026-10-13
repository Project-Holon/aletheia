/*
 * function: EVENT_COMM_COMMON_InitMsgBox
 * address:  0x0217F2B4
 * packet:   pkt_ov018_0217F2B4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   func_0201EC74  0x0201EC74  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    u8 f28;
} Ov018Obj;

typedef unsigned int   u32;
struct Ctx;
struct U16Vec;
struct WordSet;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
typedef unsigned short u16;
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);

void EVENT_COMM_COMMON_InitMsgBox(Ov018Obj *p, void *a)
{
    void *r;

    r = (void *)FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap(a));
    if (p->f00 == 0) {
        p->f00 = func_0201EC74(6, 0x20, 4);
        p->f04 = STRBUF_Create(0x1F0, 4);
        p->f08 = STRBUF_Create(0x1D0, 4);
        p->f0C = (void *)FIELD_MSGBG_CreateMsgData((u32)r, 0x44);
        p->f10 = (void *)FIELD_MSGBG_CreateMsgData((u32)r, 0x42);
        p->f14 = (void *)FIELD_MSGBG_CreateMsgData((u32)r, 0x43);
        p->f24 = r;
        p->f28 = 0;
    }
}
