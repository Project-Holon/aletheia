/*
 * function: WIFI_BSUBWAY_OnHttpError
 * address: 0x021D6E3C
 * packet: pkt_ov116_021D6E3C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two bytes zero alignment padding follow the compiled function.
 * symbols:
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 */
#include "../include/Obj13863.h"
extern void NHTTP_RAP_DeleteConnection(unsigned char *);
void WIFI_BSUBWAY_OnHttpError(unsigned char *a) { if(((struct Obj13863 *)a)->f168) NHTTP_RAP_DeleteConnection(((struct Obj13863 *)a)->f168); }
