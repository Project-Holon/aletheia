/*
 * function: func_021B6278
 * address: 0x021B6278
 * packet: pkt_ov173_021B6278
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   d_021B81FC 0x021B81FC data a4
 *   d_021B81EC 0x021B81EC data a4
 */
#include "../include/Obj00180.h"
#include "../include/Obj05449.h"
#include "../include/G_021B81EC.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id,value;} Row;
extern struct G_021B81EC d_021B81EC[];
extern const Row d_021B81FC[];
extern u32 func_0201C440(void *);
struct MsgBank;
struct R;
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021B6278(u8 *p)
{
    int i;
    const Row *r;
    u8 *q;
    ((struct Obj00180 *)p)->f218=func_0201C440((void *)79);
    ((struct Obj00180 *)p)->f1DC=func_02027F60(4,10,((struct Obj00180 *)p)->f60,((struct Obj00180 *)p)->f218,79);
    for(i=0;i<2;i++) {
        r=&d_021B81FC[i];q=p+i*12;
        ((struct Obj05449 *)q)->f1E4=func_02045EC0(((struct Obj00180 *)p)->f44,r->id);
        ((struct Obj05449 *)q)->f1E8=14819;
        ((struct Obj05449 *)q)->f1EC=r->value;
    }
    for(i=0;i<2;i++) {
        r=&((Row *)d_021B81EC)[i];q=p+i*12;
        ((struct Obj05449 *)q)->f1FC=func_02045EC0(((struct Obj00180 *)p)->f44,r->id);
        ((struct Obj05449 *)q)->f200=14819;
        ((struct Obj05449 *)q)->f204=r->value;
    }
    ((struct Obj00180 *)p)->f220=0;((struct Obj00180 *)p)->f224=0;
}
