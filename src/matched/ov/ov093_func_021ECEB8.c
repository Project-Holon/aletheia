/*
 * function: BTLV_SCU_StartMessage
 * address:  0x021ECEB8
 * packet:   pkt_ov093_021ECEB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   BTL_MAIN_GetTextSpeedFrames  0x021B85DC  thumb  ov093
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 */
#include "../include/Obj00027.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Rec;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern int BTL_MAIN_GetTextSpeedFrames(unsigned char *p);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void PRINTSYS_PrintStreamStop(void *p);

void BTLV_SCU_StartMessage(u8 *a, u32 b, u16 s, u32 c)
{
    void *o;

    BMP_Clear((struct CharBuf *)(((struct Obj00027 *)a)->f4), 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    o = PRINTSYS_PrintStreamCallBack(((struct Obj00027 *)a)->f0, 0, 0, b, ((struct Obj00027 *)a)->f24,
                      BTL_MAIN_GetTextSpeedFrames((unsigned char *)(*(int *)&((struct Obj00027 *)a)->f134)),
                      ((struct Obj00027 *)a)->f2C, 0,
                      ((struct Obj00027 *)a)->f13C, 0xc, c);
    ((struct Obj00027 *)a)->f30 = o;
    PRINTSYS_PrintStreamStop(o);
    a[0x13f] = 0;
    a[0x13e] = 0;
    if (s == 0xff) {
        ((struct Obj00027 *)a)->f148 = 0x50;
        ((struct Obj00027 *)a)->f14C = 0;
    } else {
        ((struct Obj00027 *)a)->f148 = s;
        ((struct Obj00027 *)a)->f14C = s;
    }
    ((struct Obj00027 *)a)->f14A = ((struct Obj00027 *)a)->f148;
    a[0x141] = 0;
}
