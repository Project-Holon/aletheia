/*
 * function: ZUKAN_LIST_PrintTouchbarLabel
 * address: 0x021BD440
 * packet: pkt_ov209_021BD440
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD486 two-byte alignment padding before 021BD488.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 */
#include "../include/Obj00123.h"
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void STRBUF_Delete(struct U16Vec *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
void ZUKAN_LIST_PrintTouchbarLabel(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00123 *)p)->f3C, msg);
    TOUCHBAR_PrintAligned((unsigned char *)(p + 32 + index * 8), (void *)(((struct Obj00123 *)p)->f48), x, y, (unsigned)text, *(unsigned *)&((struct Obj00123 *)p)->f38, color, mode);
    STRBUF_Delete(text);
}
