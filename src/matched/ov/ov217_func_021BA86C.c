/*
 * function: func_021BA86C
 * address: 0x021BA86C
 * packet: pkt_ov217_021BA86C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   d_021C2F98 0x021C2F98 data a4
 * Caller explicitly loads F5C's r1 despite legacy one-parameter source.
 */
#include "../include/Obj14729.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Desc {u8 a,b,c,d,e,f,g,h,i,j,k;unsigned data;};
struct Entry {struct Desc desc;unsigned mode,data;};
extern const struct Entry d_021C2F98[];
typedef unsigned int   u32;
struct Config;
struct Record;
extern struct Record *BgTextLabel_Create(const struct Config *config, u32 a, u32 b, u32 heap);
extern unsigned BgTextLabel_PrintMessage(unsigned,unsigned);
void func_021BA86C(char *p)
{
    struct Desc desc;
    int i;
    for(i=0;i<4;i++) {
        const struct Entry *s=&d_021C2F98[i];
        desc.a=s->desc.a;desc.b=s->desc.b;desc.c=s->desc.c;desc.d=s->desc.d;
        desc.e=s->desc.e;desc.f=s->desc.f;desc.g=s->desc.g;desc.h=s->desc.h;
        desc.i=s->desc.i;desc.j=s->desc.j;desc.k=s->desc.k;desc.data=s->data;
        *(unsigned *)(p+i*4+0x4c)=(unsigned int)BgTextLabel_Create((const struct Config *)(&desc),((struct Obj14729 *)p)->f8,*(unsigned *)(p+s->desc.data*4+0xc),((struct Obj14729 *)p)->f4);
        BgTextLabel_PrintMessage(*(unsigned *)(p+i*4+0x4c),s->mode);
    }
}
