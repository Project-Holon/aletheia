#ifndef GAME_OV016_AOSSLINK_H
#define GAME_OV016_AOSSLINK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of aosslink.c, prototypes copied from their definitions. */

struct WMBssDesc;
struct wlla_bss_info;
struct wlla_ssid;
struct wlla_bss_list;

#include "../ov016/wlla_types.h"
#include "../ov016/wlla_types.h"

void Set_WLLA_BSS_INFO(struct WMBssDesc *bd, struct wlla_bss_info *bi);
void Get_WLLA_SSID_PARAM(struct wlla_ssid *ssid, struct WMBssDesc *bd);
int AOSSi_InitLocal(void *(*alloc)(unsigned long), void (*free)(void *));
int AOSSi_EndLocal(void);
int AOSSi_Disconnect(void);
int AOSSi_WLANGetBSSList(struct wlla_bss_list **bssList);
int AOSSi_WLANConnect(WLLA_CONNECT_PARAM *conParam, WLLA_LINK_STAT *linkStat);
void AOSSi_Sleep(unsigned int msec);
int AOSSi_Status(int a);
/* END mkheaders: generated region */

#endif
