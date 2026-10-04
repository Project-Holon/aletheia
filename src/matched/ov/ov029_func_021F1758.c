/*
 * function: func_021F1758
 * address:  0x021F1758
 * packet:   pkt_ov029_021F1758
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stack order: c, d, x, y declared in that order ([sp,#0x10], #0xc, #8, #4).
 * The inner switch lists case 3 before case 2 (bodies 1, 6, 5 in the image).
 * func_021EFEC0 is the unlabelled ov029 leaf filed as ov029_func_021EFEC0.c.
 *
 * symbols:
 *   func_021F1758  0x021F1758  thumb  ov029
 *   func_020355D8  0x020355D8  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021F020C  0x021F020C  thumb  ov029
 *   func_021F0D80  0x021F0D80  thumb  ov029
 *   func_021EFEC0  0x021EFEC0  thumb  ov029
 *   func_021F2AEC  0x021F2AEC  thumb  ov029
 *   func_020409B4  0x020409B4  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_021F1910  0x021F1910  thumb  ov029
 *   func_0203FB44  0x0203FB44  arm
 *   func_020090E8  0x020090E8  thumb
 *   func_021F1458  0x021F1458  thumb  ov029
 *   func_021F13FC  0x021F13FC  thumb  ov029
 *   func_021F1A44  0x021F1A44  thumb  ov029
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020355D8(u8 v);
extern int func_02035CB8(int *a, int *b);
extern int func_021F020C(void *p, int a, int b, int *c, int *d);
extern int func_021F0D80(void *p, int k);
extern int func_021EFEC0(int a, int b);
struct Sub020090B0Obj;
extern void func_021F2AEC(int p, int a1, int a2, int a3, int k);
extern void func_020409B4(u32 layer);
extern void func_020061E4(u32 id);
extern int func_021F2DA8(u8 *p);
extern void func_021F1910(void *p, int on);
extern void func_0203FB44(int, u16, u16);
extern void func_020090E8(struct Sub020090B0Obj *obj, u8 value);
extern void func_021F1458(u8 *p, int a, int b, int c);
extern void func_021F13FC(void *p);
extern void func_021F1A44(void *p, int a);

void func_021F1758(u8 *p, int key)
{
    int c;
    int d;
    int x;
    int y;
    int r;
    u32 v;

    if (p[0x45A] == 0 && key != 6 && key != 0)
        return;
    if (*(int *)(p + 0x214) != 0)
        return;
    func_020355D8(1);
    switch (key) {
    case 0:
        func_02035CB8(&x, &y);
        r = func_021F020C(p, x, y, &c, &d);
        if (p[0x457] != 0) {
            *(u16 *)(p + 0x2CC) = x;
            *(u16 *)(p + 0x2CE) = y;
            if ((func_021F0D80(p, r) > 1 || r == 4) && func_021EFEC0(c, d) != 0) {
                func_021F2AEC((int)p, *(int *)(p + 0x20), c, d, (r + 1) % 5);
                func_020409B4(4);
                func_020061E4(0x628);
            }
        } else if (func_021F2DA8(p) == 0) {
            p[0x452] = c;
            p[0x453] = d;
            switch (r) {
            case 1:
                *(int *)(p + 0x214) = 1;
                break;
            case 3:
                *(int *)(p + 0x214) = 6;
                break;
            case 2:
                *(int *)(p + 0x214) = 5;
                break;
            }
        }
        break;
    case 1:
        func_020061E4(0x628);
        p[0x457] ^= 1;
        func_021F1910(p, p[0x457]);
        break;
    case 2:
        *(int *)(p + 0x214) = 0xC;
        break;
    case 3:
        *(int *)(p + 0x214) = 7;
        break;
    case 4:
        *(int *)(p + 0x214) = 0xB;
        break;
    case 5:
        func_020061E4(0x628);
        v = *(u32 *)(p + 0x14);
        func_0203FB44(6, v, v >> 16);
        p[0x458]++;
        p[0x458] = p[0x458] % 5;
        func_020090E8((struct Sub020090B0Obj *)(*(int *)(p + 0x20)), p[0x458]);
        func_021F1458(p, p[0x459], p[0x458], 0);
        func_021F13FC(p);
        func_021F1A44(p, 1);
        break;
    case 6:
        *(int *)(p + 0x214) = 0xD;
        break;
    }
}
