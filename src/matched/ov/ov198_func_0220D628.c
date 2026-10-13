/*
 * function: func_0220D628
 * address: 0x0220D628
 * packet: pkt_ov198_0220D628
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
 *   func_0201D304 0x0201D304 thumb
 */
#include "../include/Obj05524.h"
#include "../include/Obj25173.h"
#include "../include/Obj25174.h"
#include "../include/Obj25175.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_0220D628(char *p, int i)
{
    void *t;
    void *f;
    u32 width;
    if (((struct Obj25173 *)(*(char * *)&((struct Obj05524 *)p)->f0))->f4B == 4)
        t = func_02045EC0(((struct Obj05524 *)p)->f1EA0, 0x45);
    else
        t = func_02045EC0(((struct Obj05524 *)p)->f1EA0, 0x44);
    width = func_0201D304(t, ((struct Obj25174 *)(*(char * *)&((struct Obj05524 *)p)->f0))->fC, 0);
    f = ((struct Obj05524 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), (s16)((96 - width) >> 1), 5, (u32)t, ((struct Obj25175 *)(*(char * *)&((struct Obj05524 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}
