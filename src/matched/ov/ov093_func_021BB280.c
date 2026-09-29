/*
 * function: func_021BB280
 * address:  0x021BB280
 * packet:   pkt_ov093_021BB280
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B917C  0x021B917C  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B86DC  0x021B86DC  thumb  ov093
 *   func_02005D90  0x02005D90  thumb
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BB320  0x021BB320  thumb  ov093
 *   func_021BB368  0x021BB368  thumb  ov093
 *   func_021BB3B0  0x021BB3B0  thumb  ov093
 *   func_021BB3F8  0x021BB3F8  thumb  ov093
 *   func_021BB43C  0x021BB43C  thumb  ov093
 *   func_021BB484  0x021BB484  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B917C(u8 *);
extern u8 func_021B8FF4(u8 *);
extern void *func_021B86B8(void ***);
extern u16 func_021B86DC(void **);
extern void func_02005D90(u32, u32);
extern void func_021BABEC(u8 *, void *);
extern int func_021BB320(u8 *, int *);
extern int func_021BB368(u8 *, int *);
extern int func_021BB3B0(u8 *, int *);
extern int func_021BB3F8(u8 *, int *);
extern int func_021BB43C(u8 *, int *);
extern int func_021BB484(u8 *, int *);

int func_021BB280(u8 *p)
{
    int r5 = func_021B917C(*(u8 **)(p + 0xc));

    *(u16 *)(p + 0xaa) = r5;
    *(u16 *)(p + 0xa8) = func_021B8FF4(*(u8 **)(p + 0xc));

    switch ((int)func_021B86B8(*(void ****)(p + 0xc))) {
    case 1:
        func_021BABEC(p, (void *)func_021BB43C);
        break;
    case 2:
        func_021BABEC(p, (void *)func_021BB484);
        break;
    case 3:
        func_021BABEC(p, (void *)func_021BB3F8);
        break;
    case 0:
        if (r5 == 1) {
            func_021BABEC(p, (void *)func_021BB368);
        } else if (r5 == 0 || r5 == 2) {
            func_021BABEC(p, (void *)func_021BB3B0);
        } else {
            func_021BABEC(p, (void *)func_021BB320);
        }
        break;
    default:
        if (r5 == 1) {
            func_02005D90(func_021B86DC(*(void ***)(p + 0xc)), 0xffff);
        }
        func_021BABEC(p, (void *)func_021BB320);
        break;
    }
    return 0;
}
