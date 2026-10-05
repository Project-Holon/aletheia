/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov099_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): lane17 wave D2: 208 bytes, 18 differing bytes, all one register swap: original heap (r1) in r4 and the 0x588 pool offset in r6; ours heap r6, offset r4. Callee func_021B9DC0 (20 bytes) is an unlabelled ov099 function with no matched file; the MATCH step needs it filed. Shape matched: WH t, s declared in that order, s.w = raw; s.h = raw >> 16; t = s; a4 is u32 (lsrs). Tried int heap, enum offset local (worse), n declaration order.
 *
 * note: 2026-10-05 (wD4 lane20): constant-in-a-local lever applied: int off = 0x588; p+off, p+off+4, p+off+0xC, p+off+0x14. Instruction forms now match the image (adds r1,r6,#4 style and the in-place add of 0x14) and the byte count is unchanged; only the heap/off colour swap remains (heap r6, off r4; image heap r4, off r6). Tried off declared first, assigned late, u32 off: no change.
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B9DC0  0x021B9DC0  thumb  ov099
 *   func_021B9E04  0x021B9E04  thumb  ov099
 *   func_021BA810  0x021BA810  thumb  ov099
 *   func_021BA81C  0x021BA81C  thumb  ov099
 *   func_021C47A0  0x021C47A0  thumb  ov127
 *   func_021C4800  0x021C4800  thumb  ov127
 *   func_021C4880  0x021C4880  thumb  ov127
 *   func_021B9D30  0x021B9D30  thumb  ov099
 *   func_021C59D0  0x021C59D0  thumb  ov127
 *   func_021B9D6C  0x021B9D6C  thumb  ov099
 *   func_021B9E0C  0x021B9E0C  thumb  ov099
 *   func_021BA60C  0x021BA60C  thumb  ov099
 *   func_021C5EEC  0x021C5EEC  thumb  ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 w, h; } WH;
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_021B9DC0(char *a, u32 heap, u32 x);
extern void func_021B9E04(void *a, u32 heap);
extern u32 func_021BA810(int i);
extern u32 func_021BA81C(int i);
extern void *func_021C47A0(u32 w, u32 h, u32 heap);
extern void func_021C4800(void *g, u32 out);
extern void *func_021C4880(u32 count, u32 heap);
extern void func_021B9D30(char *p, u32 q, u32 heap);
extern void func_021C59D0(void *p);
extern int func_021B9D6C(char *p, u32 heap, u32 x, u32 n);
extern u32 func_021B9E0C(void *a, u32 heap, u32 x, u32 c);
extern void func_021BA60C(char *a, char *p, u32 unused, u32 arc);
extern void *func_021C5EEC(int n, int heap);

void func_021B95A0(char *p, u32 heap, u32 x2, u32 x3, u32 a4, u32 a5, u32 a6, u32 a7)
{
    WH t, s;
    u32 raw;
    u32 n = 0;
    int off = 0x588;
    func_02082BCC(p, 0, 0x5A0);
    if (a4 != 0) n = (a4 - 1) >> 3;
    *(u32 *)(p + 0x14) = a6;
    *(u32 *)(p + 0x18) = a7;
    *(u32 *)(p + 4) = heap;
    func_021B9DC0(p + 0x14, heap, x2);
    func_021B9E04(*(void **)(p + 0x10), heap);
    raw = func_021BA810(n);
    s.w = raw;
    s.h = raw >> 16;
    t = s;
    *(void **)(p + off) = func_021C47A0(t.w, t.h, heap);
    func_021C4800(*(void **)(p + off), func_021BA81C(n));
    *(void **)(p + off + 4) = func_021C4880(0x30, heap);
    func_021B9D30(p, x3, heap);
    func_021C59D0(p + off + 0xC);
    func_021B9D6C(p, heap, x2, n);
    func_021B9E0C(*(void **)(p + 0x10), heap, x2, a5);
    func_021BA60C(p, p + 0x574, x2, a5);
    *(void **)(p + off + 0x14) = func_021C5EEC(0x80, heap);
    *(u32 *)p = 1;
}
