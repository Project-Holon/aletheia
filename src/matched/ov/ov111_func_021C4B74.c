/*
 * function: func_021C4B74
 * address:  0x021C4B74
 * packet:   pkt_ov111_021C4B74
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4858  0x021C4858  thumb  ov111
 *   func_021C49D8  0x021C49D8  thumb  ov111
 *   func_021C4AB0  0x021C4AB0  thumb  ov111
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
extern void func_021C4858(Work *p, int flag);
extern void func_021C49D8(Work *p, int flag);
extern void func_021C4AB0(Work *p, int flag);

void func_021C4B74(Work *p, int flag)
{
    if (p->info->f4_7 == 1) {
        func_021C4AB0(p, flag);
    } else if (p->f24->f8 == 0) {
        func_021C49D8(p, flag);
    } else {
        func_021C4858(p, flag);
    }
}
