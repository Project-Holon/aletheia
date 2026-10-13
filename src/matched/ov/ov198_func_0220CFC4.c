/*
 * function: func_0220CFC4
 * address: 0x0220CFC4
 * packet: pkt_ov198_0220CFC4
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
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj06650.h"
#include "../include/Obj25164.h"
#include "../include/Obj25165.h"
#include "../include/Obj25166.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int func_022110D4(u8 *, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
void func_0220CFC4(char *p, int index)
{
    char *elem;
    void *bank;
    void *t;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    bank = func_02045B38(0, 2, 0xB7, ((struct Obj25164 *)(*(char * *)&((struct Obj06650 *)p)->f0))->f10);
    t = func_02045EC0(bank, ((struct Obj25165 *)elem)->f18);
    f = ((struct Obj06650 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(((struct Obj06650 *)p)->f1F80), 0, 0, (u32)t, ((struct Obj25166 *)(*(char * *)&((struct Obj06650 *)p)->f0))->fC, 0x2120);
    ((struct Obj06650 *)p)->f1F84 = 1;
    STRBUF_Delete(t);
    MSGDATA_Delete(bank);
}
