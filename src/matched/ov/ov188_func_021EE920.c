/*
 * function: func_021EE920
 * address: 0x021EE920
 * packet: pkt_ov188_021EE920
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02019A50 0x02019A50 thumb
 *   func_02019C38 0x02019C38 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a:1,b:1,c:1,mode:8,pad:5; } Flags;
typedef struct { u32 a:5,b:5,c:5,d:5,e:5,f:5,g:1,h:1; } Packed;
typedef struct { u8 a:1,b:2,c:5; } Byte;
struct Mon { u32 seed; Flags flags; u16 check; u8 block[0x80]; };
extern void func_02082BCC(void *,int,u32);
extern void func_02019A50(u16 *,u32,u32);
extern void *func_02019C38(struct Mon *,u32,u32);
void func_021EE920(struct Mon *p,char *q)
{
    char *a,*b,*c,*d;
    int i;
    func_02082BCC(q,0,0x70);
    if (!p->flags.a) {
        func_02019A50((u16 *)((char *)p+0x88),0x54,p->seed);
        func_02019A50((u16 *)p->block,0x80,p->check);
    }
    a=func_02019C38(p,p->seed,0);
    b=func_02019C38(p,p->seed,1);
    c=func_02019C38(p,p->seed,2);
    d=func_02019C38(p,p->seed,3);
    *(u32 *)q=p->seed;
    ((Flags *)(q+4))->a=0;
    ((Flags *)(q+4))->b=0;
    ((Flags *)(q+4))->c=p->flags.c;
    ((Flags *)(q+4))->mode=*(u8 *)(b+0x19);
    *(u16 *)(q+6)=*(u16 *)a;
    *(u16 *)(q+8)=*(u16 *)(a+2);
    *(u32 *)(q+0xc)=*(u32 *)(a+4);
    *(u32 *)(q+0x10)=*(u32 *)(a+8);
    *(u8 *)(q+0x14)=*(u8 *)(a+0xc);
    *(u8 *)(q+0x15)=*(u8 *)(a+0xd);
    *(u8 *)(q+0x16)=*(u8 *)(a+0x10);
    *(u8 *)(q+0x17)=*(u8 *)(a+0x11);
    *(u8 *)(q+0x18)=*(u8 *)(a+0x12);
    *(u8 *)(q+0x19)=*(u8 *)(a+0x13);
    *(u8 *)(q+0x1a)=*(u8 *)(a+0x14);
    *(u8 *)(q+0x1b)=*(u8 *)(a+0x15);
    *(u8 *)(q+0x59)=*(u8 *)(a+0xf);
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
    *(u8 *)(q+0x58)=*(u8 *)(d+0x1b);
    *(u32 *)(q+0x5c)=*(u32 *)((char *)p+0x88);
    *(u8 *)(q+0x60)=*(u8 *)((char *)p+0x8c);
    *(u8 *)(q+0x61)=*(u8 *)((char *)p+0x8d);
    *(u16 *)(q+0x62)=*(u16 *)((char *)p+0x8e);
    *(u16 *)(q+0x64)=*(u16 *)((char *)p+0x90);
    *(u16 *)(q+0x66)=*(u16 *)((char *)p+0x92);
    *(u16 *)(q+0x68)=*(u16 *)((char *)p+0x94);
    *(u16 *)(q+0x6a)=*(u16 *)((char *)p+0x96);
    *(u16 *)(q+0x6c)=*(u16 *)((char *)p+0x98);
    *(u16 *)(q+0x6e)=*(u16 *)((char *)p+0x9a);
    if (!p->flags.a) {
        func_02019A50((u16 *)((char *)p+0x88),0x54,p->seed);
        func_02019A50((u16 *)p->block,0x80,p->check);
    }
}
