/*
 * function: func_021BA138
 * address: 0x021BA138
 * packet: pkt_ov218_021BA138
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B991C 0x021B991C thumb ov218
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021B9F98 0x021B9F98 thumb ov218
 *   func_021B9944 0x021B9944 thumb ov218
 *   func_021B9C74 0x021B9C74 thumb ov218
 *   func_021B9914 0x021B9914 thumb ov218
 *   func_021B61F8 0x021B61F8 thumb ov067
 */
#include "../include/Obj04644.h"
extern void func_021B991C(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
extern void func_021B9F98(int *, int);
extern void func_021B9944(void);
extern void func_021B9C74(u8 *p);
extern void func_021B9914(struct TaskMenu *p);
extern void func_021B61F8(unsigned char *, unsigned short);
int func_021BA138(unsigned char *task, char *ctx)
{
    func_021B991C(((struct Obj04644 *)ctx)->f1C);
    if (func_020279E8(((struct Obj04644 *)ctx)->f1C) != 0) {
        switch (func_02027A04(((struct Obj04644 *)ctx)->f1C)) {
        case 0:
            func_021B9F98((int *)ctx, 0);
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 65534);
            break;
        case 1:
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 0);
            break;
        }
        return 1;
    }
    return 0;
}
