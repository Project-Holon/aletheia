/*
 * function: func_0203E808
 * address:  0x0203E808
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
 *   s_020A7D88      0x020A7D88  data
 *   s_020A7DA0      0x020A7DA0  data
 *   s_020A7DD8      0x020A7DD8  data
 */

typedef unsigned char u8;
extern int *g_021469F4;
extern char s_020A7D74[];
extern char s_020A7D88[];
extern char s_020A7DA0[];
extern char s_020A7DD8[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
void func_0203E808(u32 a0, int a1, u32 a2, u32 a3)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xcf, s_020A7DA0);
    if (g_021469F4[a1] != 0)
        func_02034714(s_020A7D74, 0xd0, s_020A7DD8);
    g_021469F4[a1] = (int)func_02030734(a2, 0x48, 1, s_020A7D74, 0xd2);
    *(int *)g_021469F4[a1] = a3;
    *(int *)(g_021469F4[a1] + 4) = a0;
    *(u8 *)(g_021469F4[a1] + 0x10) = (u8)(*(u8 *)(g_021469F4[a1] + 0x10) & ~2);
}
