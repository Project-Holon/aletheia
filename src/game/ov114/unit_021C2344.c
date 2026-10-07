/*
 * file:     unit_021C2344.c
 * unit:     yes
 * function: func_021C2344, func_021C2350
 * address:  0x021C2344
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
 *   func_021C1184  0x021C1184  arm  ov114
 *   func_021C1210  0x021C1210  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021C1184(void);
extern void func_021C1210(void);
void func_021C2344(void);
void func_021C2350(void);


/*
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */
void func_021C2344(void)
{
    func_021C1184();
}


/*
 * Tail-call thunk to func_021C1210 via `ldr ip,pool; bx ip`.
 */
void func_021C2350(void)
{
    func_021C1210();
}
