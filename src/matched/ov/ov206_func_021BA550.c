/*
 * unit: yes
 * function: func_021BA550
 * address: 0x021BA550
 * packet: pkt_ov206_021BA550
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   func_021BB160 0x021BB160 thumb ov206
 *   func_021BA4F4 0x021BA4F4 thumb ov206
 *   func_021BB0FC 0x021BB0FC thumb ov206
 *   func_021BBC38 0x021BBC38 thumb ov206
 *   func_021BB13C 0x021BB13C thumb ov206
 *   func_021BBE34 0x021BBE34 thumb ov206
 */
#include "../include/Obj00598.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern void func_021BB160(char *p, int i);
extern void func_021BA4F4(char *p);
extern void func_021BB0FC(void *obj);
struct S;
extern void func_021BBC38(struct S *p);
extern void func_021BB13C(void *a0, void *a1, void *a2, void *a3);
extern void func_021BBE34(struct S *p, int v);
void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6)
{
    int x;
    u32 h;
    int y;
    if (((struct Obj00598 *)p)->f26C != 0) POKE_PERSONAL_Delete(((struct Obj00598 *)p)->f26C);
    ((struct Obj00598 *)p)->f26C = POKE_PERSONAL_Create(a1, a2, ((struct Obj00598 *)p)->f0);
    if (((struct Obj00598 *)p)->fB4 != 0) ((struct Obj00598 *)p)->fB4 = 0; else ((struct Obj00598 *)p)->fB4 = 1;
    if (((struct Obj00598 *)p)->fE0 != 0) ((struct Obj00598 *)p)->fE0 = 0; else ((struct Obj00598 *)p)->fE0 = 1;
    if (((struct Obj00598 *)p)->f190 != 0) ((struct Obj00598 *)p)->f190 = 0; else ((struct Obj00598 *)p)->f190 = 1;
    func_021BB160(p, ((struct Obj00598 *)p)->fB4);
    func_021BA4F4(p);
    ((struct Obj00598 *)p)->fC = a1;
    ((struct Obj00598 *)p)->fE = a2;
    ((struct Obj00598 *)p)->f10 = a3;
    ((struct Obj00598 *)p)->f12 = a4;
    ((struct Obj00598 *)p)->f14 = a5;
    ((struct Obj00598 *)p)->f8 = a6;
    h = (u16)POKE_PERSONAL_GetParam(((struct Obj00598 *)p)->f26C, 0x20);
    if (((struct Obj00598 *)p)->fE >= h) ((struct Obj00598 *)p)->fE = 0;
    func_021BB0FC(p);
    func_021BBC38((struct S *)p);
    switch (((struct Obj00598 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + ((struct Obj00598 *)p)->f1B4)), (void *)(((struct Obj00598 *)p)->fB4));
    func_021BBE34((struct S *)p, (((struct Obj00598 *)p)->f44 != 0) ? 0 : 1);
}
