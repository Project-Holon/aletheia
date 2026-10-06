/*
 * function: func_021AEF10
 * address:  0x021AEF10
 * packet:   pkt_ov021_021AEF10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02028A58  0x02028A58  thumb
 *   func_02159144  0x02159144  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *a);
extern unsigned int func_02159B10(void *a, void *b);
typedef unsigned short u16;
struct SoundSys;
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void func_02159144(int n);

int func_021AEF10(u32 a, u32 b)
{
    u32 y, z;
    void *x;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4(x);
    func_0201210C((void *)x);
    y = func_02012A30((const struct BigObj *)y);
    z = func_02159B10((void *)a, (void *)b);
    func_02028A58((struct SoundSys *)y, z, (u8)func_02159B10((void *)a, (void *)b));
    func_02159144(12);
    return 0;
}
