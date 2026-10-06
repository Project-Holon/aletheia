/*
 * file:     unit_02075560_p04.c
 * unit:     yes
 * function: func_02075B28, func_02075B54, func_02075B94
 * address:  0x02075B28
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct LerpObj {
    int start;
    int target;
    int step;
    int duration;
};

int func_02075B28(void *a0);

int func_02075B28(void *a0){ int t0 = func_02087988(); int t1 = func_020604AC((int)0x214EA9C, (int)a0); int t2 = func_0208799C((int)t0); return t2; }




struct Entry { u32 f0; u32 f4; u32 f8; };   /* 0xC bytes each */
struct Table { u8 pad00[0x1c]; u32 count; struct Entry arr[]; };

/*
 * Signed compare against zero for the negative index (`movlt`/`bxlt`) but an
 *  * unsigned `>=` for the bound (`movhs`/`bxhs`), which is what an `int` index
 *  * compared against a `u32` count gives; the -1 element test is the
 *  * R_ARM_ABS32-free third guard the tail ends on. No relocations at all.
 */
struct Entry *func_02075B54(struct Table *t, int idx)
{
    struct Entry *e;

    if (idx < 0) return 0;
    if (idx >= t->count) return 0;
    e = &t->arr[idx];
    if (e->f0 == -1) return 0;
    return e;
}


void func_02075B94(struct LerpObj *obj)
{
    obj->target = 0;
    obj->start = 0;
    obj->duration = 0;
    obj->step = 0;
}
