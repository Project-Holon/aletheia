/*
 * function: WIFI_BSUBWAY_FinishProfileUpload
 * address: 0x021D6D18
 * packet: pkt_ov116_021D6D18
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two bytes zero alignment padding follow the compiled function.
 * symbols:
 *   WIFI_BSUBWAY_PollAsync 0x021D70EC thumb ov116
 *   WIFI_BSUBWAY_AsyncHasError 0x021D7158 thumb ov116
 */
#include "../include/Obj22621.h"
extern int WIFI_BSUBWAY_PollAsync(unsigned char *,int *);
typedef unsigned char  u8;
extern int WIFI_BSUBWAY_AsyncHasError(u8 *p);
int WIFI_BSUBWAY_FinishProfileUpload(unsigned char *a,unsigned char *b) { int result; if(WIFI_BSUBWAY_PollAsync(b,&result) && WIFI_BSUBWAY_AsyncHasError(b)==0) { ((struct Obj22621 *)a)->f0=1; return 1; } return 0; }
