/*
 * function: PMSIV_EDIT_ParserFree
 * address:  0x021BC484
 * packet:   pkt_ov110_021BC484
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm  arm9
 */
#include "../include/Obj22372.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void PMSIV_EDIT_ParserFree(u8 *p) { STRBUF_Delete((struct U16Vec *)(((struct Obj22372 *)p)->f0)); }
