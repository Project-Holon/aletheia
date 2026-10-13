/*
 * function: PMS_INPUT_HasInitialSentence
 * address:  0x021BF7C4
 * packet:   pkt_ov110_021BF7C4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_PARAM_HasInitialSentence  0x02024158  thumb
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 PMSI_PARAM_HasInitialSentence          -> unresolved: 02024158 (arm, from name) has no witness outside 021BF7C4..021BF7D0
 */
#include "../include/Obj22393.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 PMSI_PARAM_HasInitialSentence(const u8 *p);
u32 PMS_INPUT_HasInitialSentence(u8 *p) { return PMSI_PARAM_HasInitialSentence((const u8 *)(((struct Obj22393 *)p)->f0)); }
