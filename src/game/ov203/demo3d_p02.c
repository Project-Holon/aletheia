/*
 * file:     demo3d_p02.c
 * unit:     yes
 * function: func_021BDB64, func_021BDC20
 * address:  0x021BDB64
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BDD30 0x021BDD30 thumb ov203
 *   func_021BDF00 0x021BDF00 thumb ov203
 *   func_021BE538 0x021BE538 thumb ov203
 *   func_021BDC88 0x021BDC88 thumb ov203
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_021BE638 0x021BE638 thumb ov203
 *   d_02FFFC3C 0x02FFFC3C data
 *   func_021BE948 0x021BE948 thumb ov203
 *   func_02022268 0x02022268 thumb
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0202208C 0x0202208C thumb
 */
#include "../../matched/include/Obj01433.h"

struct PrintSys;
struct Context;
typedef unsigned int   u32;

extern void func_021BDD30(char *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BDF00(unsigned char *);
extern int func_021BE538(const struct Context *ctx, u32 frames);
extern int func_021BDC88(char *);
extern int func_021BE620(char *p);
extern void func_021BE638(char *p, int a);
extern u32 func_020221A4(void);
extern void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height);
extern void func_02022268(unsigned);
extern unsigned func_0204E6E0(void);
extern void func_0202208C(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
int func_021BDB64(void *unused, int *state, void *c, char *work);
int func_021BDC20(void *ctx, unsigned mode, unsigned heap);
extern unsigned int d_02FFFC3C;

int func_021BDB64(void *unused, int *state, void *c, char *work)
{
    int result;
    unsigned int now, delta;
    func_021BDD30(*(char * *)&((struct Obj01433 *)work)->f1C);
    func_0201C4E4(((struct Obj01433 *)work)->f10);
    func_021BDF00(*(unsigned char * *)&((struct Obj01433 *)work)->fC);
    result = func_021BE538(((struct Obj01433 *)work)->f18, ((struct Obj01433 *)work)->f24);
    now = d_02FFFC3C;
    delta = now - ((struct Obj01433 *)work)->f20;
    ((struct Obj01433 *)work)->f24 = 0;
    if (((struct Obj01433 *)work)->f20 != 0 && delta > 1)
        ((struct Obj01433 *)work)->f24 = delta - 1;
    ((struct Obj01433 *)work)->f20 = now;
    ((struct Obj01433 *)work)->f28 = ((struct Obj01433 *)work)->f28 + ((struct Obj01433 *)work)->f24;
    switch (*state) {
    case 0:
        if (func_021BDC88(work) != 0 || result != 0) {
            (*(int **)(work + 4))[4] = func_021BE620(((struct Obj01433 *)work)->f18) >> 12;
            (*(int **)(work + 4))[5] = result + 1;
            func_021BE638(((struct Obj01433 *)work)->f18, (*(int **)(work + 4))[5]);
            (*state)++;
        }
        break;
    case 1:
        if (func_020221A4() == 1) {
            if (func_021BDC20((void *)((unsigned char)(*(int **)(work + 4))[1]), 0, ((struct Obj01433 *)work)->f0))
                return 1;
            (*state)++;
        }
        break;
    case 2:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    return 0;
}

int func_021BDC20(void *ctx, unsigned mode, unsigned heap)
{
    unsigned char width, height;
    unsigned char factor;
    int color;
    func_021BE948(ctx, (unsigned char)(mode == 0), &width, &height);
    color = 0;
    if (width) color = 32767;
    func_02022268(color);
    if (height) {
        factor = func_0204E6E0();
        func_0202208C(0, mode, mode, color, height * factor, 1, heap);
        return 0;
    }
    return 1;
}
