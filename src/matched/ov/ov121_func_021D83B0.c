/*
 * function: MYSTERY_PollCardMenu
 * address: 0x021D83B0
 * packet: pkt_ov121_021D83B0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_UTIL_SetVoice 0x021DA6D0 thumb ov121
 *   MYSTERY_RotateActors 0x021D6C84 thumb ov121
 */
#include "../include/Obj00326.h"
extern int MYSTERY_UTIL_SetVoice(unsigned char *);
typedef unsigned char  u8;
extern void MYSTERY_RotateActors(u8 *p);
int MYSTERY_PollCardMenu(char *p) {
 int n=MYSTERY_UTIL_SetVoice(*(unsigned char * *)&((struct Obj00326 *)p)->f270);
 MYSTERY_RotateActors((u8 *)(p+0x294));
 return n;
}
