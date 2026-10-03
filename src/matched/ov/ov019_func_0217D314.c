/*
 * function: func_0217D314
 * address:  0x0217D314
 * packet:   pkt_ov019_0217D314
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217AEFC  0x0217AEFC  thumb  ov019
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0217EE40  0x0217EE40  thumb  ov019
 *   func_0217EE1C  0x0217EE1C  thumb  ov019
 *   func_0217EDF8  0x0217EDF8  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   d_021807E4     0x021807E4  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x58 - 0x2e];
    u16 f58;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj;

extern u16 func_0217AEFC(unsigned int x);
extern int func_0217BB04(u8 *a);
extern void func_021736E0(unsigned int x);
extern void func_0203D14C(int a, int b, u8 *c);
extern u32 func_0217F1EC(u8 *p);
extern int func_0203D1B4(void);
extern void func_0203D7BC(int a);
extern u8 func_0217F060(int i);
extern int func_020399A8(void);
extern int func_0203D1A4(int a);
extern void func_021734A8(u8 *a, int b, u8 *c);
extern void func_0217B8E4(u8 *a, int b);
extern void func_02034714(void *a, int b, void *c);
extern u32 func_020362DC(void);
extern u16 func_0217EE40(int i);
extern u16 func_0217EE1C(int i);
extern u16 func_0217EDF8(int i);
extern void func_0217F210(u8 *p, int a, u32 b);
extern void func_02172D20(u8 *a);
extern int func_02172D68(u8 *a);
extern u8 d_021807E4[];

int func_0217D314(u8 *a, Obj *b, int c, u8 *d)
{
    int idx;
    int n;
    idx = func_0217AEFC(b->f58);
    if (func_0217BB04(a) == 1)
        return 1;
    switch (*d) {
    case 0:
        b->b0 = 1;
        func_021736E0(b->f2d);
        func_0203D14C(2, 1, a + 0x2974 + idx * 0x8c);
        b->f6c = 0;
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 0)
            break;
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            n = func_0217F060(b->f2d);
            if (n <= func_0203D1A4(func_020399A8())) {
                *d = 4;
            } else {
                func_021734A8(a, 3, a + 0x2910 + idx * 0x8c);
                b->b1 = 1;
                switch (b->f2d) {
                case 0x14:
                    func_0217B8E4(a, 0x1f);
                    break;
                case 0x15:
                    func_0217B8E4(a, 0x20);
                    break;
                case 0x16:
                    func_0217B8E4(a, 0x21);
                    break;
                case 0x17:
                    func_0217B8E4(a, 0x22);
                    break;
                case 3:
                    func_0217B8E4(a, 0xe);
                    break;
                case 0x19:
                    func_0217B8E4(a, 0x24);
                    break;
                default:
                    func_02034714(d_021807E4, 0, d_021807E4);
                    break;
                }
                *d = 3;
            }
        } else {
            b->f6c++;
            if (b->f6c > 600 || (func_020362DC() & 2)) {
                b->b0 = 0;
                func_0217B8E4(a, 0);
                *d = 4;
            }
        }
        break;
    case 2:
        switch (b->f2d) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            func_0217F210(a, c, func_0217EE40(b->f14->b3));
            break;
        case 3:
            func_0217F210(a, c, func_0217EE1C(b->f14->b3));
            break;
        case 0x19:
            func_0217F210(a, c, func_0217EDF8(b->f14->b3));
            break;
        }
        *d = 3;
        break;
    case 3:
        if (func_0217F1EC(a) == 1)
            return 1;
        break;
    case 4:
        func_02172D20(a);
        (*d)++;
        break;
    case 5:
        if (func_02172D68(a) == 0)
            *d = 2;
        break;
    }
    return 0;
}
