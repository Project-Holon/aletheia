/*
 * file:     btlv_effvm_p02.c
 * unit:     yes
 * function: func_021F6E2C, func_021F6E3C, func_021F6EC0, func_021F6ED4
 * address:  0x021F6E2C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_021F73A4  0x021F73A4  thumb  ov094
 *   func_021F7208  0x021F7208  thumb  ov094
 *   d_0220AC60     0x0220AC60  data   ov094  a1
 *   d_02209CF4     0x02209CF4  data   ov094
 *   d_02209D00     0x02209D00  data   ov094
 *   d_02209CE8     0x02209CE8  data   ov094
 *   func_02048AC4 0x02048AC4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F723C  0x021F723C  thumb  ov094
 */
struct Light;
typedef unsigned int u32;

typedef struct { char pad[0x68]; u32 f : 1; u32 rest : 31; } Obj_021F6E2C;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int x, y, z;
} VecFx32;

typedef struct {
    int f0;
    int h4;
    char pad08[0x10];
    VecFx32 v18;        /* 0x18 */
    VecFx32 v24;        /* 0x24 */
    char pad30[0xb4 - 0x30];
    u16 hb4;            /* 0xb4 */
} Obj_021F6E3C;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_021F73A4(int *p);
extern void func_021F7208(VecFx32 *a, VecFx32 *b);
extern unsigned int func_02048AC4(void *ptr);
extern u32 func_020307B0(void *p);
void func_021F723C(int *p);
void func_021F6E2C(Obj_021F6E2C *o, u32 v);
Obj_021F6E3C *func_021F6E3C(int a, u16 b);
void func_021F6EC0(void **p);
void func_021F6ED4(int *p);
extern const char d_0220AC60[];
extern char d_02209CF4[];
extern char d_02209D00[];
extern char d_02209CE8[];


/*
 * Unlabelled leaf, filed as the blocker of ov094 func_021F839C (lane S22).
 */
void func_021F6E2C(Obj_021F6E2C *o, u32 v)
{
    o->f = v;
}


Obj_021F6E3C *func_021F6E3C(int a, u16 b)
{
    Obj_021F6E3C *o = sub_02030734(b, 0xb8, 1, d_0220AC60, 0x56);

    o->hb4 = b;
    o->f0 = a;
    o->h4 = func_02048A24(0, 0x399, 0xf97, 0x159a, 0, 0x1000, 0x200000, 0,
                          d_02209CF4, d_02209D00, d_02209CE8, b);
    func_021F73A4((int *)o);
    func_02048AD0((struct Light *)o->h4);
    func_021F7208(&o->v18, &o->v24);
    return o;
}


/*
 * Releases the handle at word 1, then frees the object.
 */
void func_021F6EC0(void **p)
{
    func_02048AC4(p[1]);
    func_020307B0(p);
}


void func_021F6ED4(int *p)
{
    func_021F723C(p);
}
