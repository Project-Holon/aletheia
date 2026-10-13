/*
 * function: func_0220CBE8
 * address: 0x0220CBE8
 * packet: pkt_ov197_0220CBE8
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj10835.h"
#include "../include/Obj25066.h"
#include "../include/Obj25067.h"
#include "../include/Obj25068.h"
extern unsigned WIPE_SYS_EndCheck(void);
int func_0220CBE8(char *p){if(WIPE_SYS_EndCheck()==1){if(((struct Obj25066 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==2)return 17;if(((struct Obj25067 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==1)return 5;if(((struct Obj25068 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==3)return 5;return 4;}return 3;}
