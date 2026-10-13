/*
 * function: func_021D4CD8
 * address: 0x021D4CD8
 * packet: pkt_ov122_021D4CD8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   data_021D58E0 0x021D58E0 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 */
#include "../include/Obj01405.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0x10]; void *f10[11]; } Object;
extern Row data_021D58E0[];
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
void func_021D4CD8(int i, int value, int force, int mode, Object *p)
{
    if (p->f10[i] && !force) return;
    if (!p->f10[i])
        p->f10[i] = (void *)BMP_WIN_Create((int)7, (u8)data_021D58E0[i].f00, (u8)data_021D58E0[i].f04,
            (u8)data_021D58E0[i].f08, data_021D58E0[i].f0c, (int)13, (int)0);
    BMP_Clear(BMP_WIN_GetBmp(p->f10[i]), 0);
    if (mode) {
        MSGDATA_ReadString(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f50);
        func_0201F250(((struct Obj01405 *)p)->f48, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f50);
    } else {
        MSGDATA_ReadString(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f54);
    }
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f10[i]), 0, 0, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f4C, 0x39e3);
    BMP_WIN_TransferChars(p->f10[i]);
    BMP_WIN_MakeScreen(p->f10[i]);
}
