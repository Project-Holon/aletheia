/*
 * file:     trial_house_p07.c
 * unit:     yes
 * function: func_021CF3B0, func_021CF3DC
 * address:  0x021CF3B0
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
 *   func_0203996C  0x0203996C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_021CEADC  0x021CEADC  thumb  ov021
 *   func_021CEB04  0x021CEB04  thumb  ov021
 */
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

extern struct Entry *func_0203996C(s32 idx);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D378(void);
extern u8 *func_021CEADC(u8 *p);
extern u32 func_021CEB04(u32, u32);
void func_021CF3B0(int mode);
int func_021CF3DC(u32 a, u32 b, u32 c, u8 *d);


void func_021CF3B0(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2706, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2706, 0, 0);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF3DC(u32 a, u32 b, u32 c, u8 *d)
{
if (func_0203D378() == 1) {
    return (int)func_021CEADC(d);
}
return func_021CEB04((u32)d, c);
}
