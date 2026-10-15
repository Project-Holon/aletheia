/*
 * file:     gsmemory.c
 * unit:     yes
 * function: _gsi_memalign, func_0217EA9C, gsimalloc, gsirealloc, gsifree
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
 *   MSL_C_LIB_Calloc                  0x0209146C  arm
 *   _u32_div_f                     0x0209C2B0  arm
 *   gGsMemoryFuncs                   0x021A3730  data
 *   gGsMemoryFuncs  0x021A3730  data
 */
extern void *MSL_C_LIB_Calloc(unsigned long n, unsigned long size);
void *_gsi_memalign(unsigned long boundary, unsigned long size);
void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long));
void gsimalloc(int a);
void gsirealloc(int a, int b);
void gsifree(void *p);
extern void *gGsMemoryFuncs[4];
extern void *gGsMemoryFuncs[4];


/*
 * sdk:      _gsi_memalign (gsmemory.o)
 */
void *_gsi_memalign(unsigned long boundary, unsigned long size)
{
    void *ptr = MSL_C_LIB_Calloc(size / boundary, boundary);
    return ptr;
}


void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long))
{
    gGsMemoryFuncs[0] = p_malloc;
    gGsMemoryFuncs[1] = p_free;
    gGsMemoryFuncs[2] = p_realloc;
    gGsMemoryFuncs[3] = p_memalign;
}


/*
 * Calls the first word of the table at 0x021A3730 on the argument.
 */
void gsimalloc(int a)
{
    (*(void (**)(int))gGsMemoryFuncs)(a);
}


/*
 * Calls the second word of the table at 0x021A3730 on the two arguments.
 */
void gsirealloc(int a, int b)
{
    (*(void (**)(int, int))((char *)gGsMemoryFuncs + 8))(a, b);
}


/*
 * Calls the second word of the table at 0x021A3730 on the argument.
 */
void gsifree(void *p)
{
    if (p == 0) {
        return;
    }

    (*(void (**)(void *))((char *)gGsMemoryFuncs + 4))(p);
}
