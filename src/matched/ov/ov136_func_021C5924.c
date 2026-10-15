/*
 * function: MB_SEQ_CreateMessageResources
 * address:  0x021C5924
 * packet:   pkt_ov136_021C5924
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_CreateMessageResources 0x021C5924 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj10600.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void MB_SEQ_CreateMessageResources(u8 *p)
{
    ((struct Obj10600 *)p)->f1D0 = func_02045B38(0, 2, 0x3b, 0x66);
    ((struct Obj10600 *)p)->f1D4 = WORDSET_CreateDefault(0x66);
    ((struct Obj10600 *)p)->f1D8 = STRBUF_Create(0x400, 0x66);
}
