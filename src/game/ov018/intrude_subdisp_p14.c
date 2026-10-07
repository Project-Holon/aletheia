/*
 * file:     intrude_subdisp_p14.c
 * unit:     yes
 * function: func_0217F3E4, func_0217F40C, func_0217F420, func_0217F434, func_0217F45C, func_0217F470, func_0217F4A0, func_0217F4C4, func_0217F4D8, func_0217F508, func_0217F528
 * address:  0x0217F3E4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   d_02183B2C     0x02183B2C  data
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_020362DC 0x020362DC arm
 *   func_02190708 0x02190708 thumb ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02190758 0x02190758 thumb ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_0201210C 0x0201210C thumb
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_02190C78 0x02190C78 thumb ov021
 */
struct P;
struct Fx;
struct MsgBank;
struct WordSet;
struct Ctx;
struct Handle;
typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F3E4;

typedef unsigned int   u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F40C;

typedef unsigned short u16;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F45C;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F4C4;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
} Ov018Obj_0217F528;

void func_02034714(const char *expr, u32 line, const char *file);
void func_02190F7C(struct P *p);
u32 func_02190EF0(u32 *p);
extern unsigned int func_020362DC(void);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
int func_02190728(void *a);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
int func_021909BC(void *a);
extern void *func_0201210C(const struct Ctx *);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
void func_0217F3E4(Ov018Obj_0217F3E4 *p);
int func_0217F40C(Ov018Obj_0217F40C *p);
int func_0217F420(void);
void func_0217F434(void **p);
void func_0217F45C(Ov018Obj_0217F45C *p);
void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b);
void func_0217F4A0(void **p, unsigned int index, int a, int b);
void func_0217F4C4(Ov018Obj_0217F4C4 *p);
void func_0217F4D8(void **p, int a);
int func_0217F508(void **p);
void func_0217F528(Ov018Obj_0217F528 *p, int a, int b, int c, int d, int e);
extern unsigned char d_02183B2C[];


void func_0217F3E4(Ov018Obj_0217F3E4 *p)
{
    if (p->f18 == 0) {
        func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    }
    func_02190F7C(p->f18);
    p->f28 = 0;
}


int func_0217F40C(Ov018Obj_0217F40C *p)
{
    if (p->f18 == 0) {
        return 1;
    }
    return func_02190EF0(p->f18);
}

int func_0217F420(void)
{
    if (func_020362DC() & 0xf3) return 1;
    return 0;
}

/*
 * extent: Two bytes of alignment padding at 0x0217F45A.
 */
void func_0217F434(void **p)
{
    if (p[7] == 0) p[7] = func_02190708(p[9], (u32)p[3], 1, 0x13, 0x1e, 4);
}


void func_0217F45C(Ov018Obj_0217F45C *p)
{
    if (p->f1C != 0) {
        func_02190728((void *)p->f1C);
        p->f1C = 0;
    }
}

void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b)
{
    func_02045CAC(bank, index, p[2]);
    func_0201F250(p[0], p[1], p[2]);
    func_02190758((u32)handle, (u16)a, (u16)b, (u32)p[1]);
}

void func_0217F4A0(void **p, unsigned int index, int a, int b)
{
    func_0217F434(p);
    func_0217F470(p, p[3], p[7], index, a, b);
}


void func_0217F4C4(Ov018Obj_0217F4C4 *p)
{
    if (p->f2C != 0) {
        func_021909BC((void *)p->f2C);
        p->f2C = 0;
    }
}

void func_0217F4D8(void **p, int a)
{
    func_0201210C((const struct Ctx *)a);
    if (p[11] != 0 || p[3] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    p[11] = func_02190BE4(p[9], 0);
}

int func_0217F508(void **p)
{
    if (p[11] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    return func_02190C78(p[11]);
}


void func_0217F528(Ov018Obj_0217F528 *p, int a, int b, int c, int d, int e)
{
    func_0201210C((void *)a);
    if (p->f20 != 0) {
        func_02034714((const char *)d_02183B2C, (int)0, (const char *)d_02183B2C);
    }
    p->f20 = func_02190708(p->f24, (u32)p->f0C, (u16)b, (u16)c, d, e);
}
