/*
 * function: BTL_SERVER_FLOW_IsPokeGroundedById
 * address:  0x021C8234
 * packet:   pkt_021C7EC4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_IsPokeGroundedById   0x021C8234  thumb  ov093
 *   BTL_SERVER_FLOW_IsPokeGrounded   0x021C6F0C  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk   0x021B9934  thumb  ov093
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
#include "../include/Obj00003.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_SERVER_FLOW_IsPokeGrounded(u8 *p, u8 *a, int k);

int BTL_SERVER_FLOW_IsPokeGroundedById(u8 *p, int i) { return BTL_SERVER_FLOW_IsPokeGrounded(p, BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }

