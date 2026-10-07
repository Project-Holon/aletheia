/*
 * file:     field_wfbc_p16.c
 * unit:     yes
 * function: func_02194950, func_02194960, func_02194974, func_02194984, func_02194990
 * address:  0x02194950
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
 *   func_02194B78  0x02194B78  thumb  ov021
 *   func_02194A84  0x02194A84  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02194B78(u8 *e, int i);
extern int func_02194A84(u16 *p, int i);
void func_02194950(u8 *p, int i);
u32 func_02194960(u32 a, u32 b, u32 c, u32 a3);
int func_02194974(u8 *p, int i);
u32 func_02194984(u32 a, u32 b);
u32 func_02194990(u32 a, u32 b);


/*
 * Tail call with a strided element address and the index.
 *
 * Addresses are Black-image addresses.
 */
void func_02194950(u8 *p, int i)
{
    func_02194B78(p + 0x18 + i * 100, i);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02194960(u32 a, u32 b, u32 c, u32 a3)
{
if (*(u16 *)((u8 *)((a + (b * 100))) + 24) == 0) {
    return 1;
}
return 0;
}


int func_02194974(u8 *p, int i)
{
    return func_02194A84((u16 *)(p + 0x18 + i * 100), i);
}


u32 func_02194984(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 32);
}


u32 func_02194990(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 36);
}
