/*
 * file:     unit_0205EA08_p01.c
 * unit:     yes
 * function: func_0205EA08, func_0205EA44, func_0205EA70, func_0205EAFC, func_0205EB20
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
 *   @16365                           0x020a8118 data
 *   makeShopWepKey                   0x0205ec2c arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   g_020A8118                       0x020A8118 data
 *   g_020A8124                       0x020a8124 data
 *   makeUsbWepKey                    0x0205ec7c arm
 */
extern void func_0205EB30(char *ssid, unsigned char *buf);
extern int memcmp(const void *s1, const void *s2, unsigned long n);
extern void func_0205EC2C(unsigned char *seed, unsigned char *wepkey);
extern void decodeSSID(char *ssid, unsigned char *buf);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void makeUsbWepKey(unsigned char *seed, unsigned char *wepkey);
int func_0205EA08(char *ssid);
void func_0205EA44(char *ssid, unsigned char *wep);
int func_0205EA70(char *ssid, unsigned char *pos);
void func_0205EB20(char *ssid, unsigned char *wep);
extern const char g_020A8118[];


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


extern const char g_020A8124[]; /* "NWCUSBAP", the vendor object's @16393 */

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
