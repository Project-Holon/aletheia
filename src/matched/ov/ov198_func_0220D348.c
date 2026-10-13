/*
 * function: func_0220D348
 * address: 0x0220D348
 * packet: pkt_ov198_0220D348
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
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj10844.h"
#include "../include/Obj25169.h"
#include "../include/Obj25170.h"
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
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
void func_0220D348(char *p, int i, int id)
{
    void *bank;
    void *t;
    void *f;
    bank = func_02045B38(0, 2, 0xCA, ((struct Obj25169 *)(*(char * *)&((struct Obj10844 *)p)->f0))->f10);
    t = func_02045EC0(bank, id);
    f = ((struct Obj10844 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25170 *)(*(char * *)&((struct Obj10844 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
    MSGDATA_Delete(bank);
}
