/*
 * function: POKE_SUMMARY_MAIN_StartTextStream
 * address: 0x021B7460
 * packet: pkt_ov173_021B7460
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   POKE_SUMMARY_MAIN_SetTextByKind 0x021B7378 thumb ov173
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   POKE_SUMMARY_MAIN_SoundStateCallback 0x021B74F8 thumb ov173
 */
#include "../include/Obj03858.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Rec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *, int, int, int);
extern void POKE_SUMMARY_MAIN_SetTextByKind(char *, u32);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32);
extern int POKE_SUMMARY_MAIN_SoundStateCallback(u32);
void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind)
{
    u32 zero;
    int speed;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03858 *)p)->f20), 15);
    zero = 0;
    func_0201F73C(((struct Obj03858 *)p)->f20, 0, 1, 13);
    POKE_SUMMARY_MAIN_SetTextByKind(p, kind);
    speed = MSG_SPEED_GetWait();
    ((struct Obj03858 *)p)->f6C = PRINTSYS_PrintStreamCallBack(*(u32 *)&((struct Obj03858 *)p)->f20, 0, 0, ((struct Obj03858 *)p)->f4C, ((struct Obj03858 *)p)->f60, speed, ((struct Obj03858 *)p)->f64, zero, 0x4f, 0xffff, (u32)POKE_SUMMARY_MAIN_SoundStateCallback);
    q = ((struct Obj03858 *)p)->f20;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
}
