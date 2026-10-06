/*
 * function: ov021_func_021A1244
 * address:  0x021A1244
 * packet:   pkt_ov021_021A1244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_02024DCC  0x02024DCC  thumb
 *   func_021A84BC  0x021A84BC  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
struct BigObj;
struct Ctx;
struct Obj;
extern void *func_02188C80(void *p);
struct Ctx;
extern unsigned char *func_020120F8(const struct Ctx *p);
struct Rec44;
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_021A8B18(void *a, void *b, u32 c);
extern int func_02024DCC(void);
extern void func_021A84BC(struct Obj *p);
extern void func_020403F4(u32);

void ov021_func_021A1244(u32 *p)
{
    u32 a, b, c;
    a = (u32)func_02188C80((void *)p[5]);
    b = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    c = (u32)func_020120F4((const struct Ctx *)a);
    if (func_021A8B18((void *)c, (void *)func_0201296C((const struct BigObj *)c), b) != 1)
        func_02024DCC();
    func_021A84BC((struct Obj *)p[8]);
    func_020403F4(4);
}
