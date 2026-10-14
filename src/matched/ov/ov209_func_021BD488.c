/*
 * function: ZUKAN_LIST_PrintTouchbarLabelClone
 * address: 0x021BD488
 * packet: pkt_ov209_021BD488
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD4DA two-byte alignment padding before existing labelled 021BD4DC.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201F250 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 */
#include "../include/Obj00123.h"
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void STRBUF_Delete(struct U16Vec *);
extern void func_0201F250(struct WordSet *, void *, void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
void ZUKAN_LIST_PrintTouchbarLabelClone(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00123 *)p)->f3C, msg);
    func_0201F250(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, ((struct Obj00123 *)p)->f44, text);
    TOUCHBAR_PrintAligned((unsigned char *)(p + 32 + index * 8), (void *)(((struct Obj00123 *)p)->f48), x, y, *(unsigned *)&((struct Obj00123 *)p)->f44, *(unsigned *)&((struct Obj00123 *)p)->f38, color, mode);
    STRBUF_Delete(text);
}
