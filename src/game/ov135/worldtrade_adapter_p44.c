/*
 * file:     worldtrade_adapter_p44.c
 * unit:     yes
 * function: func_022026BC, func_022026C4
 * address:  0x022026BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct StrObj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int s32;

typedef signed short s16;

extern void *func_020185F4(void *a);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
u32 func_022026BC(void *mon);
int func_022026C4(u32 *p, u32 b, u32 a, u32 c);


/*
 * Tail-call thunk to the thumb routine at 0x020185F4.
 */
u32 func_022026BC(void *mon)
{
    return (u32)func_020185F4(mon);
}


/*
 * Tail call: the third argument goes first, the dereferenced pointer second, the u16 last.
 */
int func_022026C4(u32 *p, u32 b, u32 a, u32 c)
{
    return func_0201D304((struct StrObj *)a, *p, (u16)c);
}
