/*
 * function: func_021BBD0C
 * address:  0x021BBD0C
 * packet:   pkt_ov099_021BBD0C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_021BBC34  0x021BBC34  thumb  ov099
 *   func_021BBE50  0x021BBE50  thumb  ov099
 *   func_02049238  0x02049238  arm
 */

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0201BC3C(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_021BBC34(char *p, void *a, int k, u32 o);
extern void func_021BBE50(void *p);
extern void func_02049238(void *o);

void func_021BBD0C(char *p, int a, int b)
{
    void *o;
    int t;

    o = func_020490F4(7, 0x21);
    *(void **)(p + 0x148) = (void *)func_0204ACEC(o, func_0201BC3C(), 0, 0x160, 0x21);
    t = func_0201BC78();
    *(void **)(p + 0x14C) = (void *)func_0204AF28(o, t, func_0201BCB4(), 0x21);
    func_021BBC34(p, (void *)a, 0, (u32)o);
    func_021BBC34(p, (void *)b, 6, (u32)o);
    func_021BBE50(p);
    func_02049238(o);
}
