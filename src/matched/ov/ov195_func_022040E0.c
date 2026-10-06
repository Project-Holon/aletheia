/*
 * function: func_022040E0
 * address: 0x022040E0
 * packet: pkt_ov195_022040E0
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P23 closed EXACT*. Case 34 also calls func_02204FD4(a,s) after func_02205384 (same as case 18), so the tails cross-jump into case 18's copy; case 39 reads W(0x90) into a local once for both func_022055BC arguments (ldr before the s+0x1c add). Older 5-byte DIFF came from those two points.
 * checks: 1 fresh own callee definitions and same-overlay callers confirm arities; unit355C4 setteru8 widened tou32 because caller sends only0/1 without truncation; caller-loaded forwarder args and272A4 wide-r1 payload preserved; 2 matched03FA0/05384/055BC/056E8 and loader twins read; 3 u16 keys (only bit2 used) regresses699, a/s writable so no const; 4 Boolean call/inline-wrapper and flag-ternary idioms read; 5 fresh unfiltered idioms and04DE0/04FC4/math neighbours.
 * extent: 02204B66 and 02204BB2 are internal shared tails; true end 02204C24 (2884B).
 * symbols:
 *   func_02031330 0x02031330 arm
 *   func_02031348 0x02031348 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0200873C 0x0200873C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_020178D8 0x020178D8 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_020181F4 0x020181F4 thumb
 *   func_02018328 0x02018328 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02021518 0x02021518 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_020272A4 0x020272A4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030D28 0x02030D28 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B6DC0 0x021B6DC0 thumb ov067
 *   func_021B709C 0x021B709C thumb ov067
 *   func_021B70F4 0x021B70F4 thumb ov067
 *   func_021B72DC 0x021B72DC thumb ov067
 *   func_021B7378 0x021B7378 thumb ov067
 *   func_021B76B0 0x021B76B0 thumb ov067
 *   d_021DC800 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   ov196_id 0x000000C4 data a1
 *   ov198_id 0x000000C6 data a1
 *   func_02205360 0x02205360 thumb ov195
 *   d_02208F40 0x02208F40 data a4
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   func_02204C24 0x02204C24 thumb ov195
 *   func_02204D5C 0x02204D5C thumb ov195
 *   func_02204DE0 0x02204DE0 thumb ov195
 *   func_02204EA0 0x02204EA0 thumb ov195
 *   func_02204EB0 0x02204EB0 thumb ov195
 *   func_02204ED0 0x02204ED0 thumb ov195
 *   func_02204EF0 0x02204EF0 thumb ov195
 *   func_02204F00 0x02204F00 thumb ov195
 *   func_02204F24 0x02204F24 thumb ov195
 *   func_02204F40 0x02204F40 thumb ov195
 *   func_02204F68 0x02204F68 thumb ov195
 *   func_02204F78 0x02204F78 thumb ov195
 *   func_02204F90 0x02204F90 thumb ov195
 *   func_02204FA0 0x02204FA0 thumb ov195
 *   func_02204FC4 0x02204FC4 thumb ov195
 *   func_02204FD4 0x02204FD4 thumb ov195
 *   func_02204FF8 0x02204FF8 thumb ov195
 *   func_02205138 0x02205138 thumb ov195
 *   func_02205168 0x02205168 thumb ov195
 *   func_02205340 0x02205340 thumb ov195
 *   func_02205384 0x02205384 thumb ov195
 *   func_022053E8 0x022053E8 thumb ov195
 *   func_0220546C 0x0220546C thumb ov195
 *   func_022054E8 0x022054E8 thumb ov195
 *   func_022055BC 0x022055BC thumb ov195
 *   func_022056E8 0x022056E8 thumb ov195
 *   func_02205844 0x02205844 thumb ov195
 *   func_022059FC 0x022059FC thumb ov195
 *   func_02205A10 0x02205A10 thumb ov195
 *   func_02205A1C 0x02205A1C thumb ov195
 *   func_02205A28 0x02205A28 thumb ov195
 *   func_02205A34 0x02205A34 thumb ov195
 *   func_02205A84 0x02205A84 thumb ov195
 *   func_02205D50 0x02205D50 thumb ov195
 *   func_0220602C 0x0220602C thumb ov195
 *   func_02206044 0x02206044 thumb ov195
 *   func_0220604C 0x0220604C thumb ov195
 *   func_02206050 0x02206050 thumb ov195
 *   func_02206058 0x02206058 thumb ov195
 *   func_0220605C 0x0220605C thumb ov195
 *   func_02206064 0x02206064 thumb ov195
 *   func_0220606C 0x0220606C thumb ov195
 *   func_02206070 0x02206070 thumb ov195
 *   func_02206074 0x02206074 thumb ov195
 *   func_02206078 0x02206078 thumb ov195
 *   func_0220878C 0x0220878C thumb ov195
 *   func_02208804 0x02208804 thumb ov195
 *   func_02208814 0x02208814 thumb ov195
 *   func_0220882C 0x0220882C thumb ov195
 *   func_02208844 0x02208844 thumb ov195
 *   func_02208850 0x02208850 thumb ov195
 *   func_02208860 0x02208860 thumb ov195
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02031330(void *);
/* Original explicitly prepares all four registers, despite the current forwarding own source. */
extern void func_02031348(void *,int,void *,void *);
extern void func_020061E4(u32);
struct Anim;
struct App;
struct Big;
struct Blk37;
struct Ctx;
struct Obj02021EE4;
struct Owner;
struct PalAnmSlot;
struct PrintSys;
struct S;
struct Scene;
struct Sub02008700Obj;
struct Sub02008C20Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_02012EBC(struct Big *p);
extern void *func_02012F2C(int *p);
extern void func_020178D8(void *,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_020181F4(void *,u16,u32);
extern u16 func_02018328(void *,u32 *,u32);
extern u32 func_0201AA18(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02021518(u32);
extern void func_02021540(void *);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
/* Caller narrows only r0; r1 retains the full word, copied to the callee's u16 store. */
extern void func_020272A4(u16,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_020307B0(void *);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02030D28(struct Ctx *c);
extern void func_02030DA4(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern u8 func_020355C4(void);
extern void func_020355D8(u32);
extern u32 func_020362DC(void);
extern void func_0203D34C(u32,u32),func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_02082BCC(void *,u32,u32);
extern void *func_021B6DC0(u16,u32,u32,u32,u8,u32,u32,u32,u32);
extern void func_021B709C(u8 *p);
extern void func_021B70F4(struct S *s, u32 a1, u32 a2);
extern void func_021B72DC(struct S *s);
extern void func_021B7378(struct S *p);
extern int func_021B76B0(struct S *p);
extern u8 d_021DC800[],d_02208F40[];
extern const char ov131_id[],ov196_id[],ov198_id[];
extern int func_02205360(int);
extern void func_0220F3E8(u8 *);
extern void func_02204C24(struct App *a, struct Scene *s);
extern void func_02204D5C(int a, int *p);
extern void func_02204DE0(char *,char *);
extern int func_02204EA0(int a, int *p);
extern int func_02204EF0(int a, int *p);
extern int func_02204F68(int a, int *p);
extern int func_02204F90(int a, char *b);
extern int func_02204FC4(int a, int *p);
extern void func_02204EB0(char *,char *);
extern void func_02204ED0(int a, int *p);
extern void func_02204F00(int unused, char *p);
extern void func_02204F24(int a, int *b);
extern void func_02204F40(int a, int *p);
extern void func_02204F78(int a, char *b);
extern void func_02204FA0(int a, int *p);
extern void func_02204FD4(int a, int *p);
extern void func_02204FF8(int a, char *b);
extern void func_02205138(int a, int *p);
extern int func_02205168(int a, int *p);
extern void func_02205340(int a, char *b);
extern void func_02205384(char *,u32,u32,u32,u32,u32,u32,u32);
extern int func_022053E8(char *),func_0220546C(char *);
extern void func_022054E8(int a, int *p, int flag);
extern void func_022055BC(char *,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_022056E8(u32 *a, char *b);
extern void func_02205844(int a, char *b);
extern void func_022059FC(char *a);
extern void func_02205A10(char *a);
extern void func_02205A1C(char *a);
extern void func_02205A34(void *);
extern void func_02205A84(int a0);
extern void func_02205D50(char *p);
extern void func_0220602C(struct Owner *o);
extern int func_02205A28(char *a);
extern void func_02206044(int *p);
extern void func_02206050(int *p);
extern void func_0220605C(int *p);
extern void func_02206064(int *p);
extern void func_0220878C(struct Anim *p);
extern void func_02208804(char *a);
extern void func_02208814(char *a);
extern void func_0220882C(int *p);
extern void func_02208844(int *p);
extern int func_0220604C(int *p);
extern int func_02206058(int *p);
extern int func_0220606C(int *p);
extern int func_02206070(int *p);
extern int func_02206074(int *p);
extern int func_02206078(int *p);
extern int func_02208850(int *p);
extern int func_02208860(int *p);
#define W(n) (*(u32 *)(s+(n)))
#define P(n) (*(void **)(s+(n)))
#define H(n) (*(u16 *)(s+(n)))
#define B(n) (*(u8 *)(s+(n)))
#define A(n) (*(u32 *)(a+(n)))
#define AH(n) (*(u16 *)(a+(n)))
#define AB(n) (*(u8 *)(a+(n)))
int func_022040E0(int unused0,int unused1,char *a,char *s)
{
    u32 tick,keys,result;
    u8 *q;
    void *v;
    tick=func_02031330(P(0x11c));if(tick==1)return 0;
    switch(W(0x28)){
    case 0:if(W(0x2c)==0){W(0x28)=1;func_0204E720(3,16,0,-16);}else W(0x2c)--;break;
    case 1:if(!func_0204E804()){W(0x28)=2;func_02205138((int)a,(int *)s);}break;
    case 2:if(!func_02204EA0((int)a,(int *)s)&&func_02205168((int)a,(int *)s)){if(W(0x8c))W(0x28)=4;else{W(0x28)=3;func_022054E8((int)a,(int *)s,1);}}break;
    case 3:W(0x88)=1;W(0x28)=4;break;
    case 4:func_02205384(s,W(0x78),0,0,2,W(0x10),4,0);W(0x28)=5;break;
    case 5:if(func_022053E8(s)&&func_0220546C(s)){func_022054E8((int)a,(int *)s,0);W(0x28)=6;func_02206044(P(0x104));}break;
    case 6:if(func_0220604C(P(0x104))){W(0x28)=7;func_02204ED0((int)a,(int *)s);}break;
    case 7:if(!func_02204EF0((int)a,(int *)s)){W(0x28)=8;func_02206050(P(0x104));func_0220882C(P(0x108));func_020061E4(0x7dc);W(0x10c)=1;W(0x2c)=0;}break;
    case 8:
        keys=func_020362DC();
        if(func_0220606C(P(0x104))){if(W(0x24))W(0x28)=13;else W(0x28)=9;break;}
        if(func_02206070(P(0x104)))func_02204F00((int)a,s);
        if(func_02206074(P(0x104)))func_02204F24((int)a,(int *)s);
        if(func_02206058(P(0x104))){func_02208844(P(0x108));if(!W(0x110)){func_020061E4(0x7df);W(0x10c)=0;W(0x110)=1;}}
        if(func_02208850(P(0x108)))func_0220605C(P(0x104));
        if(func_02208860(P(0x108))){func_02206064(P(0x104));if(!W(0x114)){if(!W(0x24))W(0x10c)=1;W(0x114)=1;}}
        if(W(0x10c)){
            if(!W(0x118)&&W(0x2c)>=90){if(func_02204F68((int)a,(int *)s)){func_020061E4(0x7dd);W(0x118)=1;}}
            else if(W(0x2c)==0x212||W(0x2c)==0x249||W(0x2c)==0x280||W(0x2c)==0x2b7)func_020061E4(0x7de);
            else if(W(0x2c)==0x2e4)func_020061E4(0x7e0);
            W(0x2c)++;
        }
        if(A(0x10)&&func_02204F68((int)a,(int *)s)&&!W(0x24)&&(keys&2)&&func_02206078(P(0x104))){W(0x24)=1;func_020355D8(0);func_02208814(P(0x108));}break;
    case 9:
        func_020178D8(P(0x10),AH(8));
        if(A(0)){v=func_0200CA1C((void *)A(0));func_0200CFA0(v,P(0x10));func_0200CDE0(v,P(0x10));}
        func_02204FA0((int)a,(int *)s);if(W(0x8c))W(0x28)=11;else{func_022054E8((int)a,(int *)s,1);W(0x28)=10;}break;
    case 10:W(0x88)=1;W(0x28)=11;break;
    case 11:func_02205384(s,W(0x78),2,0,0,W(0x14),1,W(0x10));W(0x28)=12;break;
    case 12:if(func_022053E8(s)&&!func_02204FC4((int)a,(int *)s)&&func_0220546C(s)){func_020272A4((u16)func_02017E1C(P(0x10),5,0),W(0x14));v=func_02012F2C((void *)A(0));func_02008DF0(v,10);func_02008DF0(v,88);W(0x28)=17;}break;
    case 13:if(W(0x24))func_02204FF8((int)a,s);else func_02204F40((int)a,(int *)s);if(W(0x8c))W(0x28)=15;else{func_022054E8((int)a,(int *)s,1);W(0x28)=14;}break;
    case 14:W(0x88)=1;W(0x28)=15;break;
    case 15:func_02205384(s,W(0x78),1,0,2,W(0x10),4,0);W(0x28)=16;break;
    case 16:if(func_022053E8(s)&&func_0220546C(s))W(0x28)=42;break;
    case 17:switch(AB(11)){case 14:func_022056E8((u32 *)a,s);break;case 6:case 19:case 20:func_02205844((int)a,s);break;}W(0x28)=18;W(0x20)=0;break;
    case 18:
        H(0x1c)=func_02018328(P(0x10),(u32 *)(s+0x20),H(0));
        if(!H(0x1c))W(0x28)=42;else if(H(0x1c)!=0xfffe){if(H(0x1c)&0x8000){H(0x1c)&=0x7fff;W(0x28)=20;}else{W(0x28)=19;func_02205384(s,W(0x7c),3,0,2,W(0x10),3,(u32)(s+0x1c));func_02204FD4((int)a,(int *)s);}}break;
    case 19:if(func_022053E8(s)&&func_0220546C(s))W(0x28)=18;break;
    case 20:W(0x28)=21;func_02205384(s,W(0x7c),4,0,2,W(0x10),3,(u32)(s+0x1c));break;
    case 21:if(func_022053E8(s)){W(0x28)=22;func_022055BC(s,W(0x90),2,4,0,4,0,W(0x90),3,4,0,4,0);func_021B70F4(P(0x9c),W(0x94),W(0x98));}break;
    case 22:
        result=func_021B76B0(P(0x9c));if(result==2)break;
        if(result==1){if(A(0xc)){W(0x28)=23;func_0204E720(3,0,16,0);}else{W(0x28)=27;func_0204E720(2,0,16,0);}}
        else if(!result)W(0x28)=36;
        func_021B72DC(P(0x9c));break;
    case 23:
        if(func_0204E804())break;
        func_02204D5C((int)a,(int *)s);W(0x28)=24;
        v=func_02012EBC((void *)A(0));
        ((u8 *)P(0x100))[0xc]=1;*(u32 *)((char *)P(0x100)+8)=A(0);*(u32 *)((char *)P(0x100)+0x24)=0;*(u32 *)P(0x100)=A(4);
        *(void **)((char *)P(0x100)+4)=func_0200873C(v);((u8 *)P(0x100))[0xe]=func_0201AA18((void *)A(4));((u8 *)P(0x100))[0xf]=AB(0xa);*(u16 *)((char *)P(0x100)+0x14)=H(0x1c);
        ((u8 *)P(0x100))[0xd]=2;((u8 *)P(0x100))[0x10]=1;*(u32 *)((char *)P(0x100)+0x20)=0;
        func_02034AC4((int)ov131_id);func_02031348(P(0x11c),-1,d_021DC800,P(0x100));break;
    case 24:if(tick!=1)W(0x28)=25;else return 0;break;
    case 25:func_02034A5C((int)ov131_id);W(0x28)=26;func_02204C24((struct App *)a,(struct Scene *)s);func_0203D34C(0,H(0));func_0204E720(3,16,0,0);break;
    case 26:
        if(!func_0204E804()){q=P(0x100);switch(q[0x12]){case 0:result=q[0x11];B(0x1a)=result;H(0x18)=func_02017E1C(P(0x10),result+0x36,0);W(0x28)=31;break;case 1:case 2:default:W(0x28)=36;break;}}break;
    case 27:
        if(func_0204E804())break;
        W(0x28)=28;func_021B709C(P(0x9c));W(0x9c)=0;func_02205A84((int)P(4));B(0xac)=func_020355C4()==0;
        P(0xa4)=func_02030734(H(0),func_02030CB0(8),0,(char *)d_02208F40,0x548);
        func_02082BCC(P(0xa4),0,func_02030CB0(8));P(0xa0)=func_02030CBC(8,P(0xa4));P(0xa8)=func_02021518(H(0));func_02021EE4(P(0xa8),1);
        func_0202155C(P(0xa8),1,0x1e0,H(0));func_0202155C(P(0xa8),3,0x1e0,H(0));
        W(0xb0)=A(0);W(0xb4)=A(4);W(0xbc)=W(8);H(0xc0)=H(0);B(0xcf)=4;B(0xfc)=0;B(0xd0)=AB(0xa);H(0xd6)=H(0x1c);W(0xc4)=0;P(0xf4)=s+0xac;W(0xd8)=W(0xa0);W(0xdc)=W(0xa8);W(0xf0)=1;
        func_02034AC4((int)ov196_id);func_02034AC4((int)ov198_id);func_0220F3E8((u8 *)(s+0xb0));func_0204E720(2,16,0,0);break;
    case 28:func_02030D28(P(0xa0));if(B(0xfc)){W(0x28)=29;func_0204E720(2,0,16,0);}break;
    case 29:
        if(func_0204E804())break;
        W(0x28)=30;func_02034A5C((int)ov196_id);func_02034A5C((int)ov198_id);func_020215A0(P(0xa8),1);func_020215A0(P(0xa8),3);func_02021540(P(0xa8));func_02030DA4(P(0xa0));func_020307B0(P(0xa4));W(0xa0)=0;W(0xa4)=0;W(0xa8)=0;
        func_02205A34(P(4));P(0x9c)=func_021B6DC0(H(0),5,0,1,0,func_02205A28(P(4)),W(8),W(0xc),0);func_0203D34C(0,H(0));func_0204E720(2,16,0,0);break;
    case 30:
        if(func_0204E804())break;
        B(0x1a)=B(0xfb);if(B(0x1a)==4)W(0x28)=36;else{H(0x18)=func_02017E1C(P(0x10),B(0x1a)+0x36,0);W(0x28)=31;}
        func_020355D8(B(0xac)?0:1);break;
    case 31:if(W(0x8c))W(0x28)=33;else{W(0x28)=32;func_022054E8((int)a,(int *)s,1);}break;
    case 32:W(0x88)=1;W(0x28)=33;break;
    case 33:func_02205384(s,W(0x7c),5,(u32)func_02205360,2,W(0x10),3,(u32)(s+0x18));W(0x28)=34;break;
    case 34:if(func_022053E8(s)){func_020181F4(P(0x10),H(0x1c),B(0x1a));W(0x28)=35;func_02205384(s,W(0x7c),6,0,2,W(0x10),3,(u32)(s+0x1c));func_02204FD4((int)a,(int *)s);}break;
    case 35:if(func_022053E8(s))W(0x28)=18;break;
    case 36:if(W(0x8c))W(0x28)=38;else{W(0x28)=37;func_022054E8((int)a,(int *)s,1);}break;
    case 37:W(0x88)=1;W(0x28)=38;break;
    case 38:func_02205384(s,W(0x7c),7,0,4,0,3,(u32)(s+0x1c));W(0x28)=39;break;
    case 39:if(func_022053E8(s)){W(0x28)=40;{u32 w=W(0x90);func_022055BC(s,w,4,3,(u32)(s+0x1c),4,0,w,5,3,(u32)(s+0x1c),4,0);}func_021B70F4(P(0x9c),W(0x94),W(0x98));}break;
    case 40:
        result=func_021B76B0(P(0x9c));if(result==2)break;
        if(result==1){W(0x28)=41;func_02205384(s,W(0x7c),8,0,2,W(0x10),3,(u32)(s+0x1c));}else if(!result)W(0x28)=20;
        func_021B72DC(P(0x9c));break;
    case 41:if(func_022053E8(s))W(0x28)=18;break;
    case 42:if(W(0x24)){func_0204E720(3,0,16,2);W(0x28)=43;}else if(func_02204F68((int)a,(int *)s)){func_02204F78((int)a,s);func_0204E720(3,0,16,2);W(0x28)=43;}break;
    case 43:if(!func_02204F90((int)a,s)){W(0x28)=44;func_02204EB0(a,s);}break;
    case 44:if(!func_0204E804()){W(0x28)=45;return 1;}break;
    case 45:return 1;
    }
    func_02204DE0(a,s);
    if(W(0x28)!=24&&W(0x28)!=25){
        if(P(0x9c))func_021B7378(P(0x9c));
        func_02205340((int)a,s);func_0201C4E4(P(0xc));func_02205D50(P(0x104));func_0220878C(P(0x108));func_022059FC(P(4));func_02205A10(P(4));func_02208804(P(0x108));func_0220602C(P(0x104));func_02205A1C(P(4));
    }
    return 0;
}
