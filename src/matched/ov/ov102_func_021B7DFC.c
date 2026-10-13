/*
 * function: func_021B7DFC
 * address: 0x021B7DFC
 * packet: pkt_ov102_021B7DFC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CC4 0x021B7CC4 thumb ov102
 *   func_021B7CC0 0x021B7CC0 thumb ov102
 *   func_021B7CBC 0x021B7CBC thumb ov102
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 */
#include "../include/Obj05269.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CC4(void *);
extern int func_021B7CC0(void *);
extern int func_021B7CBC(void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned int   u32;
struct CharBuf;
struct MsgBank;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void func_021B7DFC(u8 *p, void *q, int n, int x, s16 y)
{
    int a, b, c;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05269 *)p)->f0)), ((struct Obj05269 *)p)->f10);
    MSGDATA_ReadString((struct MsgBank *)a, n, (void *)(((struct Obj05269 *)p)->fC));
    PRINTSYS_PrintQue((struct PrintSys *)b, (int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05269 *)p)->f4), (s16)x, (s16)y, (void *)(((struct Obj05269 *)p)->fC), (int)c);
    p[8] = 1;
}
