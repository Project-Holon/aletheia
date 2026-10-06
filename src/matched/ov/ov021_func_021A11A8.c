/*
 * function: ov021_func_021A11A8
 * address:  0x021A11A8
 * packet:   pkt_ov021_021A11A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020414AC  0x020414AC  arm
 *   func_0204152C  0x0204152C  arm
 *   func_02043598  0x02043598  arm
 *   func_021A836C  0x021A836C  thumb  ov021
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_02024A20  0x02024A20  thumb
 *   func_021A8AFC  0x021A8AFC  thumb  ov021
 *   d_021D8708     0x021D8708  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
extern unsigned char d_021D8708[];
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Obj;
extern void *func_02188C80(void *p);
struct Ctx;
extern unsigned char *func_020120F8(const struct Ctx *);
struct Rec44;
extern u16 func_02012AC8(const struct Rec44 *);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_0204152C(int channel, u16 val);
extern void func_02043598(u32, u32);
extern struct Obj *func_021A836C(u16 heap, u16 a1, int a2, void *a3, int a4);
extern u32 func_021A8B18(void *a, void *b, u32 c);
extern void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
extern void func_021A8AFC(int a, int b);

void ov021_func_021A11A8(u32 *p, u32 x)
{
    u32 a, b, c, d;
    u32 f;
    a = (u32)func_02188C80((void *)p[5]);
    b = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    c = (u32)func_020120F4((const struct Ctx *)a);
    d = func_0201296C((const struct BigObj *)c);
    f = 0;
    if (x == 0 || x - 2 <= 4)
        f = 1;
    func_0203FCA0(4, (const struct BgTemplate *)d_021D8708, 0);
    func_02040588(4, 1);
    func_020414AC(4);
    func_0204152C(4, 0);
    func_02043598(0x10, 1);
    p[8] = (u32)func_021A836C(0x70, ((u16 *)p)[6], (int)p, (void *)p[5], f);
    if (func_021A8B18((void *)c, (void *)d, b) != 1)
        func_02024A20(4, 0xe, (void *)c, ((u16 *)p)[6]);
    func_021A8AFC(((u16 *)p)[6], f);
}
