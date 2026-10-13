/*
 * function: APP_TASKMENU_WIN_Free
 * address:  0x02028164
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_TASKMENU_WIN_Free.c \\
 *       --func APP_TASKMENU_WIN_Free --addr 0x02028164 --thumb --cc 1.1p1
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj15779.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);

void APP_TASKMENU_WIN_Free(u8 *p)
{
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj15779 *)p)->f0));
    func_020307B0(p);
}
