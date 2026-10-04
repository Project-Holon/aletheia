/*
 * function: func_02012C18
 * address:  0x02012C18
 * packet:   pkt_02012C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 204 bytes, 0x02012C18..0x02012CDC (the listing extent 204 includes the
 * 0x5EC pool word at 0x02012CDC).  Sibling of func_02012CE0, same shape plus
 * an opening guard `if (func_020071E4(*(u32 *)p) == 1) return;`.
 *
 * docs/notes/pkt_02012C18.c.txt recorded this as an unmovable register
 * rotation (r4/r6/r7) -- it was not.  The rotation was downstream of ONE
 * wrong argument order: the original is
 *     func_020097F0(func_02009D08(*(u32 *)p), v);
 * i.e. the inner call's result is argument 1 and the 0x0201283C result is
 * argument 2, the OPPOSITE of the sibling's func_020097F0(v, func_02009D08())
 * at 0x02012D6E.  With the arguments the sibling's way, mwcc needs an extra
 * `adds r0, r7, #0` at the call, which shifts everything after it by two
 * bytes, forces the trailing `c046` pool-alignment nop, and reallocates the
 * three callee-saved registers -- which is what the note saw and read as the
 * whole residue.  Swapping them alone takes the file from that DIFF to EXACT
 * with no other change.  (docs/idioms/cmp-operand-order-names-the-temporary.md
 * generalised: the call-result operand order names which value gets the
 * named-local treatment.)
 *
 * symbols:
 *   func_020071E4  0x020071E4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02008808  0x02008808  thumb
 *   func_020088B8  0x020088B8  thumb
 *   func_02012964  0x02012964  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200EEAC  0x0200EEAC  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_0200BE6C  0x0200BE6C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_0200A864  0x0200A864  thumb
 *   func_0200A884  0x0200A884  thumb
 *   func_0200B3C8  0x0200B3C8  thumb
 *   func_0200893C  0x0200893C  thumb
 *   func_02008954  0x02008954  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D08  0x02009D08  thumb
 *   func_020097F0  0x020097F0  thumb
 *   func_02008964  0x02008964  thumb
 *   func_0200E89C  0x0200E89C  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200863C  0x0200863C  thumb
 */
#include "../include/Obj00054.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PlayTime;
struct Rec2Head;
struct Rec94;
struct SaveBlock;
struct Sub020071E4Ctrl;
struct Sub020087E8Arg;
struct Sub02008828Obj;
struct Sub02008860Buf;
struct Sub020097BCObj;
extern u8 func_020071E4(const struct Sub020071E4Ctrl *ctrl);
extern void *func_020127A4(struct SaveBlock *p);
extern void func_02008808(void *sys, struct Sub020087E8Arg *dest);
extern void func_020088B8(void *sys, struct Sub02008860Buf *dest);
extern u32  func_02012964(void *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *h, u32 id);
extern void func_0200EEAC(void *ctx, void *list);
extern u32  func_020127B8(void *p);
extern void func_0200BE6C(void *sys, u16 *dest);
extern u32  func_020127C4(void *p);
extern void *func_0200A864(void *sys);
extern void func_0200A884(const struct Rec2Head *src, struct Rec2Head *dest);
extern void func_0200B3C8(void *sys, const struct Rec94 *src);
extern void func_0200893C(const struct Sub02008828Obj *obj, void *dest);
extern void func_02008954(const struct Sub02008828Obj *obj, u8 *out);
extern u32  func_0201283C(void *p);
extern struct Sub020097BCObj *func_02009D08(void *sys);
extern void func_020097F0(const struct Sub020097BCObj *src, struct Sub020097BCObj *dest);
extern void func_02008964(const struct Sub02008828Obj *obj, u8 *out);
extern void func_0200E89C(void *sys, void *dest);
extern struct PlayTime *func_02008748(void *sys);
extern void func_0200863C(struct PlayTime *dest, const struct PlayTime *src);

void func_02012C18(u8 *p)
{
    u32 v;
    u32 h;

    if (func_020071E4((const struct Sub020071E4Ctrl *)(*(u32 *)&((struct Obj00054 *)p)->f0)) == 1) {
        return;
    }

    v = (u32)func_020127A4((struct SaveBlock *)p);
    func_02008808((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (struct Sub020087E8Arg *)v);
    func_020088B8((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (struct Sub02008860Buf *)v);

    v = func_02012964(p);
    func_0200EEAC((void *)v, (void *)((u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x29)));

    func_0200BE6C((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (u16 *)func_020127B8(p));

    v = func_020127C4(p);
    func_0200A884(func_0200A864((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), (struct Rec2Head *)v);

    func_0200B3C8((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const struct Rec94 *)(p + 0x5EC));

    h = ((struct Obj00054 *)p)->f15C;
    func_0200893C((const struct Sub02008828Obj *)h, (void *)(*(u32 *)&((struct Obj00054 *)p)->f1B8));
    func_02008954((const struct Sub02008828Obj *)h, p + 0x1C4);

    v = func_0201283C(p);
    func_020097F0(func_02009D08((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), (struct Sub020097BCObj *)v);

    func_02008964((const struct Sub02008828Obj *)(((struct Obj00054 *)p)->f15C), p + 0x1C5);

    func_0200E89C((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), p + 0x694);

    v = (u32)func_02008748((void *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    func_0200863C((struct PlayTime *)(((struct Obj00054 *)p)->f6AC), (const struct PlayTime *)v);
}
