/*
 * function: value_for_key
 * address:  0x02193F00
 * packet:   pkt_ov009_02193F00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      value_for_key (gstats.o)
 *
 * value_for_key. The keyspec initializer is the vendor template @13818 at 0x021A1A64
 * (template class, overlay scope). strcat 0x020948B0 attests as matched through
 * unit_02094860, whose functions list names func_020948B0 since 2026-09-29 (w4_nm).
 *
 * symbols:
 *   func_020948B0 0x020948B0  arm
 *   func_02094B20 0x02094B20  arm
 *   func_0209477C 0x0209477C  arm
 *   @13818       0x021A1A64  data
 *   gGstatsConn   0x021ADFE0  data
 *   gGstatsKeyBackslash   0x021A5894  data
 *   gGstatsValueBuffers   0x021AE21C  data
 */

typedef unsigned char  u8;
extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern char *func_02094B20(const char *s, const char *sub);
extern int func_0209477C(const u8 *s);
extern char g_021A1A64[];
extern int gGstatsConn[];
extern char gGstatsKeyBackslash[];
extern char gGstatsValueBuffers[];

char *value_for_key(char *s, char *key)
{
    char keyspec[256] = "\\";
    char *pos;
    char *pos2;

    gGstatsConn[8] ^= 1;
    func_020948B0((u8 *)keyspec, (const u8 *)key);
    func_020948B0((u8 *)keyspec, (const u8 *)gGstatsKeyBackslash);
    pos = func_02094B20(s, keyspec);
    if (pos == 0)
        return 0;
    pos += func_0209477C((const u8 *)keyspec);
    pos2 = gGstatsValueBuffers + gGstatsConn[8] * 256;
    while (*pos != 0 && *pos != 0x5c)
        *pos2++ = *pos++;
    *pos2 = 0;
    return gGstatsValueBuffers + gGstatsConn[8] * 256;
}
