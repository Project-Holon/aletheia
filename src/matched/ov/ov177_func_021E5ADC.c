/*
 * function: func_021E5ADC
 * address: 0x021E5ADC
 * packet: pkt_ov177_021E5ADC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (final push G6L3): EXACT*. The three running x values are separate locals (x, x1 = x - w, x2 = x1 - w, third draw x2 - w), not one x updated in place; the separate values give each its own live range and the original colours (str r4, p r5, heap-base temp and buf r6, x r7). Earlier notes (all pragmas, declaration orders, inline helpers, u8/u16 widths) did not move the colours.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045738 0x02045738 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
struct U16Vec;
struct Descriptor;
struct PrintSys;
struct Rec;
struct StrObj;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u16 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u16 heapId);
extern u8 func_02045738(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);

void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap)
{
    struct MsgBank *msg;
    struct WordSet *ws;
    struct U16Vec *buf;
    void *e;
    int x, x1, x2;
    u16 w;

    msg = func_02045B38(0, 2, 0xa3, heap);
    ws = func_0201EC64(heap);
    buf = STRBUF_Create(0x20, heap);
    x = (u16)(func_02045738((void *)p[0]) << 3);

    e = func_02045EC0(msg, 2);
    func_0201EFA4(ws, 0, c1, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304((struct StrObj *)buf, str, 0);
    x1 = x - w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x1, 0, buf, str);
    ((u8 *)p)[4] = 1;
    STRBUF_Delete((struct U16Vec *)e);

    e = func_02045EC0(msg, 0);
    w = func_0201D304(e, str, 0);
    x2 = x1 - w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x2, 0, e, str);
    ((u8 *)p)[4] = 1;
    STRBUF_Delete((struct U16Vec *)e);

    e = func_02045EC0(msg, 1);
    func_0201EFA4(ws, 0, c2, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304((struct StrObj *)buf, str, 0);
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)(x2 - w), 0, buf, str);
    ((u8 *)p)[4] = 1;
    STRBUF_Delete((struct U16Vec *)e);
    STRBUF_Delete(buf);
    func_0201ED04(ws);
    MSGDATA_Delete((struct Rec *)msg);
}
