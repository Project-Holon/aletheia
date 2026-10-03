/*
 * function: func_021C47EC
 * address:  0x021C47EC
 * packet:   pkt_ov111_021C47EC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C479C  0x021C479C  thumb  ov111
 *   func_021C60CC  0x021C60CC  thumb  ov111
 *   func_0202DBC4  0x0202DBC4  thumb
 *   func_021C6874  0x021C6874  thumb  ov111
 *   func_021C58E0  0x021C58E0  thumb  ov111
 *   func_021C636C  0x021C636C  thumb  ov111
 *   func_021C5ACC  0x021C5ACC  thumb  ov111
 *   func_021C4B74  0x021C4B74  thumb  ov111
 *   func_021C631C  0x021C631C  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct Info Info;

typedef struct {
    u8 pad0[4];
    void *bg[7];
    u8 pad20[8];
    Info *info;
    u8 pix[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x32B0 - 0x3038];
    void *f32B0;
    u8 pad32B4[0x32C8 - 0x32B4];
    u8 phase;
    u8 pad32C9[0x32E2 - 0x32C9];
    s16 scroll;
} Work;

extern void func_021C479C(Work *p);
extern void func_021C60CC(Work *p, void **bg, Info *info);
extern void func_0202DBC4(u8 *p);
extern void func_021C6874(Work *p, int scroll, int flush, int idx);
extern void func_021C58E0(Work *p);
extern void func_021C636C(Work *p, void **bg, Info *info);
extern void func_021C5ACC(u32 bg, const void *src, int mode);
extern void func_021C4B74(Work *p, int flag);
extern void func_021C631C(Work *p, void **bg);

void func_021C47EC(Work *p)
{
    func_021C479C(p);
    func_021C60CC(p, p->bg, p->info);
    func_0202DBC4(p->f32B0);
    if (p->f3034 == 0) {
        func_021C6874(p, p->scroll, 0, 0);
        func_021C58E0(p);
    } else {
        func_021C636C(p, p->bg, p->info);
        func_021C5ACC(7, p->pix, p->phase);
    }
    func_021C4B74(p, p->f3034);
    func_021C631C(p, p->bg);
}
