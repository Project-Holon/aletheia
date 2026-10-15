/*
 * function: B_PLIST_DRAW_PrintHeader
 * address: 0x0220C60C
 * packet: pkt_ov198_0220C60C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Clear 0x02043B5C arm
 */
#include "../include/Obj00507.h"
#include "../include/Obj25142.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct CharBuf;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Flags { u8 pad[0x2177]; u8 low:4; u8 high:4; };
void B_PLIST_DRAW_PrintHeader(char *p, int id)
{
    void *t;
    void *f;
    BMP_Clear((void *)BMP_WIN_GetBmp(((struct Obj00507 *)p)->f1F60), 15);
    t = func_02045EC0(((struct Obj00507 *)p)->f1EA0, id);
    f = ((struct Obj00507 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(((struct Obj00507 *)p)->f1F60), 0, 0, (u32)t, ((struct Obj25142 *)(*(char * *)&((struct Obj00507 *)p)->f0))->fC, 0x440);
    ((struct Obj00507 *)p)->f1F64 = 1;
    STRBUF_Delete(t);
    ((struct Flags *)p)->high = 1;
}
