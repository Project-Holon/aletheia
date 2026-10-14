/*
 * function: GURU2_MAIN_DeleteWindows
 * address: 0x021E00D4
 * packet: pkt_ov137_021E00D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GURU2_MAIN_DeleteNameWindows 0x021E03A0 thumb ov137
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj05432.h"
typedef unsigned char u8;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
typedef unsigned int   u32;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void GURU2_MAIN_DeleteNameWindows(u8 *);
struct Rec;
struct U16Vec;
struct WordSet;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_Exit(void);
void GURU2_MAIN_DeleteWindows(u8 *p)
{
    u8 *s;
    void *obj;
    int i;
    s=p+3296;
    obj=((struct Obj05432 *)s)->f10;
    BMP_WIN_ClearScreen(obj);
    func_020409B4(BMP_WIN_GetBgLayer(obj));
    BMP_WIN_Delete(((struct Obj05432 *)s)->f10);
    GURU2_MAIN_DeleteNameWindows(p);
    MSGDATA_Delete(((struct Obj05432 *)s)->f8);
    func_0201ED04(((struct Obj05432 *)s)->fC);
    GF_FONT_Delete(((struct Obj05432 *)s)->f4);
    STRBUF_Delete(((struct Obj05432 *)s)->f5C);
    for(i=0;i<5;i++) STRBUF_Delete(*(void **)(p+164+i*4));
    BMP_WIN_Exit();
}
