/*
 * function: func_021D9750
 * address: 0x021D9750
 * packet: pkt_ov121_021D9750
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02050B80 0x02050B80 arm
 *   func_021D98F4 0x021D98F4 thumb ov121
 *   d_021DF598 0x021DF598 data a4
 */
#include "../include/Obj13945.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int a,b,c,d; } Config;
extern const Config d_021DF598;
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02050B80(u32 heap);
extern void func_021D98F4(u32 *p, u32 heap);
void func_021D9750(u8 *p)
{
    Config c;
    func_02040588(0,0);
    c=d_021DF598;
    c.d=1;
    func_0203FC28((struct DispConfig *)(&c));
    func_021D98F4((u32 *)(p+12),((struct Obj13945 *)p)->f18);
    func_02050B80(((struct Obj13945 *)p)->f18);
}
