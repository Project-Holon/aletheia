/*
 * function: func_021D9F08
 * address:  0x021D9F08
 * packet:   pkt_021D9F08
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_021D9F24  0x021D9F24  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00236.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D9F24(u8 *p, int mode);

void func_021D9F08(u8 *a, int b, int c, int d)
{
    func_02045CAC((struct MsgBank *)b, c, ((struct Obj00236 *)a)->f14);
    func_021D9F24(a, d);
}
