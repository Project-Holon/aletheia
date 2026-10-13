/*
 * function: func_021EBFCC
 * address:  0x021EBFCC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBFA8  0x021EBFA8  thumb  ov170
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *
 * Release-and-flag slot i of the 0x9E74 array.
 */


extern void func_021EBFA8(char *p, int i, int v);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
void func_021EBFCC(char *p, int i, int v)
{
    func_021EBFA8(p, i, v);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p + i * 4 + 0x9E74), 1);
}
