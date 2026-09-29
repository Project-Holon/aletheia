/*
 * function: func_021BD59C
 * address:  0x021BD59C
 * packet:   pkt_ov091_021BD59C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C724  0x0201C724  thumb
 */

extern int func_020450F0(int a, int b, int c, int d, int e, int f, int g);
extern int func_02045EC0(int bank, int idx);
extern int func_02045770(int);
extern void func_02045808(int);
extern void func_0201C724(int a, int b, int c, int d, int e, int f, int g);

void func_021BD59C(char *p)
{
    int s;
    *(int *)(p + 0x1FC) = func_020450F0(4, 7, 0x15, 0xB, 3, 0xE, 1);
    *(int *)(p + 0x200) = func_020450F0(4, 0x14, 0x15, 5, 3, 0xE, 1);
    s = func_02045EC0(*(int *)(p + 0x134), 0xAD);
    func_0201C724(*(int *)(p + 0x140), func_02045770(*(int *)(p + 0x1FC)), 0, 4, s,
                  *(int *)(p + 0x138), 0x3C40);
    func_02045808(s);
    *(int *)(p + 0x204) = 1;
}
