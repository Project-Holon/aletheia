/*
 * function: func_02193FF4
 * address:  0x02193FF4
 * packet:   pkt_ov009_02193FF4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FindFinal (gstats.o)
 *
 * symbols:

 */

char *func_02193FF4(char *buff, int len)
{
    char *pos = buff;

    while (pos - buff < len - 6) {
        if (pos[0] == 0x5c && pos[1] == 'f' && pos[2] == 'i' && pos[3] == 'n' &&
            pos[4] == 'a' && pos[5] == 'l' && pos[6] == 0x5c)
            return pos;
        pos++;
    }
    return 0;
}
