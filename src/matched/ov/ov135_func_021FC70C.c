/*
 * function: func_021FC70C
 * address: 0x021FC70C
 * packet: pkt_ov135_021FC70C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4E30 0x021F4E30 thumb ov135
 *   func_021F4E64 0x021F4E64 thumb ov135
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   func_0200ADB4 0x0200ADB4 thumb
 *   func_021F6DE8 0x021F6DE8 thumb ov135
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021FC810 0x021FC810 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FCBF0 0x021FCBF0 thumb ov135
 */
#include "../include/Obj00045.h"
#include "../include/Obj23409.h"
extern unsigned int func_021F4E30(unsigned char *p);
extern void func_021F4E64(unsigned char *p);
extern unsigned int BMP_MENUWORK_Delete(void *p);
extern void *func_0200ADB4(void *);
extern int func_021F6DE8(unsigned int handle);
typedef unsigned int   u32;
extern u32 func_0201AA18(void *p);
typedef unsigned char  u8;
extern void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FCBF0(char *p);
int func_021FC70C(char *p)
{
    int r;
    void *q;
    r = func_021F4E30((unsigned char *)p);
    if (r == 1) {
        func_021F4E64((unsigned char *)p);
        BMP_MENUWORK_Delete(((struct Obj00045 *)p)->fDE8);
        q = func_0200ADB4(**(void ** *)&((struct Obj00045 *)p)->f0);
        if (func_021F6DE8((unsigned int)q) && func_0201AA18(((struct Obj23409 *)(*(char * *)&((struct Obj00045 *)p)->f0))->f8) == 6) {
            func_021FC810((u8 *)p, 0x2a, 1, 0, 0xf0f, q);
            func_021F4E98((u8 *)p, 3, 1);
            return 2;
        }
        func_021FC810((u8 *)p, 6, 1, 0, 0xf0f, q);
        func_021F4E98((u8 *)p, 3, 5);
        func_021FCBF0(p);
    } else if (r == 2 || r == -2) {
        func_021F4E64((unsigned char *)p);
        BMP_MENUWORK_Delete(((struct Obj00045 *)p)->fDE8);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        func_021FCBF0(p);
    }
    return 2;
}
