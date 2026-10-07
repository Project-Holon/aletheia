/*
 * file:     unit_021BFFC8_p04.c
 * unit:     yes
 * function: func_021C0494, func_021C04B0
 * address:  0x021C0494
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_0204B3B4(struct Obj *p);
void func_021C0494(int *p);
void func_021C04B0(void *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021C0494(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0204B3B4((struct Obj *)p[i + 0xE5]);
}


/*
 * Clear two u32 slots at +0x3b0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C04B0(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x3b0) = 0;
}
