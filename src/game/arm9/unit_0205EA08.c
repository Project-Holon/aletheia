/*
 * file:     unit_0205EA08.c
 * unit:     yes
 * function: func_0205EA08, func_0205EA44, func_0205EA70, func_0205EAFC, func_0205EB20, func_0205EB30, func_0205EC2C, func_0205EC7C, func_0205EE28, func_0205EE98
 * address:  0x0205EA08
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   decodeSSID                       0x0205eb30 arm
 *   memcmp                           0x020923f0 arm
 *   makeShopWepKey                   0x0205ec2c arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   g_020A8118                       0x020A8118 data
 *   g_020A8124                       0x020a8124 data
 *   makeUsbWepKey                    0x0205ec7c arm
 *   @16365                           0x020a8118 data
 *   db64 0x0205EE98 arm
 *   g_020A1688 0x020A1688 data
 *   g_020A80B0 0x020A80B0 data
 *   MATH_MD5Init                     0x02081120 arm
 *   MATH_MD5Update                   0x02081164 arm
 *   MATH_MD5GetHash                  0x0208122c arm
 *   SHMASKkey0                       0x020a80b0 data
 *   CONV_BYTE_TABLE                  0x020a1668 data
 *   CONV_4BIT_TABLE                  0x020a1675 data
 *   g_020A1668                       0x020A1668 data
 *   g_020A1675                       0x020A1675 data
 *   codetovalue                      0x0205ee28 arm
 */
typedef struct CTable {
    unsigned char b[24];
} CTable;

typedef struct MATHMD5Context {
    unsigned long state[4];
    unsigned long length[2];
    unsigned char buffer[64];
} MATHMD5Context;

typedef union tagU4B {
    unsigned long l;
    unsigned char b[4];
} tagU4B;

extern int memcmp(const void *s1, const void *s2, unsigned long n);
extern void decodeSSID(char *ssid, unsigned char *buf);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void makeUsbWepKey(unsigned char *seed, unsigned char *wepkey);
extern int db64(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize);
extern void func_02081120(MATHMD5Context *context);
extern void func_02081164(MATHMD5Context *context, const void *input, unsigned long length);
extern void func_0208122C(MATHMD5Context *context, void *digest);
extern long codetovalue(unsigned char c);
int func_0205EA08(char *ssid);
void func_0205EA44(char *ssid, unsigned char *wep);
int func_0205EA70(char *ssid, unsigned char *pos);
int func_0205EAFC(char *ssid);
void func_0205EB20(char *ssid, unsigned char *wep);
void func_0205EB30(char *ssid, unsigned char *buf);
static void func_0205EC2C(unsigned char *seed, unsigned char *wepkey);
void func_0205EC7C(unsigned char *seed, unsigned char *wepkey);
long func_0205EE28(unsigned char c);
int func_0205EE98(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize);
extern const char g_020A8118[];
extern const char g_020A8124[]; /* "NWCUSBAP", the vendor object's @16393 */
extern const CTable g_020A1688;
extern char *g_020A80B0[4];
extern const unsigned char g_020A1668[13];
extern const unsigned char g_020A1675[16];



/*
 * sdk:      DWCi_AC_CheckNintendoShopAP (shop_usb.o)
 */
int func_0205EA08(char *ssid)
{
    unsigned char buf[24];

    func_0205EB30(ssid, buf);
    if (memcmp(buf, "NDWCSHAP", 8) == 0) {
        return 1;
    }
    return 0;
}



/*
 * sdk:      DWCi_AC_GetNintendoShopWepKey (shop_usb.o)
 */
void func_0205EA44(char *ssid, unsigned char *wep)
{
    unsigned char buf[24];

    func_0205EB30(ssid, buf);
    func_0205EC2C(buf, wep);
}



/*
 * sdk:      DWCi_AC_GetPostalCode (libdwcac.TWL.HYB.a(shop_usb.o))
 */
int func_0205EA70(char *ssid, unsigned char *pos)
{
    int i;
    unsigned char buf[24];

    decodeSSID(ssid, buf);
    if (memcmp(buf, g_020A8118, 8) == 0) {
        MI_CpuCopy8(&buf[8], pos, 10);
        for (i = 0; i < 10; i++) {
            if (pos[i] < 0x20 || pos[i] > 0x7e) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}


/*
 * sdk:      DWCi_AC_CheckNintendoUsbAP (shop_usb.o)
 */
int func_0205EAFC(char *ssid)
{
    if (memcmp(ssid, g_020A8124, 8) == 0) {
        return 1;
    }
    return 0;
}



/*
 * sdk:      DWCi_AC_GetNintendoUSBWepKey (libdwcac.TWL.HYB.a(shop_usb.o))
 */
void func_0205EB20(char *ssid, unsigned char *wep)
{
    makeUsbWepKey((unsigned char *)ssid + 12, wep);
}



/*
 * sdk:      decodeSSID (shop_usb.o)
 */
void func_0205EB30(char *ssid, unsigned char *buf)
{
    int i;
    CTable ctable_inv;
    unsigned char destnum;
    unsigned char dest;
    unsigned char srcnum;
    unsigned char src;

    ctable_inv = g_020A1688;
    db64(ssid, buf, 32, 24);
    for (i = 0; i < 24; i++) {
        buf[i] = buf[i] ^ g_020A80B0[2][i];
    }
    for (i = 0; i < 24; i++) {
        destnum = (unsigned char)i;
        srcnum = (unsigned char)i;
        src = buf[i];
        while (ctable_inv.b[srcnum] != 0xff) {
            dest = buf[ctable_inv.b[srcnum]];
            buf[ctable_inv.b[destnum]] = src;
            destnum = ctable_inv.b[srcnum];
            ctable_inv.b[srcnum] = 0xff;
            srcnum = destnum;
            src = dest;
        }
    }
    for (i = 0; i < 24; i++) {
        buf[i] = buf[i] ^ g_020A80B0[0][i];
    }
}



/*
 * sdk:      makeShopWepKey (shop_usb.o)
 */
static void func_0205EC2C(unsigned char *seed, unsigned char *wepkey)
{
    unsigned char temp[17];
    MATHMD5Context context;

    func_02081120(&context);
    func_02081164(&context, seed, 24);
    func_0208122C(&context, temp);
    MI_CpuCopy8(&temp[3], wepkey, 13);
}



/*
 * sdk:      makeUsbWepKey (libdwcac.TWL.HYB.a(shop_usb.o))
 */
void func_0205EC7C(unsigned char *seed, unsigned char *wepkey)
{
    int i;
    unsigned char keytemp[13];

    for (i = 0; i < 13; i++) {
        wepkey[i] = seed[i] ^ seed[13 + i % 7];
    }
    for (i = 0; i < 7; i++) {
        wepkey[3 + i] = wepkey[3 + i] ^ seed[13 + i];
    }
    for (i = 0; i < 13; i++) {
        wepkey[i] = wepkey[i] ^ g_020A80B0[1][i];
    }
    MI_CpuCopy8(wepkey, keytemp, 13);
    for (i = 0; i < 13; i++) {
        wepkey[g_020A1668[i]] = keytemp[i];
    }
    for (i = 0; i < 13; i++) {
        wepkey[i] = wepkey[i] ^ g_020A80B0[3][i];
    }
    for (i = 0; i < 13; i++) {
        wepkey[i] = (unsigned char)((g_020A1675[(wepkey[i] >> 4) & 0xf] << 4) | g_020A1675[wepkey[i] & 0xf]);
    }
    for (i = 0; i < 3; i++) {
        wepkey[i] ^= wepkey[i + 6];
        wepkey[i + 3] ^= wepkey[i + 9];
        wepkey[i + 6] ^= wepkey[i + 3];
        wepkey[i + 9] ^= wepkey[i];
        wepkey[12] ^= wepkey[i];
    }
}


/*
 * sdk:      codetovalue (libdwcac.TWL.HYB.a(shop_usb.o))
 */
long func_0205EE28(unsigned char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    if (c >= 'a' && c <= 'z') {
        return (long)(c - 'a') + 26;
    }
    if (c >= '0' && c <= '9') {
        return (long)(c - '0') + 52;
    }
    if (c == '+') {
        return 62;
    }
    if (c == '/') {
        return 63;
    }
    return -(c != '=');
}



/*
 * sdk:      db64 (libdwcac.TWL.HYB.a(shop_usb.o))
 */
int func_0205EE98(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize)
{
    tagU4B u4b;
    unsigned long x;
    unsigned long base64;
    int srcmod;
    int srcmax;
    int i;
    int j;
    int k;

    x = srcsize * 3 / 4;
    if (destsize >= x) {
        srcmod = srcsize & 3;
        srcmax = srcsize - srcmod;
    } else {
        return -1;
    }
    for (i = 0; i < srcmax; i += 4) {
        base64 = 0;
        for (j = 0; j < 4; j++) {
            base64 |= codetovalue(src[i + j]) << ((3 - j) * 6);
        }
        u4b.l = base64;
        for (k = 0; k < 3; k++) {
            dest[(i / 4) * 3 + k] = u4b.b[2 - k];
        }
    }
    if (srcmod != 0) {
        base64 = 0;
        u4b.l = 0;
        for (j = 0; j < srcmod; j++) {
            base64 |= codetovalue(src[srcmax + j]) << ((3 - j) * 6);
            u4b.l |= base64;
        }
        for (k = 0; k < srcmod; k++) {
            dest[srcmax * 3 / 4 + k] = u4b.b[2 - k];
        }
    }
    return x;
}
