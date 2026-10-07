/*
 * file:     unit_021BF050_p09.c
 * unit:     yes
 * function: func_021C0698, func_021C0750
 * address:  0x021C0698
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020200CC 0x020200CC thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9A60 0x021B9A60 thumb ov099
 *   func_021B9A70 0x021B9A70 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BDD60 0x021BDD60 thumb ov099
 *   func_021C08F8 0x021C08F8 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   d_021C3804 0x021C3804 data a4
 *   d_021C3818 0x021C3818 data a4
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj06358.h"

struct Obj;
struct W;
struct Work;
struct Ent;
struct S;
struct Entry;
typedef signed int     s32;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef enum { K274=0x274 } Off;

typedef unsigned char u8;

typedef struct { int v[5]; } Messages;

extern void func_021B9B64(char *);
extern int func_021BA928(char *);
extern s32 func_020200CC(struct Obj *o);
extern void func_020061E4(u32 a);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021BA8EC(char *);
extern int func_021C23C8(void *a, void *b);
extern void func_021C23D8(char *,int);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern struct Entry *func_020399A8(void);
extern void func_0203D1E8(u32, void *);
extern u8 func_021B97F4(struct W *);
extern void *func_021BE2A8(char *, int);
extern unsigned char func_021B9A60(char *p);
extern void func_021B9A70(void *, struct Ent *, int);
extern u32 func_021BDD48(int, struct S *);
extern u32 func_021BDD54(int, struct S *);
extern void func_021BA874(struct Work *, int);
extern int func_021BDD60(int);
extern int func_021C08F8(char *);
extern void func_021BAAB8(char *, int, int);
int func_021C0698(char *p,int ret);
int func_021C0750(char *p, int ret);
extern Messages d_021C3804, d_021C3818;

int func_021C0698(char *p,int ret) {
    int r;
    Off o=K274;
    func_021B9B64(p+o);
    if(!func_021BA928(p))return ret;
    r=func_020200CC((struct Obj *)(*(int *)&((struct Obj00008 *)p)->fBC));
    switch(r) {
    case -1: return ret;
    case -2:
        func_020061E4(1356);
        *(int *)(p+(o-0xa8))=28;
        break;
    default:
        func_020061E4(1356);
        func_021C18C8(p,2,r);
        *(int *)(p+(o-0xa8))=11;
        func_021BA8EC(p);
        break;
    }
    if(((struct Obj00008 *)p)->f1CC==11){func_021C23C8(p,(void *)(-1));func_021C23D8(p,1);}
    ((struct Obj00008 *)p)->f1A4=(void *)func_021BA8BC(((struct Obj00008 *)p)->f1A4);
    func_0202020C((struct Obj *)(*(int *)&((struct Obj00008 *)p)->fBC),0,(u16 *)(p+0x234+2* ((struct Obj00008 *)p)->f240));
    func_0201F868((void *)(*(int *)&((struct Obj00008 *)p)->fB8));
    return ret;
}

/*
 * lever: evaluating the third input before the call keeps 274 out of a callee-saved register.
 * note (2026-10-05, wD9r lane82): the enum-typed inline address helpers (stand-ins) are removed.
 *   The real form is a pointer local `st = p + 0x24c;` set as the first statement (before
 *   selector = 0) and passed to func_021BDD48/func_021BDD54; the two 0x274 uses are plain p + 0x274.
 *   Each use rebuilds `movs #0x93; lsls #2`, as in the image. EXACT in c99 and c. Writing the 0x274
 *   uses as st + 0x28 gives DIFF (252 of 264 bytes), with st first or second.
 * prototype-evidence: B9A60 tail-forwards to ov127 C4A8C, returning its byte
 *   consumed as B9A70's third argument. BDD48/54 return bytes through their
 *   full getter bodies; caller explicitly narrows to u16 before comparisons.
 * bounds: selector starts zero and is set only to 1,2,3,4; both tables have five words.
 */
int func_021C0750(char *p, int ret)
{
    Messages a, b;
    int selector, n, message, graphic;
    void *q;
    u16 kind, other;
    char *st;
    st = p + 0x24c;
    selector = 0;
    func_0203D1E8((u32)func_020399A8(), 0);
    n = func_021B97F4((struct W *)(p + 0x274));
    q = func_021BE2A8(p, n);
    graphic = func_021B9A60(func_021BE2A8(p, 0));
    func_021B9A70(p + 0x274, q, graphic);
    kind = (u16)func_021BDD48((int)p, (struct S *)st);
    other = (u16)func_021BDD54((int)p, (struct S *)st);
    func_021BA874((struct Work *)p, n - 1);
    if (other == 6) selector = 1;
    else if (other == 5) selector = 2;
    else if (other == 4) selector = 3;
    else if (func_021BDD60(other)) selector = 4;
    switch (kind) {
    case 0:
        message = 0x59;
        break;
    case 1:
        ((struct Obj06358 *)p)->f1CC = 11;
        func_021C08F8(p);
        return ret;
    case 2:
        a = d_021C3804;
        message = a.v[selector];
        break;
    case 4:
        b = d_021C3818;
        message = b.v[selector];
        break;
    case 5:
        message = 0x59;
        break;
    case 3:
    default:
        message = 0x59;
        break;
    }
    func_021BAAB8(p, message, 0);
    ((struct Obj06358 *)p)->f1CC = 0x23;
    return ret;
}
