/*
 * function: func_0219D184
 * address:  0x0219D184
 * packet:   pkt_ov021_0219D184
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0219CF00  0x0219CF00  thumb  ov021
 *   func_0219CF54  0x0219CF54  thumb  ov021
 *   func_0219D144  0x0219D144  thumb  ov021
 *   func_0219D1F8  0x0219D1F8  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 */
#include "../include/Obj02699.h"

typedef unsigned short u16;
extern u16 func_0216D4F0(void *p);
extern int func_0219CF00(int *, unsigned int, unsigned short *);
extern int func_0219CF54(int *, unsigned int);
extern int func_0219D144(int *, unsigned int, int);
extern void func_0219D1F8(int *);
struct Tagged;
extern void func_02046EFC(struct Tagged *p);

void func_0219D184(int *obj, int key)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short s;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] == key) {
            *((unsigned char *)p + 0xd) = 0;
            if (func_0219CF00(obj, ((struct Obj02699 *)p)->f8, &s) == 1 && (s & 1)) {
                if (func_0219D144(obj, ((struct Obj02699 *)p)->f8, p[1]) == 0) {
                    func_0219CF54(obj, ((struct Obj02699 *)p)->f8);
                }
            }
            if (p[4] != 0) {
                func_02046EFC((void *)p[4]);
                p[4] = 0;
            }
            func_0219D1F8(p);
            return;
        }
    }
}
