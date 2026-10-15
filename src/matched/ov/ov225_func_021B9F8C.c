/*
 * function: MANUAL_COMMON_DeleteTouchbar
 * address: 0x021B9F8C
 * packet: pkt_ov225_021B9F8C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02030EAC 0x02030EAC arm
 *   MANUAL_COMMON_DeleteTouchbarActors 0x021BA4D8 thumb ov225
 *   MANUAL_COMMON_DeleteTouchbarSlots 0x021BA218 thumb ov225
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../include/Obj14802.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void MANUAL_COMMON_DeleteTouchbarActors(char *);
extern void MANUAL_COMMON_DeleteTouchbarSlots(char *);
extern void TOUCHBAR_Delete(unsigned char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern const char ov067_id[];
void MANUAL_COMMON_DeleteTouchbar(char *p){func_02030EAC(((struct Obj14802 *)p)->f48);MANUAL_COMMON_DeleteTouchbarActors(p);MANUAL_COMMON_DeleteTouchbarSlots(p);TOUCHBAR_Delete(*(unsigned char * *)&((struct Obj14802 *)p)->f4);func_020307B0(p);func_02034A5C((int)ov067_id);}
