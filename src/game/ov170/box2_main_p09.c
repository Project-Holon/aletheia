/*
 * file:     box2_main_p09.c
 * unit:     yes
 * function: func_021DE728, func_021DE7B4, func_021DE7C8, func_021DE898, func_021DE8B4, func_021DE980
 * address:  0x021DE728
 * region:   ov170
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
 *   d_021F1400 0x021F1400 data a1
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_02017E88 0x02017E88 thumb
 *   func_021DE720 0x021DE720 thumb ov170
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EC548 0x021EC548 thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23849.h"
#include "../../matched/include/Obj23850.h"
#include "../../matched/include/Obj18453.h"
#include "../../matched/include/Obj23851.h"
#include "../../matched/include/Obj09222.h"
#include "../../matched/include/Obj18454.h"
#include "../../matched/include/Obj10648.h"
#include "../../matched/include/Obj10649.h"
#include "../../matched/include/Obj23852.h"

#define FLAGS(o) (*(unsigned *)((char *)(o) + 0x18))
#define WORK(p) (*(char **)((p) + 0x2C))
struct Sub02007AC8Entry;
struct PerapVoice;
typedef struct {void *p;unsigned short f4;unsigned char flags;unsigned char pad[5];} State_021DE728;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {void *p;unsigned short index;unsigned char flags;unsigned char pad[5];} State_021DE7C8;

typedef struct {
    unsigned short idx, slot;
    int mode, x, y, vx, vy;
    unsigned left:1;
    unsigned up:1;
} Mover_021DE8B4;

typedef struct {
    unsigned short idx;
    unsigned short slot;
    int mode;
    int x;
    int y;
    int vx;
    int vy;
    unsigned int left : 1;
    unsigned int up : 1;
} Mover_021DE980;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern unsigned func_02017E88(void *,unsigned,unsigned);
extern int func_021DE720(unsigned short);
extern u32 func_020307B0(void *p);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
extern void func_02007C34(struct PerapVoice *p, void *a);
extern void func_021EC0B0(char *, int, short *, short *, unsigned short);
extern void func_021EC548(unsigned, short *, short *, int);
void func_021DE728(unsigned char *p);
void func_021DE7B4(char *p);
int func_021DE7C8(unsigned char *p);
void func_021DE898(int *q);
void func_021DE8B4(unsigned char *p, int slot, unsigned idx, int mode, int flag);
void func_021DE980(unsigned char *p, int mode);
extern const char d_021F1400[];

void func_021DE728(unsigned char *p)
{
    State_021DE728 *s;
    void *m;
    unsigned i;
    int r;
    *(State_021DE728 * *)&((struct Obj23849 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190=func_02030734(0x804c,12,0,d_021F1400,0xa70);
    s=*(State_021DE728 * *)&((struct Obj23850 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190;
    s->p=*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C+*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+p[0x16]+0x3dd2)*4+0x9e74);
    s->f4=0;
    s->flags=0;
    m=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
    for(i=0;i<4;i++){
        r=func_021DE720((unsigned short)func_02017E88(m,i+0x36,0));
        if(r!=-1){s->flags|=(unsigned char)(1<<r);return;}
    }
}


/*
 * Tail call func_020307B0 with the pooled-offset word.
 */
void func_021DE7B4(char *p)
{
    func_020307B0(((struct Obj18453 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190);
}

/*
 * lever: Spell the byte-mask update as plain assignment; compound assignment inserts an extra truncation pair.
 */
int func_021DE7C8(unsigned char *p)
{
    State_021DE7C8 *s=*(State_021DE7C8 * *)&((struct Obj23851 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190;
    unsigned short n=s->index;
    unsigned j,i;
    void *m;
    int box,r,slot;
    if(n==726)return 0;
    for(j=0;j<15;j++){
        if(n<720){
            box=n/30;
            slot=n%30;
            if(box==p[0x14]&&slot==p[0x16]) m=0;
            else m=(void *)func_021DD2D0((void ***)p,box,slot);
        }else{
            slot=n-720;
            if(slot==p[0x16]-30)m=0;
            else m=(void *)func_021DD2D0((void ***)p,255,slot);
        }
        if(m&&func_02017E88(m,0xa9,0)!=0){
            for(i=0;i<4;i++){
                r=func_021DE720((unsigned short)func_02017E88(m,i+0x36,0));
                if(r!=-1)s->flags=s->flags & (255^(1<<r));
            }
        }
        ++s->index;
        n=s->index;
        if(n==726)return 0;
    }
    return 1;
}


/*
 *   func_02012F98 (0x02012F98) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_021DE898(int *q)
{
    int *r = *(int * *)&((struct Obj18454 *)q)->f0;

    if ((((struct Obj09222 *)r)->f24 - 4) > 1)
        func_02007C34((struct PerapVoice *)func_02012F98((void *)(((struct Obj09222 *)r)->f0)), (void *)(((struct Obj09222 *)r)->f8));
}

void func_021DE8B4(unsigned char *p, int slot, unsigned idx, int mode, int flag)
{
    Mover_021DE8B4 *o = *(Mover_021DE8B4 * *)&((struct Obj23852 *)(*(char * *)&((struct Obj10648 *)p)->f2C))->f60;
    short pos[2];
    short to[2];
    int d;
    func_021EC0B0(*(char * *)&((struct Obj10648 *)p)->f2C,10,&pos[1],&pos[0],0);
    func_021EC548(idx,&to[1],&to[0],mode);
    if(flag==1){to[1]+=8;to[0]+=8;}else{to[0]+=4;}
    o->idx=idx;
    o->slot=slot;
    ((struct Obj10649 *)o)->f18&=3;
    o->mode=mode;
    {
        int tx=to[1];
        int px=pos[1];
        int ty;
        int py;
        if(px>tx){o->left=1;d=px-tx;}else{o->left=0;d=tx-px;}
        o->vx=(d<<8)/8;
        ty=to[0];
        py=pos[0];
        if(py>ty){((struct Obj10649 *)o)->f18|=2;d=py-ty;}
        else{((struct Obj10649 *)o)->f18&=~2;d=ty-py;}
        o->vy=(d<<8)/8;
        o->x=px<<8;
        o->y=py<<8;
    }
}


void func_021DE980(unsigned char *p, int mode)
{
    Mover_021DE980 *o = *(Mover_021DE980 **)(WORK(p) + 0x60);
    short pos[2];
    short to[2];
    int d;
    func_021EC0B0(WORK(p), 10, &pos[1], &pos[0], 0);
    if (p[0x14] > p[0x17])
        func_021EC0B0(WORK(p), 0, &to[1], &to[0], 0);
    else
        func_021EC0B0(WORK(p), 1, &to[1], &to[0], 0);
    o->idx = 0xFF;
    o->slot = 0xFF;
    FLAGS(o) &= 3;
    o->mode = mode;
    {
        int tx = to[1];
        int px = pos[1];
        int ty;
        int py;
        if (px > tx) {
            o->left = 1;
            d = px - tx;
        } else {
            o->left = 0;
            d = tx - px;
        }
        o->vx = (d << 8) / 8;
        ty = to[0];
        py = pos[0];
        if (py > ty) {
            FLAGS(o) |= 2;
            d = py - ty;
        } else {
            FLAGS(o) &= ~2;
            d = ty - py;
        }
        o->vy = (d << 8) / 8;
        o->x = px << 8;
        o->y = py << 8;
    }
}
