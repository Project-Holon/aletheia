/*
 * function: func_021D6888
 * address: 0x021D6888
 * packet: pkt_ov121_021D6888
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D6922.
 * symbols:
 *   MYSTERY_NET_Step 0x021DE300 thumb ov121
 *   func_021DA898 0x021DA898 thumb ov121
 *   MYSTERY_GRAPHIC_Draw 0x021D9718 thumb ov121
 *   MYSTERY_GRAPHIC_DrawScene 0x021D972C thumb ov121
 *   MYSTERY_GRAPHIC_DrawEnd 0x021D9738 thumb ov121
 *   func_021D9238 0x021D9238 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021DA840 0x021DA840 thumb ov121
 *   func_021DA8AC 0x021DA8AC thumb ov121
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 */
#include "../include/Obj01402.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern void MYSTERY_NET_Step(char *p);
extern void func_021DA898(char *p);
extern void MYSTERY_GRAPHIC_Draw(u8 *p);
extern void MYSTERY_GRAPHIC_DrawScene(char *p);
extern void MYSTERY_GRAPHIC_DrawEnd(char *p);
extern void func_021D9238(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021D9E50(u8 *p);
extern int func_021DA2C8(u8 *p);
extern int func_021DA840(void **);
extern int func_021DA8AC(u32 *p);
int func_021D6888(int a, int b, int c, char *p)
{
    MYSTERY_NET_Step(((struct Obj01402 *)p)->f3B0);
    func_021DA898(((struct Obj01402 *)p)->f290);
    if (((struct Obj01402 *)p)->f394) {
        MYSTERY_GRAPHIC_Draw(((struct Obj01402 *)p)->f394);
        MYSTERY_GRAPHIC_DrawScene(((struct Obj01402 *)p)->f394);
        MYSTERY_GRAPHIC_DrawEnd(((struct Obj01402 *)p)->f394);
    }
    func_021D9238(p + 0x138);
    PRINTSYS_QUE_Main(((struct Obj01402 *)p)->f39C);
    if (((struct Obj01402 *)p)->f284) func_021D9E50(((struct Obj01402 *)p)->f284);
    if (((struct Obj01402 *)p)->f28C) func_021DA2C8(((struct Obj01402 *)p)->f28C);
    if (((struct Obj01402 *)p)->f288) func_021DA2C8(((struct Obj01402 *)p)->f288);
    if (((struct Obj01402 *)p)->f270) func_021DA840(*(void ** *)&((struct Obj01402 *)p)->f270);
    if (func_021DA8AC(((struct Obj01402 *)p)->f290)) return 1;
    return 0;
}
