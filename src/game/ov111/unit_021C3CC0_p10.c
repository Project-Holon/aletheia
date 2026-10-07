/*
 * file:     unit_021C3CC0_p10.c
 * unit:     yes
 * function: func_021C56E8, func_021C5718, func_021C581C, func_021C5874
 * address:  0x021C56E8
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
 *   func_021C5008  0x021C5008  thumb  ov111
 *   func_021C555C  0x021C555C  thumb  ov111
 *   func_021C5B80  0x021C5B80  thumb  ov111
 *   func_021C567C  0x021C567C  thumb  ov111
 *   func_021C5054  0x021C5054  thumb  ov111
 *   func_020061E4  0x020061E4  thumb
 *   func_02012F5C  0x02012F5C  thumb
 *   sub_02008A00  0x02008A00  thumb
 *   func_021C3EF8  0x021C3EF8  thumb
 *   func_021C61EC  0x021C61EC  thumb
 *   func_021C628C  0x021C628C  thumb
 *   func_021C5B34  0x021C5B34  thumb  ov111
 *   func_021C4F80  0x021C4F80  thumb  ov111
 *   func_02040618  0x02040618  arm
 *   func_020419E4  0x020419E4  arm
 *   func_0204A648  0x0204A648  arm
 *   func_0207C778  0x0207C778  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0207D59C  0x0207D59C  arm
 */
struct Sub020089A8Obj;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work_021C56E8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
} Cfg;

typedef struct {
    Cfg *cfg;
    void *f4;
    u8 pad8[4];
    u32 fC;
    u32 f10;
} Args;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x48 - 7];
    u32 f48;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args *args;
    Info *info;
    u8 pad2C[0x32C6 - 0x2C];
    u8 b32C6;
} Work_021C5718;

typedef struct {
    u8 pad0[0x32CA];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
    u8 pad32CB[0x32D6 - 0x32CB];
    u8 shake;
} Work_021C581C;

typedef int fx32;

struct Mtx {
    fx32 _00;
    fx32 _01;
    fx32 _10;
    fx32 _11;
};

extern int func_021C5008(Work_021C56E8 *p);
extern void func_021C555C(Work_021C56E8 *p);
extern void func_021C5B80(Work_021C56E8 *p);
extern int func_021C567C(Work_021C56E8 *p);
extern int func_021C5054(Work_021C56E8 *p);
extern void func_020061E4(u32 a);
extern void *func_02012F5C(void **h);
extern struct Sub020089A8Obj *sub_02008A00(struct Sub020089A8Obj *obj);
extern void func_021C3EF8(Info *info);
extern void func_021C61EC(Work_021C5718 *p, int v, int a);
extern void func_021C628C(Work_021C5718 *p, int v, int a);
extern void func_021C5B34(Work_021C581C *p);
extern void func_021C4F80(Work_021C581C *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern fx32 func_0207C778(fx32 v);
extern void func_02087AE4(void);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);
int func_021C56E8(Work_021C56E8 *p);
void func_021C5718(Work_021C5718 *p, int sel, int *seq);
void func_021C581C(void *task, Work_021C581C *p);
void func_021C5874(void);


/*
 * Addresses are Black-image addresses.
 */
int func_021C56E8(Work_021C56E8 *p)
{
    func_021C5008(p);
    func_021C555C(p);
    func_021C5B80(p);
    if (p->mode == 1) {
        return func_021C567C(p);
    }
    return func_021C5054(p);
}


void func_021C5718(Work_021C5718 *p, int sel, int *seq)
{
    switch (sel) {
    case 3:
        p->b32C6 = 0;
        *seq = 5;
        break;
    case 8:
        if (p->args->cfg->f4_6) {
            *seq = 9;
        }
        break;
    case 9:
        if (p->args->cfg->f4_6) {
            func_020061E4(0x548);
            p->b32C6 = 0;
            *seq = 6;
        }
        break;
    case 4:
        *seq = 2;
        p->args->fC = 0;
        p->args->f10 = 0;
        break;
    case 5:
        *seq = 3;
        p->args->fC = 0;
        p->args->f10 = 1;
        break;
    case 6:
        if (p->args->cfg->f4_6) {
            sub_02008A00(func_02012F5C(p->args->f4));
            func_020061E4(0x548);
            func_021C3EF8(p->info);
            func_021C61EC(p, p->info->b6, 1);
        }
        break;
    case 7:
        if (p->args->cfg->f4_6) {
            func_020061E4(0x548);
            p->info->f48++;
            if (p->info->f48 > 0x18) {
                p->info->f48 = 0;
            }
            func_021C628C(p, p->info->f48, 1);
        }
        break;
    case 10:
        p->b32C6 = 0;
        *seq = 7;
        break;
    }
}


void func_021C581C(void *task, Work_021C581C *p)
{
    int ofs;

    func_021C5B34(p);
    ofs = -(p->shake / 2);
    func_02040618(5, 0, ofs);
    func_02040618(5, 3, ofs);
    func_02040618(3, 0, ofs);
    func_02040618(3, 3, ofs);
    if (p->dirty) {
        func_021C4F80(p);
    }
    func_020419E4();
    func_0204A648();
}


void func_021C5874(void)
{
    struct Mtx m;
    fx32 a, d;

    a = func_0207C778(0x1000);
    d = func_0207C778(0x1000);
    m._00 = a;
    m._01 = 0;
    m._10 = 0;
    m._11 = d;
    func_02087AE4();
    func_0207D59C((void *)0x04001020, &m, 0x80, 0x60, 0, 0);
    func_0207D59C((void *)0x04001030, &m, 0x80, 0x60, 0, 0);
    func_02087AE4();
    func_0207D59C((void *)0x04000030, &m, 0x80, 0, 0, 0);
}
