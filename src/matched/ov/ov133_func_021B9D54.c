/*
 * function: DUP_FITTING_SetTextHelp
 * address: 0x021B9D54
 * packet: pkt_ov133_021B9D54
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_SetText 0x021B9C08 thumb ov133
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb  arm9
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void DUP_FITTING_SetText(u8 *p, unsigned int index, void *object);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
void DUP_FITTING_SetTextHelp(u8 *p, int state)
{
    int index;
    void *w;
    void *str;
    if (state == 8) {
        DUP_FITTING_SetText(p, 5, 0);
        return;
    }
    index = 0;
    switch (state) {
    case 0:
    case 1: index = 0x10; break;
    case 2: index = 0x11; break;
    case 3: index = 0x17; break;
    case 4: index = 0x14; break;
    case 5: index = 0x15; break;
    case 6:
    case 7: index = 0x16; break;
    }
    w = WORDSET_CreateDefault(((struct Obj00004 *)p)->f0);
    str = func_02045EC0(((struct Obj00004 *)p)->f18E0, index);
    WORDSET_SetSlotTag(w, 0, str, 0, 1, 2);
    DUP_FITTING_SetText(p, 4, w);
    STRBUF_Delete(str);
    WORDSET_DeleteStrbufED04(w);
}
