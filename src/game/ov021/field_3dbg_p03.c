/*
 * file:     field_3dbg_p03.c
 * unit:     yes
 * function: func_021A14CC, func_021A14EC, func_021A1500, func_021A150C, func_021A1518
 * address:  0x021A14CC
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
 *   func_021EFEC0  0x021EFEC0  thumb  ov034
 *   abs_id_22      0x00000022  data
 *   func_021EFF34  0x021EFF34  thumb  ov034
 *   func_02034A5C  0x02034A5C  arm
 *   func_021EFF5C  0x021EFF5C  thumb  ov034
 *   func_021EFFB4  0x021EFFB4  thumb  ov034
 *   func_021F0044  0x021F0044  thumb  ov034
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

extern int func_02034AC4(signed int);
extern void *func_02188C80(void *p);
extern void *func_021EFEC0(int a0, int a1);
extern void func_021EFF34(char *p);
extern void func_02034A5C(int);
extern void func_021EFF5C(int *p);
extern void func_021EFFB4(int *p);
extern int func_021F0044(int *p);
void func_021A14CC(u32 *p);
void func_021A14EC(u32 *p);
void func_021A1500(u32 *p);
void func_021A150C(u32 *p);
int func_021A1518(u32 *p);
extern unsigned char abs_id_22[];


/*
 * Addresses are Black-image addresses.
 */
void func_021A14CC(u32 *p)
{
    func_02034AC4((int)abs_id_22);
    p[8] = (u32)func_021EFEC0((int)func_02188C80((void *)p[5]), ((u16 *)p)[6]);
}


void func_021A14EC(u32 *p)
{
    func_021EFF34((char *)p[8]);
    func_02034A5C((int)abs_id_22);
}


void func_021A1500(u32 *p)
{
    func_021EFF5C((int *)p[8]);
}


void func_021A150C(u32 *p)
{
    func_021EFFB4((int *)p[8]);
}


/*
 * 2026-10-01: byte-correct; tail-call target is an unlabelled ov034 Thumb function (listing reads it as ARM), no witness.
 *
 * Addresses are Black-image addresses.
 */
int func_021A1518(u32 *p)
{
    return func_021F0044((int *)p[8]);
}
