/*
 * function: func_021C5FEC
 * address:  0x021C5FEC
 * packet:   pkt_ov021_021C5FEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Switches the window to mode 2 and opens the message box.
 *
 * symbols:
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021AE01C  0x021AE01C  thumb  ov021
 */
#include "../include/Obj06080.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_02188CD0(u8 *p);
extern void func_0216D674(u32 a, u32 b);
extern u32 func_021BB528(u32 a, u32 b, u32 c, u32 d);
typedef unsigned short u16;
extern void func_021AE01C(u32 a, u16 v);

void func_021C5FEC(u8 *p)
{
    u32 o = func_02188CD0((u8 *)(((struct Obj06080 *)p)->f8));

    func_0216D674(((struct Obj06080 *)p)->f1C, 2);
    ((struct Obj06080 *)p)->f2C = func_021BB528(o, ((struct Obj06080 *)p)->f1C, 0, 1);
    func_021AE01C(((struct Obj06080 *)p)->f30, 1);
}
