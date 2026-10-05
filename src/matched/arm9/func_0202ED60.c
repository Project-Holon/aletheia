/*
 * function: func_0202ED60
 * address:  0x0202ED60
 * packet:   pkt_0202ECB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200974C   0x0200974C  thumb
 *   func_02009750   0x02009750  thumb
 *   func_020095E8   0x020095E8  thumb
 *   func_0200856C   0x0200856C  thumb
 *
 * The three-call pair at the end is the useful part: the key is read out of
 * `b` once into a named local and handed to func_02009750; that call's
 * answer decides whether func_020095E8 runs.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ED60.c \
 *       --func func_0202ED60 --addr 0x0202ED60 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_0200974C(u32 a);
struct Sub02009470Obj;
extern u32 func_02009750(struct Sub02009470Obj *obj, u32 n);
extern void func_020095E8(struct Sub02009470Obj *obj);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
struct Slot;
extern void func_0202ED90(u8 *a, struct Slot *b, u32 c);

void func_0202ED60(u32 a, void *b, u32 c)
{
    u32 t = func_0200974C(a);
    u32 v;

    func_0202ED90((u8 *)t, b, c);

    v = func_0200856C(b);
    if (func_02009750((struct Sub02009470Obj *)a, v) != 0)
        func_020095E8((struct Sub02009470Obj *)a);
}
