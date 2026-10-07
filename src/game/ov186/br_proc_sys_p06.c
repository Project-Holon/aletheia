/*
 * file:     br_proc_sys_p06.c
 * unit:     yes
 * function: func_021F9B9C, func_021F9BA0, func_021F9BF4
 * address:  0x021F9B9C
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9C84 0x021F9C84 thumb
 *   func_021F9CA4 0x021F9CA4 thumb
 *   func_02034714 0x02034714 arm
 *   d_02200D14 0x02200D14 data a1
 */
#include "../../matched/include/Obj24810.h"
#include "../../matched/include/Obj05498.h"

typedef unsigned int u32;

typedef struct { u32 words[4]; } Info_021F9BA0;

typedef struct { unsigned words[4]; } Info_021F9BF4;

extern void func_021F9C84(char *p, int a, int b);
extern void func_021F9CA4(void *);
extern void func_02034714(const char *expr, u32 line, const char *file);
unsigned func_021F9B9C(struct Obj24810 *p);
void func_021F9BA0(unsigned *ctx);
void func_021F9BF4(unsigned *ctx, unsigned index);
extern char d_02200D14[];

/*
 * leaf: sole blocker of ov183 021DB2E0; parent cleared ownership.
 */
unsigned func_021F9B9C(struct Obj24810 *p)
{
    return p->f10;
}

void func_021F9BA0(unsigned *ctx)
{
    Info_021F9BA0 info;
    if (ctx[25] != 0) {
        ctx[25]--;
        if (ctx[25] != 0) {
            unsigned idx = (unsigned short)((unsigned *)((char *)ctx + 0x48))[ctx[25]];
            func_021F9C84((char *)(&info), idx, (int)((char *)ctx[1] + idx * 20));
            *(Info_021F9BA0 *)((char *)ctx + 0x3c) = info;
        } else {
            func_021F9CA4((char *)ctx + 0x3c);
        }
    } else {
        func_021F9CA4((char *)ctx + 0x3c);
    }
}

void func_021F9BF4(unsigned *ctx, unsigned index)
{
    Info_021F9BF4 info;
    char *base = (char *)ctx[1];
    char *entry = base + index * 20;
    if (index >= ((struct Obj05498 *)ctx)->f8)
        func_02034714(d_02200D14, 0, d_02200D14);
    func_021F9C84((char *)(&info), index, (int)entry);
    if (ctx[25] >= 6)
        func_02034714(d_02200D14, 0, d_02200D14);
    ((unsigned (*)[6])((char *)ctx + 0x4c))[0][ctx[25]] = index;
    ctx[25]++;
    *(Info_021F9BF4 *)((char *)ctx + 0x3c) = info;
}
