/*
 * file:     unit_021BE648.c
 * unit:     yes
 * function: func_021BE648, func_021BE680, func_021BE698
 * address:  0x021BE648
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
 *   func_021BA88C  0x021BA88C  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BA988  0x021BA988  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern u8 *func_021BEF08(void);
extern int func_021BA88C(void *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
extern void func_021BA988(u8 *, int);
int func_021BE648(int a, int b, int c);
void func_021BE680(int a);
void func_021BE698(void);


/*
 * Keyed unlink: 0 when the record was freed, -1 when it was absent.
 */
int func_021BE648(int a, int b, int c)
{
    return -(func_021BA88C(func_021BEF08(), (void * (*)(long unsigned int,  int))a, (void (*)(void *))b, c) == 0);
}


void func_021BE680(int a)
{
    func_021BA988(func_021BEF08(), a);
}


/*
 * Tears the module down with a null callback.
 */
void func_021BE698(void)
{
    func_021BA988(func_021BEF08(), 0);
}
