/*
 * function: func_021D68EC
 * address: 0x021D68EC
 * packet: pkt_ov125_021D68EC
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D730C 0x021D730C thumb ov125
 *   d_021D8D28 0x021D8D28 data a4
 *   d_021D8C80 0x021D8C80 data a2
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
#include "../include/Obj03806.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int   u32;
extern int func_021D730C(char *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *, int, unsigned int);
extern const char d_021D8D28[];
extern const u16 d_021D8C80[][2];
int func_021D68EC(char *p, int id, unsigned int index, int mode, u8 other)
{
    if (!func_021D730C(p)) return 0;
    if (index >= 20) func_02034714(d_021D8D28, 0, d_021D8D28);
    MI_CpuFill8(p + 0x174, 0, 16);
    ((struct Obj03806 *)p)->f174 = id;
    ((struct Obj03806 *)p)->f176 = d_021D8C80[index][0];
    ((struct Obj03806 *)p)->f178 = d_021D8C80[index][1];
    ((struct Obj03806 *)p)->f17A = mode;
    ((struct Obj03806 *)p)->f17B = other;
    ((struct Obj03806 *)p)->f17C = 100;
    ((struct Obj03806 *)p)->f3E0 = 0;
    ((struct Obj03806 *)p)->f3D8 = 0x55f1;
    return 1;
}
