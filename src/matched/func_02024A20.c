/*
 * function: func_02024A20
 * address:  0x02024A20
 * packet:   pkt_02024A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     infowin constructor.  The heap id is u16: as u32 mwcc reuses r3
 *           for the allocator call instead of reloading the spilled home
 *           (17 bytes).  Found by tools/permuter.py --types.
 *
 * symbols:
 *   func_02030734       0x02030734  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   func_020251FC       0x020251FC  thumb
 *   func_020056A0       0x020056A0  thumb
 *   func_0203568C       0x0203568C  arm
 *   func_0201283C       0x0201283C  thumb
 *   func_02012BB0       0x02012BB0  thumb
 *   func_02024ABC       0x02024ABC  thumb
 *   func_02024DFC       0x02024DFC  thumb
 *   gInfoWin            0x0214693C  data
 *   infowin_File        0x020A7478  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
    u8  pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u8  f1C;
    u8  f1D;
    u8  f1E;
    u8  f1F;
    u32 f20;
    void *f24;
};

extern struct InfoWin *gInfoWin;
extern const char infowin_File[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  func_020251FC(u32 a, u32 b, u32 heap);
extern void *func_020056A0(void (*cb)(void *), void *work, u32 pri);
extern u8    func_0203568C(void);
extern u32   func_0201283C(void *p);
extern u32   func_02012BB0(void *p);
extern void  func_02024ABC(void);
extern void  func_02024DFC(void *work);

void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap)
{
    gInfoWin = func_02030734(heap, 0x28, 0, infowin_File, 0x103);
    MI_CpuFill8(gInfoWin, 0, 0x28);
    gInfoWin->f06 = a0;
    gInfoWin->f07 = a1;
    func_020251FC(a0, a1, heap);
    gInfoWin->f24 = func_020056A0(func_02024DFC, gInfoWin, 1);
    gInfoWin->f20 = 0;
    gInfoWin->f1F = func_0203568C();
    if (a2 != 0) {
        gInfoWin->f0C = func_0201283C(a2);
        gInfoWin->f10 = func_02012BB0(a2);
    } else {
        gInfoWin->f0C = 0;
        gInfoWin->f10 = 0;
    }
    gInfoWin->f08 = 0;
    func_02024ABC();
    gInfoWin->f04 = 0x3f;
}
