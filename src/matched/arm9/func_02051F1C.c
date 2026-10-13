/*
 * function: BUTTON_MAN_InitSphere
 * address:  0x02051F1C
 * packet:   pkt_02051F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 */
struct Vec { int x, y, z; };
struct Ball { struct Vec p; int radius; };
void BUTTON_MAN_InitSphere(struct Ball *dst, struct Vec *src, unsigned radius)
{
    dst->p = *src;
    dst->radius = radius;
}
