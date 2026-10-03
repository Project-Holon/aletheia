/*
 * function: func_0203E6C0
 * address:  0x0203E6C0
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
extern void func_020307B0(void *p);
void func_0203E6C0(void)
{
    u8 i;
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x81, s_020A7DA0);
    for (i = 0; i < 8; i++) {
        int *p = (int *)g_021469F4[i];
        if (p == 0)
            continue;
        if (((((unsigned int)(*(u8 *)((char *)p + 0x10)) << 0x1e) >> 0x1f) == 1))
            func_020307B0((void *)*(int *)p);
        func_020307B0((void *)g_021469F4[i]);
    }
    func_020307B0((void *)g_021469F4);
    g_021469F4 = 0;
}
