/*
 * file:     field_3dbg_p01.c
 * unit:     yes
 * function: func_021A1428, func_021A1448
 * address:  0x021A1428
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
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021F2234  0x021F2234  thumb  ov032
 *   abs_id_20      0x00000020  data
 *   func_022022FC  0x021F22FC  thumb  ov032
 *   func_02034A5C  0x02034A5C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

extern int func_02034AC4(int);
extern void *func_02188C80(void *p);
extern char *func_021F2234(u32 a0, u32 a1);
extern void func_022022FC(char *p);
extern void func_02034A5C(int);
void func_021A1428(u32 *p);
void func_021A1448(u32 *p);
extern unsigned char abs_id_20[];


/*
 * Addresses are Black-image addresses.
 */
void func_021A1428(u32 *p)
{
    func_02034AC4((int)abs_id_20);
    p[8] = (u32)func_021F2234((u32)func_02188C80((void *)p[5]), (u32)p);
}


void func_021A1448(u32 *p)
{
    func_022022FC((char *)p[8]);
    func_02034A5C((int)abs_id_20);
}
