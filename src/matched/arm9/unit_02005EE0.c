/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005EE0
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005EE0
 *
 * symbols:
 *   sub_0200590C   0x0200590C  thumb
 *   func_02073018  0x02073018  arm
 *   func_02073038  0x02073038  arm
 *   func_02073098  0x02073098  arm
 *
 * Three optional fields of a request, each skipped when the caller passes
 * -1.  The -1 is rebuilt with `movs`/`mvns` before each of the three tests
 * rather than held in a register across them, which is what an inline
 * constant in three separate comparisons looks like: a variable would have
 * been allocated a register once.
 */

typedef unsigned int u32;

extern u32 *sub_0200590C(void);
struct Obj;
extern void func_02073018(struct Obj *o, u32 v, u32 w);
extern void func_02073038(struct Obj *o, u32 v, u32 w);
extern void func_02073098(struct Obj *o, u32 v);

void sub_02005EE0(u32 a, u32 b, u32 c, u32 d)
{
    u32 *req = sub_0200590C();

    if (b != -1) {
        func_02073098((struct Obj *)req, b);
    }
    if (c != -1) {
        func_02073018((struct Obj *)req, a, c);
    }
    if (d != -1) {
        func_02073038((struct Obj *)req, a, d);
    }
}
