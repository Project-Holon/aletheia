/*
 * file:     unit_02075BD4.c
 * unit:     yes
 * function: func_02075BD4, func_02075C08, func_02075C20
 * address:  0x02075BD4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f      0x0209C0A4  arm
 */
typedef int s32;

struct Obj {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
};

struct LerpObj {
    int start;
    int target;
    int step;
    int duration;
};



/*
 * The pair of words at +0 and +4 is a low/high bound, not a pointer table:
 * the tail is a linear map of f08 onto [f00, f04] with f0c as the denominator,
 * and the guard's `ldrge` is the same load the tail repeats after the
 * predicated return -- reading the tail as `*(s32 *)o->f04` compiles the
 * guard's load unconditionally and is six bytes out.
 */
s32 func_02075BD4(struct Obj *o)
{
    if (o->f08 >= o->f0c)
        return o->f04;
    return o->f00 + (o->f04 - o->f00) * o->f08 / o->f0c;
}


void func_02075C08(struct LerpObj *obj)
{
    if (obj->step < obj->duration) {
        obj->step++;
    }
}


int func_02075C20(struct LerpObj *obj)
{
    if (obj->step >= obj->duration) {
        return 1;
    }
    return 0;
}
