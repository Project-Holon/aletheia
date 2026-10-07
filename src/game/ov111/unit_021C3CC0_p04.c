/*
 * file:     unit_021C3CC0_p04.c
 * unit:     yes
 * function: func_021C43E8, func_021C4524, func_021C4530, func_021C453C, func_021C46F0
 * address:  0x021C43E8
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
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   d_021C85C8     0x021C85C8  data  a4
 *   d_021C85E8     0x021C85E8  data  a4
 *   d_021C8608     0x021C8608  data  a4
 *   d_021C8628     0x021C8628  data  a4
 *   d_021C8648     0x021C8648  data  a4
 *   d_021C8668     0x021C8668  data  a4
 *   func_021C436C  0x021C436C  thumb  ov111
 *   func_021C43C4  0x021C43C4  thumb  ov111
 *   func_021C58E0  0x021C58E0  thumb  ov111
 *   func_021C5958  0x021C5958  thumb  ov111
 *   func_02049DB4  0x02049DB4  arm
 *   func_02049EB4  0x02049EB4  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021C86E8     0x021C86E8  data  a4
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig {
    u32 w[4];
};

struct BgTemplate {
    u32 w[8];
};

struct BgTemplatePair {
    struct BgTemplate t[2];
};

typedef unsigned char u8;

typedef struct {
    u8 kind;
    u8 pad1[2];
    u8 b3;
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0x74 - 7];
    u8 bitmap[1];
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
    u8 pix[0x302C - 0x2C];
    void *f302C;
    void *f3030;
    u8 pad3034[0x31D8 - 0x3034];
    void *f31D8;
    void *f31DC;
} Work;

extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32 bgId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021C436C(Work *p, int k, int alt);
extern void func_021C43C4(Work *p, int k);
extern void func_021C58E0(Work *p);
extern void func_021C5958(const u8 *src, u8 *dst);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020275E4(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_020403F4(u32 bgId);
extern void func_0203F9B4(void);
void func_021C43E8(void);
int func_021C4524(int x);
int func_021C4530(int x);
void func_021C453C(Work *p);
void func_021C46F0(void);
extern const struct DispConfig d_021C85C8;
extern const struct BgTemplate d_021C85E8;
extern const struct BgTemplate d_021C8608;
extern const struct BgTemplate d_021C8628;
extern const struct BgTemplate d_021C8648;
extern const struct BgTemplatePair d_021C8668;
extern const u32 d_021C86E8[][2];


/*
 * Addresses are Black-image addresses.
 */
void func_021C43E8(void)
{
    *(volatile u16 *)0x04000304 |= 0x8000;
    {
        struct DispConfig disp = d_021C85C8;
        func_0203FC28(&disp);
    }
    {
        struct BgTemplate t = d_021C85E8;
        func_0203FCA0(7, &t, 2);
        func_020414AC(7);
        func_02040588(7, 1);
    }
    {
        struct BgTemplatePair t = d_021C8668;
        func_0203FCA0(4, &t.t[0], 0);
        func_020414AC(4);
        func_02040588(4, 1);
        func_0203FCA0(5, &t.t[1], 0);
        func_020414AC(5);
        func_02040588(5, 1);
    }
    {
        struct BgTemplate t = d_021C8608;
        func_0203FCA0(6, &t, 2);
        func_020414AC(6);
        func_02040588(6, 1);
    }
    {
        struct BgTemplate t = d_021C8628;
        func_0203FCA0(2, &t, 0);
        func_020414AC(2);
        func_02040588(2, 0);
    }
    {
        struct BgTemplate t = d_021C8648;
        func_0203FCA0(3, &t, 0);
        func_020414AC(3);
        func_02040588(3, 1);
    }
}

/*
 * Two ternaries selecting between two constants.
 */
int func_021C4524(int x)
{
    return x == 0x14 ? 0x20 : 0x1C;
}


int func_021C4530(int x)
{
    return x == 0x14 ? 0x2A : 0x29;
}


void func_021C453C(Work *p)
{
    func_021C436C(p, p->info->b3, p->info->f4_2);
    if (p->info->f4_7 == 0) {
        p->f302C = func_02049DB4(0x28, 0x1F, 0, (u32)(&p->f3030), p->heap);
        if (p->info->f4_1 == 0) {
            p->f31D8 = func_02049EB4(0x28, 0x2B, 0, (u32)(&p->f31DC), p->heap);
        } else {
            p->f31D8 = func_02049EB4(0x28, 0x2C, 0, (u32)(&p->f31DC), p->heap);
        }
    } else {
        p->f302C = func_02049DB4(0x29, d_021C86E8[p->info->b6][0], 0, (u32)(&p->f3030), p->heap);
        p->f31D8 = func_02049EB4(0x29, 0x20, 0, (u32)(&p->f31DC), p->heap);
        func_021C43C4(p, p->info->b6);
    }
    func_021C58E0(p);
    func_02049624((void *)0x28, (void *)func_021C4524(p->info->kind), (void *)6, 0, 0, 0, p->heap);
    func_0204989C(0x28, func_021C4530(p->info->kind), 6, 0, 0, 0, p->heap);
    func_02049624((void *)0x28, (void *)0x1E, (void *)5, 0, 0, 0, p->heap);
    func_0204989C(0x28, 0x28, 5, 0, 0, 0, p->heap);
    func_02049624((void *)0x28, (void *)0x1E, (void *)3, 0, 0, 0, p->heap);
    func_0204989C(0x28, 0x28, 3, 0, 0, 0, p->heap);
    func_02049B40(0x28, 0xF, 0, 0, 0x20, p->heap);
    func_021C5958(p->info->bitmap, p->pix);
    func_02049624((void *)func_020275E4(), (void *)func_02027628(), (void *)4, 0, 0, 0, p->heap);
    func_0204989C(func_020275E4(), func_0202762C(), 4, 0, 0, 0, p->heap);
    func_020413B0(4, 0, 0x15, 0x20, 3, 0xC);
    func_020409B4(4);
}


void func_021C46F0(void)
{
    func_020434DC(0x1F, 0);
    func_02043598(0x1F, 0);
    func_02040618(5, 0, 0);
    func_02040618(5, 3, 0);
    func_02040618(3, 0, 0);
    func_02040618(3, 3, 0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(2);
    func_020403F4(3);
    func_0203F9B4();
}
