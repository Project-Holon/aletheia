/*
 * function: func_02205580
 * address: 0x02205580
 * packet: pkt_ov195_02205580
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   YESNO_MENU_Delete 0x021B709C thumb ov067
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj04595.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
extern void YESNO_MENU_Delete(u8 *);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void func_02205580(void *unused,char *p) {YESNO_MENU_Delete(*(u8 * *)&((struct Obj04595 *)p)->f9C);*(u32 *)&((struct Obj04595 *)p)->f9C=0;if(((struct Obj04595 *)p)->f94)STRBUF_Delete((struct U16Vec *)(((struct Obj04595 *)p)->f94));if(((struct Obj04595 *)p)->f98)STRBUF_Delete((struct U16Vec *)(((struct Obj04595 *)p)->f98));MSGDATA_Delete(*(struct Rec * *)&((struct Obj04595 *)p)->f90);}
