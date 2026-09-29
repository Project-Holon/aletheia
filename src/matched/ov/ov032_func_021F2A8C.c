/*
 * function: func_021F2A8C
 * address:  0x021F2A8C
 * packet:   pkt_ov032_021F2A8C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021F2ACE ldr / 0x021F2AD6 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F2ADC strh to 0x04001050 (hardware registers)
 *
 * symbols:
 *   func_021F2A8C  0x021F2A8C  thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020216B4  0x020216B4  thumb
 *   func_02021640  0x02021640  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021F3608     0x021F3608  data  ov032  a4
 *   d_021F3628     0x021F3628  data  ov032  a4
 *   d_021F3648     0x021F3648  data  ov032  a4
 *   d_021F3668     0x021F3668  data  ov032  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203FCA0(u32 bgId, const void *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_020216B4(u32 a, u32 h, u32 b, u32 heap, u32 c, u32 d, u32 e);
extern void func_02021640(u32 a, u32 b, u32 c, u32 heap, u32 d, u32 e, u32 f);
extern void func_02049658(u32 p, int a, int b, int c, int d, int e, int f);
extern void func_020498F4(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_02040588(u32, u32);

extern const u8 d_021F3608[];
extern const u8 d_021F3628[];
extern const u8 d_021F3648[];
extern const u8 d_021F3668[];

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void func_021F2A8C(u8 *p, u32 h)
{
    func_0203FCA0(4, d_021F3608, 0);
    func_0203FCA0(5, d_021F3628, 0);
    func_0203FCA0(6, d_021F3648, 0);
    func_0203FCA0(7, d_021F3668, 0);
    func_02082A7C(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_020216B4(*(u32 *)(p + 0xac), h, 0x13, *(u16 *)(p + 0x96), 1, 0x1a0, 0);
    func_02021640(*(u32 *)(p + 0xac), 0x17, 5, *(u16 *)(p + 0x96), 1, 0x20, 0xd0);
    func_02049658(h, 0x14, 7, 0, 0, 1, *(u16 *)(p + 0x96));
    func_020498F4(h, 0x15, 5, 0, 0x800, 1, *(u16 *)(p + 0x96));
    func_020498F4(h, 0x16, 6, 0, 0x800, 1, *(u16 *)(p + 0x96));
    func_020498F4(h, 0x17, 7, 0, 0x800, 1, *(u16 *)(p + 0x96));
    func_0207D63C(0x04001050, 4, 0x1e, 0xd, 3);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}
