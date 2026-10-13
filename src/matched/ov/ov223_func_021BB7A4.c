/*
 * function: func_021BB7A4
 * address: 0x021BB7A4
 * packet: pkt_ov223_021BB7A4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC708 0x021BC708 data a1
 */
#include "../include/Obj06727.h"
#include "../include/Obj26099.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern int func_02061CA4(void *, unsigned, unsigned, int);
extern const u8 d_021BC708[];
void func_021BB7A4(char *p)
{
    void *object = func_020490F4(205, ((struct Obj06727 *)p)->f0);
    u8 i;
    for (i = 0; i < 4; i++) {
        char *out;
        void *buffer = ARC_UTIL_LoadPaletteBlockFromHandle(object, d_021BC708[i], (u32)(&out), ((struct Obj06727 *)p)->f0);
        MI_CpuCopy8(*(char * *)&((struct Obj26099 *)out)->fC + 256, p + 0x26A + i * 256, 256);
        func_020307B0(buffer);
    }
    ARC_TOOL_DeleteHandle(object);
    ((struct Obj06727 *)p)->f86C = 0;
    ((struct Obj06727 *)p)->f870 = 16;
    ((struct Obj06727 *)p)->f871 = 3;
    MI_CpuCopy8(p + 0x56A, p + 0x76A, 256);
    func_02061CA4((void *)31, 256, (unsigned)(p + 0x76A), 256);
}
