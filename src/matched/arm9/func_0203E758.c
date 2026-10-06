/*
 * function: func_0203E758
 * address:  0x0203E758
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

typedef unsigned char u8;
extern int *g_021469F4;
extern char s_020A7D74[];
extern char s_020A7DA0[];
extern char s_020A7DB8[];
extern char s_020A7E00[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
void func_0203E758(int a0, int a1, int a2, int a3)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x9f, s_020A7DA0);
    if (*(int *)((char *)g_021469F4 + 0x20) != 0)
        func_02034714(s_020A7D74, 0xa0, s_020A7DB8);
    *(int *)((char *)g_021469F4 + 0x20) = a0;
    *(int *)((char *)g_021469F4 + 0x24) = a1;
    *(u8 *)((char *)g_021469F4 + 0x28) = (u8)a2;
    *(int *)((char *)g_021469F4 + 0x2c) = a3;
    *(int *)((char *)g_021469F4 + 0x44) = 0;
    *(int *)((char *)g_021469F4 + 0x34) = 1;
    *(int *)((char *)g_021469F4 + 0x30) = 0;
}
