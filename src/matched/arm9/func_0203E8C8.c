/*
 * function: func_0203E8C8
 * address:  0x0203E8C8
 * packet:   pkt_0203E484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F4      0x021469F4  data
 *   s_020A7D74      0x020A7D74  data
 *   s_020A7DA0      0x020A7DA0  data
 *   s_020A7DB8      0x020A7DB8  data
 *   s_020A7E00      0x020A7E00  data
 */
#include "../include/Obj11384.h"

typedef unsigned char u8;
extern int *g_021469F4;
extern char s_020A7D74[];
extern char s_020A7DA0[];
extern char s_020A7DB8[];
extern char s_020A7E00[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
void func_0203E8C8(int idx)
{
    int *p;
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xe2, s_020A7DA0);
    if (g_021469F4[idx] == 0)
        func_02034714(s_020A7D74, 0xe3, s_020A7E00);
    p = (int *)g_021469F4[idx];
    if (((((unsigned int)(((struct Obj11384 *)p)->f10) << 0x1e) >> 0x1f) == 1))
        func_020307B0((void *)((struct Obj11384 *)p)->f0);
    func_020307B0((void *)g_021469F4[idx]);
    g_021469F4[idx] = 0;
}
