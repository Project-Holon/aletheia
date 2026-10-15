/*
 * function: TOUCHBAR_PrintYesNoCancelLabels
 * address:  0x021B6B2C
 * packet:   pkt_ov067_021B6B2C
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the heap id and a4/a5 are reloaded from their stack slots before
 *           every call because the callees take them as u16 (with u32 callee
 *           parameters they stay in registers: 300 bytes); `a3 = a3 - f()`
 *           (`-=` truncates the call result first).
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   TOUCHBAR_PrintAligned  0x021B6AE4  thumb  ov067
 *   TOUCHBAR_GetStringAlignOffset  0x021B6C4C  thumb  ov067
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *GF_FONT_Create_EC64(u16 heap);
extern void *STRBUF_Create(u32 size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u16 TOUCHBAR_GetStringAlignOffset(struct StrObj *s, u32 a, u32 mode);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);

void TOUCHBAR_PrintYesNoCancelLabels(u32 a0, void *a1, u32 a2, u16 a3, u16 a4, u16 a5, u32 a6, u32 a7, u16 heap)
{
    void *m;
    void *w;
    void *buf;
    void *s;
    u16 t;

    m = func_02045B38(0, 2, 0xa3, heap);
    w = GF_FONT_Create_EC64(heap);
    buf = STRBUF_Create(0xa, heap);
    s = func_02045EC0(m, 0);
    t = func_0201D304(s, a2, 0);
    TOUCHBAR_PrintAligned((u8 *)a0, a1, a3, a4, (u32)s, a2, a5, 2);
    a3 = a3 - TOUCHBAR_GetStringAlignOffset(s, a2, 2);
    STRBUF_Delete(s);
    s = func_02045EC0(m, 1);
    func_0201EFA4(w, 0, a6, 8, 0, 1);
    func_0201F250(w, buf, s);
    TOUCHBAR_PrintAligned((u8 *)a0, a1, a3, a4, (u32)buf, a2, a5, 1);
    STRBUF_Delete(s);
    s = func_02045EC0(m, 2);
    func_0201EFA4(w, 0, a7, 8, 0, 1);
    func_0201F250(w, buf, s);
    TOUCHBAR_PrintAligned((u8 *)a0, a1, a3 + t, a4, (u32)buf, a2, a5, 0);
    STRBUF_Delete(s);
    STRBUF_Delete(buf);
    WORDSET_DeleteStrbufED04(w);
    MSGDATA_Delete(m);
}
