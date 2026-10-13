/*
 * function: PMSIV_EDIT_ParserInit
 * address: 0x021BC458
 * packet: pkt_ov110_021BC458
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:
 *   PMS_INPUT_GetSentenceString 0x021BF708 thumb ov110
 *   STRBUF_GetChars 0x02045A90 arm
 */
#include "../include/Obj05292.h"
#include "../include/Obj22370.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *PMS_INPUT_GetSentenceString(u8 *,u32);
struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
void PMSIV_EDIT_ParserInit(u8 *p,u8 *a) { ((struct Obj05292 *)p)->f0=PMS_INPUT_GetSentenceString(*(u8 * *)&((struct Obj22370 *)a)->f4,42); *(u16 * *)&((struct Obj05292 *)p)->f4=STRBUF_GetChars(((struct Obj05292 *)p)->f0); if(**(u16 * *)&((struct Obj05292 *)p)->f4==0xF000) ((struct Obj05292 *)p)->f8=1; else ((struct Obj05292 *)p)->f8=0; }
