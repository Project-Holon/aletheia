/*
 * function: func_0220D3B4
 * address: 0x0220D3B4
 * packet: pkt_ov198_0220D3B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 */
#include "../include/Obj08359.h"
#include "../include/Obj25171.h"
#include "../include/Obj25172.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_0220D3B4(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj08359 *)p)->f1EA0, 0x3F);
    func_0201D304(t, ((struct Obj25171 *)(*(char * *)&((struct Obj08359 *)p)->f0))->fC, 0);
    f = ((struct Obj08359 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25172 *)(*(char * *)&((struct Obj08359 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}
