/*
 * file:     field_3dbg_p05.c
 * unit:     yes
 * function: func_021A1554, func_021A1560
 * address:  0x021A1554
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
 *   func_021F009C  0x021F009C  thumb  ov034
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021EFEC0  0x021EFEC0  thumb  ov035
 *   abs_id_23      0x00000023  data
 */
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

extern unsigned func_021F009C(char *p);
extern int func_02034AC4(int);
extern void *func_02188C80(void *p);
extern void *func_021EFEC0(int a0, int a1, void *a2);
int func_021A1554(u32 *p);
void func_021A1560(u32 *p);
extern unsigned char abs_id_23[];


/*
 * Addresses are Black-image addresses.
 */
int func_021A1554(u32 *p)
{
    return func_021F009C((char *)p[8]);
}


void func_021A1560(u32 *p)
{
    func_02034AC4((int)abs_id_23);
    p[8] = (u32)func_021EFEC0((int)p, (int)func_02188C80((void *)p[5]), (void *)0x70);
}
