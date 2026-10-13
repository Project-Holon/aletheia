/*
 * function: func_021F2994
 * address:  0x021F2994
 * packet:   pkt_ov029_021F2994
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202223C  0x0202223C  thumb
 *   WIPE_ResetBrightness  0x02022230  thumb
 *   func_021F26E0  0x021F26E0  thumb  ov029
 *   func_021F251C  0x021F251C  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 */

typedef unsigned int   u32;
extern void func_0202223C(u32 a, u32 color);
extern void WIPE_ResetBrightness(u32 which);
typedef unsigned char  u8;
extern void func_021F26E0(char *p);
extern void func_021F251C(u8 *p, int a1, int a2, int a3, int e);
extern void func_021F2180(char *p);

int func_021F2994(int *p)
{
    int a = p[8];
    int b = p[6];
    int c = p[7];

    if (p[0] == (int)func_021F2180) {
        func_0202223C(1, 0);
        func_021F26E0((char *)p);
        func_021F251C((u8 *)p, a, b, c, 0);
        WIPE_ResetBrightness(1);
        return 1;
    }
    return 0;
}
