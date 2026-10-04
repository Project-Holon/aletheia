/*
 * function: func_021DE950
 * address:  0x021DE950
 * packet:   pkt_ov119_021DE950
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021E1030  0x021E1030  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DE918  0x021DE918  thumb  ov119
 */
#include "../include/Obj10362.h"

typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *p);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *p, int next);
extern void func_021DE918(void *p);

void func_021DE950(char *p)
{
    func_02045CAC(((struct Obj10362 *)p)->f720, 0x88, ((struct Obj10362 *)p)->f738);
    func_021E1024(p);
    func_021E1030(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DE918);
}
