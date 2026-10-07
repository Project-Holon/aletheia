/*
 * file:     townmap_p07.c
 * unit:     yes
 * function: func_021BA6C8, func_021BA710, func_021BA774, func_021BA7A4
 * address:  0x021BA6C8
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
 *   func_021BA3BC  0x021BA3BC  thumb  ov072
 *   func_021BAA90  0x021BAA90  thumb  ov072
 *   func_021BACB0  0x021BACB0  thumb  ov072
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   func_021BAE44 0x021BAE44 thumb ov072
 *   func_021BADF4 0x021BADF4 thumb ov072
 */
#include "../../matched/include/Obj03179.h"
#include "../../matched/include/Obj13199.h"

typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
} W;

typedef unsigned short u16;

extern void func_021BA3BC(char *p, int *q);
extern int func_021BAA90(char *a, int *b, int *c);
extern int func_021BACB0(char *a, int *b, int *c, u32 *d);
extern unsigned short func_021BBB3C(char *p, int a, int b);
extern void func_021BAE44(void *p);
extern void func_021BADF4(void *p);
char *func_021BA6C8(W *p, int a);
char *func_021BA710(W *p, int a);
int func_021BA774(char *p, int i);
void func_021BA7A4(char *p, void *selected);


char *func_021BA6C8(W *p, int a)
{
    int pt[2];
    u32 i;

    func_021BA3BC((char *)a, pt);
    for (i = 0; i < p->fc; i++) {
        if (func_021BAA90(p->f8 + i * 0x44, pt, &p->f10) != 0) {
            return p->f8 + i * 0x44;
        }
    }
    return 0;
}


char *func_021BA710(W *p, int a)
{
    int pt[2];
    u32 i;
    u32 best;
    u32 d;
    int idx;

    func_021BA3BC((char *)a, pt);
    idx = -1;
    best = -1;
    for (i = 0; i < p->fc; i++) {
        if (func_021BACB0(p->f8 + i * 0x44, pt, &p->f10, &d) != 0 && best > d) {
            idx = i;
            best = d;
        }
    }
    if (idx == -1) {
        return 0;
    }
    return p->f8 + idx * 0x44;
}

/*
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
int func_021BA774(char *p, int i) {
 if (i>=2 && i<=10) return *(int *)((unsigned int)p+(i-2)*4+12);
 if (i==12) return ((struct Obj03179 *)p)->f3C;
 return func_021BBB3C(*(char * *)&((struct Obj03179 *)p)->f4,(u16)(((struct Obj03179 *)p)->f8),i);
}

void func_021BA7A4(char *p, void *selected) { u32 i; void *q; for(i=0;i<((struct Obj13199 *)p)->fC;i++) { q=(void *)(((struct Obj13199 *)p)->f8+i*0x44); if(q==selected) func_021BADF4(q); else func_021BAE44(q); } }
