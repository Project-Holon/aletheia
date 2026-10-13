/*
 * function: func_021DEA0C
 * address: 0x021DEA0C
 * packet: pkt_ov137_021DEA0C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E217C 0x021E217C data a4
 *   func_021E0570 0x021E0570 thumb ov137
 *   func_021E07A4 0x021E07A4 thumb ov137
 *   func_021DF864 0x021DF864 thumb ov137
 *   func_021DEA68 0x021DEA68 thumb ov137
 *   func_02030D28 0x02030D28 arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj23742.h"
typedef unsigned char u8;
extern int (*const d_021E217C[])(void *);
typedef unsigned int   u32;
struct Ctx;
extern void func_021E0570(u8 *p);
extern void func_021E07A4(char *p);
extern void func_021DF864(u8 *p);
extern void func_021DEA68(char *p);
extern void func_02030D28(struct Ctx *c);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 func_0200FB24(void);
int func_021DEA0C(int a, int b, int c, u8 *p)
{
    int result;
    do { result = d_021E217C[*(int *)p](p); } while (result == 1);
    if (result == 2) return 1;
    func_021E0570(p);
    func_021E07A4((char *)p);
    func_021DF864(p);
    func_021DEA68((char *)p);
    func_02030D28(((struct Obj23742 *)p)->fD98);
    if (WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
    return 0;
}
