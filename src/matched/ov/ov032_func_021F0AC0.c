/*
 * function: func_021F0AC0
 * address:  0x021F0AC0
 * packet:   pkt_ov032_021F0AC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0AC0  0x021F0AC0  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   func_021F0A98  0x021F0A98  thumb  ov032
 *   func_021F201C  0x021F201C  thumb  ov032
 */
#include "../include/Obj00007.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct WordSet;
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_021F0A98(char *p, unsigned a);
extern void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7);

void func_021F0AC0(char *p)
{
    WORDSET_SetSlotNumber((struct WordSet *)(*(int *)&((struct Obj00007 *)p)->f110), 0, ((struct Obj00007 *)p)->f7B, 2, 1, 1);
    func_021F0A98(p, 0);
    func_021F201C(p, p + 0x110 + 0x94, (void *)(*(int *)&((struct Obj00007 *)p)->f11C), 4, 0, 1, 0x3DC1, 0);
}
