/*
 * function: func_021C1CB0
 * address:  0x021C1CB0
 * packet:   pkt_ov021_021C1CB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203038C  0x0203038C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C313C  0x021C313C  thumb  ov021
 *   func_021C1E7C  0x021C1E7C  thumb  ov021
 *   d_021DA7F4     0x021DA7F4  data  ov021  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 d_021DA7F4[];

u32 func_0203038C(int a);
int func_020122C0(int a, int b, void *c, int d);
int func_020124E8(int a);
void func_021C313C(char *a, int b);
void func_021C1E7C(void);

int func_021C1CB0(int a, char *b, int c)
{
    int r;

    if (func_0203038C(0x15) < d_021DA7F4[c])
        return 0;
    *(u16 *)(b + 0x64) = 0;
    *(u32 *)(b + 0x130) = 0;
    *(u16 *)(b + 0x134) = 0;
    *(u16 *)(b + 0x136) = 0;
    *(u16 *)(b + 0x66) = c;
    *(u32 *)(b + 0x128) = 0;
    *(u32 *)(b + 0x12c) = 0;
    *(u32 *)(b + 0xc) = 0;
    r = func_020122C0(a, 0, func_021C1E7C, 0x40);
    func_021C313C(b, func_020124E8(r));
    return r;
}
