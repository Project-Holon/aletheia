/*
 * function: func_0220D370
 * address: 0x0220D370
 * packet: pkt_ov197_0220D370
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_0202173C 0x0202173C thumb
 */
#include "../include/Obj25089.h"
typedef unsigned short u16;typedef unsigned char u8;typedef short s16;typedef struct PalAnmObj PalAnmObj;
extern void *func_021F86D4(void);
extern int func_0202173C(PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
int func_0220D370(char *p){func_0202173C(*(PalAnmObj * *)&((struct Obj25089 *)p)->f8,10,65535,0,0,16,0,func_021F86D4());return 19;}
