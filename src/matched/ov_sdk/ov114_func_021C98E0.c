/*
 * function: DWCi_EncValidateKey
 * address:  0x021C98E0
 * packet:   pkt_ov114_021C98E0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 20-byte key copy is the compiler's 2x unrolled byte loop.  The r0/r1
 * assignment of the two byte temporaries is fixed by declaring the parameter
 * const (the compiler then keeps the loaded pair in r0=hi, r1=lo, matching
 * the image) and by interleaving the source-store advance (`s += 2`)
 * between the two destination stores.
 *
 * sdk:      DWCi_EncValidateKey (dwc_encsession.o)
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_02094860  0x02094860  arm
 *   gDwcEncSession     0x021CF7AC  data
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
extern Session gDwcEncSession;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);

int DWCi_EncValidateKey(char *gamename, const char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4)
{
    int bitcount = 0;
    int i;
    unsigned int n;

    gDwcEncSession.valid = 0;
    if ((unsigned long)func_0209477C((const u8 *)gamename) >= 0x20) {
        return 0;
    }
    if ((unsigned long)func_0209477C((const u8 *)secretkey) != 0x14) {
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
    func_02094860((u8 *)gDwcEncSession.gamename, (const u8 *)gamename, 0x20);
    {
        unsigned char *d = gDwcEncSession.secretkey;
        unsigned char *s = (unsigned char *)secretkey;
        for (n = 10; n != 0; n--) {
            unsigned char x0;
            unsigned char x1;
            x1 = s[1];
            x0 = s[0];
            d[1] = x1;
            s += 2;
            d[0] = x0;
            d += 2;
        }
    }
    gDwcEncSession.key1 = key1;
    gDwcEncSession.key2 = key2;
    gDwcEncSession.key3 = key3;
    gDwcEncSession.key4 = key4;
    gDwcEncSession.valid = 1;
    return 1;
}
