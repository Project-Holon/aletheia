/*
 * function: func_021C3CC0
 * address:  0x021C3CC0
 * packet:   pkt_ov111_021C3CC0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0202223C  0x0202223C  thumb
 *   func_02022224  0x02022224  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0202DB0C  0x0202DB0C  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_021C41C4  0x021C41C4  thumb  ov111
 *   func_021C43E8  0x021C43E8  thumb  ov111
 *   func_021C453C  0x021C453C  thumb  ov111
 *   func_021C6D9C  0x021C6D9C  thumb  ov111
 *   func_021C6804  0x021C6804  thumb  ov111
 *   func_021C6E8C  0x021C6E8C  thumb  ov111
 *   func_021C6000  0x021C6000  thumb  ov111
 *   func_021C6D98  0x021C6D98  thumb  ov111
 *   func_021C5874  0x021C5874  thumb  ov111
 *   func_021C47EC  0x021C47EC  thumb  ov111
 *   func_021C581C  0x021C581C  thumb  ov111
 *   d_021C8564     0x021C8564  data  a4
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
    u8 pad5[3];
    u16 h8;
    u8 padA[0x33 - 0xA];
    u8 b33;
} Info;

typedef struct {
    Info *info;
    u8 pad4[0xC - 4];
    u32 fC;
    u8 pad10[4];
    u32 f14;
} Args;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *f4;
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[8];
    Args *args;
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x304C - 0x3038];
    u32 f304C;
    u32 f3050;
    u32 f3054;
    u32 f3058;
    u8 pad305C[0x3060 - 0x305C];
    u32 f3060;
    u8 pad3064[0x3070 - 0x3064];
    Anim anim;
    u8 pad3078[0x31C4 - 0x3078];
    u32 f31C4;
    u8 pad31C8[0x31F4 - 0x31C8];
    void *f31F4;
    void *f31F8;
    void *f31FC;
    u8 pad3200[0x320C - 0x3200];
    void *f320C;
    u8 pad3210[0x32B0 - 0x3210];
    void *f32B0;
    u8 flags[16];
    u8 b32C4;
    u8 pad32C5[3];
    u8 b32C8;
    u8 pad32C9;
    u8 f32CA_0 : 1;
    u8 f32CA_1 : 1;
    u8 pad32CB;
    void *f32CC;
    u8 pad32D0[4];
    u8 b32D4;
    u8 b32D5;
    u8 pad32D6[0x3310 - 0x32D6];
} Work;

extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0202223C(u32 a, u32 b);
extern void func_02022224(u32 a);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern Work *func_0203159C(void *man, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_020355C4(void);
extern u8 func_02012FFC(void);
extern int func_0203D1B4(void);
extern void func_0203F8F4(u16 heap);
extern void func_020433E0(const void *cfg);
extern void *func_0202DB0C(void *a, u32 b, void *c, void *d, u32 e, u32 f, u32 heap);
extern void *func_020056A0(void (*cb)(void *, Work *), void *ctx, int pri);
extern void *func_0203101C(u32 a, u32 b, u32 c, u32 d);
extern void func_0203D34C(u32 a, u16 heap);
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021C41C4(Work *p);
extern void func_021C43E8(void);
extern void func_021C453C(Work *p);
extern void func_021C6D9C(Anim *a, const void *cfg);
extern void func_021C6804(Work *p, Info *info);
extern void func_021C6E8C(Anim *a);
extern void func_021C6000(Work *p);
extern void func_021C6D98(Work *p, void *bg, u32 a, void *b);
extern void func_021C5874(void);
extern void func_021C47EC(Work *p);
extern void func_021C581C(void *task, Work *p);
extern const u8 d_021C8564[];

int func_021C3CC0(void *man, int *state, Args *args)
{
    Work *p;
    int i;
    u16 mask;

    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= ~0x1F00;
    *(volatile u32 *)0x04001000 &= ~0x1F00;
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_02022224(0);
    func_02022224(1);
    func_0203064C(1, 0x27, 0x50000);
    p = func_0203159C(man, sizeof(Work), 0x27);
    func_02082BCC(p, 0, sizeof(Work));
    p->heap = 0x27;
    p->anim.heap = 0x27;
    p->args = args;
    p->info = args->info;
    p->f3060 = func_020355C4();
    p->b32D5 = func_02012FFC();
    p->b32D4 = 0;
    if (p->info->b33) {
        p->f32CA_0 = 1;
    } else {
        p->f32CA_0 = 0;
    }
    mask = 1;
    for (i = 0; i < 16; i++) {
        if (p->info->h8 & mask) {
            p->flags[i] = 1;
        } else {
            p->flags[i] = 0;
        }
        mask <<= 1;
    }
    if (func_0203D1B4() > 0) {
        p->f32CA_1 = 1;
    }
    func_0203F8F4(p->heap);
    func_021C41C4(p);
    func_020433E0(d_021C8564);
    func_021C43E8();
    func_021C453C(p);
    func_021C6D9C(&p->anim, d_021C8564);
    func_021C6804(p, p->args->info);
    func_021C6E8C(&p->anim);
    func_021C6000(p);
    p->f32B0 = func_0202DB0C(p->anim.f4, 1, p->f32CC, p->f31FC, 8, 1, 0x27);
    func_021C6D98(p, p->bg[4], 1, p->f320C);
    if (p->args->f14 == 2) {
        p->args->f14 = 0;
        p->f3034 = 1;
    } else {
        p->f3034 = 0;
    }
    p->args->fC = 0;
    p->b32C4 = 0;
    p->f31C4 = 0;
    if (p->info->f4_4) {
        p->b32C8 = 0;
    } else {
        p->b32C8 = 2;
    }
    p->f304C = 0x80;
    p->f3050 = 0x60;
    p->f3054 = 0;
    p->f3058 = 0;
    func_021C5874();
    func_021C47EC(p);
    p->f31F4 = func_020056A0(func_021C581C, p, 1);
    p->f31F8 = func_0203101C(p->heap, p->heap, 3, 0);
    func_0203D34C(1, p->heap);
    func_0202208C(1, 3, 3, 0, 6, 1, p->heap);
    return 1;
}
