/*
 * function: func_021B6368
 * address:  0x021B6368
 * packet:   pkt_ov017_021B6368
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A48  0x02082A48  arm
 *   func_02043754  0x02043754  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020437AC  0x020437AC  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0207DFB4(void);
extern u32 func_0207E24C(void);
extern void func_02082A48(int, u32, u32);
typedef signed short   s16;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020437AC(struct Obj020437AC *p);

void func_021B6368(int a)
{
    u16 *base;
    int j, i;
    u16 v;
    int p, q, r, s;

    base = func_0207DFB4();
    v = 0x20;
    for (i = 4; i < 20; i++) {
        for (j = 1; j < 31; j++) {
            base[i * 32 + j] = v;
            v++;
        }
    }
    func_02082A48(0x7777, func_0207E24C() + 0x400, 0x3C00);
    p = (int)func_02043754((void *)(func_0207E24C() + 0x400), 30, 16, 32, 1);
    q = (int)func_0201D7EC(0x17, 0, 0, 0, 1);
    r = (int)func_02045B38(0, 2, 0xe8, 1);
    s = (int)func_02045EC0((struct MsgBank *)r, a);
    func_0201C7D0((void *)p, 0, 0, (void *)s, (void *)q, 0x1167);
    func_02045808((struct U16Vec *)s);
    func_02045C04((struct Rec *)r);
    func_0201D83C((void *)q);
    func_020437AC((struct Obj020437AC *)p);
}
