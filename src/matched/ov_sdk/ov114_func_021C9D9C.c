/*
 * function: func_021C9D9C
 * address:  0x021C9D9C
 * packet:   pkt_ov114_021C9D9C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EncSessionEncrypt (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 *
 * symbols:
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_021C9890  0x021C9890  arm  ov114
 *   func_021C98A4  0x021C98A4  arm  ov114
 *   func_021C9858  0x021C9858  arm  ov114
 *   func_0217FA90  0x0217FA90  arm  ov009
 *   g_021CF7AC  0x021CF7AC  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u8  pad[0x50];
    u32 key;
} Session;

extern void *func_0205A16C(int name, u32 size);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern void func_021C9890(u32 seed);
extern u8 func_021C98A4(void);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
extern u32 func_021C9858(u32 len);
extern Session g_021CF7AC;

int func_021C9D9C(u8 *outbuf, u8 *header, u32 headerlen, u8 *srcbuf, u32 srclen)
{
    u8 *tmpbuf;
    u32 sum = 0;
    int i;

    tmpbuf = func_0205A16C(8, srclen + headerlen + 4);
    if (tmpbuf == 0)
        return 2;
    for (i = 0; i < (int)headerlen; i++)
        tmpbuf[4 + i] = header[i];
    for (i = 0; i < (int)srclen; i++)
        tmpbuf[4 + headerlen + i] = srcbuf[i];
    for (i = 0; i < (int)(srclen + headerlen); i++)
        sum += tmpbuf[4 + i];
    func_021C9890(sum);
    for (i = 0; i < (int)(srclen + headerlen); i++)
        tmpbuf[4 + i] ^= func_021C98A4();
    sum ^= g_021CF7AC.key;
    tmpbuf[0] = (u8)(sum >> 24);
    tmpbuf[1] = (u8)(sum >> 16);
    tmpbuf[2] = (u8)(sum >> 8);
    tmpbuf[3] = (u8)sum;
    func_0217FA90((char *)tmpbuf, (char *)outbuf, srclen + headerlen + 4, 2);
    func_0205A1B0(8, tmpbuf, 0);
    outbuf[func_021C9858(srclen + headerlen + 4)] = 0;
    return 0;
}
