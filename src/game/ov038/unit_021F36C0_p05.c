/*
 * file:     unit_021F36C0_p05.c
 * unit:     yes
 * function: func_021F41B0, func_021F41DC
 * address:  0x021F41B0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_021897BC 0x021897BC thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F42BC 0x021F42BC thumb ov038
 *   func_021F44C0 0x021F44C0 thumb ov038
 */
struct Ctx;
struct Desc;
typedef unsigned int u32;

extern void *func_0201210C(const struct Ctx *p);
extern int *func_021897BC(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F42BC(int, int *);
extern int func_021F44C0(void *, int *);
void *func_021F41B0(void *p, int v);
void *func_021F41DC(void *p, int v);

void *func_021F41B0(void *p, int v)
{
    unsigned char *s = (unsigned char *)func_021897BC((char *)func_0201210C(p), 1);
    if (v >= 10) return 0;
    s[1] = v;
    return func_020122C0(p, 0, func_021F42BC, 0);
}

void *func_021F41DC(void *p, int v)
{
    unsigned char *s = (unsigned char *)func_021897BC((char *)func_0201210C(p), 1);
    s[2] = v;
    return func_020122C0(p, 0, func_021F44C0, 0);
}
