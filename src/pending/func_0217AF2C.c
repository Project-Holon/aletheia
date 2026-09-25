/*
 * function: func_0217AF2C
 * address:  0x0217AF2C
 * packet:   pkt_0217AF2C
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_021E5548 (0x021E5548) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_021E567C  0x021E567C  thumb  ov177
 */

extern int func_021E5548(int);
extern int func_021E567C(int, int, int);

void func_0217AF2C(int *p)
{
    *(int *)((char *)p + 0x20) = func_021E567C(func_021E5548(*(int *)((char *)p + 0x24)), 1, *(unsigned short *)p);
}
