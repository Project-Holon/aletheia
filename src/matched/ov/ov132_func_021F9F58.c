/*
 * function: func_021F9F58
 * address: 0x021F9F58
 * packet: pkt_ov132_021F9F58
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 02051620 reads its input r0 at 02051620; this caller explicitly loads the +0x4804 payload before the call, unlike the legacy argless extern.
 * symbols:
 *   func_02051620 0x02051620 arm
 *   func_02050DB8 0x02050DB8 arm
 */
#include "../include/Obj10536.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02051620(u32);
extern void func_02050DB8(u8 *p);
void func_021F9F58(u8 *unused,u8 *p) { ((struct Obj10536 *)p)->f0=0; func_02051620(((struct Obj10536 *)p)->f4804); func_02050DB8((u8 *)(((struct Obj10536 *)p)->f4804)); }
