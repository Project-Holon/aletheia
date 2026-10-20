#ifndef GAME_ARM9_DWC_AC_SHOP_USB_H
#define GAME_ARM9_DWC_AC_SHOP_USB_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_ac_shop_usb.c, prototypes copied from their definitions. */

int DWCi_AC_CheckNintendoShopAP(char *ssid);
void DWCi_AC_GetNintendoShopWepKey(char *ssid, unsigned char *wep);
int DWCi_AC_GetPostalCode(char *ssid, unsigned char *pos);
int DWCi_AC_CheckNintendoUsbAP(char *ssid);
void DWCi_AC_GetNintendoUSBWepKey(char *ssid, unsigned char *wep);
void decodeSSID(char *ssid, unsigned char *buf);
void makeUsbWepKey(unsigned char *seed, unsigned char *wepkey);
long codetovalue(unsigned char c);
int db64(char *src, unsigned char *dest, unsigned long srcsize, unsigned long destsize);
/* END mkheaders: generated region */

#endif
