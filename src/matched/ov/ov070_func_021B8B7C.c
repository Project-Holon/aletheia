/*
 * function: func_021B8B7C
 * address:  0x021B8B7C
 * packet:   pkt_ov070_021B8B7C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0202EB04  0x0202EB04  thumb
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7128  0x021B7128  thumb  ov070
 */

typedef unsigned int   u32;
struct Obj;
extern void func_020061E4(u32 a);
extern void func_021BB398();
extern void func_0202EB04();
extern void func_0202EA40();
extern void func_021B6100();
extern void func_021B7128(struct Obj *o);

void func_021B8B7C(int p)
{
    switch (*(unsigned short *)((char *)p + 0x864)) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        func_021BB398(p, 0);
        *(unsigned short *)((char *)p + 0x864) += 1;
        return;
    case 1:
    case 4:
    case 6:
        *(unsigned short *)((char *)p + 0x866) += 1;
        if (*(unsigned short *)((char *)p + 0x866) == 4) {
            *(unsigned short *)((char *)p + 0x866) = 0;
            *(unsigned short *)((char *)p + 0x864) += 1;
        }
        return;
    case 2:
    case 5:
        func_021BB398(p, 2);
        *(unsigned short *)((char *)p + 0x864) += 1;
        return;
    case 7:
        *(unsigned short *)((char *)p + 0x864) = 0;
        func_021BB398(p, 1);
        func_0202EB04(*(int *)((char *)p + 0x850));
        func_0202EA40(*(int *)((char *)p + 0x850));
        func_021B6100(p, func_021B7128);
        return;
    }
}
