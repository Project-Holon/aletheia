/*
 * function: func_021D8C5C
 * address: 0x021D8C5C
 * packet: pkt_ov129_021D8C5C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021D9760 0x021D9760 thumb ov129
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   func_021D8FA0 0x021D8FA0 thumb ov129
 */
#include "../include/Obj00361.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern unsigned WIPE_SYS_EndCheck(void);
extern void func_021D9760(char *);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void func_021D8FA0(char *);
int func_021D8C5C(char *p) {if(((struct Obj00361 *)p)->f234==0){if(WIPE_SYS_EndCheck()==1)((struct Obj00361 *)p)->f234+=1;}else {func_021D9760(p);BUTTON_MAN_UpdateSlots(((struct Obj00361 *)p)->f294);func_021D8FA0(p);}return 0;}
