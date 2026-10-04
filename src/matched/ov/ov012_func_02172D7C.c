/*
 * function: func_02172D7C
 * address:  0x02172D7C
 * packet:   pkt_ov012_02172D7C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203D0FC  0x0203D0FC  arm
 *   func_02172D14  0x02172D14  thumb  ov012
 *   func_02172C98  0x02172C98  thumb  ov012
 *   d_02175380     0x02175380  data   ov012
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Req;
extern int func_0203CEAC(int a0);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203D0FC(int a);
extern void func_02172D14(u8 *p);
extern void func_02172C98(u8 *p);
extern char d_02175380[];

int func_02172D7C(u8 *p)
{
    switch (p[0x3561]) {
    case 0:
        if (p[0x3562] == 1) {
            return 1;
        }
        return 0;
    case 1:
        switch (p[0x3562]) {
        case 0:
        case 1:
            p[0x3561] = 2;
            break;
        case 2:
            p[0x3561] = 4;
            break;
        default:
            p[0x3561] = 0;
            break;
        }
        break;
    case 2:
        p[0x3560] = 4;
        if (func_0203CEAC((int)func_02172D14) == 0) {
            func_02172D14(p);
        }
        p[0x3561]++;
        break;
    case 3:
        if (p[0x3560] == 5) {
            if (p[0x3562] == 1) {
                p[0x3561] = 0;
            } else {
                p[0x3561]++;
            }
        }
        break;
    case 4:
        p[0x3560] = 1;
        func_0203CBAC((struct Req *)d_02175380, (u32)func_02172C98, (u32)p);
        p[0x3561]++;
        break;
    case 5:
        if (p[0x3560] >= 2) {
            p[0x3560] = 3;
            func_0203D0FC(0);
            p[0x3561] = 0;
        }
        break;
    }
    return 1;
}
