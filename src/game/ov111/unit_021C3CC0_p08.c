/*
 * file:     unit_021C3CC0_p08.c
 * unit:     yes
 * function: func_021C5054, func_021C513C
 * address:  0x021C5054
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
 *   func_021C6FA0  0x021C6FA0  thumb  ov111
 *   func_020061E4  0x020061E4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02012BF8  0x02012BF8  thumb
 *   func_02012BE0  0x02012BE0  thumb
 */
typedef unsigned char u8;

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
    u8 f4_7 : 1;
} Info;

typedef struct {
    u8 pad0[4];
    void *f4;
} Args;

typedef struct {
    u8 pad0[0x98];
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args *args;
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim anim;
} Work;

extern void func_021C6FA0(Anim *a, int idx, u8 x, u8 y);
extern void func_020061E4(u32 a);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern int func_02012BF8(int a0, int a1);
extern void func_02012BE0(void *p, u32 a, u32 b);
int func_021C5054(Work *p);
void func_021C513C(Work *p);


/*
 * Addresses are Black-image addresses.
 */
int func_021C5054(Work *p)
{
    u32 key = func_020362DC();

    if (key & 2) {
        if (p->h305E == 0) {
            func_021C6FA0(&p->anim, 0, 9, 1);
            func_020061E4(0x551);
            func_020355D8(0);
            return 4;
        }
    } else if (key & 0x400) {
        if (p->h305E == 0 && !p->info->f4_7) {
            func_021C6FA0(&p->anim, 1, 8, 1);
            func_020061E4(0x556);
            return 5;
        }
    } else if (key & 0x30) {
        if (p->h305E == 0) {
            func_021C6FA0(&p->anim, 6, 0x17, 1);
            return 3;
        }
    } else if (key & 0x800) {
        if (!p->info->f4_7) {
            func_021C513C(p);
        }
    } else if (key & 1) {
        if (!p->info->f4_7 && p->f3034 == 0) {
            func_020061E4(0x54C);
            func_021C6FA0(&p->anim, 2, 0x11, 1);
            return 10;
        }
    }
    return 0;
}


void func_021C513C(Work *p)
{
    int v;

    func_020061E4(0x646);
    if (p->f3034 == 0) {
        v = func_02012BF8((int)p->args->f4, 0x15) ^ 1;
        func_021C6FA0(&p->anim, 7, v + 6, 1);
        func_02012BE0(p->args->f4, 0x15, v);
    } else {
        v = func_02012BF8((int)p->args->f4, 0x16) ^ 1;
        func_021C6FA0(&p->anim, 7, v + 6, 1);
        func_02012BE0(p->args->f4, 0x16, v);
    }
}
