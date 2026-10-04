/*
 * function: func_021B9928
 * address:  0x021B9928
 * packet:   pkt_ov088_021B9928
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B99E0  0x021B99E0  thumb  ov088
 *   func_021B9BD4  0x021B9BD4  thumb  ov088
 *   func_021B9DD0  0x021B9DD0  thumb  ov088
 *   func_021B9F68  0x021B9F68  thumb  ov088
 */
#include "../include/Obj07719.h"

extern void func_021B99E0(void *, unsigned short);
extern void func_021B9BD4(void *, unsigned short);
extern void func_021B9DD0(void *, unsigned short);
extern void func_021B9F68(void *, unsigned short);

void func_021B9928(unsigned char *p)
{
    func_021B99E0(p + 0x08, ((struct Obj07719 *)p)->f2);
    func_021B9BD4(p + 0x14, ((struct Obj07719 *)p)->f2);
    func_021B9DD0(p + 0x40, ((struct Obj07719 *)p)->f2);
    func_021B9F68(p + 0x54, ((struct Obj07719 *)p)->f2);
}
