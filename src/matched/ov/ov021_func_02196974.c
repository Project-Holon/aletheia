/*
 * function: func_02196974
 * address:  0x02196974
 * packet:   pkt_ov021_02196974
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02197644  0x02197644  thumb  ov021
 *   func_021968DC  0x021968DC  thumb  ov021
 *   func_02196944  0x02196944  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_020061E4(u32 a);
struct BigObj;
struct Obj;
extern void *func_02012934(const struct BigObj *p);
extern int func_0201AA1C(void *p);
extern void func_02045CAC(u32 a, u32 b, u32 c);
extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02197644(u8 *p, u32 b);
extern void func_021968DC(struct Obj *a);
extern void func_02196944(u8 *a);

int func_02196974(u32 s, u8 *p)
{
    int r = 0;

    *(u32 *)(p + 0x300) = s;
    switch (s) {
    case 0:
    case 5:
        func_020061E4(0x73B);
        func_02196034(p, (void *)func_021968DC, 0x3DE);
        r = 1;
        *(u32 *)(p + 8) = 1;
        break;
    case 1:
    case 6:
        if (func_0201AA1C(func_02012934(*(void **)(p + 0x30))) < 2) {
            func_02045CAC(*(u32 *)(p + 0x28), 0x2C, *(u32 *)(p + 0x38));
            func_02197644(p, 0);
            func_02196034(p, (void *)func_02196944, 0x3EA);
        } else {
            func_020061E4(0x73B);
            *(u32 *)(p + 8) = 6;
            func_02196034(p, (void *)func_021968DC, 0x3F0);
            r = 1;
        }
        break;
    case 2:
        func_020061E4(0x73B);
        *(u32 *)(p + 8) = 8;
        func_02196034(p, (void *)func_021968DC, 0x3F6);
        r = 1;
        break;
    case 3:
    case 7:
        func_020061E4(0x73B);
        *(u32 *)(p + 8) = 7;
        func_02196034(p, (void *)func_021968DC, 0x3FD);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        *(u32 *)(p + 8) = 0xC;
        func_02196034(p, (void *)func_021968DC, 0x404);
        break;
    }
    return r;
}
