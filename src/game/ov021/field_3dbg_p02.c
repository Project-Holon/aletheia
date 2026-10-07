/*
 * file:     field_3dbg_p02.c
 * unit:     yes
 * function: func_021A1480, func_021A14A0
 * address:  0x021A1480
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
 *   func_021F000C  0x021F000C  thumb  ov033
 *   abs_id_21      0x00000021  data
 *   func_02210124  0x021F0124  thumb  ov033
 *   func_02034A5C  0x02034A5C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

extern int func_02034AC4(int);
extern void *func_021F000C(u32 heap, u32 heap2, u32 a, u32 b);
extern void func_02210124(char *p);
extern void func_02034A5C(int handle);
void func_021A1480(u32 *p);
void func_021A14A0(u32 *p);
extern unsigned char abs_id_21[];


/*
 * Addresses are Black-image addresses.
 */
void func_021A1480(u32 *p)
{
    func_02034AC4((int)abs_id_21);
    p[8] = (u32)func_021F000C(0x70, ((u16 *)p)[6], (u32)p, p[5]);
}


void func_021A14A0(u32 *p)
{
    func_02210124((char *)p[8]);
    func_02034A5C((int)abs_id_21);
}
