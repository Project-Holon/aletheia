/*
 * function: BOX2_UI_GetSlotOamEnabled
 * address:  0x021EE234
 * packet:   pkt_021EE234
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   BMP_OAM_GetEnabled (0x020257C4) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   BMP_OAM_GetEnabled  0x020257C4  thumb
 */

extern int BMP_OAM_GetEnabled(const int *p);

int BOX2_UI_GetSlotOamEnabled(int *a, int i)
{
    return BMP_OAM_GetEnabled((const int *)(*(int *)((char *)a + i * 8 + 4)));
}
