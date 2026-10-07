/*
 * file:     scrcmd_musical_p05.c
 * unit:     yes
 * function: func_0215E0EC, func_0215E130
 * address:  0x0215E0EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02012F80  0x02012F80  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 */
#include "../../matched/include/Obj00005.h"

struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02012F80(char *base);
extern u32 func_02026454(void *obj);
extern u32 func_02026474(void *obj);
extern void func_02156BAC(void *p);
extern unsigned int func_02156BCC(void *p);
int func_0215E0EC(int a0, int a1);
int func_0215E130(void *a, void *b);


/*
 * blocked:
 */
int func_0215E0EC(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E0F6:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215E0FC:
a0 = t4 + 0;
    v2 = func_0215A5E4((void *)a0);
loc_0215E104:
    a0 = func_02012138(v1);
loc_0215E10C:
t5 = a0 + 0;
    a0 = func_02012F80(v2);
loc_0215E114:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02026454((void *)a0);
loc_0215E11C:
    if (a0 != 4) goto loc_0215E12C;
loc_0215E120:
a0 = t5 + 0;
    a0 = func_02026474((void *)a0);
loc_0215E126:
*(int *)&((struct Obj00005 *)t4)->f4 = a0;
a0 = 1;
    return a0;
loc_0215E12C:
a0 = 0;
    return a0;}


int func_0215E130(void *a, void *b)
{
    void *t;
    void *s;
    int *w;

    func_0215A5F4(b);
    t = func_0215A5DC(b);
    s = func_0215A5E4(b);
    t = (void *)func_02012138(t);
    w = (int *)func_02012F80(s);
    if (*w != 0) {
        func_02156BAC((void *)(*w));
        if (func_02156BCC((void *)(*w)) == 1) {
            return 1;
        }
    }
    if (func_02026454(t) == 0) {
        return 1;
    }
    return 0;
}
