/*
 * function: UNION_COMMAND_SendTrainerCard
 * address:  0x02173BB0
 * packet:   pkt_ov012_02173BB0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */
#include "../include/Obj12446.h"

typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 UNION_COMMAND_SendTrainerCard(unsigned char *p)
{
    if (((struct Obj12446 *)p)->f3540 == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
    }
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x1406, 0x678, ((struct Obj12446 *)p)->f3540, 1, 0, 1);
}
