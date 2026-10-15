/*
 * function: POKE_SUMMARY_MAIN_CreateBmpWindows
 * address: 0x021B67A4
 * packet: pkt_ov173_021B67A4
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: const extern table restores the original argument-load scheduling.
 * symbols:
 *   d_021B8420 0x021B8420 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 */
#include "../include/Obj00180.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 a,b,c,d,e,f,g; } Entry;
extern const Entry d_021B8420[];
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 APP_KEYCURSOR_CreateDefault(int,int,int,int);
void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *p)
{
    u32 i;
    u32 h;
    for (i=0;i<16;i++) {
        *(u32 *)(p+i*4+4)=BMP_WIN_Create((u8)d_021B8420[i].a,(u8)d_021B8420[i].b,(u8)d_021B8420[i].c,(u8)d_021B8420[i].d,d_021B8420[i].e,d_021B8420[i].f,(int)1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p+i*4+4))),0);
    }
    h=((struct Obj00180 *)p)->f28;
    BMP_WIN_ClearScreen((struct Descriptor *)h);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    ((struct Obj00180 *)p)->f21C=APP_KEYCURSOR_CreateDefault(15,1,1,79);
}
