/*
 * function: func_021C8738
 * address:  0x021C8738
 * packet:   pkt_ov021_021C8738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

int func_021C8738(char *p, int k)
{
    int r;
    int i;

    switch (k) {
    case 0:
        r = *(unsigned char *)(p + 0x1b0);
        break;
    case 1:
        r = *(unsigned char *)(p + 0x1b1);
        break;
    case 2:
        r = *(unsigned char *)(p + 0x1b2);
        break;
    case 3:
        r = *(unsigned char *)(p + 0x1b3);
        break;
    case 4:
        r = *(unsigned short *)(p + 6);
        break;
    case 5:
        r = 0;
        for (i = 0; i < 15; i++) {
            if (*(int *)(p + i * 0x1c + 0x24) != 0) {
                r++;
            }
        }
        break;
    default:
        r = 0;
        break;
    }
    return r;
}
