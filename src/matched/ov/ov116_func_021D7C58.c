/*
 * function: func_021D7C58
 * address: 0x021D7C58
 * packet: pkt_ov116_021D7C58
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D7FC4 0x021D7FC4 thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 *   func_021D82AC 0x021D82AC thumb ov116
 */
#include "../include/Obj01721.h"
typedef unsigned char u8;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void func_0201CE48(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021D7FC4(u8 *p);
extern void func_021D81B4(u8 *p);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021D82AC(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
void func_021D7C58(u8 *p) {
    if(((struct Obj01721 *)p)->f0!=0) {
        if(((struct Obj01721 *)p)->f9A4) func_0201CE48(((struct Obj01721 *)p)->f9A4);
        TCBL_Destroy(((struct Obj01721 *)p)->f9A8);
        MSGDATA_Delete(((struct Obj01721 *)p)->f990);
        func_0201ED04(((struct Obj01721 *)p)->f994);
        GF_FONT_Delete(((struct Obj01721 *)p)->f998);
        STRBUF_Delete(((struct Obj01721 *)p)->f99C);
        STRBUF_Delete(((struct Obj01721 *)p)->f9A0);
        func_021D7FC4(p);
        func_021D81B4(p);
        if(((struct Obj01721 *)p)->f980) {
            BMP_MENU_DeleteYesNo(((struct Obj01721 *)p)->f980);
            ((struct Obj01721 *)p)->f980=0;
        }
        func_020452E8(((struct Obj01721 *)p)->f97C);
        func_021D82AC(((struct Obj01721 *)p)->f8);
        func_0201DD68();
        func_02082BCC(p,0,0x9ac);
    }
}
