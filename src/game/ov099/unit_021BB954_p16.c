/*
 * file:     unit_021BB954_p16.c
 * unit:     yes
 * function: func_021BCB8C, func_021BCBB0, func_021BCBBC
 * address:  0x021BCB8C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   sub_020307B0  0x020307B0  arm
 *   func_0201A090  0x0201A090  thumb
 */
struct Big;
typedef unsigned int u32_021BCB8C;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BCBB0;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021BCBBC;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern u32_021BCB8C func_0200BBA8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern u32_021BCBB0 sub_020307B0(void *p);
extern int func_0201A090(void *rules, void *party, u32_021BCBBC *mask);
int func_021BCB8C(void *p);
void func_021BCBB0(void *p);
int func_021BCBBC(int a, int b, int *out);

/*
 * note: Two bytes of alignment padding follow at 0x021BCBAE.
 */
int func_021BCB8C(void *p)
{
    void *obj = func_0200BAC8(func_02012EBC(p));
    if (func_0200BBA8(obj) == 0) return 0;
    return (int)func_0200BAF4((int)obj, 0x21);
}


/*
 * Free-like guard: calls sub_020307B0 only for a non-null pointer.
 */
void func_021BCBB0(void *p)
{
    if (p != 0) {
        sub_020307B0(p);
    }
}


/*
 * Returns 4 or whatever func_0201A090 answers, and writes 0 or -1 through
 * the third argument.
 */
int func_021BCBBC(int a, int b, int *out)
{
    int r = 4;

    *out = 0;

    if (b != 0) {
        r = func_0201A090((void *)a, (void *)b, (u32_021BCBBC *)out);
    } else {
        *out = -1;
    }

    return r;
}
