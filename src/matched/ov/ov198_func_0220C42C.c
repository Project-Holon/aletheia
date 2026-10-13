/*
 * function: func_0220C42C
 * address: 0x0220C42C
 * packet: pkt_ov198_0220C42C
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
 *   func_022110D4 0x022110D4 thumb ov198
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj04599.h"
#include "../include/Obj14555.h"
#include "../include/Obj25136.h"
#include "../include/Obj25137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int func_022110D4(u8 *, int);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0220C42C(char *p, int i, int index)
{
    char *elem;
    void *t;
    void *format;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    if (((struct Obj14555 *)elem)->f1A == 0)
        t = func_02045EC0(((struct Obj04599 *)p)->f1EA0, 0x1E);
    else {
        t = (void *)STRBUF_Create(0x12, ((struct Obj25136 *)(*(char * *)&((struct Obj04599 *)p)->f0))->f10);
        format = func_02045EC0(((struct Obj04599 *)p)->f1EA0, 15);
        func_0201EF40(((struct Obj04599 *)p)->f1EA4, 0, ((struct Obj14555 *)elem)->f1A);
        func_0201F250(((struct Obj04599 *)p)->f1EA4, (void *)((u32)t), format);
        STRBUF_Delete(format);
    }
    f = ((struct Obj04599 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25137 *)(*(char * *)&((struct Obj04599 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}
