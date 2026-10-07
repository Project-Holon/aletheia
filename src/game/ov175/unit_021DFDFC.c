/*
 * file:     unit_021DFDFC.c
 * unit:     yes
 * function: func_021DFDFC, func_021DFE08, func_021DFE14, func_021DFE20
 * address:  0x021DFDFC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int   u32;

extern void func_021E02F0(void);
extern void func_021E03F8(void);
extern int func_021DFF30(u32 *p);
extern char *func_021DF968(void);
void func_021DFDFC(void);
void func_021DFE08(void);
int func_021DFE14(u32 *a0);
void func_021DFE20(void);


/*
 * ARM tail jump to func_021E02F0 in the ov175 writer group.
 */
void func_021DFDFC(void)
{
    func_021E02F0();
}


/*
 * ARM tail jump to func_021E03F8 in the ov175 writer group.
 */
void func_021DFE08(void)
{
    func_021E03F8();
}


/*
 * ARM tail jump to func_021DFF30 in the ov175 prologue group.
 */
int func_021DFE14(u32 *a0)
{
    return func_021DFF30(a0);
}


/*
 * ARM tail jump to func_021DF968, the ov175 +0x5c/+0x84 string writer.
 */
void func_021DFE20(void)
{
    func_021DF968();
}
