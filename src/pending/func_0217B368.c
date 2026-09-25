/*
 * function: func_0217B368
 * address:  0x0217B368
 * packet:   pkt_0217B368
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_021E8A90 (0x021E8A90) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_021E8A90  0x021E8A90  thumb  ov177
 */

extern int func_021E8A90(int);

int func_0217B368(int *p)
{
    if (func_021E8A90(*(int *)p))
        return *(int *)((char *)p + 0x10);
    return 0;
}
