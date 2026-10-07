/*
 * file:     townmap_p08.c
 * unit:     yes
 * function: func_021BA7D4, func_021BA7F8, func_021BA834, func_021BA86C, func_021BAA14, func_021BAA30
 * address:  0x021BA7D4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BAE44 0x021BAE44 thumb ov072
 *   func_02166C7C 0x02166C7C thumb ov010
 *   func_021BA774 0x021BA774 thumb ov072
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_02166CD0  0x02166CD0  thumb  ov010
 *   func_0204B294  0x0204B294  arm
 *   func_0204B570  0x0204B570  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021BADBC  0x021BADBC  thumb  ov072
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../../matched/include/Obj13200.h"
#include "../../matched/include/Obj09909.h"
#include "../../matched/include/Obj03179.h"

struct Obj;
struct Actor;
struct Node;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Pos;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern void func_021BAE44(void *p);
extern u32 func_02166C7C(void *a, u32 b);
extern int func_021BA774(char *p, int i);
extern unsigned short func_021BBB3C(char *p, int a, int b);
extern void func_02082BCC(void *p, int v, int n);
extern int func_02166CD0(void *a, u32 msg);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B84C(int obj, int v);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B3B4(struct Obj *p);
extern void func_021BADBC(char *p, int v);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
void func_021BA7D4(char *p);
void *func_021BA7F8(char *p, u32 b, int y);
int func_021BA834(char *p);
void func_021BA86C(W *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5);
void func_021BAA14(unsigned int *p);
void func_021BAA30(W *p, int a);

void func_021BA7D4(char *p) { u32 i; for(i=0;i<((struct Obj13200 *)p)->fC;i++) func_021BAE44((void *)(((struct Obj13200 *)p)->f8+i*0x44)); }

void *func_021BA7F8(char *p, u32 b, int y) { u32 i; u32 v; void *q; v=func_02166C7C(((struct Obj09909 *)p)->f0,b); for(i=0;i<((struct Obj09909 *)p)->fC;i++) { q=(void *)(((struct Obj09909 *)p)->f8+i*0x44); if(v==func_021BA774(q,0)) return q; } return 0; }

/*
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
int func_021BA834(char *p) { int v; v=func_021BBB3C(*(char * *)&((struct Obj03179 *)p)->f4,(u16)(((struct Obj03179 *)p)->f8),15); if((v!=65535 && ((struct Obj03179 *)p)->f38!=0 && ((struct Obj03179 *)p)->f40==0) || v==65535) return 1; return 0; }


void func_021BA86C(W *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5)
{
    Pos pos;
    u32 r;
    int i;

    func_02082BCC(p, 0, 0x44);
    p->f34 = 0x1000;
    p->f4 = a;
    p->f8[0] = b;
    r = func_021BBB3C((char *)a, (u16)b, 15);
    if (r != 0xFFFF)
        p->f38 = func_02166CD0(s3, r);
    else
        p->f38 = 0;
    if (s5)
        p->f38 = 1;
    for (i = 0; i < 9; i++)
        p->f8[i + 1] = func_021BBB3C((char *)p->f4, (u16)p->f8[0], i + 2);
    if (s5)
        p->f3c = 1;
    else
        p->f3c = p->f38 && func_021BBB3C((char *)p->f4, (u16)p->f8[0], 12);
    r = func_021BBB3C((char *)p->f4, (u16)p->f8[0], 16);
    if (r != 0xFFFF)
        p->f40 = func_02166CD0(s3, r) == 0;
    else
        p->f40 = 0;
    if (s5)
        p->f40 = 0;
    switch (func_021BA774((char *)p, 11)) {
    case 0:
        p->f31 = 2;
        p->f30 = 1;
        break;
    case 2:
        p->f31 = 3;
        p->f30 = 0xff;
        break;
    case 1:
        p->f31 = 0xff;
        p->f30 = 0xff;
        break;
    case 3:
        p->f31 = 3;
        p->f30 = 0xd;
        break;
    case 4:
        p->f31 = 0xf;
        p->f30 = 0xe;
        break;
    case 5:
        p->f31 = 0x12;
        if (p->f38)
            p->f30 = 0x11;
        else
            p->f30 = 0x10;
        break;
    }
    if (func_021BA774((char *)p, 11) != 1) {
        func_02082BCC(&pos, 0, 8);
        pos.x = func_021BA774((char *)p, 2);
        pos.y = func_021BA774((char *)p, 3);
        p->obj = (int)func_0204B294((void *)c, s0, s2, s1, &pos, 0, s4);
        func_0204B570((struct Actor *)p->obj, 2);
        func_0204B84C(p->obj, 2);
        func_0204B800((struct Node *)p->obj, 4);
    }
    func_021BAE44(p);
}

void func_021BAA14(unsigned int *p) { if (*p) func_0204B3B4((struct Obj *)(*p)); func_02082BCC(p,0,0x44); }


void func_021BAA30(W *p, int a)
{
    if (p->obj == 0 || p->f32 == 0xff) {
        return;
    }
    if (p->f40 != 0) {
        func_0204B3DC((struct Obj *)p->obj, 0);
        return;
    }
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        func_021BADBC((char *)p, p->f30);
        func_0204B3DC((struct Obj *)p->obj, 1);
    } else {
        func_0204B3DC((struct Obj *)p->obj, a);
    }
}
