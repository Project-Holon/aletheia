/*
 * function: P_STA_SUB_HideSprite
 * address:  0x021D6D04
 * packet:   pkt_021D6D04
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   P_STA_SUB_DeleteMcss  0x021D797C  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23137.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void P_STA_SUB_DeleteMcss(u8 *p, void **q);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void P_STA_SUB_HideSprite(void *a, u8 *p)
{
    P_STA_SUB_DeleteMcss(a, (void **)p);
    func_0204B3DC(((struct Obj23137 *)p)->f20, 0);
}
