/*
 * function: func_021C98E0
 * address:  0x021C98E0
 * packet:   pkt_ov114_021C98E0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * near miss: 20-byte key copy loop matches except that r0/r1 are swapped in the two ldrb/strb pairs
 * (4 instructions differ; no other byte differs). The original is the compiler struct-copy expansion.
 * The copy is written as an explicit 2x unrolled byte loop here.
 *
 * sdk:      DWCi_EncValidateKey (dwc_encsession.o)
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_02094860  0x02094860  arm
 *   g_021CF7AC     0x021CF7AC  data
 *   g_021CF7BC     0x021CF7BC  data
 *   g_021CF7DC     0x021CF7DC  data
 */

typedef struct {
    int state;
    int active;
    int unk8;
    int valid;
    char gamename[0x20];
    unsigned char secretkey[0x14];
    unsigned long key1;
    unsigned long key2;
    unsigned long key3;
    unsigned long key4;
} Session;
extern Session g_021CF7AC;
extern unsigned long func_0209477C(const char *s);
extern char *func_02094860(char *dst, const char *src, unsigned long n);

int func_021C98E0(char *gamename, char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4)
{
    int bitcount = 0;
    int i;
    unsigned int n;

    g_021CF7AC.valid = 0;
    if (func_0209477C(gamename) >= 0x20) {
        return 0;
    }
    if (func_0209477C(secretkey) != 0x14) {
        return 0;
    }
    if ((key1 - 5) & 7) {
        return 0;
    }
    if ((key2 & 1) == 0) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        if (((key3 >> i) & 1) == 1) {
            bitcount++;
        }
    }
    if (bitcount != 1) {
        return 0;
    }
    func_02094860(g_021CF7AC.gamename, gamename, 0x20);
    {
        unsigned char *d = g_021CF7AC.secretkey;
        unsigned char *s = (unsigned char *)secretkey;
        for (n = 10; n != 0; n--) {
            unsigned char x1 = s[1];
            unsigned char x0 = s[0];
            s += 2;
            d[1] = x1;
            d[0] = x0;
            d += 2;
        }
    }
    g_021CF7AC.key1 = key1;
    g_021CF7AC.key2 = key2;
    g_021CF7AC.key3 = key3;
    g_021CF7AC.key4 = key4;
    g_021CF7AC.valid = 1;
    return 1;
}
