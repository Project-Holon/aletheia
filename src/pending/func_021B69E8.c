/*
 * function: func_021B69E8
 * address:  0x021B69E8
 * packet:   pkt_021B69E8
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_02015E04 (0x02015E04) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_02015E04  0x02015E04  thumb
 */

extern void func_02015E04(int);

void func_021B69E8(int *p)
{
    func_02015E04(*(int *)((char *)p + 0x1c));
    *(int *)((char *)p + 0x24) = 1;
}
