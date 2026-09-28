/*
 * unit:     yes
 * function: func_021F0D00, func_021F0D08, func_021F0D10
 * address:  0x021F0D00
 * packet:   pkt_021F0D00
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021F0D00(unsigned short *p, int i)
{
    p[i] = 0;
}

unsigned short func_021F0D08(unsigned short *p, int i)
{
    return p[i];
}

void func_021F0D10(char *p, char v)
{
    p[9] = v;
}
