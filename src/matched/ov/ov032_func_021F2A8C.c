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
#include "../include/Obj00007.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
struct PalAnmSlot;
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_02040588(u32, u32);

extern const u8 d_021F3608[];
extern const u8 d_021F3628[];
extern const u8 d_021F3648[];
extern const u8 d_021F3668[];

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void func_021F2A8C(u8 *p, void *h)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021F3608, 0);
    func_0203FCA0(5, (const struct BgTemplate *)d_021F3628, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F3648, 0);
    func_0203FCA0(7, (const struct BgTemplate *)d_021F3668, 0);
    func_02082A7C(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_020216B4((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), (void *)h, 0x13, ((struct Obj00007 *)p)->f96, 1, 0x1a0, 0);
    func_02021640((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 0x17, 5, ((struct Obj00007 *)p)->f96, 1, 0x20, 0xd0);
    func_02049658((void *)h, 0x14, 7, 0, 0, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x15, 5, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x16, 6, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x17, 7, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_0207D63C(0x04001050, 4, 0x1e, 0xd, 3);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}
