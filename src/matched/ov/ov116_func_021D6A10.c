/*
 * function: WIFI_BSUBWAY_FinishPlayerDownload
 * address: 0x021D6A10
 * packet: pkt_ov116_021D6A10
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Remaining extent: existing matched accessor files at 021D6A40 and 021D6A44.
 * symbols:
 *   WIFI_BSUBWAY_PollAsync 0x021D70EC thumb ov116
 *   WIFI_BSUBWAY_AsyncHasError 0x021D7158 thumb ov116
 */
#include "../include/Obj13860.h"
extern int WIFI_BSUBWAY_PollAsync(unsigned char *,int *);
typedef unsigned char  u8;
extern int WIFI_BSUBWAY_AsyncHasError(u8 *p);
int WIFI_BSUBWAY_FinishPlayerDownload(unsigned char *a,unsigned char *b) { int result; if(((struct Obj13860 *)a)->f4) return 1; if(WIFI_BSUBWAY_PollAsync(b,&result) && WIFI_BSUBWAY_AsyncHasError(b)==0) { ((struct Obj13860 *)a)->f4=1; return 1; } return 0; }
