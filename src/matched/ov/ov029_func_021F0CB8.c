/*
 * function: func_021F0CB8
 * address: 0x021F0CB8
 * packet: pkt_ov029_021F0CB8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
void func_021F0CB8(unsigned char *p)
{
    int i;
    if (p[9]) {
        for (i = 0; i < 3; i++) {
            if (((unsigned short *)p)[i] < ((unsigned short *)p)[3])
                ((unsigned short *)p)[i]++;
        }
    }
}
