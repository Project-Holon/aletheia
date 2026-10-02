/*
 * function: func_021F0A68
 * address: 0x021F0A68
 * packet: pkt_ov029_021F0A68
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F0C68 0x021F0C68 thumb ov029
 */
extern int func_021F0C68(unsigned short *);
int func_021F0A68(char *p)
{
    int result, i, j;
    result = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            if (func_021F0C68((unsigned short *)(p + 0x2d0 + i * 32 + j * 8))) {
                result = 1;
                break;
            }
        }
    }
    return result;
}
