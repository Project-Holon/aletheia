/*
 * function: FIELD_PLACE_NAME_FreeBgChars
 * address:  0x021BC704
 * packet:   pkt_ov021_021BC704
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_DeleteHalf  0x0203FB44  arm  arm9
 */

typedef struct {
    char pad[0x28];
    int f28;
} Obj;

typedef unsigned int   u32;
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

void FIELD_PLACE_NAME_FreeBgChars(Obj *p)
{
    if (p->f28 != -1) {
        BG_SYS_DeleteHalf(3, p->f28, 0x20);
        p->f28 = -1;
    }
}
