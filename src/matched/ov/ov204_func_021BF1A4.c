/*
 * function: func_021BF1A4
 * address: 0x021BF1A4
 * packet: pkt_ov204_021BF1A4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF580 0x021BF580 thumb ov204
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01292.h"
struct U16Vec; struct Descriptor; struct S02031140;
typedef unsigned char  u8;
extern void func_021BF580(u8 *p);
extern int APP_KEYCURSOR_Delete(int);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int GF_FONT_Delete(void *ptr);
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *);
struct PrintSys;
struct Rec;
struct WordSet;
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BF1A4(char *p)
{
    func_021BF580((u8 *)p);
    APP_KEYCURSOR_Delete(((struct Obj01292 *)p)->f20);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    GF_FONT_Delete(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        func_0201CE48((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    func_0201C4C0(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        MSGDATA_Delete(((struct Obj01292 *)p)->fC);
    func_0201ED04(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}
