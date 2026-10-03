/*
 * function: func_021BC6CC
 * address: 0x021BC6CC
 * packet: pkt_ov091_021BC6CC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 seven-argument C724 and scalar stack widths read; 2 own ARM9 C724/D304/18328 and ov091 callees read; 3 u8 flag retained5 out, u32 width with explicit truncation gave20 out; 4 scoped spill locals and narrowed coordinate extern restore instruction order; 5 neighbours and struct-local idiom re-read; permuter300 baseline10 out, verified winner5 out; next lever is flag/width spill allocation.
 * retry: declaring case0 flag before width swaps their spill slots into
 * the original order and closes all 1376 bytes; one wave59 retry run.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02018328 0x02018328 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 *   func_021BC6C0 0x021BC6C0 thumb ov091
 *   func_021B9E44 0x021B9E44 thumb ov091
 *   d_021BECE4 0x021BECE4 data ov091 a2
 * BB9CC's last parameter is a full word here: result stays untruncated in r3.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020450F0(u32,u32,u32,u32,u32,u32,u32);
extern void func_0201F73C(u32,u32,u32,u32);
extern u32 func_02045770(u32);
extern void func_02043B5C(u32,int);
extern void func_02045334(u32);
extern void func_02045374(u32);
extern u8 func_02045730(u32);
extern void func_02041B6C(u8);
extern u32 func_02017E1C(u32,u32,u32);
extern u32 func_02045EC0(u32,u32);
extern void func_0201C724(u32,u32,s16,s16,u32,u32,u16);
extern void func_02045808(u32);
extern u32 func_020457B0(u32,u32);
extern u32 func_0201EC64(u16);
extern void func_0201EFA4(u32,int,int,int,int,int);
extern void func_0201F250(u32,u32,u32);
extern u32 func_0201D304(u32,u32,u32);
extern void func_0201ED04(u32);
extern int func_0201C6C4(u32,u32);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32);
extern void func_02043AF4(u32,int,int,int,int,int);
extern void func_020456F8(u32);
extern void func_0201F7A8(u32,int);
extern void func_020452E8(u32);
extern u16 func_02018328(u32,u32 *,u32);
extern void func_021BB7A4(u8 *,u32);
extern void func_021BB97C(u8 *,u32);
extern void func_021BB99C(u8 *,u32,u32,u32);
extern void func_021BB9CC(u8 *,u32,u32,u32);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BB98C(u8 *,u32);
extern void func_021B9EB0(void);
extern void func_021BC6C0(void);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void func_021B9E44(u8 *);
extern u16 d_021BECE4[];
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define S ((u8 *)W(0x280))
#define T(k) (*(u32 *)(S+(k)))
void func_021BC6CC(u8 *p)
{
    u8 i,j,x;
    u32 q,result,off;
    switch(p[0xe]) {
    case 0: {
        u8 flag;
        u32 delta,buf,tmp,text;
        int y;
        u16 width;
        flag=0;
        W(0x130)=func_020450F0(0,1,1,14,12,14,1);
        func_0201F73C(W(0x130),1,1,12);
        func_02043B5C(func_02045770(W(0x130)),15);
        q=W(0x130); func_02045334(q); func_02045374(q); func_02041B6C(func_02045730(q));
        for(i=0;i<6;i++) {
            off=i; off=off*2;
            delta=func_02017E1C(W(0x38),*(u16 *)((u8 *)d_021BECE4+off),0)-*(u16 *)(p+off+0x124);
            if(delta>=10) flag=1;
            buf=func_02045EC0(W(0x134),i+0x95); y=i<<4;
            func_0201C724(W(0x140),func_02045770(W(0x130)),0,(s16)(i<<4),buf,W(0x138),0x440);
            func_02045808(buf);
            buf=func_02045EC0(W(0x134),0x9c); tmp=func_020457B0(0x20,H(0)); text=func_0201EC64(H(0));
            func_0201EFA4(text,0,delta,3,0,1); func_0201F250(text,tmp,buf);
            width=func_0201D304(tmp,W(0x138),0);
            func_0201C724(W(0x140),func_02045770(W(0x130)),(s16)(104-width),(s16)y,tmp,W(0x138),0x440);
            func_02045808(buf); func_02045808(tmp); func_0201ED04(text);
        }
        for(j=0;j<6;j++) {
            x=flag==1 ? 72 : 80;
            buf=func_02045EC0(W(0x134),0x9b);
            func_0201C724(W(0x140),func_02045770(W(0x130)),x,(s16)(j<<4),buf,W(0x138),0x440);
            func_02045808(buf);
        }
        p[0xe]=1; break;
    }
    case 1:
        if(func_0201C6C4(W(0x140),func_02045770(W(0x130)))==0) {
            q=W(0x130); func_02045334(q); func_02045374(q); func_02041B6C(func_02045730(q)); p[0xe]=2;
        } break;
    case 2:
        if((func_020362DC()&1)||(func_020362DC()&2)||func_02035C60()==1) { func_020061E4(0x547); p[0xe]=3; }
        break;
    case 3: {
        u16 width;
        u32 delta,buf,tmp,text;
        func_02043AF4(func_02045770(W(0x130)),0x50,0,0x20,0x60,15);
        for(i=0;i<6;i++) {
            delta=func_02017E1C(W(0x38),d_021BECE4[i],0);
            buf=func_02045EC0(W(0x134),0x9c); tmp=func_020457B0(0x20,H(0)); text=func_0201EC64(H(0));
            func_0201EFA4(text,0,delta,3,0,1); func_0201F250(text,tmp,buf);
            width=func_0201D304(tmp,W(0x138),0);
            func_0201C724(W(0x140),func_02045770(W(0x130)),(s16)(104-width),(s16)(i<<4),tmp,W(0x138),0x440);
            func_02045808(buf); func_02045808(tmp); func_0201ED04(text);
        }
        p[0xe]=4; break;
    }
    case 4:
        if(func_0201C6C4(W(0x140),func_02045770(W(0x130)))==0) {
            q=W(0x130); func_02045334(q); func_02045374(q); func_02041B6C(func_02045730(q)); p[0xe]=5;
        } break;
    case 5:
        if((func_020362DC()&1)||(func_020362DC()&2)||func_02035C60()==1) {
            p[0xe]=6; func_020061E4(0x547); func_020456F8(W(0x130)); func_0201F7A8(W(0x130),1); func_020452E8(W(0x130)); W(0x130)=0;
        } break;
    case 6:
        result=func_02018328(W(0x38),(u32 *)(S+0x50),H(0)); func_021BB7A4(p,W(0x150));
        if(result==0) { p[0xe]=7; return; }
        if(result==0xfffe) { p[0xe]=7; return; }
        if(result&0x8000) {
            *(u16 *)(S+0x46)=result-0x8000;
            func_021BB97C(p,W(0x150)); func_021BB99C(p,W(0x150),0,W(0x38));
            func_021BB9CC(p,W(0x150),1,*(u16 *)(S+0x46));
            func_021B9788(p,0x20,0,(int)func_021B9EB0); func_021BB98C(p,W(0x150));
        } else {
            func_021BB97C(p,W(0x150)); func_021BB99C(p,W(0x150),0,W(0x38));
            func_021BB9CC(p,W(0x150),1,result);
            func_021B9788(p,0x29,1,(int)func_021BC6C0); func_021BB98C(p,W(0x150));
        } break;
    case 7:
        func_02017E1C(W(0x38),5,0);
        if(func_0201B2B0((void *)T(0),(void *)W(0x38),0,*(u16 *)(S+0x30),S[0x5f],0,H(0))!=0) {
            p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=9;
        } else {
            T(0x34)=5; T(0x3c)=W(0x2c); T(0x40)=10; func_021B9E44(p);
        } break;
    }
}

