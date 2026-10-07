/*
 * file:     monolith_tool_p15.c
 * unit:     yes
 * function: func_021B8EE8, func_021B9070, func_021B94CC, func_021B9560, func_021B95CC, func_021B95FC, func_021B9694, func_021B96A4, func_021B9734
 * address:  0x021B8EE8
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_02045B38  0x02045B38  arm
 *   func_021BA11C  0x021BA11C  thumb  ov071
 *   func_021B9BB8  0x021B9BB8  thumb  ov071
 *   func_021B9AE4  0x021B9AE4  thumb  ov071
 *   func_021B9B64  0x021B9B64  thumb  ov071
 *   func_021B9BE8  0x021B9BE8  thumb  ov071
 *   func_021B9750  0x021B9750  thumb  ov071
 *   func_021B7174  0x021B7174  thumb  ov071
 *   func_020056A0  0x020056A0  thumb
 *   func_021BA1B0  0x021BA1B0  thumb  ov071
 *   func_021B9970  0x021B9970  thumb  ov071
 *   func_021B992C  0x021B992C  thumb  ov071
 *   func_021B9A40  0x021B9A40  thumb  ov071
 *   func_021BA140  0x021BA140  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   func_021B9F2C  0x021B9F2C  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_02012138 0x02012138 thumb
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
 *   func_021B7108 0x021B7108 thumb ov071
 *   func_021B9C7C 0x021B9C7C thumb ov071
 *   func_021BA004 0x021BA004 thumb ov071
 *   func_021BA0CC 0x021BA0CC thumb ov071
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
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_02034714 0x02034714 arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020435F4  0x020435F4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B9A18  0x021B9A18  thumb  ov071
 *   func_021B718C  0x021B718C  thumb  ov071
 *   func_021B9BA0  0x021B9BA0  thumb  ov071
 *   func_021B9B3C  0x021B9B3C  thumb  ov071
 *   func_021B9BC8  0x021B9BC8  thumb  ov071
 *   func_021B9C1C  0x021B9C1C  thumb  ov071
 *   func_02045C04  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAB28     0x021BAB28  data  ov071  a4
 *   d_021BAB48     0x021BAB48  data  ov071  a4
 *   d_021BAB68     0x021BAB68  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02027634  0x02027634  thumb
 *   func_02049238  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../../matched/include/Obj01884.h"
#include "../../matched/include/Obj02123.h"
#include "../../matched/include/Obj13181.h"
#include "../../matched/include/Obj03177.h"
#include "../../matched/include/Obj20746.h"
#include "../../matched/include/Obj20747.h"
#include "../../matched/include/G_Config.h"
#include "../../matched/include/Obj09894.h"
#include "../../matched/include/Obj09895.h"
#include "../../matched/include/Obj04341.h"

#define W(k) (*(u32 *)(o+(k)))
#define C(k) (*(u32 *)(c+(k)))
#define CP(k) ((u8 *)C(k))
struct Obj0203159C;
struct MsgBank;
struct PrintSys;
struct R;
struct Descriptor;
struct Ctx;
struct Big;
struct BigObj;
struct WordSet;
struct Rec1B0;
struct Node;
struct Rec;
struct Rec3;
struct S020315D4;
struct U16Vec;
struct BgTemplate;
struct Cfg;
struct CharBuf;
struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned int u32;

typedef enum { B_FALSE, B_TRUE } Bool_021B8EE8;

typedef unsigned short u16;

typedef enum { FALSE, TRUE } Bool_021B9070;

typedef signed int     s32;

extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021B6C54(char *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021BA11C(char *p);
extern void func_021B9BB8(char *p, char *q);
extern void func_021B9AE4(void *a, void *b);
extern void func_021B9B64(char *p, char *q);
extern void func_021B9BE8(char *p, char *q);
extern void func_021B9750(char *a, char *b);
extern struct R *func_021B7174(u32 *p, int a, u16 heap);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_021BA1B0(void *unused, char *p);
extern void func_021B9970(void *a, void *b, void *c);
extern void func_021B992C(char *a);
extern int func_021B9A40(char *a, char *b);
extern void func_021BA140(u8 *p);
extern u8 func_020355C4(void);
extern int func_021B9F2C(u8 *p, int i, int v);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_021B6C7C(int *p, int idx);
extern void func_021B9BD8(char *p);
extern void func_021B9BAC(void *p, int a);
extern void func_021B9798(char *a, char *b, u32 c);
extern int func_021B98B4(u8 *a, u8 *b);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern u32 func_0203630C(void);
extern void func_021B98C4(char *a);
extern void func_020061E4(u32);
extern int func_02035C08(const void *);
extern void func_021B7108(void *);
extern void func_020355D8(u8 v);
extern void func_021B9C7C(void *,void *);
extern void func_021BA004(char *p);
extern int func_021BA0CC(u8 *p, int d);
extern void func_021BA01C(void *a, u8 *p);
extern void func_021B6B58(void **p, int v);
extern u8 func_021B6C74(void *,int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_021B7194(int *p, void *arg1, u32 heap);
extern int func_021B7204(int a, int b, void *p, int *q);
extern void func_021B71FC(void *p);
extern void func_021B6C30(int *p, int flag, int index);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern int func_02174660(int,...);
extern void func_021B9818(char *a, char *b, u32 c);
extern void func_02005E30(u32 a);
extern int func_02005E50(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int,int);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern void func_02005DF8(u32 a);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0200BF08(struct Rec1B0 *p, u32 v);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_020266AC(u32,u32,u32);
extern int func_021B7114(void *);
extern void func_021B9C30(u8 *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_020435F4(u32 a);
extern void func_02030EAC(struct Node *n);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_021B9A18(char *p);
extern void func_021B718C(void *a);
extern void func_021B9BA0(void *a);
extern void func_021B9B3C(char *p);
extern void func_021B9BC8(char *p);
extern void func_021B9C1C(char *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020315D4(struct S020315D4 *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern void func_020403F4(unsigned int);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
extern void func_02049238(void *a);
extern void func_020409B4(u32 a);
extern void func_0203FB44(unsigned int, unsigned int, unsigned int);
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern u8 func_0201F548(int i);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern u32 func_020452E8(struct Descriptor *d);
int func_021B8EE8(struct Obj0203159C *a, int *b, u8 *c, u8 *o);
int func_021B9070(int unused,int *state,u8 *c,u8 *o);
int func_021B94CC(void *a, void *b, char *c, char *d);
void func_021B9560(void);
void func_021B95CC(void);
void func_021B95FC(void *a, void *b);
void func_021B9694(unsigned int *p);
void func_021B96A4(char *a, void **b);
void func_021B9734(char *p);
extern const u32 d_021BAAFC[];
extern const u32 d_021BABFC[];
extern char d_021BAB28[];
extern char d_021BAB48[];
extern struct Config d_021BAB68;


int func_021B8EE8(struct Obj0203159C *a, int *b, u8 *c, u8 *o)
{
    int busy;
    u32 t;
    Bool_021B8EE8 f;

    switch (*b) {
    case 0:
        o = func_0203159C(a, 0x314, 0x61);
        func_02082BCC(o, 0, 0x314);
        ((struct Obj01884 *)o)->f2D8 = 0x800;
        ((struct Obj01884 *)o)->f300 = 0xffff;
        ((struct Obj01884 *)o)->f2F8 = 0xffff;
        ((struct Obj01884 *)o)->f2FC = 0xffff;
        func_021B6C54((char *)c);
        ((struct Obj01884 *)o)->f20 = (int)func_02045B38(0, 2, 0xa0, 0x61);
        func_021B9560();
        func_021B95FC(o, ((struct Obj02123 *)c)->f4);
        func_021B96A4((char *)o, ((struct Obj02123 *)c)->f4);
        func_021BA11C((char *)o);
        func_021B9BB8((char *)c, (char *)o);
        func_021B9AE4(o, ((struct Obj02123 *)c)->f4);
        func_021B9B64((char *)c, (char *)o);
        func_021B9BE8((char *)c, (char *)o);
        func_021B9750((char *)c, (char *)o);
        ((struct Obj01884 *)o)->f30C = (int)func_021B7174(((struct Obj02123 *)c)->f4, 4, 0x61);
        (*(u8 **)(c + 8))[1] = 0x30;
        ((struct Obj01884 *)o)->f0 = func_020056A0((void (*)(void))func_021BA1B0, o, 3);
        func_021B9970(c, o, ((struct Obj02123 *)c)->f4);
        func_021B992C((char *)o);
        *b = *b + 1;
        break;
    case 1:
        if (func_021B9A40((char *)o, ((struct Obj02123 *)c)->f4) == 1) {
            func_021BA140(o);
            ((struct Obj01884 *)o)->f2F0 = 1;
            if (func_020355C4() == 0) {
                func_021B9F2C(o, 1, 0);
            } else {
                func_021B9F2C(o, 0xffff, 0);
            }
            *b = *b + 1;
        }
        break;
    case 2:
        busy = 0;
        t = (*(u32 **)(c + 4))[2];
        if (o[0x28c] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj01884 *)o)->f288))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj01884 *)o)->f288);
                o[0x28c] = 0;
            }
        }
        f = o[0x28c] == 0 ? B_TRUE : B_FALSE;
        if (f == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * extent: final halfword at 021B94CA is alignment padding.
 * lever: state9 writes its state10 tail twice, one reached by goto, preserving the cross-jump.
 */
int func_021B9070(int unused,int *state,u8 *c,u8 *o)
{
    u32 initial,handle,mask,save;
    int active,result,off;
    unsigned short flip;
    initial=func_02158344(func_02012138((const struct Ctx *)*(u32 *)CP(0)));
    func_021B6C7C((int *)c,1); func_021B6C7C((int *)c,3);
    func_021B9BD8((char *)o); func_021B9BAC(CP(4),(u32)o);
    handle=*(u32 *)(CP(4)+8);
    if (o[0x28c]!=0 && func_0201C6C4((struct PrintSys *)handle,(void *)((u32)func_02045770((struct Descriptor *)W(0x288))))==0) {
        func_02045334((struct Descriptor *)W(0x288)); o[0x28c]=0;
    }
    if (c[0x2e]==1 && *state==4) return 1;
    switch (*state) {
    case 0: *state=1; break;
    case 1: func_021B9798((char *)o,(char *)CP(4),0x25); ++*state; break;
    case 2:
        if (func_021B98B4(CP(4),o)==1 && (func_02035C60()!=0 || (func_020362DC()&3))) {
            func_021B98C4((char *)o); func_020061E4(0x547);
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
        func_021B9C7C(c,o); func_021BA004((char *)o);
        off=0x2e0;
        if (func_021BA0CC(o,W(off)+W(off+4))==1) {
            func_021BA11C((char *)o); func_021BA140(o); W(off+16)=1;
        }
        func_021BA01C(c,o);
        if (W(0x2f4)==0xffff) { CP(8)[1]=0x30; }
        else {
            CP(8)[1]=*(u32 *)(o+(W(0x2f4)<<2)+0xec);
            CP(8)[2]=*(u32 *)(o+(W(0x2f4)<<2)+0x1b4);
            if (*(u32 *)(o+(W(0x2f4)<<2)+0x1b4)==0) {
                func_021B6B58((void **)(o+8),1); goto selected;
            }
        }
        func_021B6B58((void **)(o+8),0);
selected:
        if (W(0x300)!=0xffff) { func_020061E4(0x54c); *state=5; }
        break;
    case 5:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_021B9798((char *)o,(char *)CP(4),0x20); ++*state;
        } break;
    case 6:
        if (func_021B98B4(CP(4),o)==1) {
            if (W(0x310)!=0) func_02034714((const char *)d_021BABFC,0,(const char *)d_021BABFC);
            W(0x310)=(u32)func_021B7194((int *)CP(4),(void *)W(0x30c),0x61); ++*state;
        } break;
    case 7:
        if (func_021B7204(C(4),4,(void *)W(0x310),&result)==1) {
            func_021B71FC((void *)W(0x310)); W(0x310)=0; func_021B98C4((char *)o);
            if (result==1) *state=8;
            else { W(0x300)=0xffff; func_021B6C30((int *)c,1,1); func_021B6B98(c,(int *)(o+8),1,0xff,3); *state=4; }
        } break;
    case 8:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_0201F184((struct WordSet *)(*(u32 *)(CP(4)+0x10)),0,*(u32 *)(o+(W(0x300)<<2)+0xec));
            func_021B9818((char *)o,(char *)CP(4),0x23); *state=9;
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
            func_021B98C4((char *)o);
            func_0200BF08((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4((const struct Ctx *)(*(u32 *)CP(0))))),*(u32 *)(o+(W(0x300)<<2)+0xec));
            save=func_02012138((const struct Ctx *)*(u32 *)CP(0));
            handle=C(0);
            func_020266AC(save,func_02012B58(func_020120F4((const struct Ctx *)(((struct Obj13181 *)handle)->f0))),((struct Obj13181 *)handle)->f3C);
            W(0x300)=0xffff; func_021B6C30((int *)c,1,1); func_021B6B98(c,(int *)(o+8),1,0xff,3);
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


int func_021B94CC(void *a, void *b, char *c, char *d)
{
    if (func_0201C6B4(((struct Obj20747 *)(*(char * *)&((struct Obj20746 *)c)->f4))->f8) == 0)
        return 0;
    func_020435F4(8);
    func_02030EAC(((struct Obj03177 *)d)->f0);
    if (((struct Obj03177 *)d)->f294 != 0)
        func_0201CE48(((struct Obj03177 *)d)->f294);
    if (((struct Obj03177 *)d)->f290 != 0)
        func_02045808(((struct Obj03177 *)d)->f290);
    func_021B9A18(d);
    if (((struct Obj03177 *)d)->f310 != 0)
        func_021B71FC(((struct Obj03177 *)d)->f310);
    func_021B718C(((struct Obj03177 *)d)->f30C);
    func_021B9BA0(d);
    func_021B9B3C(d);
    func_021B9BC8(d);
    func_021B9C1C(d);
    func_021B9694((unsigned int *)d);
    func_021B9734(d);
    func_021B95CC();
    func_02045C04(((struct Obj03177 *)d)->f20);
    func_020315D4(a);
    return 1;
}


void func_021B9560(void)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021BAB28, 0);
    func_0203FCA0(5, (const struct BgTemplate *)d_021BAB48, 0);
    func_0203FCA0(6, (const struct BgTemplate *)((char *)&d_021BAB68), 0);
    func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
}

void func_021B95CC(void) { func_02040588(4,0); func_02040588(5,0); func_02040588(6,0); func_020403F4(4); func_020403F4(5); func_020403F4(6); }


void func_021B95FC(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_020498F4(((struct Obj09895 *)r5)->f30, 7, 6, 0, 0, 1, 0x61);
    func_02049658(((struct Obj09895 *)r5)->f30, 0xe, 5, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj09895 *)r5)->f30, 9, 5, 0, 0, 1, 0x61);
    h = func_020490F4(0x53, 0x61);
    ((struct Obj09894 *)d)->f4 = (void *)func_0203FA08(5, 0x80, 1);
    func_02049658(h, 0x1c, 5, (u32)(((struct Obj09894 *)d)->f4), 0x80, 0, 0x61);
    func_02027634(h, 5, 0x61, (int)(((struct Obj09894 *)d)->f4), 0xc);
    func_02049238(h);
    func_020409B4(5);
    func_020409B4(6);
}

void func_021B9694(unsigned int *p) { func_0203FB44(5, p[1], 0x80); }


void func_021B96A4(char *a, void **b)
{
    func_0201F554(4, 1, 0, 0x61);
    func_020215EC(*b, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    ((struct Obj04341 *)a)->f280 = (void *)func_020450F0(4, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(((struct Obj04341 *)a)->f280), 0xff);
    ((struct Obj04341 *)a)->f284 = (void *)func_020450F0(4, 0, 0, 0x20, 3, 0xd, 1);
    func_02045374(((struct Obj04341 *)a)->f284);
    func_020409B4(4);
    ((struct Obj04341 *)a)->f288 = ((struct Obj04341 *)a)->f284;
    ((struct Obj04341 *)a)->f28C = 0;
}

void func_021B9734(char *p) { int i; for (i=0;i<2;i++) func_020452E8(*(void **)(p + 0x280 + i*4)); }
