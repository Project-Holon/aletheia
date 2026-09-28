/*
 * function: func_02155168
 * address:  0x02155168
 * packet:   pkt_ov009_02155168
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_02157048  0x02157048  thumb  ov009
 *   func_02030734  0x02030734  arm
 *   d_021A8260     0x021A8260  data  ov009  a4
 *   d_021A1C4C     0x021A1C4C  data  ov009  a1
 */

extern int *d_021A8260;
extern char d_021A1C4C[];
int func_0203D798(void);
void func_02157048(int a, int b);
int *func_02030734(int a, int b, int c, char *file, int line);

int func_02155168(int a, int b)
{
    int p;

    if (d_021A8260 != 0)
        return 0;
    p = func_0203D798();
    func_02157048(*(unsigned short *)(p + 0x58), *(int *)(p + 0x48));
    d_021A8260 = func_02030734(a, 8, 1, d_021A1C4C, 0xba);
    *d_021A8260 = b;
    return 1;
}
