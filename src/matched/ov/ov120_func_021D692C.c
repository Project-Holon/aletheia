/*
 * function: GTSNEGO_DISP_CreateTouchbar
 * address: 0x021D692C
 * packet: pkt_ov120_021D692C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8990 0x021D8990 data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Data { u32 w[8]; } Data;
typedef struct Config { Data *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } Config;
extern const Data d_021D8990;
extern void MI_CpuFill8(void *, u32, u32);
extern void *TOUCHBAR_Create(Config *, int);
void GTSNEGO_DISP_CreateTouchbar(u8 *p, int n)
{
    Data data = d_021D8990;
    Config c;
    MI_CpuFill8(&c, 0, 32);
    c.f0 = &data;
    c.f4 = 1;
    c.f8 = *(u32 *)&((struct Obj00199 *)p)->f10;
    c.fC = 7;
    c.f10 = 15;
    c.f18 = 2;
    c.f1c = 0;
    c.f14 = n;
    ((struct Obj00199 *)p)->fC = TOUCHBAR_Create(&c, ((struct Obj00199 *)p)->fF4);
}
