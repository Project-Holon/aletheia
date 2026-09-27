/*
 * function: DWCi_LSTlPopFront
 * address:  0x0215DD78
 * packet:   pkt_ov009_0215DD78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SOCLi_ConsumeCPSBuffer  0x0215DD88  arm
*/

extern void SOCLi_ConsumeCPSBuffer(void *next);

void DWCi_LSTlPopFront(void *list)
{
    SOCLi_ConsumeCPSBuffer(*(void **)((char *)list + 4));
}
