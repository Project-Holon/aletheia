/*
 * file:     shinka_demo_view_p08.c
 * unit:     yes
 * function: func_022065C8, func_02206604, func_02206664, func_0220672C, func_0220673C, func_02206750, func_02206768
 * address:  0x022065C8
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02208514 0x02208514 thumb ov195
 *   func_02206A3C 0x02206A3C thumb ov195
 *   func_020307B0 0x020307B0 arm
 *   func_022076A0 0x022076A0 thumb ov195
 *   func_02208410 0x02208410 thumb ov195
 *   func_02208430 0x02208430 thumb ov195
 *   d_02208E8C 0x02208E8C data
 *   d_02148BCC 0x02148BCC data
 *   func_020467EC 0x020467EC arm
 *   func_02046AFC 0x02046AFC arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_0206A9DC 0x0206A9DC arm
 *   func_02082B60 0x02082B60 arm
 *   func_0206AA0C 0x0206AA0C arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0206DB80 0x0206DB80 arm
 *   func_02046858 0x02046858 arm
 *   func_02046B40 0x02046B40 arm
 *   func_02207510 0x02207510 thumb ov195
 *   func_02208570 0x02208570 thumb ov195
 *   func_022067B0 0x022067B0 thumb ov195
 *   func_022086BC 0x022086BC thumb ov195
 */
#include "../../matched/include/Obj02911.h"
#include "../../matched/include/Obj10824.h"
#include "../../matched/include/Obj08348.h"
#include "../../matched/include/Obj24968.h"
#include "../../matched/include/Obj00300.h"
#include "../../matched/include/Obj14534.h"

#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)
#define REG_DIF_AMB      (*(vu32 *)0x040004C0)
#define REG_SPE_EMI      (*(vu32 *)0x040004C4)
struct Fade;
struct Light;
struct Grid;
struct Quad;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct Grid {
    u8 pad00[0x28];
    int state;
} Grid;

typedef struct Work_02206604 {
    u32 f00;
    u32 f04;
    Grid *grid[2];
} Work_02206604;

typedef struct Owner_02206604 {
    u16 heap;
    u8 pad02[0x3e];
    u32 f40;
    u8 pad44[0x14];
    Work_02206604 *work;
} Owner_02206604;

typedef signed int s32;

typedef s32 fx32;

typedef volatile u32 vu32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct MtxFx33 {
    fx32 m[3][3];
} MtxFx33;

typedef struct GlbState {
    u8 pad00[0x3c];
    MtxFx33 baseRot;
    u8 pad60[0x7c - 0x60];
    u32 flag;
} GlbState;

typedef struct Work_02206664 {
    u32 f00;
    void *tex;
    void *grid[2];
    void *quad;
} Work_02206664;

typedef struct Owner_02206664 {
    u16 heap;
    u8 pad02[0x56];
    Work_02206664 *work;
} Owner_02206664;

typedef struct Work_0220672C {
    u32 f00;
} Work_0220672C;

typedef struct Owner_0220672C {
    u16 heap;
    u8 pad02[0x56];
    Work_0220672C *work;
} Owner_0220672C;

typedef signed char s8;

typedef signed short s16;

extern unsigned int func_02048AC4(void *ptr);
extern void func_02208514(void *,int);
extern void func_02206A3C(char *,int);
extern u32 func_020307B0(void *p);
extern void func_022076A0(Owner_02206604 *o);
extern int func_02208410(char *p, u16 heap);
extern void func_02208430(struct Fade *p, int x);
extern void func_020467EC(int p0);
extern void func_02046AFC(u8 *dst);
extern void func_0207ADC4(MtxFx33 *m);
extern void func_0206A9DC(const VecFx32 *trans);
extern void func_02082B60(const MtxFx33 *src, MtxFx33 *dst);
extern void func_0206AA0C(const VecFx32 *scale);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_0206DB80(void);
extern void func_02046858(const u32 *src);
extern void func_02046B40(u8 *a0);
extern void func_02207510(struct Grid *w, u16 heap);
extern void func_02208570(struct Quad *p, u16 heap);
extern void func_022067B0(char *a, int b, int c, int d, int e);
extern void func_022086BC(char *a, int b, int c, int d, int e);
void func_022065C8(char *p);
void func_02206604(Owner_02206604 *o);
void func_02206664(Owner_02206664 *o);
void func_0220672C(Owner_0220672C *o);
int func_0220673C(int *p);
void func_02206750(int *p);
void func_02206768(char *a, u32 x, u32 y, u32 z);
extern const VecFx32 d_02208E8C;
extern GlbState d_02148BCC;

void func_022065C8(char *p){char *q;u8 i;q=*(char * *)&((struct Obj02911 *)p)->f58;func_02048AC4((void *)(((struct Obj10824 *)q)->f4));if(((struct Obj10824 *)q)->f10)func_02208514(((struct Obj10824 *)q)->f10,((struct Obj02911 *)p)->f0);for(i=0;i<2;i++){if(*(char **)(q+i*4+8))func_02206A3C(*(char **)(q+i*4+8),((struct Obj02911 *)p)->f0);}func_020307B0(q);}


void func_02206604(Owner_02206604 *o)
{
    Work_02206604 *w = o->work;
    u16 heap = o->heap;
    u8 i;
    Grid *g;

    switch (w->f00) {
    case 0:
        break;
    case 1:
        func_022076A0(o);
        break;
    case 2:
    case 3:
        break;
    }
    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            if (o->f40 != 0 && func_02208410((char *)g, heap))
                g->state = 4;
            func_02208430((struct Fade *)g, heap);
        }
    }
}


void func_02206664(Owner_02206664 *o)
{
    u8 save0[0x20];
    u8 save1[0x24];
    Work_02206664 *w = o->work;
    u8 i;

    func_020467EC((int)save0);
    func_02046AFC(save1);
    {
        VecFx32 scale = d_02208E8C;
        MtxFx33 rot;
        VecFx32 trans = {0, 0, 0};

        func_0207ADC4(&rot);
        func_0206A9DC(&trans);
        func_02082B60(&rot, &d_02148BCC.baseRot);
        d_02148BCC.flag &= ~0xa4;
        func_0206AA0C(&scale);
    }
    func_02048AD0(w->tex);
    func_020479D8();
    func_0206DB80();
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    REG_DIF_AMB = 0x7fff7fff;
    REG_SPE_EMI = 0x7fff7fff;
    for (i = 0; i < 2; i++) {
        if (w->grid[i] != 0)
            func_02207510(w->grid[i], o->heap);
    }
    if (w->quad != 0)
        func_02208570(w->quad, o->heap);
    func_02046858((const u32 *)save0);
    func_02046B40(save1);
    func_020479D8();
    func_0206DB80();
}


/*
 * Unlabelled Thumb leaf (saves no lr), seeded by address.
 */
void func_0220672C(Owner_0220672C *o)
{
    Work_0220672C *w = o->work;

    if (w->f00 == 0)
        w->f00 = 1;
}


int func_0220673C(int *p)
{
    int v = **(int * *)&((struct Obj08348 *)p)->f58;

    return v != 0 && v != 4;
}


void func_02206750(int *p)
{
    char *q = *(char * *)&((struct Obj08348 *)p)->f58;
    int *r = *(int * *)&((struct Obj24968 *)q)->f8;
    int v = r[0x28 / 4];

    if (v == 1) return;
    if (v == 2) return;
    if (v == 3) return;
    r[0x28 / 4] = 1;
}


void func_02206768(char *a, u32 x, u32 y, u32 z)
{
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(void **)(t + i * 4 + 8) != 0)
            func_022067B0(*(void **)(t + i * 4 + 8), ((struct Obj00300 *)a)->f0, x, y, z);
    }
    if (((struct Obj14534 *)t)->f10 != 0)
        func_022086BC(((struct Obj14534 *)t)->f10, ((struct Obj00300 *)a)->f0, x, y, z);
}
