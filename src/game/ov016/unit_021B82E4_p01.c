/*
 * file:     unit_021B82E4_p01.c
 * unit:     yes
 * function: func_021B82E4, func_021B830C, func_021B8324
 * address:  0x021B82E4
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
unsigned long AOSS_Htonl(unsigned long hostlong);
unsigned short AOSS_Htons(unsigned short hostshort);
unsigned long AOSS_Ntohl(unsigned long netlong);

unsigned long AOSS_Htonl(unsigned long hostlong)
{
    return ((hostlong >> 24) & 0xff) | ((hostlong >> 8) & 0xff00) |
           ((hostlong << 8) & 0xff0000) | ((hostlong << 24) & 0xff000000);
}

unsigned short AOSS_Htons(unsigned short hostshort)
{
    return ((hostshort >> 8) & 0xff) | ((hostshort << 8) & 0xff00);
}

unsigned long AOSS_Ntohl(unsigned long netlong)
{
    return ((netlong >> 24) & 0xff) | ((netlong >> 8) & 0xff00) |
           ((netlong << 8) & 0xff0000) | ((netlong << 24) & 0xff000000);
}
