/*
 * function: func_021C1D18
 * address:  0x021C1D18
 * packet:   pkt_ov021_021C1D18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_021C27F4  0x021C27F4  thumb  ov021
 *   func_021C2854  0x021C2854  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

int func_021C1CB0(int a, char *b, int c);
void func_021C27F4(void);
void func_021C2854(void);

int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g)
{
    char *q;
    int r;

    r = func_021C1CB0(a, b, 3);
    if (r == 0)
        return 0;
    *(void **)(b + 0x128) = func_021C27F4;
    *(void **)(b + 0x12c) = func_021C2854;
    q = b + 0x9c;
    *(int *)(q + 8) = e;
    *(int *)(b + 0x9c) = c;
    *(int *)(q + 0xc) = f;
    *(int *)(q + 4) = d;
    *(int *)(q + 0x10) = g;
    *(u16 *)(q + 0x18) = 5;
    *(int *)(q + 0x14) = 1;
    *(u16 *)(q + 0x1a) = 0x1e;
    return r;
}
