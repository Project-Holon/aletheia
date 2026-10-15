/*
 * function: NAMEIN_GRAPHIC_NextPairChar
 * address: 0x021F4F7C
 * packet: pkt_ov194_021F4F7C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_GetPairCount 0x021F4F68 thumb ov194
 *   NAMEIN_GRAPHIC_GetPairEntry 0x021F4F6C thumb ov194
 */
typedef unsigned short u16;
extern int NAMEIN_GRAPHIC_GetPairCount(const u16 *p);
extern unsigned short NAMEIN_GRAPHIC_GetPairEntry(char *base, int i, int j);
int NAMEIN_GRAPHIC_NextPairChar(char *p, const unsigned short *key, unsigned short *out)
{
    int i, j;
    if (*key == 0x3000) return 0;
    for (i = 0; i < NAMEIN_GRAPHIC_GetPairCount((const u16 *)p); i++) {
        for (j = 0; j < 3; j++) {
            if (*key == NAMEIN_GRAPHIC_GetPairEntry(p, (unsigned short)i, (unsigned short)j)) {
                p += i * 6;
                do {
                    j = (j + 1) % 3;
                    *out = *(unsigned short *)(p + 2 + j * 2);
                } while (*out == 0x3000);
                return 1;
            }
        }
    }
    return 0;
}
