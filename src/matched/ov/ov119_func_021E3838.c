/*
 * function: func_021E3838
 * address: 0x021E3838
 * packet: pkt_ov119_021E3838
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207F7A0 0x0207F7A0 arm
 *   func_02030734 0x02030734 arm
 *   d_021E81C0 0x021E81C0 data ov119 a4
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E380C 0x021E380C thumb ov119
 *   func_021E37D8 0x021E37D8 thumb ov119
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207F7FC 0x0207F7FC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207F9B4 0x0207F9B4 arm
 *   func_021E3B2C 0x021E3B2C thumb ov119
 */
#include "../include/Obj10376.h"
extern void func_0207F7A0(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021E81C0[];
extern void MI_CpuFill8(void *, int, int);
extern void func_021E380C(u16 *p, unsigned char *src, int a2);
typedef unsigned char  u8;
extern void func_021E37D8(u16 *p, u8 *src, int k, int a3);
extern void DWCi_ScreenDC_FlushRange(void *, int);
extern void func_0207F7FC(void *, int, int);
extern u32 func_020307B0(void *p);
extern void func_0207F9B4(void);
extern void func_021E3B2C(char *);
void func_021E3838(char *p, int count)
{
    char *v;
    int i;
    func_0207F7A0();
    v = func_02030734(((struct Obj10376 *)p)->f5F4, 0x200, 1, d_021E81C0, 0x510);
    for (i = 0; i < count; i++) {
        MI_CpuFill8(v, 0, 0x200);
        if (i == 0)
            func_021E380C((u16 *)v, (unsigned char *)(p + 0x5B6), 2);
        else
            func_021E37D8((u16 *)v, (u8 *)(p + 0x2E6), i - 1, 2);
        DWCi_ScreenDC_FlushRange(v, 0x200);
        func_0207F7FC(v, i * 0x200 + 0x3000, 0x200);
    }
    func_020307B0(v);
    func_0207F9B4();
    func_021E3B2C(p);
}
