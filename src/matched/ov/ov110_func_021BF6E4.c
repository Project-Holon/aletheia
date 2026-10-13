/*
 * function: PMS_INPUT_GetSentenceType
 * address:  0x021BF6E4
 * packet:   pkt_ov110_021BF6E4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_PARAM_GetSentenceType  0x0202452C  thumb
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 PMSI_PARAM_GetSentenceType          -> unresolved: 0202452C (arm, from name) has no witness outside 021BF6E4..021BF6F0
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int PMSI_PARAM_GetSentenceType(const u16 *p);
int PMS_INPUT_GetSentenceType(u8 *p) { return PMSI_PARAM_GetSentenceType((const u16 *)(p + 8)); }
