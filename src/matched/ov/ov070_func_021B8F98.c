/*
 * function: func_021B8F98
 * address:  0x021B8F98
 * packet:   pkt_ov070_021B8F98
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BG setup: GX_SetDispSelect(0), then seven 32-byte BG templates copied
 * to the stack and handed to func_0203FCA0 for BGs 0-6, each followed by
 * its clear/enable calls.
 *
 * volatile: 0x04000304 (POWCNT1, read-modify-write at 0x021B8FA0/0x021B8FA8)
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_020414EC  0x020414EC  arm
 *   d_021BBB40     0x021BBB40  data  a4
 *   d_021BBB60     0x021BBB60  data  a4
 *   d_021BBB80     0x021BBB80  data  a4
 *   d_021BBB20     0x021BBB20  data  a4
 *   d_021BBAC0     0x021BBAC0  data  a4
 *   d_021BBAE0     0x021BBAE0  data  a4
 *   d_021BBB00     0x021BBB00  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
#define REG_GX_POWCNT_DSEL_MASK 0x8000
#define REG_GX_POWCNT_DSEL_SHIFT 15

typedef enum {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;

static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                          (sel << REG_GX_POWCNT_DSEL_SHIFT));
}

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

extern const BgTemplate d_021BBB40;
extern const BgTemplate d_021BBB60;
extern const BgTemplate d_021BBB80;
extern const BgTemplate d_021BBB20;
extern const BgTemplate d_021BBAC0;
extern const BgTemplate d_021BBAE0;
extern const BgTemplate d_021BBB00;

extern void func_0203FCA0(int bg, void *tmpl, int mode);
extern void func_020414AC(int bg);
extern void func_020409B4(u32 layer);
extern void func_02040588(int a, int b);
extern void func_02040C14(int, int, int, int);
extern void func_020414EC(u32 i);

void func_021B8F98(void)
{
    BgTemplate t0;
    BgTemplate t1;
    BgTemplate t2;
    BgTemplate t3;
    BgTemplate t4;
    BgTemplate t5;
    BgTemplate t6;

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    t0 = d_021BBB40;
    func_0203FCA0(0, &t0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 0);

    t1 = d_021BBB60;
    func_0203FCA0(1, &t1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 0);

    t2 = d_021BBB80;
    func_0203FCA0(2, &t2, 0);
    func_020414AC(2);
    func_020409B4(2);
    func_02040588(2, 0);

    t3 = d_021BBB20;
    func_0203FCA0(3, &t3, 0);
    func_02040C14(3, 0, 1, 0);
    func_020414AC(3);
    func_020409B4(3);
    func_02040588(3, 0);

    t4 = d_021BBAC0;
    func_0203FCA0(4, &t4, 0);
    func_02040588(4, 0);
    func_020409B4(4);

    t5 = d_021BBAE0;
    func_0203FCA0(5, &t5, 0);
    func_02040588(5, 0);

    t6 = d_021BBB00;
    func_0203FCA0(6, &t6, 0);
    func_02040588(6, 0);
    func_02040C14(6, 0, 1, 0);
    func_020414EC(6);
}
