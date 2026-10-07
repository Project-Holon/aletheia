/*
 * file:     field_msgbg_p74.c
 * unit:     yes
 * function: func_02191870, func_021918DC
 * address:  0x02191870
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_020457B0  0x020457B0  arm  arm9
 *   func_02045CAC  0x02045CAC  arm  arm9
 *   func_021917C4  0x021917C4  thumb  ov021
 *   func_0219319C  0x0219319C  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_020458F8  0x020458F8  arm
 *   func_02045838  0x02045838  arm
 */
struct MsgBank;
struct U16Vec;
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_0219319C(u8 *p, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021917C4(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i);
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
void func_02191870(Fx *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h);
/* d is u8: its caller (0x021B11B6) truncates r3, and the narrow type is what * pins its home store to the front of the prologue. */ void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g);
extern char d_021DDA50[];


/*
 * Addresses are Black-image addresses.
 */
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


/* d is u8: its caller (0x021B11B6) truncates r3, and the narrow type is what
 * pins its home store to the front of the prologue. */
void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g)
{
    u32 *h;
    u32 t;

    h = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0xE48);
    t = func_0219319C((u8 *)a, (u32)h);
    h[0] = (u32)func_020457B0(func_020458F8((struct U16Vec *)b) + 1, *a);
    func_02045838((struct U16Vec *)h[0], (struct U16Vec *)b);
    func_021917C4(a, h, h[0], (u16)(t + 3), d, e, f, g, c);
}
