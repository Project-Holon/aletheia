/*
 * function: func_02193F00
 * address:  0x02193F00
 * packet:   pkt_ov009_02193F00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      value_for_key (gstats.o)
 *
 * Byte-correct (208/208); two relocation sites stay wildcarded.\nBlockers: strcat 0x020948B0 is an unlabelled ARM9 leaf (game/unknown, no witness,\nsame as BucketConcat 0x02193A90); the keyspec initializer copies from the vendor\ntemplate @13818 at 0x021A1A64 in ov009 data, and the template class only attests\ntemplates inside the ARM9 static module.
 *
 * symbols:
 *   func_020948B0 0x020948B0  arm
 *   func_02094B20 0x02094B20  arm
 *   func_0209477C 0x0209477C  arm
 *   @13818       0x021A1A64  data
 *   g_021ADFE0   0x021ADFE0  data
 *   g_021A5894   0x021A5894  data
 *   g_021AE21C   0x021AE21C  data
 */

extern char *func_020948B0(char *dst, const char *src);
extern char *func_02094B20(const char *s, const char *sub);
extern int func_0209477C(const char *s);
extern char g_021A1A64[];
extern int g_021ADFE0[];
extern char g_021A5894[];
extern char g_021AE21C[];

char *func_02193F00(char *s, char *key)
{
    char keyspec[256] = "\\";
    char *pos;
    char *pos2;

    g_021ADFE0[8] ^= 1;
    func_020948B0(keyspec, key);
    func_020948B0(keyspec, g_021A5894);
    pos = func_02094B20(s, keyspec);
    if (pos == 0)
        return 0;
    pos += func_0209477C(keyspec);
    pos2 = g_021AE21C + g_021ADFE0[8] * 256;
    while (*pos != 0 && *pos != 0x5c)
        *pos2++ = *pos++;
    *pos2 = 0;
    return g_021AE21C + g_021ADFE0[8] * 256;
}
