/*
 * function: func_021BD064
 * address: 0x021BD064
 * packet: pkt_ov210_021BD064
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware stores at 0x021BD0D8 and 0x021BD0DC.
 * symbols:
 *   func_021BCE58 0x021BCE58 thumb ov210
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   func_021BC330 0x021BC330 thumb ov210
 *   func_021BC2AC 0x021BC2AC thumb ov210
 *   func_021BC92C 0x021BC92C thumb ov210
 *   func_021BCC1C 0x021BCC1C thumb ov210
 *   func_021BCA78 0x021BCA78 thumb ov210
 *   func_021BC800 0x021BC800 thumb ov210
 *   func_021BCA10 0x021BCA10 thumb ov210
 *   func_021BED54 0x021BED54 thumb ov210
 *   func_021BE3B4 0x021BE3B4 thumb ov210
 *   func_021BC99C 0x021BC99C thumb ov210
 *   func_021BC578 0x021BC578 thumb ov210
 *   func_0207D534 0x0207D534 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj00085.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021BCE58(char *);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern u32 func_021BC330(u8 *p);
extern u32 func_021BC2AC(u8 *p);
extern void func_021BC92C(u32);
extern u32 func_021BCC1C(u8 *);
extern void func_021BCA78(u8 *p);
extern void func_021BC800(u8 *p);
extern u32 func_021BCA10(u8 *);
extern void func_021BED54(int p);
extern void func_021BE3B4(char *);
extern u32 func_021BC99C(u8 *p);
extern void func_021BC578(u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void func_02034A5C(int);
extern const char ov067_id[];
int func_021BD064(char *p)
{
    if (func_021BCE58(p) == 1 || PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00085 *)p)->fC) != 0) return 1;
    func_021BC330((u8 *)p);
    func_021BC92C(func_021BC2AC((u8 *)p));
    func_021BCC1C((u8 *)p);
    func_021BCA78((u8 *)p);
    func_021BC800((u8 *)p);
    func_021BCA10((u8 *)p);
    func_021BED54((int)p);
    func_021BE3B4(p);
    func_021BC578(func_021BC99C((u8 *)p));
    func_0207D534((void *)0x0400006c, -16);
    func_0207D534((void *)0x0400106c, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return 27;
}
