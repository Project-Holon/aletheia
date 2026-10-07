/*
 * file:     unit_021C3CC0_p07.c
 * unit:     yes
 * function: func_021C4F80, func_021C5008
 * address:  0x021C4F80
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207C778  0x0207C778  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_0203630C  0x0203630C  arm
 */
typedef unsigned char u8;

typedef int fx32;

typedef unsigned int u32;

struct Mtx {
    fx32 _00;
    fx32 _01;
    fx32 _10;
    fx32 _11;
};

typedef struct {
    u8 pad0[0x303C];
    fx32 scaleX;
    fx32 scaleY;
    u8 pad3044[0x304C - 0x3044];
    u32 cx;
    u32 cy;
    u32 x;
    u32 y;
    u8 pad305C[0x32CA - 0x305C];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
} Work_021C4F80;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work_021C5008;

extern fx32 func_0207C778(fx32 v);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);
extern int func_02035C38(void);
extern unsigned int func_0203630C(void);
void func_021C4F80(Work_021C4F80 *p);
int func_021C5008(Work_021C5008 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021C4F80(Work_021C4F80 *p)
{
    struct Mtx m;

    m._00 = func_0207C778(p->scaleX);
    m._01 = 0;
    m._10 = 0;
    m._11 = func_0207C778(p->scaleY);
    func_0207D59C((void *)0x04001020, &m, p->cx, p->cy, p->x, p->y);
    func_0207D59C((void *)0x04001030, &m, p->cx, p->cy, p->x, p->y);
    p->dirty = 0;
}


int func_021C5008(Work_021C5008 *p)
{
    if (p->mode == 1) {
        if (func_02035C38()) {
            return 0;
        }
        if (func_0203630C()) {
            p->mode = 0;
            return 1;
        }
    } else {
        if (func_0203630C()) {
            return 0;
        }
        if (func_02035C38()) {
            p->mode = 1;
            return 0;
        }
    }
    return 0;
}
