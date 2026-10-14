/*
 * function: TR_AI_GetChosenMove
 * address:  0x02188134
 * packet:   pkt_ov096_02188134
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetUserData  0x02011324  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 *VM_GetUserData(u8 *);
u8 TR_AI_GetChosenMove(u8 *p) { return VM_GetUserData(p)[0x46]; }
