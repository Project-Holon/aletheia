/*
 * function: DWC_RAP_GetTargetFriendIndex
 * address:  0x02156A3C
 * packet:   pkt_ov009_02156A3C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after DWC_RAP_StartFriendMatch's pool (no lr save, so disasm.py
 * never labels it).
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 */

typedef struct {
    char pad[0x770];
    int aid;            /* 0x770 */
} G;

extern G *_pRapWork;

int DWC_RAP_GetTargetFriendIndex(void)
{
    if (_pRapWork != 0)
        return _pRapWork->aid;
    return -1;
}
