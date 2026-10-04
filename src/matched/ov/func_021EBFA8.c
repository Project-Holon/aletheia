/*
 * function: func_021EBFA8
 * address:  0x021EBFA8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Stop and re-issue slot i of the 0x9E74 array; the word is
 *   re-read for the second call.  Writing the array offset before the index
 *   term is what puts the pool constant in r2 and the index in r6.
 */


typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021EBFA8(char *p, int i, int v)
{
    func_0204B8C4((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), 0);
    func_0204B878((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned short)v);
}
