/*
 * file:     unit_021BE9B8_p01.c
 * unit:     yes
 * function: func_021BE9E8, func_021BE9F8
 * address:  0x021BE9E8
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
 *   func_021BEA48 0x021BEA48 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02080C54 0x02080C54 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BEAB8 0x021BEAB8 thumb ov203
 *   func_021BEAF8 0x021BEAF8 thumb ov203
 *   func_021BEB48 0x021BEB48 thumb ov203
 */
#include "../../matched/include/Obj10864.h"

struct CaptureConfig;
struct S02030FB4;
typedef struct Config { unsigned words[11]; } Config;

extern void func_021BEA48(int *s, unsigned a, unsigned b, unsigned c);
extern void func_021BEAB8(void *task, const int *ctx);
extern void func_021BEAF8(void *node, int *s);
extern void *func_020311B8(void *, void (*)(void *, void *), unsigned, unsigned);
extern void *func_02031290(struct S02030FB4 *p);
extern unsigned short func_02080C54(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BEB48(struct CaptureConfig *s);
void func_021BE9E8(int a);
void *func_021BE9F8(void *manager, const Config *source);


void func_021BE9E8(int a)
{
    func_021BEA48((int *)a, 1, 0, 1);
}

void *func_021BE9F8(void *manager, const Config *source)
{
    void *task;
    char *ctx;
    task = func_020311B8(manager, (void (*)(void *, void *))func_021BEAB8, 56, 5);
    ctx = func_02031290(task);
    *(Config *)(ctx + 4) = *source;
    ((struct Obj10864 *)ctx)->f34 = task;
    ((struct Obj10864 *)ctx)->f30 = 0;
    ((struct Obj10864 *)ctx)->f0 = func_02080C54();
    func_021BEB48((struct CaptureConfig *)(ctx + 4));
    func_020056A0((unsigned)func_021BEAF8, (unsigned)ctx, 0);
    return ctx;
}
