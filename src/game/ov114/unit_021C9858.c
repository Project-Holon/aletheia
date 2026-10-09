/*
 * file:     unit_021C9858.c
 * unit:     yes
 * function: func_021C9858, func_021C9890, func_021C98A4, func_021C98E0, func_021C99D0
 * address:  0x021C9858
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   g_021CF7AC     0x021CF7AC  data
 *   g_021D4228     0x021D4228  data
 *   func_0209477C  0x0209477C  arm
 *   func_02094860  0x02094860  arm
 *   g_021CF7BC     0x021CF7BC  data
 *   g_021CF7DC     0x021CF7DC  data
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_020816B8  0x020816B8  arm
 *   func_020949F4  0x020949F4  arm
 *   func_0217FA90  0x0217FA90  arm  ov009
 *   @16077  0x021CE1B8  data
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct Session {
    int state;
    int isinitialized;
    int reqid;
    int validated;
    char gamename[32];
    char secretkey[20];
    unsigned int key1;
    unsigned int key2;
    unsigned int key3;
    unsigned int key4;
    char *request;
    char *hash;
    char *data;
    void *resbuf;
    unsigned int resbuflen;
    void *decodedbuf;
    unsigned int decodedbuflen;
    int (*callback)(unsigned int *, int);
    char lastHash[41];
};

typedef struct { char c[20]; } Key20;

extern int func_0209477C(const u8 *s);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern void *func_0205A16C(int name, u32 size);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
extern void func_020816B8(void *digest, void *data, u32 len);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
unsigned long func_021C9858(unsigned long len);
void func_021C9890(u32 v);
unsigned char func_021C98A4(void);
int func_021C98E0(char *gamename, const char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4);
int func_021C99D0(char *buf, int len);
extern struct Session g_021CF7AC;
extern int g_021D4228;




/*
 * sdk:      b64size (dwc_encsession.o)
 */
unsigned long func_021C9858(unsigned long len)
{
    return (len / 3 + (len % 3 != 0 ? 1 : 0)) * 4;
}





/*
 * Duplicates a 16-bit value across the 32-bit word at 0x021D4228.
 */
void func_021C9890(u32 v)
{
    *(u32 *)0x021D4228 = v | ((u32)v << 16);
}




/*
 * sdk:      my_rand (dwc_encsession.o)
 */
unsigned char func_021C98A4(void)
{
    g_021D4228 = (g_021CF7AC.key1 * g_021D4228 + g_021CF7AC.key2) % g_021CF7AC.key3;
    return g_021D4228 >> 16;
}



/*
 * The 20-byte key copy is the compiler's 2x unrolled byte loop.  The r0/r1
 * assignment of the two byte temporaries is fixed by declaring the parameter
 * const (the compiler then keeps the loaded pair in r0=hi, r1=lo, matching
 * the image) and by interleaving the source-store advance (`s += 2`)
 * between the two destination stores.
 *
 * sdk:      DWCi_EncValidateKey (dwc_encsession.o)
 */
int func_021C98E0(char *gamename, const char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4)
{
    int bitcount = 0;
    int i;
    unsigned int n;

    g_021CF7AC.validated = 0;
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
    func_02094860((u8 *)g_021CF7AC.gamename, (const u8 *)gamename, 0x20);
    {
        unsigned char *d = (unsigned char *)g_021CF7AC.secretkey;
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
    g_021CF7AC.key1 = key1;
    g_021CF7AC.key2 = key2;
    g_021CF7AC.key3 = key3;
    g_021CF7AC.key4 = key4;
    g_021CF7AC.validated = 1;
    return 1;
}


/*
 * notes:    byte-correct; the pool word at +0x184 is the hextbl initializer template (vendor @16077, image 0x021CE1B8), attested by the `template` class in ov114 (prong (b): the only other copy, 0x021CE1CC, is @16117 at CompleteCallback's slot). The 404-byte listing extent became 400 once 0x021C9B60 was seeded. The block-scoped `d` destination pointer is not a DWARF local; it is the spelling that gives the image register order for the second key copy.
 *
 * sdk:      DWCi_EncSessionValidateResponse (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 */
int func_021C99D0(char *buf, int len)
{
    int i;
    u8 *tmpbuf;
    char hashhex[41];
    u8 hash[20];
    char hextbl[17] = "0123456789abcdef";

    if (len <= 40)
        return 0;
    tmpbuf = func_0205A16C(8, func_021C9858(len - 40u) + 41);
    if (tmpbuf == 0)
        return 0;
    *(Key20 *)tmpbuf = *(Key20 *)g_021CF7AC.secretkey;
    func_0217FA90(buf, (char *)(tmpbuf + 20), len - 40u, 2);
    {
        Key20 *d = (Key20 *)(tmpbuf + 20 + func_021C9858(len - 40u));
        *d = *(Key20 *)g_021CF7AC.secretkey;
    }
    func_020816B8(hash, tmpbuf, func_021C9858(len - 40u) + 40);
    func_0205A1B0(8, tmpbuf, 0);
    for (i = 0; i < 20; i++) {
        hashhex[i * 2] = hextbl[hash[i] >> 4];
        hashhex[i * 2 + 1] = hextbl[hash[i] & 15];
    }
    hashhex[40] = '\0';
    if (func_020949F4((const u8 *)(&buf[len - 40]), (const u8 *)hashhex, 40) != 0)
        return 0;
    g_021CF7AC.decodedbuf = buf;
    g_021CF7AC.decodedbuflen = len - 40u;
    return 1;
}
