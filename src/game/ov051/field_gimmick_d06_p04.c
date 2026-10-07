/*
 * file:     field_gimmick_d06_p04.c
 * unit:     yes
 * function: func_021F3C98, func_021F3CCC, func_021F3D04, func_021F3D38, func_021F3D6C
 * address:  0x021F3C98
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F3BC4 0x021F3BC4 thumb ov051
 *   func_02164280 0x02164280 thumb ov010
 *   func_02188CD0 0x02188CD0 thumb ov021
 *   func_021C9258 0x021C9258 thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021F3D94 0x021F3D94 thumb ov051
 *   func_021C928C 0x021C928C thumb ov021
 *   func_02188C7C 0x02188C7C thumb ov021
 *   func_0216CE6C 0x0216CE6C thumb ov010
 */
struct Big;
struct Ctx;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_021F3BC4(int *, int *, int, unsigned short, unsigned *);
extern void func_02164280(int, int, int *);
extern u32 func_02188CD0(u8 *p);
extern unsigned func_021C9258(unsigned, int *);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u16 func_02188C9C(u8 *p);
extern char *func_0200B3A4(unsigned, int);
extern int func_021F3D94(int);
extern void func_021C928C(unsigned);
extern void *func_02188C7C(u8 *p);
extern void *func_0216CE6C(void *, int, int, unsigned short, unsigned, unsigned, unsigned, unsigned);
int func_021F3C98(int *a, int *b);
void func_021F3CCC(int *a, unsigned *b, int x, int y, int z);
void func_021F3D04(int a, int b);
void *func_021F3D38(int a, int x, int y);
void *func_021F3D6C(int a);


int func_021F3C98(int *a, int *b)
{
    unsigned short i = 0;
    unsigned out;
    do {
        if (func_021F3BC4(a, b, i, 1, &out) == 1)
            return 1;
        i++;
    } while (i < 4);
    return 0;
}


/*
 * note: Original 021F3CFE stores r0 after 021C9258, whose filed void
 *       definition leaves its final call result live; caller uses unsigned.
 */
void func_021F3CCC(int *a, unsigned *b, int x, int y, int z)
{
    int v[3];
    func_02164280((short)x, (short)z, v);
    v[1] = (int)(((unsigned)y << 16) + 0x8000u);
    *b = func_021C9258(func_02188CD0((u8 *)a[2]), v);
}


void func_021F3D04(int a, int b)
{
    unsigned h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    char *p = *(char **)(func_0200B3A4(h, func_021F3D94(func_02188C9C((u8 *)a))) + 4);
    func_021C928C(((unsigned *)(p + 0x6c))[b]);
}


void *func_021F3D38(int a, int x, int y)
{
    void *p = func_02188C7C((u8 *)a);
    int n = func_02188C9C((u8 *)a);
    return func_0216CE6C(p, (short)x, (short)y, 0, 0xfd, 0, 0, n);
}


void *func_021F3D6C(int a)
{
    unsigned h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    return *(void **)(func_0200B3A4(h, func_021F3D94(func_02188C9C((u8 *)a))) + 4);
}
