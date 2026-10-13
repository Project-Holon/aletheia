/*
 * function: func_021B6824
 * address: 0x021B6824
 * packet: pkt_ov174_021B6824
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 * symbols:
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201DD68 0x0201DD68 thumb
 */
#include "../include/Obj00681.h"
typedef unsigned char u8;
extern int APP_KEYCURSOR_Delete(int a0);
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_020452E8(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_0201DD68(void);
void func_021B6824(u8 *p)
{
    APP_KEYCURSOR_Delete((int)(((struct Obj00681 *)p)->f7C));
    func_0201C4C0(((struct Obj00681 *)p)->f78);
    if(((struct Obj00681 *)p)->f64) func_0201CE48(((struct Obj00681 *)p)->f64);
    if(((struct Obj00681 *)p)->f70) STRBUF_Delete(((struct Obj00681 *)p)->f70);
    if(((struct Obj00681 *)p)->f74) func_0201ED04(((struct Obj00681 *)p)->f74);
    MSGDATA_Delete(((struct Obj00681 *)p)->f6C);
    MSGDATA_Delete(((struct Obj00681 *)p)->f68);
    if(((struct Obj00681 *)p)->f5C) func_020452E8(((struct Obj00681 *)p)->f5C);
    GF_FONT_Delete(((struct Obj00681 *)p)->f60);
    TCBL_Destroy(((struct Obj00681 *)p)->f58);
    func_0201DD68();
}
