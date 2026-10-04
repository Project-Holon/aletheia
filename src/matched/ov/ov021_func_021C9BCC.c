/*
 * function: func_021C9BCC
 * address:  0x021C9BCC
 * packet:   pkt_ov021_021C9BCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pushes the kind, the +0x1e and +0x32 blocks and, for kind 2/7, the selected +0x628 entry to the +0x70 object.
 *
 * symbols:
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D868  0x0200D868  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02732.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

struct Blk3C;
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern void func_0200D868(struct Blk3C *p, u32 v);

void func_021C9BCC(u8 *p)
{
    u8 v = p[9];

    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 0, &v);
    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 5, p + 0x1e);
    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 8, p + 0x32);
    func_0200D868((struct Blk3C *)(((struct Obj02732 *)p)->f70), 1);
    if (p[9] == 2 || p[9] == 7) {
        v = ((Sel *)p)->sel;
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 9, &v);
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 6, p + 0x628 + ((Sel *)p)->sel * 0x14);
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 7, p + 0x664 + ((Sel *)p)->sel);
    }
}
