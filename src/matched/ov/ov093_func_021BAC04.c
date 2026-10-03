/*
 * function: func_021BAC04
 * address:  0x021BAC04
 * packet:   pkt_ov093_021BAC04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB718  0x021BB718  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BBB60  0x021BBB60  thumb  ov093
 *   func_021BB5FC  0x021BB5FC  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BABF4  0x021BABF4  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB280  0x021BB280  thumb  ov093
 */

extern void func_021BB718(void *, int);
extern int func_021BB798(void *);
extern void func_021BB7D0(void *);
extern void *func_021B86B8(void ***);
extern int func_021BBB60(int);
extern void func_021BB5FC(void *, int);
extern void func_021BABEC(void *, void *);
extern void func_021BABF4(void *);
extern void func_021BB724(void *, int, int, int);
typedef unsigned char  u8;
extern int func_021BB280(u8 *p);

int func_021BAC04(char *p, int *st)
{
    int *q;

    switch (*st) {
    case 0:
        func_021BB718(p, 1);
        (*st)++;
    case 1:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021B86B8(*(void ****)(p + 0xc)) != (void *)4) {
                func_021BB5FC(p, func_021BBB60(*(int *)(p + 0x44)));
                (*st)++;
            } else {
                func_021BABEC(p, (void *)func_021BB280);
            }
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*st)++;
        }
        break;
    case 3:
        q = *(int **)(p + 0xcb0);
        func_021BB724(p, 8, (int)(q + 2), *q);
        (*st)++;
        break;
    case 4:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            func_021BABF4(p);
        }
        break;
    }
    return 0;
}
