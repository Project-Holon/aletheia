/*
 * function: SCRCMD_PROC_FLD_LoadShopMessages
 * address:  0x021B331C
 * packet:   pkt_ov021_021B331C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 */
#include "../include/Obj00037.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void SCRCMD_PROC_FLD_LoadShopMessages(u8 *w, int b)
{
    if (b == 1) {
        ((struct Obj00037 *)w)->f194 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0xd);
    } else {
        ((struct Obj00037 *)w)->f194 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0xc);
    }
    ((struct Obj00037 *)w)->f1A0 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0xe);
}
