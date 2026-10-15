/*
 * function: HALL_OF_FAME_InitText
 * address: 0x021B6418
 * packet: pkt_ov180_021B6418
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj02515.h"
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap); extern void *STRBUF_Create(unsigned,unsigned);
void HALL_OF_FAME_InitText(char *p) {
 ((struct Obj02515 *)p)->f9038=func_02045B38(0,2,32,141);
 ((struct Obj02515 *)p)->f9030=GF_FONT_Create(23,0,0,0,141);
 ((struct Obj02515 *)p)->f9034=GF_FONT_Create(23,3,0,0,141);
 ((struct Obj02515 *)p)->f903C=WORDSET_CreateDefault(141);
 ((struct Obj02515 *)p)->f9040=STRBUF_Create(1024,141);
}
