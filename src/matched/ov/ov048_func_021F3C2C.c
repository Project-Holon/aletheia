/*
 * function: func_021F3C2C
 * address:  0x021F3C2C
 * packet:   pkt_ov048_021F3C2C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021F4DF4  0x021F4DF4  thumb  ov048
 *   func_021F4E3C  0x021F4E3C  thumb  ov048
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02188C9C(u32 a);
extern u32 func_0201296C(u32 a);
extern int func_020142E8(u32 a, u32 b);
extern int func_021F4DF4(int *p, int v);
extern int func_021F4E3C(int *p);

u8 *func_021F3C2C(u8 *o)
{
    int b;
    int a;
    int i;
    int off;
    int c;
    int d;

    a = func_02188C9C(*(u32 *)(o + 4));
    b = func_0201296C(*(u32 *)(o + 8));
    if (*(u8 **)(o + 0x20) == 0) {
        return 0;
    }
    for (i = 0; i < *(u8 *)(o + 0x24); i++) {
        off = i * 0x24;
        c = func_020142E8(b, (u16)*(u32 *)(*(u8 **)(o + 0x20) + off + 4));
        d = func_021F4DF4((int *)(*(u8 **)(o + 0x20) + off), a);
        if (func_021F4E3C((int *)(*(u8 **)(o + 0x20) + off)) && c && d) {
            return *(u8 **)(o + 0x20) + off;
        }
    }
    return 0;
}
