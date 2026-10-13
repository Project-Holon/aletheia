/*
 * function: func_021BA3C4
 * address: 0x021BA3C4
 * packet: pkt_ov214_021BA3C4
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   d_021BB480 0x021BB480 data a1
 */
#include "../include/Obj00182.h"
typedef unsigned char u8;
typedef struct {u8 a,b,c,d,e,f;} Rec;
typedef struct {Rec r[4];} Table;
extern const Table d_021BB480;
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
void func_021BA3C4(int unused,char*p)
{
    Table t=d_021BB480;
    u8 i;
    for(i=0;i<4;i++){
        *(unsigned*)(p+i*4+0x8c)=BMP_WIN_Create(t.r[i].a,t.r[i].b,t.r[i].c,t.r[i].d,t.r[i].e,9,t.r[i].f);
        BMP_Clear(func_02045770(*(void**)(p+i*4+0x8c)),0);
        *(int*)(p+i*4+0x9c)=1;
    }
    ((struct Obj00182 *)p)->fBC=0;
    ((struct Obj00182 *)p)->fC0=0;
}
