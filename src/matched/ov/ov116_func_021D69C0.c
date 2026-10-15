/*
 * function: WIFI_BSUBWAY_FinishRoomRequest
 * address: 0x021D69C0
 * packet: pkt_ov116_021D69C0
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
#include "../include/Obj13859.h"
extern int WIFI_BSUBWAY_PollAsync(unsigned char *,int *);
typedef unsigned char  u8;
extern int WIFI_BSUBWAY_AsyncHasError(u8 *p);
int WIFI_BSUBWAY_FinishRoomRequest(unsigned char *a,unsigned char *b) { int result; if(WIFI_BSUBWAY_PollAsync(b,&result) && WIFI_BSUBWAY_AsyncHasError(b)==0) { ((struct Obj13859 *)a)->fC=result; ((struct Obj13859 *)a)->f0=1; return 1; } return 0; }
