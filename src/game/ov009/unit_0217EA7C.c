/*
 * file:     unit_0217EA7C.c
 * unit:     yes
 * function: func_0217EA7C, func_0217EA9C, func_0217EAB0, func_0217EAC8, func_0217EAE0
 * address:  0x0217EA7C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0209146C                  0x0209146C  arm
 *   _u32_div_f                     0x0209C2B0  arm
 *   d_021A3730                   0x021A3730  data
 *   g_021A3730  0x021A3730  data
 */
extern void *func_0209146C(unsigned long n, unsigned long size);
void *func_0217EA7C(unsigned long boundary, unsigned long size);
void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long));
void func_0217EAB0(int a);
void func_0217EAC8(int a, int b);
void func_0217EAE0(void *p);
extern void *d_021A3730[4];
extern char g_021A3730[];


/*
 * sdk:      _gsi_memalign (gsmemory.o)
 */
void *func_0217EA7C(unsigned long boundary, unsigned long size)
{
    void *ptr = func_0209146C(size / boundary, boundary);
    return ptr;
}


void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long))
{
    d_021A3730[0] = p_malloc;
    d_021A3730[1] = p_free;
    d_021A3730[2] = p_realloc;
    d_021A3730[3] = p_memalign;
}


/*
 * Calls the first word of the table at 0x021A3730 on the argument.
 */
void func_0217EAB0(int a)
{
    (*(void (**)(int))g_021A3730)(a);
}


/*
 * Calls the second word of the table at 0x021A3730 on the two arguments.
 */
void func_0217EAC8(int a, int b)
{
    (*(void (**)(int, int))(g_021A3730 + 8))(a, b);
}


/*
 * Calls the second word of the table at 0x021A3730 on the argument.
 */
void func_0217EAE0(void *p)
{
    if (p == 0) {
        return;
    }

    (*(void (**)(void *))(g_021A3730 + 4))(p);
}
