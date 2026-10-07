/*
 * function: func_021C5484
 * address:  0x021C5484
 * packet:   pkt_ov111_021C5484
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
 *   func_021C513C  0x021C513C  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 kind;
    u8 pad1[3];
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
    Info *info;
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
    u8 pad3038[0x305C - 0x3038];
    u16 h305C;
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim anim;
    u8 pad3108[0x32C6 - 0x3108];
    u8 b32C6;
    u8 pad32C7[0x32D8 - 0x32C7];
    u32 f32D8;
    u32 f32DC;
    u8 pad32E0[0x32F6 - 0x32E0];
    u8 b32F6;
} Work;

extern void func_021C6FA0(Anim *a, int idx, u8 x, u8 y);
extern void func_020061E4(u32 a);
extern void func_021C513C(Work *p);

int func_021C5484(Work *p, int hit)
{
    switch (hit) {
    case 4:
        if (p->f3034 != 0) {
            func_021C6FA0(&p->anim, 4, 0x15, 1);
            func_020061E4(0x649);
            p->b32C6 = 3;
            return 8;
        }
        break;
    case 5:
        if (p->f3034 != 0) {
            func_020061E4(0x548);
            func_021C6FA0(&p->anim, 5, 9 - p->b32F6 * 2, 1);
            p->b32F6 ^= 1;
        }
        break;
    case 6:
        func_021C513C(p);
        break;
    case 10:
        if (p->h305C == 0) {
            func_020061E4(0x548);
            p->b32C6 = 9;
            return 8;
        }
        break;
    case 11:
        if (p->h305C == 1) {
            func_020061E4(0x548);
            p->b32C6 = 6;
            return 8;
        }
        break;
    }
    return 0;
}
