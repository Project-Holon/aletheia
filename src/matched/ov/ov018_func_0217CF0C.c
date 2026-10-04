/*
 * function: func_0217CF0C
 * address:  0x0217CF0C
 * packet:   pkt_ov018_0217CF0C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D324C  0x021D324C  thumb  ov093
 *   func_021A0F40  0x021A0F40  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02188E30(u8 *p);
extern void func_021D324C();
extern void func_021A0F40();

int func_0217CF0C(int a0, int *state, Obj *o)
{
    switch (*state) {
    case 0:
        o->f8 += 1;
        if (o->f8 > 15) {
            func_021D324C(func_02188E30((u8 *)o->f0), -16);
            *state += 1;
        }
        break;
    case 1:
        func_021A0F40(o->f4, 0);
        *state += 1;
        break;
    case 2:
        func_021D324C(func_02188E30((u8 *)o->f0), 0);
        *state += 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
