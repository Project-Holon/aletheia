/*
 * function: func_021BD504
 * address:  0x021BD504
 * packet:   pkt_ov091_021BD504
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BB7D8  0x021BB7D8  thumb  ov091
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BBA0C  0x021BBA0C  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern int func_021BB7D8(void *unused, u32 p);
extern void func_021BB714(char *a, int x, int y);
extern void func_021BB97C(char *a, int x);
extern void func_021BBA0C(char *a, int x, int y, int z, int w);
extern void func_021BB7E8(char *a, int x, int y);
extern void func_021BB98C(void *p, u32 s);
extern int func_020457B0(int size, int heap);
extern void func_02045924(int buf, int src);
extern void func_02045808(int buf);

void func_021BD504(char *a)
{
    int t;
    if (*(u8 *)(*(char **)(a + 0x280) + 0x94) == 0)
        return;
    if (func_021BB7D8(a, *(int *)(a + 0x150)) == 0)
        func_021BB714(a, *(int *)(a + 0x150), 1);
    if (*(int *)(*(char **)(a + 0x280) + 0x64) == 1) {
        t = func_020457B0(0x10, *(u16 *)a);
        func_02045924(t, *(int *)(*(char **)(a + 0x280) + 0x78));
        func_021BB97C(a, *(int *)(a + 0x150));
        func_021BBA0C(a, *(int *)(a + 0x150), 0, t, *(u8 *)(*(char **)(a + 0x280) + 0x7C));
        func_021BB7E8(a, *(int *)(a + 0x150), 0xA9);
        func_021BB98C(a, *(int *)(a + 0x150));
        func_02045808(t);
    } else {
        func_021BB7E8(a, *(int *)(a + 0x150), *(u8 *)(*(char **)(a + 0x280) + 0x94) + 0xA9);
    }
}
