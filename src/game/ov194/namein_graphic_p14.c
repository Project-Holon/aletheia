/*
 * file:     namein_graphic_p14.c
 * unit:     yes
 * function: func_021F3B18, func_021F3BD4, func_021F3C40, func_021F3CD0, func_021F3D54
 * address:  0x021F3B18
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_020061E4 0x020061E4 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021F1A1C 0x021F1A1C thumb ov194
 *   func_02035D20 0x02035D20 arm
 *   func_021F265C 0x021F265C thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_021F3364 0x021F3364 thumb ov194
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj00117.h"
#include "../../matched/include/Obj01774.h"
#include "../../matched/include/Obj14504.h"

struct Rect;
struct U16Vec;
struct Cfg;
struct Descriptor;
struct CharBuf;
typedef unsigned int u32;

typedef struct {int x,y;} Pair;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_020362DC(void);
extern int func_021F2828(char *,int,int *);
extern u8 func_020355C4(void);
extern int func_021F2818(char *,int,int);
extern void func_020061E4(u32 a);
extern void func_020355D8(u8 v);
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F265C(char *,int *,int *);
extern unsigned func_021F2614(char *,int *,unsigned short *);
extern int func_021F3364(char *,int);
extern void func_02082BCC(unsigned char *,unsigned,unsigned);
extern struct U16Vec *func_020457B0(unsigned int capacity, unsigned int heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
int func_021F3B18(char *p,int *out);
int func_021F3BD4(char *p,int *out);
void func_021F3C40(char *p,int *input);
void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e);
void func_021F3D54(u8 *p);

int func_021F3B18(char *p,int *out) {
    int changed=0;
    int rect[4];
    if (((struct Obj00117 *)p)->f118==0) {
        if (func_020362DC()&1) {
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1; out[1]=1;
        }
        if (func_020362DC()&4) {
            out[0]=((struct Obj00117 *)p)->f100+3;
            if (out[0]>5) out[0]=2;
            func_021F2828(p,out[0],(int *)(p+0xd8));
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1;
        }
        if (changed && func_020355C4()==1) {
            if (func_021F2818(p,(int)(p+0xd8),(int)rect)) {
                func_020061E4(1352); func_020355D8(0);
                func_021F1A1C(p+0x24,1,(const struct Rect *)rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                return 0;
            }
        }
    }
    return changed;
}

/*
 * note: unsigned result minus two tests the contiguous range; point precedes x/y declarations.
 */
int func_021F3BD4(char *p,int *out) {
    int point[2],u;
    unsigned x,y;
    if (((struct Obj00117 *)p)->f118==0) {
        if (func_02035D20(&x,&y)) {
            point[0]=x; point[1]=y;
            if (func_021F265C(p,point,(int *)(p+0xd8))) {
                if (func_021F2614(p,(int *)(p+0xd8),0)-2<=3) {
                    u=((struct Obj00117 *)p)->fD8;
                    out[3]=((struct Obj00117 *)p)->fDC;
                    out[1]=1; out[2]=u;
                    func_020355D8(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}

void func_021F3C40(char *p,int *input) {
    unsigned code;
    int rect[4];
    if (input[1]) code=func_021F2614(p,(int *)(p+0xd8),(unsigned short *)(p+0xfc));
    else code=input[0];
    switch (code) {
    case 0: case 1: break;
    case 2: case 3: case 4: case 5:
        if (func_021F3364(p,code-2)) {
            func_020061E4(1611);
            ((struct Obj00117 *)p)->fE4=2; ((struct Obj00117 *)p)->fE8=6;
        }
        break;
    }
    if (func_021F2818(p,(int)(input+2),(int)rect))
        func_021F1A1C(p+0x24,2,(const struct Rect *)rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}

void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e) {
    int window;
    func_02082BCC(p,0,0x24);
    ((struct Obj01774 *)p)->f20=15;
    ((struct Obj01774 *)p)->f4=a; ((struct Obj01774 *)p)->f18=d; ((struct Obj01774 *)p)->f0=b; ((struct Obj01774 *)p)->f10=c;
    ((struct Obj01774 *)p)->f1C=(int)func_020457B0(255,e);
    ((struct Obj01774 *)p)->f14=func_020450F0(4,1,19,30,4,15,1);
    func_0201F73C((void *)(((struct Obj01774 *)p)->f14),2,1,14);
    ((struct Obj01774 *)p)->f8=((struct Obj01774 *)p)->f14;
    ((struct Obj01774 *)p)->fC=0;
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj01774 *)p)->f14),((struct Obj01774 *)p)->f20);
    window=((struct Obj01774 *)p)->f14;
    func_02045334((struct Descriptor *)window); func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F3D54(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj14504 *)p)->f14));
    func_02045808((struct U16Vec *)(((struct Obj14504 *)p)->f1C));
    func_02082BCC(p, 0, 0x24);
}
