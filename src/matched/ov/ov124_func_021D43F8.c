/*
 * function: func_021D43F8
 * address: 0x021D43F8
 * packet: pkt_ov124_021D43F8
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display read-modify-writes 021D440E/021D4416, 021D4418/021D441C; POWCNT1 021D443E/021D4444.
 * symbols:
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D4534 0x021D4534 thumb ov124
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   d_021D4CC4 0x021D4CC4 data a4
 *   d_021D4BF4 0x021D4BF4 data a4
 *   d_021D4C44 0x021D4C44 data a4
 *   d_021D4C64 0x021D4C64 data a4
 *   d_021D4C84 0x021D4C84 data a4
 *   d_021D4C24 0x021D4C24 data a4
 *   d_020A1448 0x020A1448 data a4
 */
#include "../include/Obj00068.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b; u8 c, d, e, f; u32 g; u16 h, i, j, k, l, m; } Config;
extern const Config d_020A1448;
extern const u32 d_021D4CC4[], d_021D4BF4[], d_021D4C44[], d_021D4C64[], d_021D4C84[], d_021D4C24[];
extern void func_0204361C(void), func_020434CC(void), func_02043588(void);
extern void func_0202223C(u32, u32);
extern u32 func_02022224(void *);
struct Cfg;
struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16), func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
struct BgTemplate;
extern void func_021D4534(const struct BgTemplate *p, int layer, int type);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_02043598(u32, u32);
static inline void visible(int plane)
{
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00) | (plane << 8);
}
static inline void subvisible(int plane)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | (plane << 8);
}
void func_021D43F8(char *p)
{
    Config cfg;
    func_0204361C();
    func_020434CC();
    func_02043588();
    visible(0);
    subvisible(0);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_02022224(0);
    func_02022224((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_020433E0((const struct DispVram *)d_021D4CC4);
    func_0203F8F4(((struct Obj00068 *)p)->f0);
    func_02045088(((struct Obj00068 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021D4BF4);
    func_021D4534((const struct BgTemplate *)d_021D4C44, 4, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C64, 5, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C84, 6, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C24, 7, 0);
    func_0207D63C(0x04001050, 4, 8, 15, 4);
    cfg = d_020A1448;
    cfg.h = 0x40;
    func_0204A48C((const struct Cfg *)(&cfg), (u32)d_021D4CC4, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f4C = func_0204B100(0x30, 0, ((struct Obj00068 *)p)->f0);
    func_0204B270(((struct Obj00068 *)p)->f4C);
    func_02043598(0x10, 1);
}
