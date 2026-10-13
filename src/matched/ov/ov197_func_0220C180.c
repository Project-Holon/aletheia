/*
 * function: func_0220C180
 * address: 0x0220C180
 * packet: pkt_ov197_0220C180
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: u16 item restores entry spill order without extra truncation; unsigned item differs in eight bytes.
 * symbols:
 *   func_02020F08 0x02020F08 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj01075.h"
#include "../include/Obj14545.h"
#include "../include/Obj25020.h"
#include "../include/Obj25021.h"
typedef unsigned short u16;
extern unsigned func_02020F08(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned func_02020E60(unsigned,unsigned);
typedef unsigned int   u32;
struct PalAnmSlot;
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
struct Sub0204A9D0;
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049238(void *);
void func_0220C180(char *p,u16 item,unsigned slot,unsigned offset)
{
    char *q=*(char * *)&((struct Obj01075 *)p)->f0;
    unsigned first, second;
    void *arc;
    void *data,*buffer;
    if(((struct Obj14545 *)q)->f8==1) {first=3;second=4;} else {first=1;second=2;}
    arc=func_020490F4(func_02020F08(),(u16)((((struct Obj14545 *)q)->fC&0x7fff)|0x8000));
    buffer=func_02049E74(arc,func_02020E60(item,first),0,(u32)(&data),((struct Obj25020 *)(*(char * *)&((struct Obj01075 *)p)->f0))->fC);
    func_0204A9D0(*(int *)(p+slot*4+0x544),data);
    func_020307B0(buffer);
    PALANM_LoadHandlePaletteToSlot(((struct Obj01075 *)p)->f8,(void *)((unsigned)arc),func_02020E60(item,second),((struct Obj25021 *)(*(char * *)&((struct Obj01075 *)p)->f0))->fC,3,32,offset*16);
    func_02049238(arc);
}
