/*
 * function: func_021A6E30
 * address:  0x021A6E30
 * packet:   pkt_ov021_021A6E30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the 12-byte model holder for a field-map object, loads its
 * model, and places it through func_021A7258 in the mode the object's
 * record asks for (0: at pos; else attached to the record's anchor).
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012AC0  0x02012AC0  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219F058  0x0219F058  thumb  ov021
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_021A3664  0x021A3664  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021A7258  0x021A7258  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   d_021DDF64     0x021DDF64  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct Holder {
    int mode;
    void *f04;
    void *f08;
} Holder;

extern char d_021DDF64;

extern void *func_02188C80(void *o);
struct Ctx;
struct Rec44;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02188CAC(u8 *p, u32 v);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern u8 func_02012AC0(const struct Rec44 *p);
extern void *func_021A3074(u8 *p);
extern void func_0219F058(u32 a, u16 *o1, u16 *o2);
extern void func_021A35E0(u32 *p, u32 heap);
extern void func_021A3664(u32 *p, u32 heap);
extern void func_021A305C(char *p, u32 b);
struct H4;
extern struct H4 *func_02012AB8(struct Rec44 *p);
extern void func_021A7258(void *o, Holder *h, int mode, VecFx32 *pos, u16 e, u16 f, u16 g);
extern void *func_0216D888(void *m);
extern void func_02188D40(u8 *p, u32 v);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);

void func_021A6E30(void *o, VecFx32 *pos, u16 e)
{
    void *r;
    u16 heap;
    Holder *h;
    int mode;
    void *m;
    VecFx32 *anchor;
    u16 anim[2];

    r = func_020127A4(func_020120F4(func_02188C80(o)));
    heap = func_02188C84(o);
    h = func_02030734(heap, sizeof(Holder), 1, &d_021DDF64, 0xbd);
    func_02188CAC(o, (u32)h);
    h->f04 = func_02188CB4(o);
    mode = func_02012AC0(r);
    h->mode = 2;
    m = func_021A3074(h->f04);
    func_0219F058((u32)m, &anim[0], &anim[1]);
    if (mode == 0) {
        func_021A35E0(h->f04, heap);
        func_021A3664(h->f04, heap);
        func_021A305C(h->f04, e);
        func_021A7258(o, h, mode, pos, e, anim[0], anim[1]);
    } else {
        anchor = (VecFx32 *)func_02012AB8(r);
        func_021A3664(h->f04, heap);
        func_021A35E0(h->f04, heap);
        func_021A305C(h->f04, e);
        func_021A7258(o, h, mode, anchor, e, anim[0], anim[1]);
    }
    func_02188D40(o, (u32)func_0216D888(m));
    func_021A3038(h->f04, pos);
}
