/*
 * file:     unit_021DFCE8.c
 * unit:     yes
 * function: func_021DFCE8, func_021DFCF4, func_021DFD00, func_021DFD0C, func_021DFD18
 * address:  0x021DFCE8
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

typedef unsigned char  u8;

extern int func_021E0040(u32 *p);
extern int func_021E0070(u32 *p);
extern int func_021E0080(u32 *p);
extern int func_021E0000(u8 *p);
extern void func_021E0098(void);
int func_021DFCE8(u32 *a0);
int func_021DFCF4(u32 *a0);
int func_021DFD00(u32 *a0);
int func_021DFD0C(u8 *a0);
void func_021DFD18(void);


int func_021DFCE8(u32 *a0)
{
    return func_021E0040(a0);
}


/*
 * ARM tail jump to the untraced 0x021E0070 block of ov175's data area.
 */
int func_021DFCF4(u32 *a0)
{
    return func_021E0070(a0);
}


/*
 * ARM tail jump to 0x021E0080, which carries labels in ov093 and ov183 as
 *  *  well, so the site needs the region hint below.
 */
int func_021DFD00(u32 *a0)
{
    return func_021E0080(a0);
}


int func_021DFD0C(u8 *a0)
{
    return func_021E0000(a0);
}


/*
 * ARM tail jump to func_021E0098, the ov175 byte-read path.
 */
void func_021DFD18(void)
{
    func_021E0098();
}
