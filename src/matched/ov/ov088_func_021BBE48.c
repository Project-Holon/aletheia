/*
 * function: STARTMENU_OpenNoticeWindow
 * address:  0x021BBE48
 * packet:   pkt_ov088_021BBE48
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   STARTMENU_DrawFrameBox  0x021BBA64  thumb  ov088
 *   func_02041EE4  0x02041EE4  arm
 *   STARTMENU_ShowRowActors  0x021BB9DC  thumb  ov088
 */
#include "../include/Obj05167.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void STARTMENU_DrawFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern void func_02041EE4(u32, u32, u32);
extern void STARTMENU_ShowRowActors(char *, int);

void STARTMENU_OpenNoticeWindow(char *p)
{
    u32 msg = (u32)func_02045B38(0, 2, 0xe8, 0x800b);
    u32 s;
    u32 a;

    ((struct Obj05167 *)p)->fF0 = BMP_WIN_Create(0, 2, 2, 0x1e, 0x14, 5, 1);
    s = (u32)func_02045EC0((struct MsgBank *)msg, 0x20);
    a = ((struct Obj05167 *)p)->f68;
    PRINTSYS_PrintQueColor((void *)a, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05167 *)p)->fF0), 0, 0, s, ((struct Obj05167 *)p)->f58, 0x440);
    ((struct Obj05167 *)p)->fF4 = 1;
    STRBUF_Delete((struct U16Vec *)s);
    MSGDATA_Delete((struct Rec *)msg);

    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj05167 *)p)->fF0));
    func_02041B6C(0);
    STARTMENU_DrawFrameBox(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    STARTMENU_ShowRowActors(p, 0);
}
