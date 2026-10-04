/*
 * function: func_021DE898
 * address:  0x021DE898
 * packet:   pkt_021DE898
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_02012F98 (0x02012F98) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 */

extern int func_02012F98(int);
struct PerapVoice;
extern void func_02007C34(struct PerapVoice *p, void *a);

void func_021DE898(int *q)
{
    int *r = *(int **)q;

    if ((*(unsigned *)((char *)r + 0x24) - 4) > 1)
        func_02007C34((struct PerapVoice *)func_02012F98(*(int *)r), (void *)(*(int *)((char *)r + 8)));
}
