/*
 * file:     unit_020746C4_p13.c
 * unit:     yes
 * function: func_0207533C, func_02075404, func_020754C4
 * address:  0x0207533C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207482C  0x0207482C  arm
 *   func_020745A4  0x020745A4  arm
 *   func_0208A638  0x0208A638  arm
 *   func_0208A640  0x0208A640  arm
 *   func_0208A674  0x0208A674  arm
 *   func_020752F4  0x020752F4  arm
 *   DC_StoreRange  0x020862D4  arm
 *   func_0208A46C  0x0208A46C  arm
 *   func_0208A48C  0x0208A48C  arm
 *   func_020742FC  0x020742FC  arm
 *   func_020744B4  0x020744B4  arm
 *   func_02072DB0  0x02072DB0  arm
 *   func_02072DD0  0x02072DD0  arm
 *   func_02072DE8  0x02072DE8  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 pad00[2];
    u32 f08;
    u32 pad0c[(0x38 - 0x0c) / 4];
    u32 f38;
    u32 f3c[1];
} Bank;

extern u32   func_0208A674(Bank *o, u32 i);
extern void *func_0208A638(char *p);
extern void  func_0208A640(Bank *o, u32 i, void *p);
extern u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void  DC_StoreRange(void *addr, u32 size);
extern void func_020752F4(u32 a, u32 n, u32 x, u32 y);

/*
 * Bank-entry loader.  Skip the work if the entry is already resident
 * (func_0208A674), otherwise take the entry's byte range from the object's
 * offset table and stream it in: allocate range+0x20 through func_0207482C
 * with func_020752F4 as the teardown callback, read it with func_020745A4,
 * flush it with DC_StoreRange and publish it with func_0208A640.  Returns 1
 * for "resident on exit" (already-resident and success both), 0 for failure.
 *
 * THE OFFSET TABLE.  `ldr r1,[r8,#0x38]` / `add r1,r1,r7` /
 * `add r1,r8,r1,lsl #2` / `ldr r4,[r1,#0x3c]` / `ldrlo r0,[r1,#0x40]` at
 * 0x02075368..0x02075380 fixes it: a u32 array based at +0x3c of the object,
 * indexed by the object's own base index at +0x38 plus the caller's entry
 * index.  The entry's end is the NEXT slot, except for the last entry
 * (`cmp r7, r0` against count-1) where it is the object's total size at +0x08;
 * the `ldrlo`/`ldrhs` pair is the unsigned compare, so both index and count
 * are u32.
 *
 * THE DEAD POINTER IS LOAD-BEARING.  `e` is assigned the table-entry address
 * and then never read: both reads are spelled as fresh
 * `(&o->f3c[o->f38 + i])[0]` / `[1]` expressions.  Dropping the assignment, or
 * reading through `e` instead of recomputing, both move the whole frame down
 * one callee-saved register (r8/r7/r6/r5 becomes r7/r6/r5/r4) and add an
 * instruction: 204 bytes against the original's 200, 134-143 concrete bytes
 * out.  The assignment is an extra definition point for the address value,
 * which is what makes the allocator number it before the four parameters --
 * the mechanism docs/notes/permuter.md describes for the `temp` mutation.
 * Likewise `n = func_0208A638(o); n = n - 1;` must be TWO statements; folded
 * into one the subtract is scheduled after the compare.  Both levers were
 * found by tools/permuter.py (`--mode hill --budget 800 --jobs 8 --types`,
 * closing at compile 573 with `split-assign(n) ; temp(tmp=e[0]) ; expand(e x2)`
 * from a body that was already size-exact) and then re-verified by hand: every
 * hand-tidied spelling that removes either one goes back to DIFF.
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, "kept constants").
 * The image materialises the four failure exits' zero fresh at each
 * (`moveq r0,#0` at 0x02075390, 0x020753B4, `movne r0,#0` at 0x020753D4).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0207533C.c \
 *       --func func_0207533C --addr 0x0207533C --arm --cc ../2.0/sp2
 */
u32 func_0207533C(Bank *o, u32 i, u32 h, u32 *heap)
{
  u32 n;
  u32 off;
  u32 end;
  u32 len;
  u32 *e;
  void *p;
  u32 tmp;
  if (func_0208A674(o, i) != 0)
    return 1;
  n = (u32)func_0208A638((char *)o);
  n = n - 1;
  e = &o->f3c[o->f38 + i];
  tmp = (&o->f3c[o->f38 + i])[0];
  if (i < n)
    end = (&o->f3c[o->f38 + i])[1];
  else
    end = o->f08;
  off = tmp;
  len = end - off;
  if (heap == 0)
    return 0;
  p = (void *)func_0207482C(heap, len + 0x20, (u32) func_020752F4, (u32) o, i);
  if (p == 0)
    return 0;
  if (func_020745A4(h, p, len, off) != len)
    return 0;
  DC_StoreRange(p, len);
  func_0208A640(o, i, p);
  return 1;
}

struct Global;

typedef struct { u32 a; u32 b; } Iter;
typedef struct { u8 kind; u8 p1; u16 h2; u16 h4; u16 h6; u32 w8; } Rec;

extern void func_0208A46C(Iter *it, u32 a, u32 b, u32 c);
extern u32  func_0208A48C(u32 seq, Rec *r, Iter *it);

/*
 * "Load every bank this sequence needs for one group": open an iterator over
 * the sequence (func_0208A46C), copy it to a working cursor, then step it
 * (func_0208A48C) and, for every record of kind 1 whose group id matches the
 * caller's, pull the bank in with func_0207533C.  Any failed load answers 0;
 * a run to exhaustion answers 1.  The null-sequence guard answers 0 and is
 * emitted AFTER the iterator open, which is why it shares the mid-function
 * epilogue rather than the entry.
 *
 * THE FRAME IS THE EVIDENCE FOR BOTH STRUCT SIZES, and it took two levers:
 *
 *  - DECLARATION ORDER IS STACK ORDER, reversed
 *    (docs/idioms/local-declaration-order-is-stack-order.md).  The image puts
 *    the freshly-opened iterator at sp+0, the working cursor at sp+8 and the
 *    record at sp+0x10; declaring them in that order lays them out backwards
 *    (record at sp+0) and costs 17 bytes.  Declared `Rec r; Iter it; Iter it0;`
 *    the offsets line up.
 *
 *  - THE RECORD IS 12 BYTES, NOT 8.  With an 8-byte Rec every offset is right
 *    but the frame is `push {r4..sl, lr}` / `sub sp, #0x18`; the image is
 *    `push {r3, r4..sl, lr}` / `sub sp, #0x1c`, i.e. eight bytes more of
 *    locals.  Only the first four bytes of the tail are ever read
 *    (`ldrb [sp,#0x10]`, `ldrh [sp,#0x12]`, `ldrheq [sp,#0x14]`), so the
 *    +6..+11 members are sized by the frame alone and their split is not
 *    constrained: `u16 h6; u32 w8;`, `u16 h6; u16 h8;` and a bare `u32 w8;`
 *    all give the same 192 bytes, 0 mismatches.  Recorded as the three-member
 *    form; a later caller of func_0208A48C can settle the split.
 *
 * PIN ../2.0/sp2, the cluster pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075404.c \
 *       --func func_02075404 --addr 0x02075404 --arm --cc ../2.0/sp2
 */
u32 func_02075404(u32 o, u32 seq, u32 want, u32 h, u32 *heap)
{
    Rec r;
    Iter it;
    Iter it0;

    func_0208A46C(&it0, seq, want, h);
    it = it0;
    if (seq == 0) return 0;
    if (func_0208A48C(seq, &r, &it) != 0) {
        do {
            if (r.kind == 1 && want == r.h4) {
                if (func_0207533C((Bank *)o, r.h2, h, heap) == 0) return 0;
            }
        } while (func_0208A48C(seq, &r, &it) != 0);
    }
    return 1;
}

typedef struct {
    u8  count;
    u8  pad01;
    u16 h2;
    void *data;
} Ent;

extern struct Global *func_020742FC(void);
extern void *func_020744B4(int index);
extern void  func_02072DB0(int idx, int v);
extern void func_02072DD0(u32 idx, u32 val);
extern u32   func_02072DE8(int idx, u32 a, void *src);
u32 func_020754C4(u32 a);


/*
 * Walk the 32 slots of the current archive (func_020742FC is called for its
 * side effect only): for every slot record func_020744B4 hands back, apply
 * its count byte and +2 halfword (func_02072DB0 / func_02072DD0), and when
 * both the record's +4 payload and the argument are non-null, register the
 * payload count times with func_02072DE8, failing out on the first refusal.
 *
 * Levers (permuter hill found the first, the second is a prototype read):
 *   - declaration order i, e, j (register r6 / r7 / r8);
 *   - the slot index is `int` in the CALLEE PROTOTYPES as well as the loop
 *     (func_02072DE8's first parameter above all).  With the callee declared
 *     u32 the implicit conversion reshuffles r4-r7 (14 bytes out); the loop
 *     compare is `blt`, so the index itself is signed.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020754C4.c \
 *       --func func_020754C4 --addr 0x020754C4 --arm --cc ../2.0/sp2
 *   EXACT, 156 bytes, 5 of 5 relocation sites resolved (sp2p2 the same,
 *   dsi/1.1p1 152 bytes DIFF).
 */
u32 func_020754C4(u32 a)
{
    int i;
    Ent *e;
    int j;

    func_020742FC();
    for (i = 0; i < 32; i++) {
        e = func_020744B4(i);
        if (e == 0)
            continue;
        func_02072DB0(i, e->count);
        func_02072DD0(i, e->h2);
        if (e->data != 0 && a != 0) {
            for (j = 0; j < e->count; j++) {
                if (func_02072DE8(i, a, e->data) == 0)
                    return 0;
            }
        }
    }
    return 1;
}
