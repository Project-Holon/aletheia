/*
 * function: func_021DF1C4
 * address: 0x021DF1C4
 * packet: pkt_ov137_021DF1C4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1584 0x021E1584 thumb ov137
 *   func_021E0A44 0x021E0A44 thumb ov137
 *   func_02039338 0x02039338 arm
 */
typedef unsigned char u8;
extern void func_021E1584(void *, int);
extern u8 *func_021E0A44(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02039338(void);
extern void func_020061E4(u32 a);
int func_021DF1C4(u8 *p)
{
    func_021E1584(p, 0);
    *(u8 **)(p + 0x28) = func_021E0A44(p);
    if (func_02039338() == 0) {
        if (*(int *)(*(u8 **)(p + 0x28) + 0xc) == func_02039338())
            *(int *)p = 29;
        else
            *(int *)p = 30;
    } else {
        *(int *)p = 31;
    }
    func_020061E4(1833);
    return 1;
}
