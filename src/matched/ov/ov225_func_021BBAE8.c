/*
 * function: MANUAL_CATEGORY_DeleteOption
 * address: 0x021BBAE8
 * packet: pkt_ov225_021BBAE8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MANUAL_COMMON_GetDefaultId 0x021B9CDC thumb ov225
 *   MANUAL_COMMON_SetScreenId 0x021B9E80 thumb ov225
 *   TCB_DeleteTask 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10985.h"
#include "../include/Obj26308.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int MANUAL_COMMON_GetDefaultId(void *);
extern void MANUAL_COMMON_SetScreenId(char *,u32);
struct Node;
extern void TCB_DeleteTask(struct Node *);
extern u32 func_020307B0(void *p);
void MANUAL_CATEGORY_DeleteOption(char *p) { MANUAL_COMMON_SetScreenId(*(char * *)&((struct Obj10985 *)p)->f4,MANUAL_COMMON_GetDefaultId(((struct Obj26308 *)(*(char * *)&((struct Obj10985 *)p)->f4))->f2C)); TCB_DeleteTask(*(struct Node * *)&((struct Obj10985 *)p)->f34); func_020307B0(p); }
