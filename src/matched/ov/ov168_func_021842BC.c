/*
 * function: func_021842BC
 * address: 0x021842BC
 * packet: pkt_ov168_021842BC
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   BMP_WIN_CreateAt 0x02045180 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02184888 0x02184888 data a1
 *   d_02184868 0x02184868 data a2
 */
#include "../include/Obj03845.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct MsgBank;
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int BMP_WIN_CreateAt(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, unsigned int offset);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern const u8 d_02184888[];
extern u16 d_02184868[];
void func_021842BC(void **p, int heap)
{
    int i;
    const u8 *row;
    void *a;
    void *b;
    void *s;
    p[3] = func_02045B38((int)0,(int)2,(int)65,(u16)heap);
    for (i=0;i<3;i++) {
        row = d_02184888+i*12;
        p[i] = (void *)BMP_WIN_CreateAt((int)row[0],(int)row[1],(int)row[2],(int)row[3],row[4],row[5],(int)(((struct Obj03845 *)row)->f6));
        a = func_02045770(p[i]);
        BMP_Clear(a,0);
        BMP_WIN_ClearScreen(p[i]);
        b = func_02045EC0(p[3],i);
        PRINTSYS_PrintColor(a,row[8],0,b,p[4],d_02184868[i]);
        STRBUF_Delete(b);
        s = p[i];
        BMP_WIN_TransferChars(s);
        BMP_WIN_MakeScreen(s);
        func_020409B4(func_02045730(s));
    }
}
