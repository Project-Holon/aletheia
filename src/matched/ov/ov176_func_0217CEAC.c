/*
 * function: func_0217CEAC,func_0217CFD0,func_0217CFDC
 * unit: yes
 * address: 0x0217CEAC
 * packet: pkt_ov176_0217CEAC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * function_starts: 0217CFD0,0217CFDC
 * ABI: coordinates are byte locals; X/width/height externs are widened because original has no call-site narrowing.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   func_021E89D0 0x021E89D0 thumb ov177
 *   func_021E8A00 0x021E8A00 thumb ov177
 */
#include "../include/Obj00053.h"
#include "../include/Obj24418.h"
#include "../include/Obj24419.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f00, f04, f08, option0, option1, option2, f18, count; u16 f20, f22, f24, f26; u32 f28; u16 f2c, f2e; } Menu;
extern void func_02082BCC(void *, int, u32);
extern void *func_021E88B0(Menu *, int, u8, int, int, int);
extern void func_021E89D0(void *);
extern int func_021E8A00(void *);
void func_0217CEAC(u8 *p, int mode)
{
    Menu rec;
    int layout;
    u8 x, y, width, height;
    func_02082BCC(&rec, 0, 0x30);
    rec.f00 = ((struct Obj00053 *)p)->f20;
    rec.f04 = *(u32 *)&((struct Obj00053 *)p)->f1A8;
    rec.f08 = *(u32 *)&((struct Obj00053 *)p)->f1AC;
    switch (mode) {
    case 3: rec.f2e = 1;
    case 0:
        rec.option0 = 6; rec.option1 = 7; rec.count = 2; rec.f28 = 1; rec.f2c = 1; layout = 1; break;
    case 1:
        rec.f28 = 0;
        if (((struct Obj00053 *)p)->f1D0 && ((struct Obj24418 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC == 0) {
            rec.option0 = 13; rec.option1 = 14; rec.option2 = 15; rec.count = 3;
        } else { rec.option0 = 13; rec.option1 = 15; rec.count = 2; }
        layout = 0; break;
    case 2:
        rec.f28 = 0;
        if (((struct Obj00053 *)p)->f1D0 && ((struct Obj24419 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC == 0) {
            rec.option0 = 14; rec.option1 = 30; rec.count = 2;
        } else { rec.option0 = 30; rec.count = 1; }
        layout = 0; break;
    }
    rec.f20 = 0; rec.f22 = 15; rec.f24 = 13; rec.f26 = 1;
    switch (layout) {
    case 0: width = 28; height = rec.count * 2; x = 2; y = 9 - height / 2; break;
    case 1: width = 12; height = rec.count * 2; x = 19; y = 17 - height; break;
    }
    ((struct Obj00053 *)p)->f4 = func_021E88B0(&rec, x, y, width, height, ((struct Obj00053 *)p)->f1C8);
    ((struct Obj00053 *)p)->f8 = mode;
}
void func_0217CFD0(int *p) { func_021E89D0((void *)p[1]); }
int func_0217CFDC(int *p) { return func_021E8A00((void *)p[1]); }
