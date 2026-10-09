/*
 * file:     dwc_rap_p03.c
 * unit:     yes
 * function: func_02155294, func_021552AC, func_021552DC, func_021552E8
 * address:  0x02155294
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021562EC  0x021562EC  thumb  ov009
 *   func_02156D84 0x02156D84 thumb ov009
 *   func_02155388 0x02155388 thumb ov009
 *   func_02156CAC 0x02156CAC thumb ov009
 *   func_0216B908 0x0216B908 arm ov009
 *   func_0205CCD8  0x0205CCD8  arm
 *   func_02059E38  0x02059E38  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203CA98  0x0203CA98  arm
 */
typedef unsigned int   u32;

extern int func_021562EC(void);
extern int func_02156D84(void);
extern int func_02155388(void);
extern int func_02156CAC(void);
extern int func_0216B908(void);
extern int func_0205CCD8(void);
int func_02059E38(int *a, int *b);
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
u32 func_0203CA98(void);
int func_02155294(void);
/* * Follower func_021552C4 resolves through the verified ov009 02156CAC leaf; * ov010's same-address allocator is a different function. */ int func_021552AC(void);
int func_021552C4(void);
int func_021552CC(void);
int func_021552D4(void);
/* * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns. */ int func_021552DC(void);
int func_021552E8(void);


/*
 * False when the word call returns -1.
 */
int func_02155294(void)
{
    if (func_021562EC() != -1) {
        return 1;
    }

    return 0;
}


/*
 * Follower func_021552C4 resolves through the verified ov009 02156CAC leaf;
 * ov010's same-address allocator is a different function.
 */
int func_021552AC(void)
{
    int r;
    r = func_02156D84();
    if (!func_02155388()) r |= 1;
    return r;
}


int func_021552C4(void)
{
    return func_02156CAC();
}


int func_021552CC(void)
{
    return func_0216B908();
}


int func_021552D4(void)
{
    return func_021562EC();
}



/*
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 */
int func_021552DC(void)
{
    return 3 - func_0205CCD8();
}



int func_021552E8(void)
{
    int a, b, r;

    r = func_02059E38(&a, &b);
    if (r != 0)
        func_0203C9AC(a, b, r, 0);
    if (r == 0)
        return 0;
    if (a == 0)
        return -10000;
    r = ((int *)func_0203CA98())[3];
    if (r == 0)
        r = a;
    return r;
}
