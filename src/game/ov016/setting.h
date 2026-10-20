#ifndef GAME_OV016_SETTING_H
#define GAME_OV016_SETTING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of setting.c, prototypes copied from their definitions. */

void DWCi_SETTIGNlInit(void);
void DWCi_SETTIGNlEnd(void);
char *DWCi_SETTIGNlGet(void);
void DWCi_SETTINGlSetIpAuto(unsigned char v);
void DWCi_SETTINGlSetDnsAuto(unsigned char v);
void DWCi_SETTINGlSetSsid(char *ssid);
void DWCi_SETTINGlSetWep(unsigned char *wep);
void DWCi_SETTINGlSetIp(char *ip);
void DWCi_SETTINGlSetNetMask(char *netmask);
void DWCi_SETTINGlSetGateway(char *gateway);
void DWCi_SETTINGlSetDnsP(char *dns);
void DWCi_SETTINGlSetDnsS(char *dns);
void DWCi_SETTINGlGetSsid(unsigned char *buf);
void DWCi_SETTINGlGetIp(char *buf);
void DWCi_SETTINGlGetNetMask(char *buf);
void DWCi_SETTINGlGetGateway(char *buf);
void DWCi_SETTINGlGetDnsP(char *buf);
void DWCi_SETTINGlGetDnsS(char *buf);
unsigned char DWCi_SETTINGlGetSetType(unsigned int i);
void DWCi_SETTINGlSetSetting(int idx);
void DWCi_SETTINGlSet(void);
void DWCi_SETTINGlSetRaku(void *param);
void DWCi_SETTINGlSetAoss(void *param);
char *DWCi_SETTINGlGetMemMap(void);
void DWCi_SETTINGlErasePage(int page);
void DWCi_SETTINGlEraseAll(void);
void DWCi_SETTINGlConvAddress(char *adr, unsigned char *buf);
/* END mkheaders: generated region */

#endif
