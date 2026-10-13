/*
 * function: func_0220D034
 * address: 0x0220D034
 * packet: pkt_ov198_0220D034
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
 */
#include "../include/Obj10842.h"
#include "../include/Obj25167.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_0220D034(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10842 *)p)->f1EA0, 0x3D);
    f = ((struct Obj10842 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25167 *)(*(char * *)&((struct Obj10842 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}
