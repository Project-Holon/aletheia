/*
 * function: func_021D6848
 * address: 0x021D6848
 * packet: pkt_ov093_021D6848
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj02137.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Rec {u16 a,b,c,d;};
void func_021D6848(u8 *p, struct Rec *r)
{
    u8 n;
    u8 k = p[0x1ef];
    u32 i;
    u8 *q;
    n = (p + 0x1ec)[k];
    if (n == 6) {
        for (i = 0; i < 5; i++) {
            q = p + k * 0x30 + i * 8;
            ((struct Obj02137 *)q)->f15C = ((struct Obj02137 *)q)->f164;
            ((struct Obj02137 *)q)->f15E = ((struct Obj02137 *)q)->f166;
            ((struct Obj02137 *)q)->f160 = ((struct Obj02137 *)q)->f168;
            ((struct Obj02137 *)q)->f162 = ((struct Obj02137 *)q)->f16A;
        }
        n--;
    }
    q = p + k * 0x30 + n * 8;
    ((struct Obj02137 *)q)->f15C = r->a;
    ((struct Obj02137 *)q)->f15E = r->b;
    ((struct Obj02137 *)q)->f160 = r->c;
    ((struct Obj02137 *)q)->f162 = r->d;
    if ((p + 0x1ec)[k] < 6) (p + 0x1ec)[k]++;
}
