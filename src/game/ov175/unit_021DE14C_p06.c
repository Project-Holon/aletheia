/*
 * file:     unit_021DE14C_p06.c
 * unit:     yes
 * function: func_021DECFC, func_021DED3C, func_021DEDB4, func_021DEE18
 * address:  0x021DECFC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DE14C  0x021DE14C  arm  ov175
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3EFC     0x021E3EFC  data
 *   d_021E3F04     0x021E3F04  data
 *   d_021E3F1C     0x021E3F1C  data
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182CF0  0x02182CF0  arm
 *   func_021DE184  0x021DE184  arm  ov175
 *   func_021DE840  0x021DE840  arm
 */
struct SAKEField;
typedef unsigned int u32;

extern int func_021DE14C(char **, int);
extern void func_02182AC0(void *, void *, void *, void *);
extern void func_02182CF0(void *, void *, void *, int);
extern void func_021DE184(u32 ctx, u32 *arr, int n);
extern int  func_021DE2E0(void *p, int **pa, int *nb, int c, int d);
extern void func_0217EAE0(int *pa);
extern void func_021DE840(int numFields, struct SAKEField *record);
int func_021DECFC(u32 ctx);
int func_021DED3C(u32 ctx);
int func_021DEDB4(int **p);
void func_021DEE18(char *p);
extern char d_021E3DF8[];
extern char d_021E3EFC[];
extern char d_021E3F04[];
extern char d_021E3F1C[];


/*
 * SDK provenance: sakeiGetMyRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 */
int func_021DECFC(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 6;
    if (p[1] == 0)
        return 5;
    return func_021DE14C((char **)p[1], p[2]);
}


int func_021DED3C(u32 ctx)
{
    u32 *p = *(u32 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3EFC,
                  (void *)p[0]);
    if (p[3] != 0)
        func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3F04,
                      (void *)p[3]);
    func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3F1C, 1);
    func_021DE184(ctx, (u32 *)p[1], p[2]);
    return 0;
}


int func_021DEDB4(int **p)
{
    int *t = (int *)p[2];
    int *out = (int *)p[3];
    int *pa;
    int nb;
    int h = func_021DE2E0(p, &pa, &nb, t[2], t[1]);

    if (h == 0) {
        if (pa != 0 && nb > 0)
            *out = *pa;
        else
            *out = 0;
    }
    func_0217EAE0(pa);
    return h;
}


/*
 * Voice state tail: the +0x0c cursor is the gate -- a null one returns
 * immediately; otherwise the +0x08 block's third word and the cursor's head
 * word are handed to func_021DE840.
 */
void func_021DEE18(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE840(r[2], (struct SAKEField *)q[0]);
}
