/*
 * file:     field_wfbc_data_local_p03.c
 * unit:     yes
 * function: func_0218606C, func_0218608C, func_02186090, func_0218609C, func_021860B8, func_021860D4, func_021861BC
 * address:  0x0218606C
 * region:   ov020
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
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   func_0216D588  0x0216D588  thumb
 *   func_02161E78 0x02161E78 thumb ov010
 *   func_02008530  0x02008530  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_02186B60  0x02186B60  thumb  ov020
 *   func_021869E0  0x021869E0  thumb  ov020
 *   func_02186B84  0x02186B84  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 *   func_02161E84 0x02161E84 thumb ov010
 */
#include "../../matched/include/Obj03572.h"
#include "../../matched/include/Obj07401.h"

struct Sub0200852CObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u16 func_0216D588(void *p);
extern void func_02161E78(void *a0);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_020056EC(u32 n);
extern int *func_021867C4(int a, int id);
extern char *func_0218682C(char *p);
extern char *func_02186B60(char *p);
extern char *func_021869E0(char *a, int limit, char *h, int *out);
extern void func_02186B84(void *slot, u8 a, int b, u16 c, int d);
extern void func_02186804(void **p);
extern int func_02161E84(char *);
void *func_0218606C(void);
void func_0218608C(void);
int func_02186090(void *p);
void func_0218609C(char *p);
void func_021860B8(char *p);
void func_021860D4(u16 *p, int a1, int id);
int func_021861BC(unsigned short *p);
extern char d_02187EA0[];

void *func_0218606C(void) { return func_02030734(0x8004,0x1000,0,d_02187EA0,0xe3a); }

/*
 * Unlabelled leaf: an empty function (`bx lr` plus two bytes of padding)
 * after func_0218606C.  ov020 func_021841C0 passes its address as the end
 * of the range handed to the ov230 routine func_021883CC, the same way it
 * passes func_0218604C and func_0218606C to func_021882A0 and func_02188318.
 */
void func_0218608C(void)
{
}


/*
 * extent: two zero alignment bytes after the return.
 */
int func_02186090(void *p)
{
    return func_0216D588(p) - 0x80;
}

void func_0218609C(char *p) { int i; p += 8; for (i=0;i<10;i++) func_02161E78(p+i*0x18); }

void func_021860B8(char *p) { int i; p += 0xf8; for (i=0;i<10;i++) func_02161E78(p+i*0x18); }


void func_021860D4(u16 *p, int a1, int id)
{
    int i;
    int j;
    int r;
    char *e;
    int rem;
    int flag;
    int out;
    void *slot;
    int h;
    int v;

    p[0] = 1;
    i = 0;
    p[1] = 0;
    rem = 0x1CE;
    ((struct Obj03572 *)p)->f4 = func_02008530((const struct Sub0200852CObj *)a1);
    h = (int)func_021867C4(0, (u16)((id & 0x7FFF) | 0x8000));
    func_0218682C((char *)h);
    for (i = 0; i < 10; i++) {
        r = func_020056EC(rem);
        slot = func_02186B60((char *)(p + 4));
        e = func_021869E0((char *)p, r, (char *)h, &out);
        if (p[1] == 0) {
            v = ((struct Obj07401 *)e)->f6;
            flag = 1;
        } else {
            v = ((struct Obj07401 *)e)->f4;
            flag = 0;
        }
        func_02186B84(slot, (u8)out, a1, v, flag);
        rem -= ((struct Obj07401 *)e)->f2C;
    }
    for (j = 0; j < 3; j++) {
        r = func_020056EC(rem);
        slot = func_02186B60((char *)p + 0xf8);
        e = func_021869E0((char *)p, r, (char *)h, &out);
        func_02186B84(slot, (u8)out, a1, 0, flag);
        rem -= ((struct Obj07401 *)e)->f2C;
    }
    func_02186804((void **)h);
}

int func_021861BC(unsigned short *p) { char *q; int i; if(p[0]==1 && p[1]>=2) return 0; q=(char *)p; i=0; q+=8; for(;i<10;i++) if(func_02161E84(q+i*0x18)==0) return 0; return 1; }
