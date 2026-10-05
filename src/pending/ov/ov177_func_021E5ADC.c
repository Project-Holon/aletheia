/*
 * function: func_021E5ADC
 * address: 0x021E5ADC
 * packet: pkt_ov177_021E5ADC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wP6 U10): DIFF 25 B, 322 B compiled vs 324 B listing, all residue is callee-saved colour (original: str r4, p r5, buf r6, x r7, &heap temp r6; ours: &heap r4, str r6, buf r7, x r4). Frame, stack slots and every instruction otherwise match. Callees: three message blocks (EC0 2, EC0 0 without word set, EC0 1), x = (u16)(f(*p) << 3) kept int, w u16 per width, third draw uses x - w (w spilled at sp+0x10). heap is re-read by ldrh from its stack slot: needs heap (plain u16 param copies it once, 302 B off). Tried without gain: each of six per-function pragmas, x declared first, x u32, w u32 with cast, separate e locals, `x -= w` in third block (94 B), one-field struct heap (299 B), pointer local to heap (299 B).
 * recoup 2026-10-05 (R19): still DIFF 25 B. Heap now a plain u16 parameter with u16 heap parameters on func_02045B38 (4th), func_0201EC64 and func_020457B0 (2nd): same bytes as the *(u16 *)&heap form, so the cast is gone (real source). Also tried, all 25 B: buf declared first, x declared first, e before buf, inline (u16) widths in blocks 1 and 2, extra scratch local, str as void * with pointer D304/C6FC prototypes, u32 handle locals and prototypes (ov222 021B9964 twin shape), p as a struct with field 4, six per-function pragmas on the new form; u8 c1/c2 gives 285 B. Residue is unchanged: original colours str r4, p r5, heap-arg-base temp and buf share r6, x r7; ours gives temp r4 (shared with x), str r6, buf r7.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045738 0x02045738 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
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
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u16 heapId);
extern struct WordSet *func_0201EC64(u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u16 heapId);
extern u32 func_02045738(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(void *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);

void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap)
{
    struct MsgBank *msg;
    struct WordSet *ws;
    struct U16Vec *buf;
    void *e;
    int x;
    u16 w;

    msg = func_02045B38(0, 2, 0xa3, heap);
    ws = func_0201EC64(heap);
    buf = func_020457B0(0x20, heap);
    x = (u16)(func_02045738((void *)p[0]) << 3);

    e = func_02045EC0(msg, 2);
    func_0201EFA4(ws, 0, c1, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304(buf, str, 0);
    x -= w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x, 0, buf, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);

    e = func_02045EC0(msg, 0);
    w = func_0201D304(e, str, 0);
    x -= w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x, 0, e, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);

    e = func_02045EC0(msg, 1);
    func_0201EFA4(ws, 0, c2, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304(buf, str, 0);
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)(x - w), 0, buf, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);
    func_02045808(buf);
    func_0201ED04(ws);
    func_02045C04((struct Rec *)msg);
}
