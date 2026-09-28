/*
 * function: func_021C99D0
 * address:  0x021C99D0
 * packet:   pkt_ov114_021C99D0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH*
 * notes:    byte-correct; the pool word at +0x184 is the hextbl initializer template (vendor @16077, image 0x021CE1B8), which no existing class attests in an overlay (vendor_template finds no template at this slot, and the template class is ARM9-only). The block-scoped `d` destination pointer is not a DWARF local; it is the spelling that gives the image register order for the second key copy.
 *
 * sdk:      DWCi_EncSessionValidateResponse (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 *
 * symbols:
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_020816B8  0x020816B8  arm
 *   func_020949F4  0x020949F4  arm
 *   func_021C9858  0x021C9858  arm  ov114
 *   func_0217FA90  0x0217FA90  arm  ov009
 *   g_021CF7AC  0x021CF7AC  data
 *   @16077  0x021CE1B8  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    int   state;
    int   isinitialized;
    int   reqid;
    int   validated;
    char  gamename[32];
    char  secretkey[20];
    u32   key1;
    u32   key2;
    u32   key3;
    u32   key4;
    char *request;
    char *hash;
    char *data;
    void *resbuf;
    u32   resbuflen;
    void *decodedbuf;
    u32   decodedbuflen;
    int (*callback)(u32 *, int);
    char  lastHash[41];
} Session;

extern void *func_0205A16C(int name, u32 size);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern void func_0217FA90(char *input, char *output, int inlen, int type);
extern u32 func_021C9858(u32 len);
extern void func_020816B8(void *digest, void *data, u32 len);
extern int func_020949F4(const char *a, const char *b, u32 n);
extern Session g_021CF7AC;
typedef struct { char c[20]; } Key20;

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
    if (func_020949F4(&buf[len - 40], hashhex, 40) != 0)
        return 0;
    g_021CF7AC.decodedbuf = buf;
    g_021CF7AC.decodedbuflen = len - 40u;
    return 1;
}
