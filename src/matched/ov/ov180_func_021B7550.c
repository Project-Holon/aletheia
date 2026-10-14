/*
 * function: HALL_OF_FAME_ReleaseCellAnim
 * address:  0x021B7550
 * packet:   pkt_021B7550
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 */

typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);

void HALL_OF_FAME_ReleaseCellAnim(char *p, int i)
{
    if (*(int *)(p + 0x9100 + i * 4) != -1) {
        CLACT_ReleaseCellAnim(*(int *)(p + 0x9100 + i * 4));
        *(int *)(p + 0x9100 + i * 4) = -1;
    }
}
