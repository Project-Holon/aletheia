/*
 * function: func_02049B90
 * address:  0x02049B90
 * packet:   pkt_02049B90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02049C28  0x02049C28  arm
 *
 * One of two seven-argument entry points on the cell-actor system, an
 * address apart, that differ only in which half of func_02049C28's dispatch
 * they reach first (func_0204A380 in func_02049BDC, 0x0204A1BC here); both
 * then forward into 0x02049C28 itself.
 *
 * The seventh parameter is a u16: it is read off the caller's stack with
 * `ldrh` (a 32-bit parameter would be `ldr`), masked with the pooled 0x7FFF
 * and re-set to the 0x8000 bit before being passed as the fourth argument of
 * the dispatch call.  0x7FFF is not an ARM immediate, which is why it costs a
 * pool word rather than a `mov`.
 *
 * The second call's first argument is the first call's result: no register is
 * written for it, r0 is simply left as the callee returned it.  Declaring the
 * dispatch call's own first argument as a saved parameter instead costs the
 * function a callee-saved register, a 4-byte frame and 16 bytes.
 *
 * Complements func_02049BDC, which is a separate file on purpose: 0x02049C28
 * has five branch references image wide and three of them are inside
 * 0x02049C28 itself, so a `tu` spanning both wrappers loses every witness and
 * only the two single-function ranges keep one each.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_0204A1BC(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02049C28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = func_0204A1BC(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    func_02049C28(r, a2, a3, a4, a5);
}
