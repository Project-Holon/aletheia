/*
 * function: INTRUDE_COMM_RecvUnionInfo
 * address:  0x021746EC
 * packet:   pkt_ov011_021746EC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   func_020127D0  0x020127D0  thumb
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb ov010
 *   FIELD_WFBC_DATA_LOCAL_Sanitize  0x021861F4  thumb ov020
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_TakeUnionInfo  0x02012800  thumb
 */
#include "../include/Obj12421.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 GAME_COMM_GetGameData(void *obj);
u8 *func_020127D0(u8 *o, u32 idx);
int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
typedef unsigned short u16;
void FIELD_WFBC_DATA_LOCAL_Sanitize(u16 *p, int x);
void MI_CpuCopy8(void *d, void *s, int n);
void GAME_DATA_TakeUnionInfo(u8 *obj, void *dst);

void INTRUDE_COMM_RecvUnionInfo(int a, int b, void *c, char *d)
{
    int h;
    int s;

    h = GAME_COMM_GetGameData((void *)(((struct Obj12421 *)d)->f4));
    s = (int)func_020127D0((u8 *)h, 0);
    FIELD_WFBC_DATA_LOCAL_Sanitize(c, GAME_DATA_GetMyStatusByNetId((void *)h, a));
    MI_CpuCopy8(c, (void *)s, 0x1E8);
    GAME_DATA_TakeUnionInfo((u8 *)h, c);
    d[0x90C] = 1;
}
