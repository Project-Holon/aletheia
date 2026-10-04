/*
 * function: func_021EFF5C
 * address:  0x021EFF5C
 * packet:   pkt_ov034_021EFF5C
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFF5C 0x021EFF5C thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */

typedef unsigned int   u32;
struct Ctx;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern unsigned int func_0201AA18(void *);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);

void func_021EFF5C(int *p)
{
    unsigned int i;
    void *n;

    if (!(p[0x4A] & 1) && func_0201C6B4((const struct PrintSys *)p[2]) == 1) {
        n = func_02012934(func_020120F4((const struct Ctx *)p[0]));
        for (i = 0; i < func_0201AA18(n); i++)
            func_0204B3DC((struct Obj *)p[0x15 + i], 1);
        p[0x4A] |= 1;
    }
}
