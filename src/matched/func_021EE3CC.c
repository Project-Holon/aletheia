/*
 * function: func_021EE3CC
 * address:  0x021EE3CC
 * packet:   pkt_021EE3CC
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_02025D14 (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_02025D14  0x02025D14  thumb
 */

extern void func_02025D14(int);

void func_021EE3CC(int *p)
{
    if (*(int *)(*(int *)((char *)p + 0x2c) + 0x70)) {
        func_02025D14(*(int *)(*(int *)((char *)p + 0x2c) + 0x70));
        *(int *)(*(int *)((char *)p + 0x2c) + 0x70) = 0;
    }
}
