/*
 * function: MB_COMM_SYS_ClearRoundFlags
 * address:  0x021F1064
 * packet:   pkt_ov107_021F1064
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void MB_COMM_SYS_ClearRoundFlags(unsigned char *p)
{
    unsigned short *h = (unsigned short *)(p + 0x18);
    *h = *h & ~(unsigned short)2;
    *h = *h & ~(unsigned short)4;
    *h = *h & ~(unsigned short)8;
    *h = *h & ~(unsigned short)0x10;
    *h = *h & ~(unsigned short)0x20;
    *h = *h & ~(unsigned short)0x40;
    *h = *h & ~(unsigned short)0x80;
    *h = *h & ~0x100;
    *h = *h & ~0x200;
    *h = *h & ~0x400;
    *h = *h & ~0x1000;
    p[0x1C] = 0;
}
