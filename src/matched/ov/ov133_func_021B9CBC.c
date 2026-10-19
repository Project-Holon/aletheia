/*
 * function: DUP_FITTING_SetTextItem
 * address: 0x021B9CBC
 * packet: pkt_ov133_021B9CBC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetActorPoolResource 0x021F4F10 thumb ov112
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   MUSICAL_MCSS_GetElemC 0x021F5158 thumb ov112
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   DUP_FITTING_SetText 0x021B9C08 thumb ov133
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 */
#include "../include/Obj00004.h"
#include "../include/Obj14153.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int MUSICAL_MCSS_GetActorPoolResource(u8 *p);
extern unsigned int DUP_FITTING_ITEM_ElemGetData(u8 *p);
extern u8 MUSICAL_MCSS_GetElemC(void *, int);
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void DUP_FITTING_SetText(u8 *, unsigned int, void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
void DUP_FITTING_SetTextItem(u8 *p, u8 *entry)
{
    void *manager = (void *)MUSICAL_MCSS_GetActorPoolResource(*(u8 * *)&((struct Obj00004 *)p)->f1884);
    u8 *data = (u8 *)DUP_FITTING_ITEM_ElemGetData(entry);
    int index = MUSICAL_MCSS_GetElemC(manager, ((struct Obj14153 *)data)->f0);
    void *obj = WORDSET_CreateDefault(((struct Obj00004 *)p)->f0);
    void *a = func_02045EC0(((struct Obj00004 *)p)->f18DC, ((struct Obj14153 *)data)->f0 + 3);
    void *b = func_02045EC0(((struct Obj00004 *)p)->f18E0, index + 16);
    WORDSET_SetSlotTag(obj, 0, a, 0, 1, 2);
    WORDSET_SetSlotTag(obj, 1, b, 0, 1, 2);
    DUP_FITTING_SetText(p, 3, obj);
    STRBUF_Delete(b);
    STRBUF_Delete(a);
    WORDSET_Delete(obj);
}
