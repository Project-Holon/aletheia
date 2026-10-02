/*
 * function: func_021544F0
 * address: 0x021544F0
 * packet: pkt_ov006_021544F0
 * region: ov006
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blockers: code-start witnesses for ov006 func_021544BC and ov099
 * func_021C2850; overlay-ID consumer evidence for func_02012444:r1
 * (IDs 127,134,8,119,195,172). All concrete bytes match.
 * Matching levers: typed Sel table folds the u16 field offset into its
 * pool word; Pair struct copies to SP; char-pointer field addressing
 * avoids loop spills; repeated cleanup tails preserve cross-jumped hops.
 * checks: 1 callees and PC-relative IDs rederived; 2 no matching twin;
 * 3 const 02031330 and unsigned counter worsened; 4 repeated cleanup
 * tails closed branch residue; 5 idioms relisted and neighbours reread.
 * TU --suggest-split: one section, no viable cut; tool consumer correction
 * needed before filing the two overlay leaves. No ARM9 blocker remains.
 * Prototype evidence: 02031324 and 02031348 forward all registers to
 * 02031354(int) and 020314F4(obj,u32,u32,u32); 0200F7B8 receives the
 * explicitly loaded zero despite its legacy void declaration.
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_02026454 0x02026454 thumb
 *   func_020144DC 0x020144DC thumb
 *   func_02012374 0x02012374 thumb
 *   func_02029F6C 0x02029F6C thumb
 *   func_020145CC 0x020145CC thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_020130B4 0x020130B4 thumb
 *   func_02013090 0x02013090 thumb
 *   func_02012444 0x02012444 thumb
 *   func_02012950 0x02012950 thumb
 *   func_02012F2C 0x02012F2C thumb
 *   ov008_id 0x8 data a1
 *   ov067_id 0x43 data a1
 *   ov127_id 0x7f data a1
 *   ov115_id 0x73 data a1
 *   ov099_id 0x63 data a1
 *   ov134_id 0x86 data a1
 *   ov093_id 0x5d data a1
 *   ov119_id 0x77 data a1
 *   ov195_id 0xc3 data a1
 *   ov172_id 0xac data a1
 *   func_0203CDBC 0x0203CDBC arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   func_0203133C 0x0203133C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203A574 0x0203A574 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203D210 0x0203D210 arm
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_0215444C 0x0215444C thumb ov006
 *   func_021544BC 0x021544BC thumb ov006
 *   func_021544D4 0x021544D4 thumb ov006
 *   func_02154ABC 0x02154ABC thumb ov006
 *   func_021542C0 0x021542C0 thumb ov006
 *   func_021C2850 0x021C2850 thumb ov099
 *   d_021D6338 0x021D6338 data ov115 a4
 *   d_021D654C 0x021D654C data ov115 a4
 *   d_021C37E8 0x021C37E8 data ov099 a4
 *   d_02154C40 0x02154C40 data ov006 a2
 *   d_021DCCA4 0x021DCCA4 data ov134 a4
 *   d_021F03C4 0x021F03C4 data ov093 a4
 *   d_02154C2C 0x02154C2C data ov006 a1
 *   d_0215513C 0x0215513C data ov008 a4
 *   d_021E75C0 0x021E75C0 data ov119 a4
 *   d_02154C80 0x02154C80 data ov006 a4
 *   d_02208C40 0x02208C40 data ov195 a4
 *   d_021C7240 0x021C7240 data ov172 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#define W(p,k) (*(u32 *)((char *)(p)+(k)))
#define H(p,k) (*(u16 *)((char *)(p)+(k)))
#define B(p,k) (*(u8 *)((char *)(p)+(k)))
typedef struct {u32 pad00[5];u32 values[2];} Sub;
extern u16 func_02005C44(void);
extern void func_02005E30(u32);
extern int func_02012138(void *);
extern u32 func_02026454(void *);
extern int func_020144DC(int,int);
extern void *func_020145CC(void *);
extern void func_02012374(void *,void *);
extern void func_020057AC(void);
extern int func_0203CDBC(void);
extern void func_02029F6C(void);
extern int func_021BE92C(void *,int,int,int,int,u8,u8);
extern void func_02082BCC(void *,int,int);
extern int func_020120F4(void *);
extern void func_02006740(void);
extern void func_02005D90(u32,u16);
extern void func_02005DF8(u32);
extern void *func_02031324(int);
extern void func_02031348(void *,u32,u32,u32);
extern u32 func_02031330(void *);
extern void func_0203133C(void *);
extern void func_0200F7B8(int);
extern u32 func_0201283C(const void *);
extern u32 func_02009A34(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_021C2850(u32);
extern int func_020130B4(int);
extern void func_02012444(void *,u32,u32,u32);
extern void func_0215444C(char *,u32,int);
extern void *func_02013090(u32);
extern void func_021542C0(char *,int);
extern void func_021544BC(char *,u32,int);
extern void *func_020399A8(void);
extern void func_0203A574(u32,u32,u32,u32);
extern void func_02039C68(void *,u32,u32);
extern u32 func_02039CB4(void *,u32,u32);
extern int func_0203CD98(void);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
extern u32 func_0203D1A4(void *);
extern void *func_02012950(void *,u32);
extern void *func_02012F2C(int *);
extern void func_02009BB8(void *,int,int,int,int);
extern void func_0203A5E4(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_020307B0(void *);
extern void func_021544D4(u8 *);
extern int func_0203CEAC(int);
extern u32 func_0203D210(void);
extern void func_02154ABC(int *);
extern const char d_021D6338[],d_021D654C[],d_021DCCA4[],d_021F03C4[],d_021C37E8[];
extern const char d_0215513C[],d_021E75C0[],d_02154C80[],d_02208C40[],d_021C7240[];
extern char ov008_id[],ov067_id[],ov127_id[],ov115_id[],ov099_id[];
extern char ov134_id[],ov093_id[],ov119_id[],ov195_id[],ov172_id[];
typedef struct {u8 a,b;} Pair;
extern const Pair d_02154C2C;
typedef struct {u8 val,pad;u16 state;} Sel;
extern const Sel d_02154C40[];

int func_021544F0(void *evt,u32 *state,char *obj)
{
    void *p;
    u32 s;
    int i,off;
    Pair pair;
    char *r;
    p=(void *)W(obj,4);
    s=*state;
    switch(s) {
    case 0:
        H(obj,0x170)=func_02005C44();
        func_02005E30(6);
        ++*state;
        break;
    case 1:
        if (!func_02026454((void *)func_02012138(p))) {
            W(obj,0x10)=0;
            func_02012374(evt,(void *)func_020144DC((int)p,W(obj,8)));
            ++*state;
        }
        break;
    case 2:
        func_020057AC();
        *state=8;
        break;
    case 3: break;
    case 4:
        if (func_0203CDBC()) {
            ++*state;
            func_02154ABC((int *)obj);
            func_02006740();
            func_02005D90(H(obj,0x170),0xffff);
            func_02005DF8(60);
        }
        break;
    case 5:
        func_02029F6C();
        func_02012374(evt,func_020145CC(p));
        ++*state;
        break;
    case 6:
        if (W(obj,0x14))
            func_02012374(evt,(void *)func_021BE92C(p,W(obj,8),0,0,1,0,0));
        ++*state;
        break;
    case 7: return 1;
    case 8:
        func_02082BCC(obj+0x98,0,0x28);
        *state=9;
        W(obj,0xac)=0;
        break;
    case 9:
        W(obj,0x98)=func_020120F4(p);
        W(obj,0xa0)=1;
        W(obj,0x9c)=0;
        W(obj,0xa4)=10;
        W(obj,0xb0)=1;
        func_02005D90(0x481,0xffff);
        W(obj,0x1c)=(u32)func_02031324(4);
        func_02031348((void *)W(obj,0x1c),(u32)ov115_id,(u32)d_021D6338,(u32)(obj+0x98));
        W(W(obj,0x5c),0xc)=0;
        *state=10;
        break;
    case 10:
        if (func_02031330((void *)W(obj,0x1c))) { func_0200F7B8(0); return 0; }
        func_0203133C((void *)W(obj,0x1c));
        if (!W(obj,0xb4)) {
            if (!func_02009A34((void *)func_0201283C((void *)W(obj,0x90)))) *state=30;
            else { *state=11; func_02005E30(6); }
        } else { func_02005E30(6); *state=25; }
        break;
    case 30:
        W(obj,0xc0)=func_020120F4(p);
        W(obj,0xc8)=1;
        W(obj,0xc4)=0;
        W(obj,0xcc)=1;
        W(obj,0xd0)=0;
        W(obj,0xd4)=0;
        W(obj,0xd8)=0;
        W(obj,0x1c)=(u32)func_02031324(4);
        func_02031348((void *)W(obj,0x1c),(u32)ov115_id,(u32)d_021D654C,(u32)(obj+0xc0));
        ++*state;
        break;
    case 31:
        if (func_02031330((void *)W(obj,0x1c))) { func_0200F7B8(0); return 0; }
        func_0203133C((void *)W(obj,0x1c));
        func_02005E30(6);
        *state=4;
        break;
    case 11:
        func_02034AC4((int)ov099_id);
        func_02034AC4((int)ov067_id);
        func_021C2850(W(W(obj,0x5c),0));
        if (W(obj,0xdc)) { func_020130B4(W(obj,0xdc)); W(obj,0xdc)=0; }
        func_02012444((void *)W(obj,0),(u32)ov127_id,(u32)d_021C37E8,W(obj,0x5c));
        ++*state;
        break;
    case 12:
        *state=d_02154C40[W(W(obj,0x5c),0xc)].state;
        if (W(W(obj,0x5c),0xc)==1) W(obj,0xac)=1;
        B(obj,0x172)=d_02154C40[W(W(obj,0x5c),0xc)].val;
        func_02034A5C((int)ov067_id);
        func_02034A5C((int)ov099_id);
        break;
    case 13:
        func_0215444C(obj,func_020120F4(p),s);
        W(obj,0xdc)=(u32)func_02013090(4);
        func_021542C0(obj,W(W(obj,0x5c),0xc));
        func_02012444((void *)W(obj,0),(u32)ov134_id,(u32)d_021DCCA4,(u32)(obj+0x20));
        ++*state;
        break;
    case 14:
        if (W(obj,0x48)==1) {
            if (func_0203CD98()) {
                B(W(obj,0x5c),0x49)=0;
                *state=11;
            } else {
                func_021544D4((u8 *)obj);
                *state=9;
            }
        } else {
            func_021544BC(obj,func_020120F4(p),s);
            func_02034AC4((int)ov093_id);
            func_0203A574(0x100,(u32)d_021F03C4,9,0);
            func_02039C68(func_020399A8(),100,10);
            ++*state;
        }
        break;
    case 15:
        if (!func_0203CD98() || func_0200FB24()) {
            func_0200FBB0(); func_0200F83C(); goto cleanup;
        }
        if (func_02039CB4(func_020399A8(),100,10)) ++*state;
        break;
    case 16:
        func_02005D90(0x490,0xffff);
        W(obj,0x124)=1;
        if (!func_0203D1A4(func_020399A8())) {
            for (i=0;i<2;i++) {
                off=i<<4;
                W((u32)obj+off,0xe4)=(u32)func_02012950((void *)func_020120F4(p),i);
                W((u32)obj+off,0xe0)=((Sub *)W(obj,0x5c))->values[i];
            }
        } else {
            pair=d_02154C2C;
            for (i=0;i<2;i++) {
                off=((u8 *)&pair)[i]<<4;
                W((u32)obj+off,0xe4)=(u32)func_02012950((void *)func_020120F4(p),i);
                W((u32)obj+off,0xe0)=((Sub *)W(obj,0x5c))->values[i];
            }
        }
        W(obj,0x138)=func_020120F4((void *)W(obj,4));
        W(obj,0x13c)=W(obj,0xdc);
        W(obj,0x140)=(u32)(obj+0xe0);
        W(obj,0x14c)=1;
        W(obj,0x134)=(u32)func_02012F2C((int *)func_020120F4((void *)W(obj,4)));
        func_02034A5C((int)ov093_id);
        func_02012444((void *)W(obj,0),(u32)ov008_id,(u32)d_0215513C,(u32)(obj+0x138));
        ++*state;
        break;
    case 17:
        if (!func_0203CD98()) goto cleanup;
        if (W(obj,0x120)==0)
            func_02009BB8((void *)func_0201283C((void *)func_020120F4((void *)W(obj,4))),B(W(obj,0x5c),0x47)-1,1,0,0);
        else if (W(obj,0x120)==1)
            func_02009BB8((void *)func_0201283C((void *)func_020120F4((void *)W(obj,4))),B(W(obj,0x5c),0x47)-1,0,1,0);
        func_0203A5E4(0x100);
        *state=11;
        break;
    case 18:
        W(obj,0x68)=0;
        H(obj,0x8c)=B(W(obj,0x5c),0x47);
        ++*state;
        break;
    case 19:
        W(obj,0x74)=func_020120F4(p);
        func_02012444((void *)W(obj,0),(u32)ov119_id,(u32)d_021E75C0,(u32)(obj+0x60));
        ++*state;
        break;
    case 20:
        switch(W(obj,0x68)) {
        case 1: *state=21; break;
        case 2: W(W(obj,0x5c),0xc)=1; *state=11; break;
        default: *state=11; break;
        }
        if (!func_0203CD98()) {
            func_021544D4((u8 *)obj);
            *state=9;
        }
        break;
    case 21:
        r=func_02030734(4,0x14,0,d_02154C80,0x24b);
        W(r,0)=func_020120F4((void *)W(obj,4));
        W(r,4)=W(obj,0x7c);
        H(r,8)=W(obj,0x6c);
        B(r,0xa)=0;
        B(r,0xb)=W(obj,0x70);
        W(r,0xc)=1;
        W(r,0x10)=0;
        W(obj,0x80)=(u32)r;
        func_02012444((void *)W(obj,0),(u32)ov195_id,(u32)d_02208C40,(u32)r);
        *state=22;
        break;
    case 22:
        func_020307B0((void *)W(obj,0x80));
        W(obj,0x68)=1;
        *state=19;
        if (!func_0203CD98()) {
            func_021544D4((u8 *)obj);
            *state=9;
        }
        break;
    case 23:
        W(obj,0x4c)=func_020120F4(p);
        W(obj,0x50)=3;
        func_02012444((void *)W(obj,0),(u32)ov172_id,(u32)d_021C7240,(u32)(obj+0x4c));
        ++*state;
        break;
    case 24:
        if (func_0203CD98()) goto menu;
cleanup:
        func_021544D4((u8 *)obj);
        *state=9;
        break;
menu:
        *state=11;
        break;
    case 28: func_0203CEAC(0); *state=29; break;
    case 29: if (func_0203D210()) *state=4; break;
    case 25: case 26: case 27: *state=4; break;
    }
    return 0;
}
