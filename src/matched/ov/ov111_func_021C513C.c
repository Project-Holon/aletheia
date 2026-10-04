/*
 * function: func_021C513C
 * address:  0x021C513C
 * packet:   pkt_ov111_021C513C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6FA0  0x021C6FA0  thumb  ov111
 *   func_020061E4  0x020061E4  thumb
 *   func_02012BF8  0x02012BF8  thumb
 *   func_02012BE0  0x02012BE0  thumb
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
extern int func_02012BF8(int a0, int a1);
extern void func_02012BE0(void *p, u32 a, u32 b);

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
