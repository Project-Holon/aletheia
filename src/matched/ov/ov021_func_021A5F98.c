/*
 * function: func_021A5F98
 * address:  0x021A5F98
 * packet:   pkt_ov021_021A5F98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 
 *
 * symbols:
 *   func_021A6278  0x021A6278  thumb  ov021
 *   func_021A627C  0x021A627C  thumb  ov021
 *   func_021A62B4  0x021A62B4  thumb  ov021
 *   func_021A62D8  0x021A62D8  thumb  ov021
 *   func_021A62FC  0x021A62FC  thumb  ov021
 *   func_021A6338  0x021A6338  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021A6278(void *a, int b, int c, int d, int e, int f);
extern void func_021A627C(void *a, int b, int c, int d, int e, int f);
extern void func_021A62B4(void *a, int b, int c, int d, int e, int f);
extern void func_021A62D8(void *a, int b, int c, int d, int e, int f);
extern void func_021A62FC(void *a, int b, int c, int d, int e, int f);
extern void func_021A6338(void *a, int b, int c, int d, int e, int f);

void func_021A5F98(int *a, int sel, int c, int d, int e, int f)
{
    int p = a[7];
    switch (sel) {
    case 0: func_021A6278(a, p, c, d, e, f); break;
    case 1: func_021A627C(a, p, c, d, e, f); break;
    case 2: func_021A62B4(a, p, c, d, e, f); break;
    case 3: func_021A62D8(a, p, c, d, e, f); break;
    case 4: func_021A62FC(a, p, c, d, e, f); break;
    case 5: func_021A6338(a, p, c, d, e, f); break;
    }
}
