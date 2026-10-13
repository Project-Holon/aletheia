/*
 * function: BTL_SERVER_FLOW_ReleaseBindingTargetById
 * address:  0x021C8494
 * packet:   pkt_021C7EC4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_ReleaseBindingTargetById   0x021C8494  thumb  ov093
 *   BTL_SERVER_FLOW_ReleaseBindingTarget   0x021BFF60  thumb  ov093
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
extern void BTL_SERVER_FLOW_ReleaseBindingTarget(u8 *p, u8 *a, int z);

void BTL_SERVER_FLOW_ReleaseBindingTargetById(u8 *p, int i) { BTL_SERVER_FLOW_ReleaseBindingTarget(p, BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }

