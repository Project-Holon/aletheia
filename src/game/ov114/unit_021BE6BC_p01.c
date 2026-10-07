/*
 * file:     unit_021BE6BC_p01.c
 * unit:     yes
 * function: func_021BE838, func_021BE880, func_021BE8B8
 * address:  0x021BE838
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
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEC2C 0x021BEC2C arm ov114
 *   func_021BBDFC 0x021BBDFC arm ov114
 *   func_021BEC10  0x021BEC10  arm  ov114
 */
typedef unsigned char  u8;

typedef unsigned int u32;

extern u8 *func_021BEF08(void);
extern void *func_021BEF3C(void);
extern void *func_021BEF58(int p);
extern int func_021BEC2C(int a, int d);
extern int func_021BBDFC(void *bgnEndInfo_p, void *res_p, char **value_pp);
extern int func_021BEC10(int, int);
int func_021BE838(void *handle, char **value_pp);
int func_021BE880(int a);
int func_021BE8B8(int a, int v);


int func_021BE838(void *handle, char **value_pp)
{
    void *sysInfo_p = func_021BEF08();
    void *bgnEndInfo_p = func_021BEF3C();
    void *mutexInfo_p = func_021BEF58((int)sysInfo_p);
    void *res_p = (void *)func_021BEC2C((int)mutexInfo_p, (int)handle);
    if (res_p == 0) {
        return -1;
    }
    return func_021BBDFC(bgnEndInfo_p, res_p, value_pp);
}


/*
 * Keyed field read: -1 unknown key, -1 when unset, else the +0x18 word.
 */
int func_021BE880(int a)
{
    u8 *p = (u8 *)func_021BEC2C((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    if (*(u32 *)(p + 0x14) != 0)
        return *(u32 *)(p + 0x18);
    return -1;
}


int func_021BE8B8(int a, int v)
{
    u8 *p = (u8 *)func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xd0) = v;
    return 0;
}
