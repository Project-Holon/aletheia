/*
 * file:     unit_021D85C0_p03.c
 * unit:     yes
 * function: func_021D93D4, func_021D9490, func_021D9564
 * address:  0x021D93D4
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_0204B878 0x0204B878 arm
 *   d_021DA798 0x021DA798 data a2
 *   func_021D958C 0x021D958C thumb ov129
 *   func_02051B84 0x02051B84 arm
 *   d_021DA72C 0x021DA72C data a4 ov129
 */
#include "../../matched/include/Obj00912.h"
#include "../../matched/include/Obj14055.h"
#include "../../matched/include/Obj14056.h"

struct Obj;
typedef unsigned short u16;

typedef struct  {
    int state, value, flag, handle;
    char tail[12];
}
Record;

typedef unsigned char u8;

typedef short s16;

typedef struct { s16 a,b,c,d; } Rect;

typedef struct { Rect rows[12]; } Rects;

typedef unsigned int   u32;

typedef struct { u8 a,b; } Entry;

extern int func_021DA158(int x, int flag);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D958C(u32 n, int touch, char *p);
extern void *func_02051B84(u8 *,int,int,int);
void func_021D93D4(const Record *p);
void func_021D9490(char *p);
void func_021D9564(u8 *p,int n);
extern const Rects d_021DA798;
extern Entry d_021DA72C[];

static inline unsigned clear_record(Record *q)  {
    q->state=0;
    return func_021DA158(0,q->flag);
}

void func_021D93D4(const Record *p)  {
    int i, v, next;
    ((struct Obj00912 *)p)->f1DC=1;
    ((struct Obj00912 *)p)->f1F4=0;
    if(((struct Obj00912 *)p)->f240==0)  {
        i=((struct Obj00912 *)p)->f23C-1;
        ((struct Obj00912 *)p)->f188=i;
        next=p[i].value;
        ((struct Obj00912 *)p)->f31C=1;
        ((struct Obj00912 *)p)->f320=next;
        ((struct Obj00912 *)p)->f324=1;
        return;
    }
    i=((struct Obj00912 *)p)->f188;
    func_0204B878((struct Obj *)p[i].handle,clear_record(&((Record *)p)[i]));
    v=p[i].value;
    if(i>0)  {
        func_0204B878((struct Obj *)p[i-1].handle,func_021DA158(p[i-1].state,p[i-1].flag));
        next=p[i-1].value;
        if(v!=next)  {
            ((struct Obj00912 *)p)->f31C=1;
            ((struct Obj00912 *)p)->f320=next;
            ((struct Obj00912 *)p)->f324=1;
            return;
        }
        ((struct Obj00912 *)p)->f31C=2;
        ((struct Obj00912 *)p)->f320=i-1;
    }
}

void func_021D9490(char *p)
{
    int i;
    Rects t;
    for(i=0;i<12;i++) *(void **)(p+i*28+16)=p+0x298+i*4;
    t=d_021DA798;
    for(;i<24;i++) {
        *(u8 *)(p+i*4+0x298)=t.rows[i-12].b-t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29a)=t.rows[i-12].a-t.rows[i-12].c;
        *(u8 *)(p+i*4+0x299)=t.rows[i-12].b+t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29b)=t.rows[i-12].a+t.rows[i-12].c;
    }
    ((struct Obj14055 *)p)->f2F8=255;
    ((struct Obj14055 *)p)->f294=func_02051B84((u8 *)(p+0x298),(int)func_021D958C,(int)p,50);
}

/*
 * lever: The two-byte table record has byte fields a and b; both pool words reference that record.
 */
void func_021D9564(u8 *p,int n) { if(n>=12 && n<24) { ((struct Obj14056 *)p)->f1B8=d_021DA72C[n-12].a; ((struct Obj14056 *)p)->f1BA=d_021DA72C[n-12].b; } }
