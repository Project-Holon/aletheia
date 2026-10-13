/*
 * function: func_021DEBA0
 * address:  0x021DEBA0
 * packet:   pkt_ov119_021DEBA0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DEB34  0x021DEB34  thumb  ov119
 */
#include "../include/Obj10363.h"

typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_021DEB34(void *p);

void func_021DEBA0(char *p)
{
    MSGDATA_ReadString(((struct Obj10363 *)p)->f720, 0x91, ((struct Obj10363 *)p)->f738);
    func_021E1024(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DEB34);
}
