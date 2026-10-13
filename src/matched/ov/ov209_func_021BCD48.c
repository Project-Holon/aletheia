/*
 * function: func_021BCD48
 * address: 0x021BCD48
 * packet: pkt_ov209_021BCD48
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCDB6, 021BCDBA
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BC91C 0x021BC91C thumb ov209
 *   func_021BC2FC 0x021BC2FC thumb ov209
 *   func_021BC2B0 0x021BC2B0 thumb ov209
 *   func_021BC810 0x021BC810 thumb ov209
 *   func_021BCB60 0x021BCB60 thumb ov209
 *   func_021BC8A4 0x021BC8A4 thumb ov209
 *   func_021BD824 0x021BD824 thumb ov209
 *   func_021BD3E0 0x021BD3E0 thumb ov209
 *   func_021BC868 0x021BC868 thumb ov209
 *   func_021BC52C 0x021BC52C thumb ov209
 *   func_021BC704 0x021BC704 thumb ov209
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 */
#include "../include/Obj00088.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char ov067_id[];
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern void func_02034A5C(int);
extern int func_021BC91C(char *);
extern void func_021BC810(void);
extern void func_021BC52C(void);
extern void func_021BC2FC(char *);
extern void func_021BC2B0(char *);
extern void func_021BCB60(char *);
extern void func_021BC8A4(char *);
extern void func_021BD824(char *);
extern void func_021BD3E0(char *);
extern void func_021BC868(char *);
extern void func_021BC704(char *);
int func_021BCD48(char *p)
{
    if (func_021BC91C(p) == 1 || PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) != 0) return 1;
    func_021BC2FC(p);
    func_021BC2B0(p);
    func_021BC810();
    func_021BCB60(p);
    func_021BC8A4(p);
    func_021BD824(p);
    func_021BD3E0(p);
    func_021BC868(p);
    func_021BC52C();
    func_021BC704(p);
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return 9;
}
