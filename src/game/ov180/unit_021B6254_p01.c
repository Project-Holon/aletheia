/*
 * file:     unit_021B6254_p01.c
 * unit:     yes
 * function: func_021B6360, func_021B63E8
 * address:  0x021B6360
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(u8 *p);
extern void func_0207D63C(void *,u32,u32,u32,u32);
void func_021B6360(void);
void func_021B63E8(void);


void func_021B6360(void)
{
    u8 *p = func_020490F4(0xd8, 0x8d);
    func_02049B68(p, 1, 2, 0x6000, 0x20, 0x8d);
    func_02049B68(p, 1, 6, 0x6000, 0x20, 0x8d);
    func_02049658(p, 0x16, 3, 0, 0, 0, 0x8d);
    func_02049658(p, 0x16, 7, 0, 0, 0, 0x8d);
    func_020498F4(p, 0x1c, 3, 0, 0, 0, 0x8d);
    func_020498F4(p, 0x1c, 7, 0, 0, 0, 0x8d);
    func_02049238(p);
}

void func_021B63E8(void) {func_0207D63C((void *)0x04000050,1,46,6,10);func_0207D63C((void *)0x04001050,1,46,6,10);}
