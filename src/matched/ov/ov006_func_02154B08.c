/*
 * function: EVENT_WIFICLUB_InitWork
 * address:  0x02154B08
 * packet:   pkt_ov006_02154B08
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4   0x020120F4  thumb
 *   func_02012138   0x02012138  thumb
 *   func_020124E8   0x020124E8  thumb
 *   func_02026454   0x02026454  thumb
 *   func_02026400   0x02026400  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_02030734   0x02030734  arm
 *   func_02012EBC   0x02012EBC  thumb
 *   func_0201283C   0x0201283C  thumb
 *   GFL_USE_GetBgmNo   0x02005C44  thumb
 *   func_0200ADF0   0x0200ADF0  thumb
 *   d_02154C80      0x02154C80  data  ov006  a4
 */
#include "../include/Obj00652.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct BigObj;
struct Comm;
struct Ctx;
struct Party;
struct Reg;
void *func_020120F4(const struct Ctx *p);
struct Ctx;
struct Obj;
u32 func_02012138(const struct Ctx *p);
void *func_020124E8(struct Obj *p);
u32 func_02026454(void *obj);
void func_02026400(struct Comm *p);
struct Party *func_0201A920(u32 heap);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void *func_02012EBC(struct Big *p);
u32 func_0201283C(const struct BigObj *p);
u16 GFL_USE_GetBgmNo(void);
struct Reg *func_0200ADF0(u32 heap);

extern char d_02154C80[];

typedef struct Sub {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    u8  f20;
    u8  pad21[0x25];
    u8  f46;
    u8  pad47[2];
    u8  f49;
} Sub;

void EVENT_WIFICLUB_InitWork(void *obj_in, void *p, int a, int b)
{
    char *obj;
    Sub *s;

    if (func_02026454((void *)func_02012138(p)))
        func_02026400((struct Comm *)func_02012138(p));
    obj = func_020124E8(obj_in);
    ((struct Obj00652 *)obj)->f4 = p;
    ((struct Obj00652 *)obj)->f8 = a;
    ((struct Obj00652 *)obj)->f0 = obj_in;
    ((struct Obj00652 *)obj)->f14 = b;
    *(Sub * *)&((struct Obj00652 *)obj)->f5C = func_02030734(0x8004, 0x4c, 1, d_02154C80, 0x2b0);
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f00 = (int)func_02030734(0x8004, 0x20, 1, d_02154C80, 0x2b1);
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f04 = (int)func_020120F4(((struct Obj00652 *)obj)->f4);
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f08 = (int)func_02012EBC((struct Big *)((*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f04));
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f46 = 1;
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f49 = 0;
    ((struct Obj00652 *)obj)->f90 = (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f04;
    ((struct Obj00652 *)obj)->f94 = func_0201283C((const struct BigObj *)(((struct Obj00652 *)obj)->f90));
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f0c = 0;
    ((struct Obj00652 *)obj)->f7C = ((struct Obj00652 *)obj)->f168 = (int)func_0201A920(0x8004);
    *(char * *)&((struct Obj00652 *)obj)->fC = obj;
    ((struct Obj00652 *)obj)->f170 = GFL_USE_GetBgmNo();
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f14 = (int)func_0201A920(0x8001);
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f18 = (int)func_0201A920(0x8001);
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f1c = (int)func_0200ADF0(0x8001);
    (*(Sub * *)&((struct Obj00652 *)obj)->f5C)->f20 = 1;
}
