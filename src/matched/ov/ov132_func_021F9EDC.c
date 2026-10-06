/*
 * function: func_021F9EDC
 * address: 0x021F9EDC
 * packet: pkt_ov132_021F9EDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051230 0x02051230 arm
 */
#include "../include/Obj10535.h"
#include "../include/Obj14089.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern unsigned func_020056BC(void);
extern void func_02051230(void *, void *, unsigned, unsigned);
char *func_021F9EDC(char *p, u32 a)
{
    char *q = 0;
    void *v;
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) if (*(int *)(p + i * 0x4848 + 4) == 0) q = (p + 4) + i * 0x4848;
    j = 0;
    ((struct Obj10535 *)q)->f4804 = (void *)func_02050C04((int)(q + 4), 0x4800, 0, ((struct Obj14089 *)p)->f0);
    v = (void *)func_0205121C(47, a, ((struct Obj14089 *)p)->f0);
    func_02051230(((struct Obj10535 *)q)->f4804, v, 0, func_020056BC());
    for (; j < 4; j++) *(int *)(q + j * 16 + 0x4808) = 0;
    ((struct Obj10535 *)q)->f0 = 1;
    return q;
}
