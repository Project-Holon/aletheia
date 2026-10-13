/*
 * function: func_021F4748
 * address: 0x021F4748
 * packet: pkt_ov112_021F4748
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 */
#include "../include/Obj01924.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void TIME_ICON_Delete(u8 *);
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
void func_021F4748(u8 *p)
{
    func_0201C6EC((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    func_0201C4C0((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    if (*(u8 * *)&((struct Obj01924 *)p)->f34) {
        TIME_ICON_Delete(*(u8 * *)&((struct Obj01924 *)p)->f34);
        *(u32 *)&((struct Obj01924 *)p)->f34=0;
    }
    if (((struct Obj01924 *)p)->f24) func_0201CE48(((struct Obj01924 *)p)->f24);
    if (((struct Obj01924 *)p)->f2C) STRBUF_Delete(((struct Obj01924 *)p)->f2C);
    MSGDATA_Delete(((struct Obj01924 *)p)->f28);
    func_020452E8(((struct Obj01924 *)p)->f1C);
    GF_FONT_Delete(((struct Obj01924 *)p)->f20);
    TCBL_Destroy(((struct Obj01924 *)p)->f18);
}
