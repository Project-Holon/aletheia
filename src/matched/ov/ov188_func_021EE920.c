/*
 * function: BATTLE_REC_TOOL_PackMon
 * address: 0x021EE920
 * packet: pkt_ov188_021EE920
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   POKE_CRYPTO_XorBlock 0x02019A50 thumb
 *   POKE_TOOL_GetBoxSubstruct 0x02019C38 thumb
 */
#include "../include/Obj00685.h"
#include "../include/Obj01968.h"
#include "../include/Obj02905.h"
#include "../include/Obj24888.h"
#include "../include/Obj24889.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a:1,b:1,c:1,mode:8,pad:5; } Flags;
typedef struct { u32 a:5,b:5,c:5,d:5,e:5,f:5,g:1,h:1; } Packed;
typedef struct { u8 a:1,b:2,c:5; } Byte;
struct Mon { u32 seed; Flags flags; u16 check; u8 block[0x80]; };
extern void MI_CpuFill8(void *,int,u32);
extern void POKE_CRYPTO_XorBlock(u16 *,u32,u32);
extern void *POKE_TOOL_GetBoxSubstruct(struct Mon *,u32,u32);
void BATTLE_REC_TOOL_PackMon(struct Mon *p,char *q)
{
    char *a,*b,*c,*d;
    int i;
    MI_CpuFill8(q,0,0x70);
    if (!p->flags.a) {
        POKE_CRYPTO_XorBlock((u16 *)((char *)p+0x88),0x54,p->seed);
        POKE_CRYPTO_XorBlock((u16 *)p->block,0x80,p->check);
    }
    a=POKE_TOOL_GetBoxSubstruct(p,p->seed,0);
    b=POKE_TOOL_GetBoxSubstruct(p,p->seed,1);
    c=POKE_TOOL_GetBoxSubstruct(p,p->seed,2);
    d=POKE_TOOL_GetBoxSubstruct(p,p->seed,3);
    ((struct Obj00685 *)q)->f0=p->seed;
    ((Flags *)(q+4))->a=0;
    ((Flags *)(q+4))->b=0;
    ((Flags *)(q+4))->c=p->flags.c;
    ((Flags *)(q+4))->mode=((struct Obj24888 *)b)->f19;
    ((struct Obj00685 *)q)->f6=((struct Obj01968 *)a)->f0;
    ((struct Obj00685 *)q)->f8=((struct Obj01968 *)a)->f2;
    ((struct Obj00685 *)q)->fC=((struct Obj01968 *)a)->f4;
    ((struct Obj00685 *)q)->f10=((struct Obj01968 *)a)->f8;
    ((struct Obj00685 *)q)->f14=((struct Obj01968 *)a)->fC;
    ((struct Obj00685 *)q)->f15=((struct Obj01968 *)a)->fD;
    ((struct Obj00685 *)q)->f16=((struct Obj01968 *)a)->f10;
    ((struct Obj00685 *)q)->f17=((struct Obj01968 *)a)->f11;
    ((struct Obj00685 *)q)->f18=((struct Obj01968 *)a)->f12;
    ((struct Obj00685 *)q)->f19=((struct Obj01968 *)a)->f13;
    ((struct Obj00685 *)q)->f1A=((struct Obj01968 *)a)->f14;
    ((struct Obj00685 *)q)->f1B=((struct Obj01968 *)a)->f15;
    ((struct Obj00685 *)q)->f59=((struct Obj01968 *)a)->fF;
    for(i=0;i<4;i++) {
        *(u16 *)(q+2*i+0x1c)=*(u16 *)(b+2*i);
        *(u8 *)(q+i+0x24)=*(u8 *)(b+i+8);
        *(u8 *)(q+i+0x28)=*(u8 *)(b+i+0xc);
    }
    ((Packed *)(q+0x2c))->a=((Packed *)(b+0x10))->a;
    ((Packed *)(q+0x2c))->b=((Packed *)(b+0x10))->b;
    ((Packed *)(q+0x2c))->c=((Packed *)(b+0x10))->c;
    ((Packed *)(q+0x2c))->d=((Packed *)(b+0x10))->d;
    ((Packed *)(q+0x2c))->e=((Packed *)(b+0x10))->e;
    ((Packed *)(q+0x2c))->f=((Packed *)(b+0x10))->f;
    ((Packed *)(q+0x2c))->g=((Packed *)(b+0x10))->g;
    ((Packed *)(q+0x2c))->h=((Packed *)(b+0x10))->h;
    ((Byte *)(q+0x30))->a=((Byte *)(b+0x18))->a;
    ((Byte *)(q+0x30))->b=((Byte *)(b+0x18))->b;
    ((Byte *)(q+0x30))->c=((Byte *)(b+0x18))->c;
    for(i=0;i<11;i++) *(u16 *)(q+2*i+0x32)=*(u16 *)(c+2*i);
    for(i=0;i<8;i++) *(u16 *)(q+2*i+0x48)=*(u16 *)(d+2*i);
    ((struct Obj00685 *)q)->f58=((struct Obj24889 *)d)->f1B;
    ((struct Obj00685 *)q)->f5C=((struct Obj02905 *)p)->f88;
    ((struct Obj00685 *)q)->f60=((struct Obj02905 *)p)->f8C;
    ((struct Obj00685 *)q)->f61=((struct Obj02905 *)p)->f8D;
    ((struct Obj00685 *)q)->f62=((struct Obj02905 *)p)->f8E;
    ((struct Obj00685 *)q)->f64=((struct Obj02905 *)p)->f90;
    ((struct Obj00685 *)q)->f66=((struct Obj02905 *)p)->f92;
    ((struct Obj00685 *)q)->f68=((struct Obj02905 *)p)->f94;
    ((struct Obj00685 *)q)->f6A=((struct Obj02905 *)p)->f96;
    ((struct Obj00685 *)q)->f6C=((struct Obj02905 *)p)->f98;
    ((struct Obj00685 *)q)->f6E=((struct Obj02905 *)p)->f9A;
    if (!p->flags.a) {
        POKE_CRYPTO_XorBlock((u16 *)((char *)p+0x88),0x54,p->seed);
        POKE_CRYPTO_XorBlock((u16 *)p->block,0x80,p->check);
    }
}
