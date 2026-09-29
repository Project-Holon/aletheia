/*
 * function: func_021BAE60
 * address:  0x021BAE60
 * packet:   pkt_ov093_021BAE60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB718  0x021BB718  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021BC360  0x021BC360  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BAEF8  0x021BAEF8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021BB718(u8 *, int);
extern void func_021BB724(u8 *, int, int *, int);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(u8 *);
extern u8 func_021B8FF4(u8 *);
extern u8 *func_021EEB64(u32, int);
extern int func_021BC360(int);
extern void func_021BABEC(u8 *, void *);
extern int func_021BAEF8(u8 *, int *);

int func_021BAE60(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB718(p, 7);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            u8 idx = func_021B8FF4(*(u8 **)(p + 0xc));
            int *q;

            func_021BB7D0(p);
            if (*func_021EEB64(*(u32 *)(p + 0x14 + idx * 12), 0) == 0) {
                func_021BABEC(p, (void *)func_021BAEF8);
            } else {
                *(int *)(p + 0x48) = func_021BC360(*(int *)(p + 0x44));
                q = *(int **)(p + 0xcb0);
                func_021BB724(p, 8, q + 2, *q);
                (*s)++;
            }
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            if (*(int *)(p + 0x48) != 0)
                return 1;
            func_021BABEC(p, (void *)func_021BAEF8);
        }
        break;
    }
    return 0;
}
