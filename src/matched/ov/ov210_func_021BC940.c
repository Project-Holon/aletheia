/*
 * function: ZKNSEARCH_MAIN_InitTextSystem
 * address: 0x021BC940
 * packet: pkt_ov210_021BC940
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj06693.h"
typedef unsigned int u32;
struct MsgBank;
struct GfFont;
struct WordSet;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern struct GfFont *GF_FONT_Create(int, int, int, int, u32);
extern struct WordSet *WORDSET_CreateDefault(u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct U16Vec *STRBUF_Create(u32, u32);
void ZKNSEARCH_MAIN_InitTextSystem(char *p)
{
    *(struct MsgBank * *)&((struct Obj06693 *)p)->f1D0 = func_02045B38(0, 2, 277, 123);
    *(struct GfFont * *)&((struct Obj06693 *)p)->f1CC = GF_FONT_Create(23, 0, 0, 0, 123);
    *(struct WordSet * *)&((struct Obj06693 *)p)->f1D4 = WORDSET_CreateDefault(123);
    ((struct Obj06693 *)p)->f1DC = PRINTSYS_QUE_Create((void *)123);
    *(struct U16Vec * *)&((struct Obj06693 *)p)->f1D8 = STRBUF_Create(128, 123);
}
