/*
 * function: func_021C49D8
 * address:  0x021C49D8
 * packet:   pkt_ov111_021C49D8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6FA0  0x021C6FA0  thumb  ov111
 *   func_021C51B4  0x021C51B4  thumb  ov111
 *   func_02012BF8  0x02012BF8  thumb
 *
 * Addresses are Black-image addresses.
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
    u32 f8;
} Sub24;

typedef struct {
    u8 pad0[0x98];
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Sub24 *f24;
    Info *info;
    u8 pad2C[0x305E - 0x2C];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim anim;
    u8 pad3108[0x32F6 - 0x3108];
    u8 b32F6;
} Work;

extern void func_021C6FA0(Anim *a, int idx, u8 x, u8 y);
extern void func_021C51B4(Work *p, int flag, int v);
extern int func_02012BF8(void *a, u32 b);

void func_021C49D8(Work *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 4, 0x12, 0);
        func_021C6FA0(&p->anim, 5, 6, 0);
        func_021C6FA0(&p->anim, 2, 0x10, 1);
        func_021C6FA0(&p->anim, 7, func_02012BF8(p->f24->f4, 0x15) + 6, 1);
    } else {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 1, 0, 1);
        func_021C6FA0(&p->anim, 4, 0x12, 0);
        func_021C6FA0(&p->anim, 6, 0x16, 1);
        func_021C6FA0(&p->anim, 5, 8 - p->b32F6 * 2, 0);
        func_021C51B4(p, p->info->f4_4, 0);
        func_021C6FA0(&p->anim, 7, func_02012BF8(p->f24->f4, 0x16) + 6, 1);
    }
}
