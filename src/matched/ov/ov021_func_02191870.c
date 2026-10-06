/*
 * function: func_02191870
 * address:  0x02191870
 * packet:   pkt_ov021_02191870
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_020457B0  0x020457B0  arm  arm9
 *   func_02045CAC  0x02045CAC  arm  arm9
 *   func_021917C4  0x021917C4  thumb  ov021
 *   func_0219319C  0x0219319C  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct O {
    u32 f00;
} O;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct MsgBank;
struct U16Vec;
extern int func_0219319C(u8 *p, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021917C4(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i);

void func_02191870(Fx *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h)
{
    O *o;
    int k;

    o = func_02030734(a->f00, 0x18, 1, d_021DDA50, 0xE2A);
    k = func_0219319C((u8 *)a, (u32)o);
    o->f00 = (u32)func_020457B0(0x40, a->f00);
    func_02045CAC((struct MsgBank *)b, c, (void *)o->f00);
    func_021917C4((u16 *)a, (u32 *)o, o->f00, (u16)(k + 3), e, f, g, h, d);
}
