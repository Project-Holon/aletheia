/*
 * function: func_021B974C
 * address: 0x021B974C
 * packet: pkt_ov181_021B974C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B97BA, then the next function.
 * symbols:
 *   func_021BA83C 0x021BA83C thumb ov181
 */
extern int func_021BA83C(char *);
#define STATE(p) (*(int *)((p) + 0x2EC))
#define COUNT(p) (*(unsigned *)((p) + 0x2E4))
int func_021B974C(char *p)
{
    switch (STATE(p)) {
    case 0:
        if (COUNT(p) >= 41) {
            COUNT(p) = 0;
            STATE(p)++;
        } else if (*(unsigned char *)(p + 0x2D2) == 1) {
            COUNT(p) += 4;
        } else {
            COUNT(p)++;
        }
        break;
    case 1:
        if (func_021BA83C(p) == 0)
            STATE(p)++;
        break;
    case 2:
        COUNT(p) = 0;
        STATE(p) = 0;
        return 4;
    }
    return 3;
}
