/*
 * file:     ctvt_comm_p02.c
 * unit:     yes
 * function: func_021B7B30, func_021B7B3C
 * address:  0x021B7B30
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE100  0x021BE100  thumb  ov172
 *   func_02085D3C  0x02085D3C  arm
 *   func_021B7B5C  0x021B7B5C  arm    ov172
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int func_021BE100(void);
extern int func_02085D3C(int a);
extern void func_021B7B5C(int a, int b, int c);
u32 func_021B7B30(int unused, char *base, int i);
void func_021B7B3C(int x, int y, int z);


/*
 * Field getter, u32 at +0x34 of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B7B30(int unused, char *base, int i)
{
    return *(u32 *)(base + i * 0x1c + 0x34);
}


void func_021B7B3C(int x, int y, int z)
{
    int r = func_021BE100();
    if (r != 1) {
        return;
    }
    r = func_02085D3C(r);
    if (r != 1) {
        return;
    }
    func_021B7B5C(3, 3, z);
}
