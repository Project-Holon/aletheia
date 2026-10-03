/*
 * function: func_0207533C
 * address:  0x0207533C
 * packet:   pkt_02074A34
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0207482C  0x0207482C  arm
 *   func_020745A4  0x020745A4  arm
 *   func_0208A638  0x0208A638  arm
 *   func_0208A640  0x0208A640  arm
 *   func_0208A674  0x0208A674  arm
 *   func_020752F4  0x020752F4  arm
 *   DC_StoreRange  0x020862D4  arm
 *
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

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 pad00[2];
    u32 f08;
    u32 pad0c[(0x38 - 0x0c) / 4];
    u32 f38;
    u32 f3c[1];
} Bank;

extern u32   func_0208A674(Bank *o, u32 i);
extern u32   func_0208A638(Bank *o);
extern void  func_0208A640(Bank *o, u32 i, void *p);
extern void *func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void  DC_StoreRange(void *addr, u32 size);
extern void func_020752F4(u32 a, u32 n, u32 x, u32 y);

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
  n = func_0208A638(o);
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
  p = func_0207482C(heap, len + 0x20, (u32) func_020752F4, (u32) o, i);
  if (p == 0)
    return 0;
  if (func_020745A4(h, p, len, off) != len)
    return 0;
  DC_StoreRange(p, len);
  func_0208A640(o, i, p);
  return 1;
}


