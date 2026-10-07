/*
 * file:     guru2_main_p18.c
 * unit:     yes
 * function: func_021E0D0C, func_021E0D50, func_021E0DC0, func_021E0DE8
 * address:  0x021E0D0C
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E0450 0x021E0450 thumb ov137
 *   func_021E0F64 0x021E0F64 thumb ov137
 *   func_021E1090 0x021E1090 thumb ov137
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 */
#include "../../matched/include/Obj14243.h"

struct Ctx;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021E0450(u8 *p, void *text, int index, int a);
extern void func_021E0F64(char *p, int key);
extern void func_021E1090(char *p, int key);
extern void func_02082BCC(void *,int,unsigned);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
int func_021E0D0C(int *p);
void func_021E0D50(char *p,int *q);
void func_021E0DC0(void *unused,char *p);
void func_021E0DE8(char *p);

/*
 * extent: two-byte alignment padding at 0x021E0D4E.
 */
int func_021E0D0C(int *p)
{
    int *q = (int *)p[4];
    char *r;
    if (p[3] > 0x1000) {
        p[3] -= 0x1000;
        if (p[3] < 0x1000) p[3] = 0x1000;
    }
    q[21] -= p[3];
    if (q[21] <= 0) {
        q[21] = 0;
        r = (char *)p[5];
        func_021E0450((u8 *)r, (void *)(*(int *)(r + 0xa4 + q[3]*4)), q[5], q[3]);
        return 2;
    }
    return 0;
}

void func_021E0D50(char *p,int *q)
{
    int *r=(int *)q[7];
    switch(q[1]) {
    case 0:
        func_021E0F64(p,(int)r);
        q[4]=0x4000;
        q[5]=-1092;
        q[1]++;
    case 1:
        r[23]+=q[4];
        q[4]+=q[5];
        q[2]++;
        if(q[2]>=15) {
            q[2]=0;
            q[4]=0;
            if(q[3]==0) { q[3]=1; return; }
            r[23]=0;
            func_021E1090(p,(int)r);
            func_02082BCC(q,0,32);
        }
        break;
    }
}

void func_021E0DC0(void *unused,char *p) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) if(*q!=0) func_021E0D50(p,q); }

void func_021E0DE8(char *p) { func_02082BCC(p+2808,0,160); *(struct Node * *)&((struct Obj14243 *)p)->fD7C=func_02030DA8(*(struct Ctx * *)&((struct Obj14243 *)p)->fD98,(u32)func_021E0DC0,(u32)p,256); }
