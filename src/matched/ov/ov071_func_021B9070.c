/*
 * function: func_021B9070
 * address: 0x021B9070
 * packet: pkt_ov071_021B9070
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final halfword at 021B94CA is alignment padding.
 * lever: state9 writes its state10 tail twice, one reached by goto, preserving the cross-jump.
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0201F184 0x0201F184 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF08 0x0200BF08 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_020266AC 0x020266AC thumb
 *   func_02158344 0x02158344 thumb ov010
 *   func_02174660 0x02174660 thumb ov011
 *   func_021B6C7C 0x021B6C7C thumb ov071
 *   func_021B9BD8 0x021B9BD8 thumb ov071
 *   func_021B9BAC 0x021B9BAC thumb ov071
 *   func_021B9798 0x021B9798 thumb ov071
 *   func_021B98B4 0x021B98B4 thumb ov071
 *   func_021B98C4 0x021B98C4 thumb ov071
 *   func_021B9F2C 0x021B9F2C thumb ov071
 *   func_021B7108 0x021B7108 thumb ov071
 *   func_021B9C7C 0x021B9C7C thumb ov071
 *   func_021BA004 0x021BA004 thumb ov071
 *   func_021BA0CC 0x021BA0CC thumb ov071
 *   func_021BA11C 0x021BA11C thumb ov071
 *   func_021BA140 0x021BA140 thumb ov071
 *   func_021BA01C 0x021BA01C thumb ov071
 *   func_021B6B58 0x021B6B58 thumb ov071
 *   func_021B6C74 0x021B6C74 thumb ov071
 *   func_021B7194 0x021B7194 thumb ov071
 *   func_021B7204 0x021B7204 thumb ov071
 *   func_021B71FC 0x021B71FC thumb ov071
 *   func_021B6C30 0x021B6C30 thumb ov071
 *   func_021B6B98 0x021B6B98 thumb ov071
 *   func_021B9818 0x021B9818 thumb ov071
 *   func_021B7114 0x021B7114 thumb ov071
 *   func_021B9C30 0x021B9C30 thumb ov071
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_02034714 0x02034714 arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 */
#include "../include/Obj13181.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { FALSE, TRUE } Bool;
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02158344(u32);
extern void func_021B6C7C(void *,int);
extern void func_021B9BD8(u8 *);
extern void func_021B9BAC(void *,u32);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef signed int     s32;
typedef unsigned short u16;
struct Big;
struct BigObj;
struct PrintSys;
struct WordSet;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_021B9798(void *,void *,u32);
extern int func_021B98B4(void *,void *);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern u32 func_0203630C(void);
extern void func_021B98C4(void *);
extern void func_020061E4(u32);
extern int func_021B9F2C(void *,int,int);
extern int func_02035C08(const void *);
extern void func_021B7108(void *);
extern void func_020355D8(u8 v);
extern void func_021B9C7C(void *,void *);
extern void func_021BA004(void *);
extern int func_021BA0CC(void *,int);
extern void func_021BA11C(void *);
extern void func_021BA140(void *);
extern void func_021BA01C(void *,void *);
extern void func_021B6B58(void *,int);
extern u8 func_021B6C74(void *,int);
extern void func_02034714(const void *,int,const void *);
extern void *func_021B7194(int *p, void *arg1, u32 heap);
extern int func_021B7204(int a, int b, void *p, int *q);
extern void func_021B71FC(void *p);
extern void func_021B6C30(void *,int,int);
extern void func_021B6B98(void *,void *,int,int,int);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern int func_02174660(int,...);
extern void func_021B9818(void *,void *,u32);
extern void func_02005E30(int);
extern int func_02005E50(void);
extern void func_02005DE4(void *p);
extern void func_02005E64(void);
extern void func_02005D90(int,int);
extern int func_02005F38(void);
extern void func_02005E9C(void);
extern void func_02005DF8(int);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0200BF08(u32,u32);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_020266AC(u32,u32,u32);
extern int func_021B7114(void *);
extern void func_021B9C30(u8 *);
extern const u32 d_021BAAFC[];
extern const u32 d_021BABFC[];
#define W(k) (*(u32 *)(o+(k)))
#define C(k) (*(u32 *)(c+(k)))
#define CP(k) ((u8 *)C(k))
int func_021B9070(int unused,int *state,u8 *c,u8 *o)
{
    u32 initial,handle,mask,save;
    int active,result,off;
    unsigned short flip;
    initial=func_02158344(func_02012138((const struct Ctx *)*(u32 *)CP(0)));
    func_021B6C7C(c,1); func_021B6C7C(c,3);
    func_021B9BD8(o); func_021B9BAC(CP(4),(u32)o);
    handle=*(u32 *)(CP(4)+8);
    if (o[0x28c]!=0 && func_0201C6C4((struct PrintSys *)handle,(void *)((u32)func_02045770((struct Descriptor *)W(0x288))))==0) {
        func_02045334((struct Descriptor *)W(0x288)); o[0x28c]=0;
    }
    if (c[0x2e]==1 && *state==4) return 1;
    switch (*state) {
    case 0: *state=1; break;
    case 1: func_021B9798(o,CP(4),0x25); ++*state; break;
    case 2:
        if (func_021B98B4(CP(4),o)==1 && (func_02035C60()!=0 || (func_020362DC()&3))) {
            func_021B98C4(o); func_020061E4(0x547);
            if (func_02035C60()==0) func_021B9F2C(o,1,0);
            else func_021B9F2C(o,0xffff,0);
            ++*state;
        } break;
    case 3:
        if (func_02035C38()==0 && !(func_0203630C()&3)) *state=4;
        break;
    case 4:
        mask=func_020362DC(); active=func_02035C08(d_021BAAFC);
        if (active==0 || (mask&2)) {
            func_021B7108(o+0x298);
            if (active==0) func_020355D8(TRUE);
            else func_020355D8(FALSE);
            func_020061E4(0x551); *state=17; break;
        }
        func_021B9C7C(c,o); func_021BA004(o);
        off=0x2e0;
        if (func_021BA0CC(o,W(off)+W(off+4))==1) {
            func_021BA11C(o); func_021BA140(o); W(off+16)=1;
        }
        func_021BA01C(c,o);
        if (W(0x2f4)==0xffff) { CP(8)[1]=0x30; }
        else {
            CP(8)[1]=*(u32 *)(o+(W(0x2f4)<<2)+0xec);
            CP(8)[2]=*(u32 *)(o+(W(0x2f4)<<2)+0x1b4);
            if (*(u32 *)(o+(W(0x2f4)<<2)+0x1b4)==0) {
                func_021B6B58(o+8,1); goto selected;
            }
        }
        func_021B6B58(o+8,0);
selected:
        if (W(0x300)!=0xffff) { func_020061E4(0x54c); *state=5; }
        break;
    case 5:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_021B9798(o,CP(4),0x20); ++*state;
        } break;
    case 6:
        if (func_021B98B4(CP(4),o)==1) {
            if (W(0x310)!=0) func_02034714(d_021BABFC,0,d_021BABFC);
            W(0x310)=(u32)func_021B7194((int *)CP(4),(void *)W(0x30c),0x61); ++*state;
        } break;
    case 7:
        if (func_021B7204(C(4),4,(void *)W(0x310),&result)==1) {
            func_021B71FC((void *)W(0x310)); W(0x310)=0; func_021B98C4(o);
            if (result==1) *state=8;
            else { W(0x300)=0xffff; func_021B6C30(c,1,1); func_021B6B98(c,o+8,1,0xff,3); *state=4; }
        } break;
    case 8:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_0201F184((struct WordSet *)(*(u32 *)(CP(4)+0x10)),0,*(u32 *)(o+(W(0x300)<<2)+0xec));
            func_021B9818(o,CP(4),0x23); *state=9;
        } break;
    case 9:
        if (initial==0) goto write10;
        if (func_02174660(CP(0)[0x3c])==1) { *state=10; break; }
        break;
write10:
        *state=10;
        break;
    case 10:
        if (func_021B98B4(CP(4),o)==1) { func_02005E30(6); ++*state; }
        break;
    case 11:
        if (func_02005E50()==0) { func_02005DE4((void *)1); func_02005E64(); ++*state; }
        break;
    case 12: func_02005D90(0x531,0xffff); ++*state; break;
    case 13:
        if (func_02005F38()==0) { func_02005E9C(); func_02005DE4(0); func_02005DF8(6); ++*state; }
        break;
    case 14: if (func_02005E50()==0) *state=15; break;
    case 15:
        if (func_02035C60()!=0 || (func_020362DC()&3)) {
            func_021B98C4(o);
            func_0200BF08((u32)func_0200BE48(func_02012EBC(func_020120F4((const struct Ctx *)(*(u32 *)CP(0))))),*(u32 *)(o+(W(0x300)<<2)+0xec));
            save=func_02012138((const struct Ctx *)*(u32 *)CP(0));
            handle=C(0);
            func_020266AC(save,func_02012B58(func_020120F4((const struct Ctx *)(((struct Obj13181 *)handle)->f0))),((struct Obj13181 *)handle)->f3C);
            W(0x300)=0xffff; func_021B6C30(c,1,1); func_021B6B98(c,o+8,1,0xff,3);
            if (func_02035C60()!=0) *state=16;
            else *state=17;
        } break;
    case 16: if (func_02035C38()==0) *state=17; break;
    case 17:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2 && func_021B7114(o+0x298)==0) {
            c[0x2c]=0; return 1;
        } break;
    }
    func_021B9C30(o); return 0;
}
