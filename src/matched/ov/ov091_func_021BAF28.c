/*
 * function: PLIST_PLATE_DrawEgg
 * address:  0x021BAF28
 * packet:   pkt_ov091_021BAF28
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   gSpeciesNameBank     0x020A7370  data
 *   func_02045EC0  0x02045EC0  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   POKELIST_PrintExpandedTextMain  0x021B9CF4  thumb  ov091
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
#include "../include/Obj03183.h"
#include "../include/Obj06211.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct MsgBank;
struct Obj;
struct U16Vec;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *gSpeciesNameBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void POKELIST_PrintExpandedTextMain(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void PLIST_PLATE_DrawEgg(u8 *a, u8 *s)
{
    u32 r6;
    u32 r7;

    r6 = (u32)WORDSET_CreateDefault(((struct Obj06211 *)a)->f0);
    r7 = (u32)func_02045EC0(gSpeciesNameBank, 0x28a);
    WORDSET_SetSlotTag((struct WordSet *)r6, 0, (const void *)r7, 0, 1, 2);
    POKELIST_PrintExpandedTextMain(a, ((struct Obj03183 *)s)->f20, (void *)r6, 3, 0x29, 9, 0x440);
    STRBUF_Delete((struct U16Vec *)r7);
    WORDSET_Delete((struct WordSet *)r6);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03183 *)s)->f38, 0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj03183 *)s)->f30), 1);
    ((struct Obj03183 *)s)->f18 = 1;
}
