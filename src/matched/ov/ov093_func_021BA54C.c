/*
 * function: func_021BA54C
 * address:  0x021BA54C
 * packet:   pkt_ov093_021BA54C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021D826C  0x021D826C  thumb  ov093
 *   func_021D8270  0x021D8270  thumb  ov093
 */

typedef unsigned char u8;

struct F {
    u8 b : 1;
};

extern void *func_021B86B8(void *);
extern unsigned int func_021D826C(void *);
extern int func_021D8270(void *, int, unsigned int);

void func_021BA54C(char *p)
{
    int v;

    if ((int)func_021B86B8(p) == 4) {
        v = 1;
    } else if (((struct F *)(p + 0x473))->b) {
        v = 6;
    } else if (*(u8 *)(*(char **)p + 0x90) != 6) {
        v = 5;
    } else if (func_021D826C(p + 0x448)) {
        v = func_021D8270(p + 0x448, *(u8 *)(p + 0x46c), (unsigned int)func_021B86B8(p));
    } else {
        if (*(int *)(p + 0x444) == 7) {
            *(int *)(p + 0x444) = 1;
        }
        v = *(int *)(p + 0x444);
    }
    *(int *)(*(char **)p + 0x8c) = v;
}
