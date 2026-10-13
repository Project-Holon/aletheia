/*
 * function: func_021BC940
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
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
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
extern struct WordSet *func_0201EC64(u32);
extern u32 func_0201C440(void *);
extern struct U16Vec *STRBUF_Create(u32, u32);
void func_021BC940(char *p)
{
    *(struct MsgBank * *)&((struct Obj06693 *)p)->f1D0 = func_02045B38(0, 2, 277, 123);
    *(struct GfFont * *)&((struct Obj06693 *)p)->f1CC = GF_FONT_Create(23, 0, 0, 0, 123);
    *(struct WordSet * *)&((struct Obj06693 *)p)->f1D4 = func_0201EC64(123);
    ((struct Obj06693 *)p)->f1DC = func_0201C440((void *)123);
    *(struct U16Vec * *)&((struct Obj06693 *)p)->f1D8 = STRBUF_Create(128, 123);
}
