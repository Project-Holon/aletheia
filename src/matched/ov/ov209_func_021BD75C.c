/*
 * function: ZUKAN_LIST_PrintListRow
 * address: 0x021BD75C
 * packet: pkt_ov209_021BD75C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 */
#include "../include/Obj02924.h"
#include "../include/Obj25567.h"
struct Blk37;
struct MsgBank;
struct WordSet;
struct U16Vec;
typedef unsigned short u16;
extern unsigned FRAME_LIST_GetPrinter(char *);
extern unsigned ZUKAN_SAVE_GetViewMode(struct Blk37 *);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void WORDSET_SetSlotNumber(struct WordSet *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void WORDSET_CopyTaggedText(struct WordSet *, void *, void *);
extern void STRBUF_Delete(struct U16Vec *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
void ZUKAN_LIST_PrintListRow(char *p, unsigned char *dest, unsigned text0, unsigned index)
{
    unsigned ps;
    void *text;
    ps = FRAME_LIST_GetPrinter(*(char * *)&((struct Obj02924 *)p)->fC2C);
    if (ZUKAN_SAVE_GetViewMode(*(struct Blk37 * *)&((struct Obj25567 *)(*(char * *)&((struct Obj02924 *)p)->f0))->f4) == 0)
        index = (*(u16 **)(p + 0xc38))[index];
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj02924 *)p)->f3C, 8);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, 0, index, 3, 2, 1);
    WORDSET_CopyTaggedText(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, ((struct Obj02924 *)p)->f44, text);
    STRBUF_Delete(text);
    TOUCHBAR_PrintAligned(dest, (void *)ps, 0, 4, *(unsigned *)&((struct Obj02924 *)p)->f44, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
    TOUCHBAR_PrintAligned(dest, (void *)ps, 28, 4, text0, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
}
