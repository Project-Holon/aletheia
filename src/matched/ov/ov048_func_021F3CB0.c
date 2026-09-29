/*
 * function: func_021F3CB0
 * address:  0x021F3CB0
 * packet:   pkt_ov048_021F3CB0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021F4DF4  0x021F4DF4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int func_02188C9C(int);
extern int func_0201296C(int);
extern int func_020142E8(int, int);
extern int func_021F4DF4(int *, int);

int *func_021F3CB0(int *p)
{
    int a = func_02188C9C(p[1]);
    int b = func_0201296C(p[2]);
    int i;

    if (p[8] == 0)
        return 0;
    for (i = 0; i < *(u8 *)((u8 *)p + 0x24); i++) {
        int off = i * 0x24;
        int t = func_020142E8(b, (u16)((int *)(p[8] + off))[1]);
        int r = func_021F4DF4((int *)(p[8] + off), a);

        if (t != 0 && r != 0 && ((int *)(p[8] + off))[4] == 2)
            return (int *)(p[8] + off);
    }
    return 0;
}
