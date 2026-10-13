/*
 * function: func_021D9634
 * address: 0x021D9634
 * packet: pkt_ov123_021D9634
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj03800.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
extern void TIME_ICON_Delete(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021D9634(char *p) { if(((struct Obj03800 *)p)->f90) { TIME_ICON_Delete(((struct Obj03800 *)p)->f90); ((struct Obj03800 *)p)->f90=0; } if(((struct Obj03800 *)p)->f48) { func_0201F7A8(((struct Obj03800 *)p)->f48,2); BMP_WIN_ClearScreen(((struct Obj03800 *)p)->f48); func_02041B6C(5); BMP_WIN_Delete(((struct Obj03800 *)p)->f48); ((struct Obj03800 *)p)->f48=0; } }
