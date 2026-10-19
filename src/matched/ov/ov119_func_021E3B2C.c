/*
 * function: POKETRADE_3D_LoadTexturePalette
 * address: 0x021E3B2C
 * packet: pkt_ov119_021E3B2C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   DC_FlushRange 0x020862F0 arm
 *   func_02083194 0x02083194 arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj10376.h"
#include "../include/Obj22795.h"
#include "../include/Obj22796.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void DC_FlushRange(void *, int);
extern void func_02083194(const void *, void *, int);
extern void func_0207FA0C(void);
extern void func_0207FA40(const void *, int, int);
extern void func_0207FADC(void);
extern void MI_CpuCopy8(const void *, void *, int);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void POKETRADE_3D_LoadTexturePalette(char *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = func_020490F4(0x74, ((struct Obj10376 *)p)->f5F4);
    allocation = ARC_UTIL_LoadPaletteBlockFromHandle(v, 0x48, (u32)(&descriptor), ((struct Obj10376 *)p)->f5F4);
    data = *(char * *)&((struct Obj22795 *)descriptor)->fC;
    DC_FlushRange(data + 32, 32);
    func_02083194(data + 32, data + 34, 30);
    ((struct Obj22796 *)data)->f20 = 0x14A5;
    DC_FlushRange(data + 32, 32);
    func_0207FA0C();
    func_0207FA40(data + 32, 0x2000, 32);
    func_0207FADC();
    MI_CpuCopy8(data + 32, p + 0x1134, 32);
    func_020307B0(allocation);
    ARC_TOOL_DeleteHandle(v);
}
