/*
 * file:     symbol_map_p04.c
 * unit:     yes
 * function: func_02166B0C, func_02166B2C
 * address:  0x02166B0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005654  0x02005654  thumb
 *   func_02166A6C  0x02166A6C  thumb  ov010
 *   d_02172BA4     0x02172BA4  data  ov010  a4
 *   func_0207AD40 0x0207AD40 arm
 *   func_0207D59C 0x0207D59C arm
 */
typedef unsigned int u32;

extern int func_02005654(int a, int b);
extern void func_02166A6C(void);
extern void func_0207AD40(void *);
extern void func_0207D59C(void *, void *, int, int, int, int);
extern void func_0200566C(void);
void func_02166B0C(void);
void func_02166B2C(void);
extern u32 d_02172BA4[2];


/*
 * Unlabelled leaf: stores 0x3F800000 and 0 into a two-word datum, then
 * tail-calls func_02005654(func_02166A6C, 0).
 */
void func_02166B0C(void)
{
    d_02172BA4[0] = 0x3F800000;
    d_02172BA4[1] = 0;
    func_02005654((int)func_02166A6C, 0);
}

void func_02166B2C(void) {
    int m[4];
    func_0207AD40(m);
    func_0207D59C((void *)0x04000020, m, 128, 92, 0, 0);
    func_0200566C();
}
