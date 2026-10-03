/*
 * function: func_021EEBF0
 * address: 0x021EEBF0
 * packet: pkt_ov188_021EEBF0
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02019A50 0x02019A50 thumb
 *   func_02019A9C 0x02019A9C thumb
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
extern u16 func_02019A9C(const u16 *,u32);
extern void *func_02019C38(struct Mon *,u32,u32);
void func_021EEBF0(char *p,struct Mon *q)
{
    char *a,*b,*c,*d;
    int i;
    func_02082BCC(q,0,0xdc);
    a=func_02019C38(q,*(u32 *)p,0);
    b=func_02019C38(q,*(u32 *)p,1);
    c=func_02019C38(q,*(u32 *)p,2);
    d=func_02019C38(q,*(u32 *)p,3);
    q->seed=*(u32 *)p;
    q->flags.a=0;
    q->flags.b=0;
    q->flags.c=((Flags *)(p+4))->c;
    *(u16 *)a=*(u16 *)(p+6);
    *(u16 *)(a+2)=*(u16 *)(p+8);
    *(u32 *)(a+4)=*(u32 *)(p+0xc);
    *(u32 *)(a+8)=*(u32 *)(p+0x10);
    *(u8 *)(a+0xc)=*(u8 *)(p+0x14);
    *(u8 *)(a+0xd)=*(u8 *)(p+0x15);
    *(u8 *)(a+0x10)=*(u8 *)(p+0x16);
    *(u8 *)(a+0x11)=*(u8 *)(p+0x17);
    *(u8 *)(a+0x12)=*(u8 *)(p+0x18);
    *(u8 *)(a+0x13)=*(u8 *)(p+0x19);
    *(u8 *)(a+0x14)=*(u8 *)(p+0x1a);
    *(u8 *)(a+0x15)=*(u8 *)(p+0x1b);
    *(u8 *)(a+0xf)=*(u8 *)(p+0x59);
    for(i=0;i<4;i++) {
        *(u16 *)(b+2*i)=*(u16 *)(p+2*i+0x1c);
        *(u8 *)(b+i+8)=*(u8 *)(p+i+0x24);
        *(u8 *)(b+i+0xc)=*(u8 *)(p+i+0x28);
    }
    ((Packed *)(b+0x10))->a=((Packed *)(p+0x2c))->a;
    ((Packed *)(b+0x10))->b=((Packed *)(p+0x2c))->b;
    ((Packed *)(b+0x10))->c=((Packed *)(p+0x2c))->c;
    ((Packed *)(b+0x10))->d=((Packed *)(p+0x2c))->d;
    ((Packed *)(b+0x10))->e=((Packed *)(p+0x2c))->e;
    ((Packed *)(b+0x10))->f=((Packed *)(p+0x2c))->f;
    ((Packed *)(b+0x10))->g=((Packed *)(p+0x2c))->g;
    ((Packed *)(b+0x10))->h=((Packed *)(p+0x2c))->h;
    ((Byte *)(b+0x18))->a=((Byte *)(p+0x30))->a;
    ((Byte *)(b+0x18))->b=((Byte *)(p+0x30))->b;
    ((Byte *)(b+0x18))->c=((Byte *)(p+0x30))->c;
    *(u8 *)(b+0x19)=((Flags *)(p+4))->mode;
    for(i=0;i<11;i++) *(u16 *)(c+2*i)=*(u16 *)(p+2*i+0x32);
    for(i=0;i<8;i++) *(u16 *)(d+2*i)=*(u16 *)(p+2*i+0x48);
    *(u8 *)(d+0x1b)=*(u8 *)(p+0x58);
    *(u32 *)((char *)q+0x88)=*(u32 *)(p+0x5c);
    *(u8 *)((char *)q+0x8c)=*(u8 *)(p+0x60);
    *(u8 *)((char *)q+0x8d)=*(u8 *)(p+0x61);
    *(u16 *)((char *)q+0x8e)=*(u16 *)(p+0x62);
    *(u16 *)((char *)q+0x90)=*(u16 *)(p+0x64);
    *(u16 *)((char *)q+0x92)=*(u16 *)(p+0x66);
    *(u16 *)((char *)q+0x94)=*(u16 *)(p+0x68);
    *(u16 *)((char *)q+0x96)=*(u16 *)(p+0x6a);
    *(u16 *)((char *)q+0x98)=*(u16 *)(p+0x6c);
    *(u16 *)((char *)q+0x9a)=*(u16 *)(p+0x6e);
    func_02019A50((u16 *)((char *)q+0x88),0x54,q->seed);
    q->check=func_02019A9C((u16 *)q->block,0x80);
    func_02019A50((u16 *)q->block,0x80,q->check);
}
