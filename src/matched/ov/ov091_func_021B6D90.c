/*
 * function: func_021B6D90
 * address:  0x021B6D90
 * packet:   pkt_ov091_021B6D90
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; 36 of 37 sites resolve.  The one wildcard is the arm9 call
 * at +013C to func_02061C30, which has no witness outside this range.
 * blocker:
 *   func_02061C30  0x02061C30  arm  (arm9, Ilias's leaf; unlabelled ARM
 *   tail-call stub `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C;
 *   .word 0x02146B80`).  No verified C exists: src/pending/arm9_sdk/
 *   func_02061C30.c (`OS_WakeupThreadDirect(&dacktimer_thread);`) is DIFF,
 *   network.o is a 3.0.0.139 object no available mwcc build reproduces.
 *   Same blocker as src/pending/ov/ov091_func_021B6FEC.c.
 *
 * volatile: 0x021B6DCA/0x021B6DD4 re-read DISPCNT (0x04000000) and
 *   DB_DISPCNT (0x04001000), 0x021B6DFA POWCNT (0x04000304): SDK inlines
 *   GX_SetVisiblePlane, GXS_SetVisiblePlane, GX_SetDispSelect.
 *
 * symbols:
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021B7078  0x021B7078  thumb  ov091
 *   func_021B6F0C  0x021B6F0C  thumb  ov091
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0202223C  0x0202223C  thumb
 *   func_02022224  0x02022224  thumb
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02061C30  0x02061C30  arm
 *   d_021BEC3C     0x021BEC3C  data  a4
 *   d_021BEAEC     0x021BEAEC  data  a4
 *   d_021BEAFC     0x021BEAFC  data  a4
 *   d_021BEB1C     0x021BEB1C  data  a4
 *   d_021BEB3C     0x021BEB3C  data  a4
 *   d_021BEB5C     0x021BEB5C  data  a4
 *   d_021BEB9C     0x021BEB9C  data  a4
 *   d_021BEBBC     0x021BEBBC  data  a4
 *   d_021BEBDC     0x021BEBDC  data  a4
 *   d_020A1448     0x020A1448  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w[12];
} A48;

typedef struct {
    u32 w[7];
} B28;

extern A48 d_021BEC3C;
extern B28 d_020A1448;
extern char d_021BEAEC[];
extern char d_021BEAFC[];
extern char d_021BEB1C[];
extern char d_021BEB3C[];
extern char d_021BEB5C[];
extern char d_021BEB9C[];
extern char d_021BEBBC[];
extern char d_021BEBDC[];

struct Cfg;
struct DispConfig;
struct DispVram;
extern int func_021B9A84(u32 p);
extern void func_021B7078(const void *p, unsigned id, unsigned type);
extern void func_021B6F0C(u8 *p);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0202223C(u32 a, u32 color);
extern void func_02022224(int a);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207D63C(u32 r, int a, int b, int c, int d);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02061C30(void);

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)

static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (u32)((reg_GX_DISPCNT & ~0x1f00) | (plane << 8));
}

static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (u32)((reg_GXS_DB_DISPCNT & ~0x1f00) | (plane << 8));
}

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~0x8000) | (sel << 15));
}

void func_021B6D90(u8 *p)
{
    A48 a;
    B28 b;

    a = d_021BEC3C;
    if (func_021B9A84((u32)p) == 1) {
        a.w[6] = 8;
        a.w[8] = 0;
    } else {
        a.w[6] = 0x100;
    }
    func_020434CC();
    func_02043588();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_02022224(0);
    func_02022224(1);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0((const struct DispVram *)(&a));
    func_0203F8F4(*(u16 *)p);
    func_02045088(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021BEAEC);
    func_021B7078(d_021BEBDC, 3, 0);
    func_021B7078(d_021BEBBC, 2, 0);
    func_021B7078(d_021BEB9C, 1, 0);
    func_021B7078(d_021BEB5C, 7, 0);
    func_021B7078(d_021BEB3C, 6, 0);
    func_021B7078(d_021BEB1C, 5, 0);
    func_021B7078(d_021BEAFC, 4, 0);
    func_021B6F0C(p);
    func_0207D63C(0x04000050, 0x14, 8, 0x10, 10);
    func_0207D63C(0x04001050, 4, 8, 0x10, 10);
    func_02040618(2, 0, 0x80);
    func_02040618(1, 0, 0x80);
    b = d_020A1448;
    func_0204A48C((const struct Cfg *)(&b), (u32)(&a), *(u16 *)p);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02061C30();
}
