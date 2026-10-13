/*
 * function: func_021B9B04
 * address: 0x021B9B04
 * packet: pkt_ov205_021B9B04
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DFC 0x02008DFC thumb
 *   FIELD_CLOCK_SaveTimestamp 0x02169120 thumb ov010
 */
#include "../include/Obj14633.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub02008C20Obj;extern void *GAME_DATA_GetTrainerRecord(int *);extern u32 func_02008DFC(struct Sub02008C20Obj *,int);extern void FIELD_CLOCK_SaveTimestamp(void *);
void func_021B9B04(char *p) { if(func_02008DFC(GAME_DATA_GetTrainerRecord(*(int * *)&((struct Obj14633 *)p)->f4),71)==0)FIELD_CLOCK_SaveTimestamp(*(char * *)&((struct Obj14633 *)p)->f4); }
