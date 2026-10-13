/*
 * function: func_021D9838
 * address: 0x021D9838
 * packet: pkt_ov129_021D9838
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 */
#include "../include/Obj14057.h"

typedef struct  {
    unsigned words[7];
}
Config;
extern const Config d_020A1448;
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern void func_020434DC(unsigned,unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
void func_021D9838(char *p,unsigned a)  {
    Config c = d_020A1448;
    ((unsigned char *)&c)[8] = 16;
    ((unsigned char *)&c)[9] = 112;
    func_0204A48C((const struct Cfg *)(&c),a,50);
    func_020434DC(16,1);
    ((struct Obj14057 *)p)->f25C=func_0204B100(64,0,50);
    CLACT_SetUnitDefaultRenderer(((struct Obj14057 *)p)->f25C);
}
