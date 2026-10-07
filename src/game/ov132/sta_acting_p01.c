/*
 * file:     sta_acting_p01.c
 * unit:     yes
 * function: func_021F8480, func_021F8640, func_021F879C
 * address:  0x021F8480
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021FD8D4 0x021FD8D4 thumb ov132
 *   func_021F95F0 0x021F95F0 thumb ov132
 *   func_020490F4 0x020490F4 arm
 *   func_021F899C 0x021F899C thumb ov132
 *   func_021F8BD4 0x021F8BD4 thumb ov132
 *   func_021F92CC 0x021F92CC thumb ov132
 *   func_021F8DC4 0x021F8DC4 thumb ov132
 *   func_021F8E58 0x021F8E58 thumb ov132
 *   func_021F8E88 0x021F8E88 thumb ov132
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F9FEC 0x021F9FEC thumb ov132
 *   func_021FA5B0 0x021FA5B0 thumb ov132
 *   func_021FAAF4 0x021FAAF4 thumb ov132
 *   func_021F9CF4 0x021F9CF4 thumb ov132
 *   func_0203D34C 0x0203D34C arm
 *   func_021F8D88 0x021F8D88 thumb ov132
 *   d_021FDCA0 0x021FDCA0 data a1
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   func_02005D28 0x02005D28 thumb
 *   func_02006504 0x02006504 thumb
 *   func_02006518 0x02006518 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021F9D08 0x021F9D08 thumb ov132
 *   func_021FAB58 0x021FAB58 thumb ov132
 *   func_02045808 0x02045808 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_021FA64C 0x021FA64C thumb ov132
 *   func_021FA04C 0x021FA04C thumb ov132
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F9E94 0x021F9E94 thumb ov132
 *   func_021F6A24 0x021F6A24 thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F8EA8 0x021F8EA8 thumb ov132
 *   func_021FA6CC 0x021FA6CC thumb ov132
 *   func_021F9794 0x021F9794 thumb ov132
 *   func_021FABD8 0x021FABD8 thumb ov132
 *   func_021F9ECC 0x021F9ECC thumb ov132
 *   func_021F9374 0x021F9374 thumb ov132
 *   func_021F94F8 0x021F94F8 thumb ov132
 *   func_021FA064 0x021FA064 thumb ov132
 *   func_021F91CC 0x021F91CC thumb ov132
 *   func_021F9ED4 0x021F9ED4 thumb ov132
 *   func_021F9E4C 0x021F9E4C thumb ov132
 *   func_021F90E0 0x021F90E0 thumb ov132
 *   func_021FAD7C 0x021FAD7C thumb ov132
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F6F64 0x021F6F64 thumb ov112
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F6A58 0x021F6A58 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204F7DC 0x0204F7DC arm
 *   func_0204A648 0x0204A648 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 */
#include "../../matched/include/Obj00675.h"
#include "../../matched/include/Obj00191.h"
#include "../../matched/include/Obj23177.h"
#include "../../matched/include/Obj23178.h"

struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct Board;
struct Camera;
struct Lights;
typedef unsigned int u32_021F8480;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32_021F8640;

typedef unsigned u32_021F879C;

extern void *func_02030734(u32_021F8480 heapId, u32_021F8480 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void (*)(void),void *,u32_021F8480);
extern u32_021F8480 func_021FD8D4(char *p);
extern void func_021F95F0(u8 *);
extern void *func_020490F4(u32_021F8480 id, u32_021F8480 heap);
extern void func_021F899C(u8 *);
extern void func_021F8BD4(u8 *);
extern void func_021F92CC(u8 *);
extern void func_021F8DC4(u8 *);
extern void func_021F8E58(char *p);
extern void func_021F8E88(char *p);
extern void *func_021F6BD8(u16,void *);
extern char *func_021F9FEC(u32_021F8480,void *,u32_021F8480);
extern char *func_021FA5B0(u32_021F8480,void *,char *);
extern void *func_021FAAF4(u32_021F8480,void *);
extern void func_021F9CF4(char *);
extern void func_0203D34C(u32_021F8480,u32_021F8480);
extern void func_021F8D88(u8 *,u32_021F8480);
extern void func_02005D28(void);
extern void func_02006504(void);
extern void func_02006518(void);
extern void func_0207D534(volatile u16 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021F9D08(char *);
extern void func_021FAB58(char *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32_021F8640 func_02045C04(struct Rec *rec);
extern u32_021F8640 func_020452E8(struct Descriptor *d);
extern u32_021F8640 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_021FA64C(char *);
extern void func_021FA04C(u8 *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F6C7C(char *p);
extern void func_021F9E94(u8 *p);
extern void func_021F6A24(char *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *p);
extern void func_0204A5AC(void);
extern void func_0204ED24(void *);
extern u32_021F8640 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_020403F4(u32_021F8640);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *);
extern u32_021F8640 func_020307B0(void *p);
extern void func_0202208C(void *,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C);
extern u32_021F879C func_020221A4(void),func_0200FB24(void);
extern int func_02006238(void);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern u8 func_021FAD7C(char *);
extern void func_021F8EA8(u8 *);
extern void func_021FA6CC(char *p);
extern void func_021F9794(char *p);
extern void func_021FABD8(char *p);
extern int func_021F9ECC(u8 *a0);
extern void func_021F9374(u8 *);
extern void func_021F94F8(char *p);
extern void func_021FA064(char *p);
extern void func_021F91CC(u8 *);
extern int func_021F9ED4(u8 *a0);
extern void func_021F9E4C(u8 *);
extern void func_021F90E0(u8 *);
extern void func_021F6F64(u8 *);
extern void func_021F7160(u8 *);
extern void func_021F6A58(char *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u8 *);
extern void func_021F75A0(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *);
extern void func_02047964(void),func_020479D8(void),func_02047970(void),func_0204A600(void),func_0204A648(void);
extern void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights);
u8 *func_021F8480(u8 *input, int heap);
void func_021F8640(char *p);
int func_021F879C(u8 *p);
void func_021F8994(void);
extern const char d_021FDCA0[];
extern u32_021F8480 g_02FFFC3C;
extern u32_021F879C d_02FFFC3C,d_021FDE80;

u8 *func_021F8480(u8 *input, int heap)
{
    u8 *p;
    u8 i;
    p=func_02030734(heap,0x1f0,1,d_021FDCA0,0x11a);
    *(u16 *)p=heap;
    *(void **)(p+0x30)=input;
    i=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=127;
    *(u16 *)(p+6)=128;
    *(u16 *)(p+8)=0;
    *(u32_021F8480 *)(p+0xb4)=0;
    *(u32_021F8480 *)(p+0x1c)=0;
    *(u32_021F8480 *)(p+0x164)=0;
    *(u32_021F8480 *)(p+0xc)=1;
    *(u32_021F8480 *)(p+0x14)=0;
    *(u32_021F8480 *)(p+0x10)=0;
    *(u32_021F8480 *)(p+0x24)=0;
    *(u32_021F8480 *)(p+0x28)=0;
    *(u32_021F8480 *)(p+0x2c)=0;
    *(void **)(p+0x20)=func_020056A0(func_021F8994,p,64);
    if(**(u32_021F8480 **)(p+0x30)==0){
        for(;i<4;i++){
            if(**(u32_021F8480 **)(*(u8 **)(p+0x30)+4+i*4)==0){p[0xa]=i;break;}
        }
        if(i==4)p[0xa]=1;
    }else p[0xa]=func_021FD8D4((void *)**(u32_021F8480 **)(p+0x30));
    for(i=0;i<4;i++)p[0xf7+i]=0;
    func_021F95F0(p);
    *(u32_021F8480 *)(p+0xec)=1;
    p[0xf0]=4;
    p[0xf1]=4;
    p[0xf2]=4;
    p[0x11c]=4;
    *(u16 *)(p+0x11e)=0;
    *(u32_021F8480 *)(p+0x15c)=0;
    *(u16 *)(p+0x168)=0;
    for(i=0;i<4;i++){
        *(u32_021F8480 *)(p+0xfc+i*4)=0;
        *(u16 *)(p+0x124+i*2)=0;
        *(u32_021F8480 *)(p+0x13c+i*8)=0;
        *(u32_021F8480 *)(p+0x140+i*8)=0;
    }
    *(void **)(p+0x18)=func_020490F4(47,*(u16 *)p);
    func_021F899C(p);
    func_021F8BD4(p);
    func_021F92CC(p);
    func_021F8DC4(p);
    func_021F8E58((char *)p);
    func_021F8E88((char *)p);
    *(void **)(p+0x90)=func_021F6BD8(*(u16 *)p,p);
    *(void **)(p+0xb8)=func_021F9FEC(*(u16 *)p,p,*(u32_021F8480 *)(p+0x30));
    *(void **)(p+0xa4)=func_021FA5B0(*(u16 *)p,p,*(char **)(*(u8 **)(p+0x30)+p[0xa]*4+4));
    *(void **)(p+0xb0)=func_021FAAF4(*(u16 *)p,p);
    func_021F9CF4((char *)p);
    func_0203D34C(0,*(u16 *)p);
    func_021F8D88(p,0);
    *(u32_021F8480 *)(p+0x1dc)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x14);
    *(u32_021F8480 *)(p+0x1e0)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x18);
    *(u32_021F8480 *)(p+0x1e4)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x1c);
    *(u32_021F8480 *)(p+0x1ec)=g_02FFFC3C;
    return p;
}

/*
 * volatile: hardware display register 0x04000000 read at 0x021F868C.
 */
void func_021F8640(char *p)
{
    if(((struct Obj00675 *)p)->f2C==1)func_02005D28();
    if(((struct Obj00675 *)p)->f28==1)func_02006504();
    if(((struct Obj00675 *)p)->f24==1)func_02006518();
    func_0207D534((volatile u16 *)0x0400006c,-16);
    func_0207D534((volatile u16 *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    *(volatile u32_021F8640 *)0x04000000 &= 0xffff1fff;
    func_021F9D08(p);
    func_021FAB58(((struct Obj00675 *)p)->fB0);
    if(((struct Obj00675 *)p)->fE0!=0)func_02045808(((struct Obj00675 *)p)->fE0);
    func_0201C6EC(((struct Obj00675 *)p)->fE8);
    func_0201C4C0(((struct Obj00675 *)p)->fE8);
    func_02045C04(((struct Obj00675 *)p)->fDC);
    func_020452E8(((struct Obj00675 *)p)->fD0);
    func_0201D83C(((struct Obj00675 *)p)->fD4);
    func_02031140(((struct Obj00675 *)p)->fCC);
    func_021FA64C(*(char * *)&((struct Obj00675 *)p)->fA4);
    func_021FA04C(((struct Obj00675 *)p)->fB8);
    func_021F6F4C(((struct Obj00675 *)p)->f3C);
    func_021F6C7C(((struct Obj00675 *)p)->f90);
    func_021F9E94(((struct Obj00675 *)p)->f6C);
    func_021F6A24(((struct Obj00675 *)p)->f54);
    func_021F7120(((struct Obj00675 *)p)->f40);
    func_021F51B0((int)(((struct Obj00675 *)p)->f34));
    func_021F4948(((struct Obj00675 *)p)->f38);
    func_0204A5AC();
    func_0204ED24(((struct Obj00675 *)p)->fAC);
    func_02048AC4(((struct Obj00675 *)p)->fA8);
    func_02046788();
    func_020403F4(0);
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    func_020403F4(5);
    func_020403F4(7);
    func_020450C8();
    func_0203F9B4();
    func_02030EAC(((struct Obj00675 *)p)->f20);
    func_02049238(((struct Obj00675 *)p)->f18);
    func_020307B0(p);
}

/*
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 */
int func_021F879C(u8 *p)
{
    u32_021F879C tick;
    tick=d_02FFFC3C;
    ((struct Obj00191 *)p)->f1E8=tick-((struct Obj00191 *)p)->f1EC;
    ((struct Obj00191 *)p)->f1EC=tick;
    switch(((struct Obj00191 *)p)->f1C) {
    case 0:
        func_0202208C(0,1,1,0,6,1,((struct Obj00191 *)p)->f0);
        ((struct Obj00191 *)p)->f1C=1;
        break;
    case 1:
        if(func_020221A4()==1) {
            if(**(u32_021F879C * *)&((struct Obj00191 *)p)->f30!=0) {
                ((struct Obj00191 *)p)->f1C=7;
                func_021FCDEC(**(int * *)&((struct Obj00191 *)p)->f30,200);
            } else ((struct Obj00191 *)p)->f1C=4;
        }
        break;
    case 2:
        if(func_02006238()==0) {
            func_0202208C(0,0,0,0,6,1,((struct Obj00191 *)p)->f0);
            ((struct Obj00191 *)p)->f1C=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if((((struct Obj00191 *)p)->f2)++ >=60) ((struct Obj00191 *)p)->f1C=5;
        break;
    case 5:
        if(((struct Obj00191 *)p)->f164==0) {
            ((struct Obj00191 *)p)->fB4=((struct Obj23178 *)(*(u8 * *)&((struct Obj23177 *)(*(u8 * *)&((struct Obj00191 *)p)->f30))->f18))->fC;
            func_021F90E0(p);
            ((struct Obj00191 *)p)->f1C=6;
        }
        break;
    case 6:
        if(func_021FAD7C(*(char * *)&((struct Obj00191 *)p)->fB0)==0) {
            ((struct Obj00191 *)p)->fB4=0;
            if(((struct Obj00191 *)p)->f164==0) ((struct Obj00191 *)p)->f1C=2;
            else ((struct Obj00191 *)p)->f1C=255;
        }
        break;
    case 7:
        if(func_021FCE00(*(void **)*(u8 * *)&((struct Obj00191 *)p)->f30,200)==1)
            ((struct Obj00191 *)p)->f1C=4;
        break;
    }
    func_021F8EA8(p);
    func_021FA6CC((char *)(*(u8 * *)&((struct Obj00191 *)p)->fA4));
    func_021F9794((char *)p);
    if(d_021FDE80==0) func_021FABD8((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB0));
    func_021F6F64(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    func_021F7160(*(u8 * *)&((struct Obj00191 *)p)->f40);
    func_021F6A58((char *)(*(u8 * *)&((struct Obj00191 *)p)->f54));
    func_021F9ECC(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    func_021F9374(p);
    func_021F51E8(*(u8 * *)&((struct Obj00191 *)p)->f34);
    func_021F6CB0((char *)(*(u8 * *)&((struct Obj00191 *)p)->f90));
    func_021F94F8((char *)p);
    func_021FA064((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB8));
    func_021F91CC(p);
    func_02047964(); func_020479D8();
    func_021F6E74(*(u8 * *)&((struct Obj00191 *)p)->f90);
    func_021F75A0(*(u8 * *)&((struct Obj00191 *)p)->f40);
    func_021F51F4((void **)(*(u8 * *)&((struct Obj00191 *)p)->f34));
    func_021F718C((char *)(*(u8 * *)&((struct Obj00191 *)p)->f40));
    func_021F6F8C(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    func_0204F7DC(((struct Obj00191 *)p)->fAC,((struct Obj00191 *)p)->fA8,0);
    func_021F9ED4(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    func_021F9E4C(p);
    func_02047970(); func_0204A600();
    if(**(u32_021F879C * *)&((struct Obj00191 *)p)->f30!=0 && ((struct Obj00191 *)p)->f1C!=0 &&
       ((struct Obj00191 *)p)->f1C!=1 && ((struct Obj00191 *)p)->f1C!=2 &&
       ((struct Obj00191 *)p)->f1C!=3 && func_0200FB24()!=0)
        ((struct Obj00191 *)p)->f1C=2;
    return 0;
}

void func_021F8994(void) { func_0204A648(); }
