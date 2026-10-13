/*
 * function: func_022052E8
 * address: 0x022052E8
 * packet: pkt_ov195_022052E8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj02240.h"
extern int APP_KEYCURSOR_Delete(int);
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
void func_022052E8(int task, int *p)
{
    APP_KEYCURSOR_Delete(((struct Obj02240 *)p)->f84);
    if (((struct Obj02240 *)p)->f64) func_0201CE48((struct Rec3 *)(((struct Obj02240 *)p)->f64));
    TCBL_Destroy((struct S02031140 *)(((struct Obj02240 *)p)->f68));
    if (((struct Obj02240 *)p)->f80) STRBUF_Delete((struct U16Vec *)(((struct Obj02240 *)p)->f80));
    MSGDATA_Delete(((struct Obj02240 *)p)->f78);
    MSGDATA_Delete(((struct Obj02240 *)p)->f7C);
    func_0203FB44(1, (unsigned short)(((struct Obj02240 *)p)->f74), (unsigned short)(((struct Obj02240 *)p)->f74 >> 16));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f6C));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f70));
}
