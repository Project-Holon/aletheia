/*
 * function: func_021D4AD4
 * address: 0x021D4AD4
 * packet: pkt_ov122_021D4AD4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D45E8 0x021D45E8 thumb ov122
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 */
#include "../include/Obj02472.h"
typedef unsigned short u16;
extern void func_0201DD68(void);
extern void func_021D45E8(char *);
typedef unsigned int   u32;
struct Descriptor;
struct Rec;
struct U16Vec;
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021D4AD4(char *p)
{
    unsigned ranges;
    func_0201DD68();
    func_021D45E8(p);
    func_02040DA8(5, 1, 0);
    ranges = ((struct Obj02472 *)p)->f5C;
    func_0203FB44(5, (u16)ranges, (u16)(ranges >> 16));
    func_020403F4(5);
    func_020403F4(4);
    MSGDATA_Delete(((struct Obj02472 *)p)->f44);
    GF_FONT_Delete(((struct Obj02472 *)p)->f4C);
    STRBUF_Delete(((struct Obj02472 *)p)->f54);
    STRBUF_Delete(((struct Obj02472 *)p)->f50);
    STRBUF_Delete(((struct Obj02472 *)p)->f58);
    BMP_WIN_Delete(((struct Obj02472 *)p)->f3C);
}
