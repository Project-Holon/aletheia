/*
 * file:     scrcmd_screeneffects_p07.c
 * unit:     yes
 * function: func_021AEEE0, func_021AEF00
 * address:  0x021AEEE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02005F38  0x02005F38  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02005F38(void *);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern void func_020113D0(char *p, int val);
int func_021AEEE0(u32 a, u32 b, u32 c, u32 d);
int func_021AEF00(u32 a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AEEE0(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5DC((void *)b);
if (func_02005F38(func_0215A5F4((void *)b)) == 0) {
    return 1;
}
return 0;
}


int func_021AEF00(u32 a)
{
    func_020113D0((char *)a, (int)func_021AEEE0);
    return 1;
}
