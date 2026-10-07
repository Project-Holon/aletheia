/*
 * file:     unit_021C2464_p04.c
 * unit:     yes
 * function: func_021C297C, func_021C29AC
 * address:  0x021C297C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C26B8   0x021C26B8  arm
 *   func_021C2620   0x021C2620  arm
 *   func_02092004  0x02092004  arm
 *   func_02091D38  0x02091D38  arm
 *   func_02092120  0x02092120  arm
 */
struct GHIConnection;
typedef struct Obj {
    int *f0;
    int f4;
    void *f8;
    int fC;
} Obj;

typedef signed int     s32;

typedef unsigned int   u32;

extern int func_021C26B8(void *connection);
extern int func_021C2620(struct GHIConnection *connection);
extern int func_02092004(void *, int, int);
extern s32 func_02091D38(u32 a0);
extern int func_02092120(void *);
int ghiPostGetContentLength(void *connection);
int func_021C29AC(Obj *o);


int ghiPostGetContentLength(void *connection)
{
    void *post = *(void **)((char *)connection + 0x164);

    if (!post)
        return 0;
    if (*(void **)((char *)post + 0xC))
        return func_021C26B8(connection);
    return func_021C2620(connection);
}


int func_021C29AC(Obj *o)
{
    int t = *o->f0;

    o->f4 = -1;
    if (t == 0) {
    } else if (t == 1) {
        if (o->f8 == 0)
            return 0;
        if (func_02092004(o->f8, 0, 2) != 0)
            return 0;
        o->fC = func_02091D38((u32)o->f8);
        if (o->fC == -1)
            return 0;
        func_02092120(o->f8);
    } else if (t != 2 && t != 3) {
        return 0;
    }
    return 1;
}
