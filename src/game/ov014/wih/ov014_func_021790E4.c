/*
 * function: func_021790E4
 * address:  0x021790E4
 * packet:   pkt_ov014_021790E4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   d_02179794     0x02179794  data   ov014  a1
 *   func_021791A0  0x021791A0  thumb  ov014
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern u8 *g_021797A8;
extern char d_02179794[];

extern BOOL func_021791A0(int a, int b);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern void func_02082BCC(void *p, int v, u32 n);

BOOL func_021790E4(u32 heap, int a, int b)
{
    BOOL ok;

    if (g_021797A8 != 0)
        return 0;
    g_021797A8 = func_0203D7C8(heap, 0x1F00, d_02179794, 0xC33);
    func_02082BCC(g_021797A8, 0, 0x1EE0);
    *(u16 *)(g_021797A8 + 0x1EC2) = 1;
    *(u16 *)(g_021797A8 + 0x1EAA) = 1;
    *(int *)(g_021797A8 + 0x1E98) = 0;
    *(u16 *)(g_021797A8 + 0x1EC0) = heap;
    ok = 1;
    if (!func_021791A0(a, b))
        ok = 0;
    return ok;
}
