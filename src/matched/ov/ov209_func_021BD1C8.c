/*
 * function: ZUKAN_LIST_StateCursorFlash
 * address: 0x021BD1C8
 * packet: pkt_ov209_021BD1C8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: repeated decrement in each arm cross-jumps through branch stubs; explicit shared goto costs DIFF81/156.
 * symbols:
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01435.h"
typedef unsigned char u8;
extern int FRAME_LIST_GetCursor(char *);
typedef unsigned int   u32;
extern void FRAME_LIST_SetRowPalette(u8 *p, int a, u32 b);
extern void func_02041B6C(unsigned);
int ZUKAN_LIST_StateCursorFlash(char *p)
{
    switch (((struct Obj01435 *)p)->fC26) {
    case 0:
    case 2:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            FRAME_LIST_SetRowPalette((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)FRAME_LIST_GetCursor(*(char * *)&((struct Obj01435 *)p)->fC2C), 1);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 1:
    case 3:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            FRAME_LIST_SetRowPalette((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)FRAME_LIST_GetCursor(*(char * *)&((struct Obj01435 *)p)->fC2C), 2);
            func_02041B6C(2);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 4:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            ((struct Obj01435 *)p)->fC26 = 0;
            return 8;
        }
        (((struct Obj01435 *)p)->fC27)--;
        break;
    }
    return 7;
}
