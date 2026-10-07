/*
 * file:     scrcmd_screeneffects_p20.c
 * unit:     yes
 * function: func_021B0730, func_021B07E0
 * address:  0x021B0730
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D48  0x02188D48  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02188D4C  0x02188D4C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 */
struct Blk34;
struct Ctx;
struct MsgBank;
struct Rec;
struct SaveBlock;
struct U16Vec;
struct WordSet;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188D48(u8 *p);
extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern u32 func_02158F7C(u8 *p);
extern u16 func_02188C84(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190788(u8 *p);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern int func_02190728(void *a);
extern void func_02188D4C(u8 *p, u32 v);
int func_021B0730(u32 a, u32 b);
int func_021B07E0(u32 a, u32 b);


int func_021B0730(u32 a, u32 b)
{
    u32 x, r5, r6, r7, r4, z;
    void *y;
    void *t;

    t = func_0215A5DC((void *)b);
    x = (u32)func_020120F4(t);
    func_020127A4((struct SaveBlock *)x);
    y = func_0201210C(t);
    r5 = func_02188D48(y);
    t = func_0215A5F4((void *)b);
    r6 = (u32)func_02158F74(t);
    r7 = func_02158F7C(t);
    r4 = func_02188C84(y);
    z = (u32)func_02045B38(0, 3, 0x9e, r4);
    r4 = (u32)func_020457B0(0x80, r4);
    func_0201EFA4((struct WordSet *)r6, 2, func_0200C274(func_02012F08((int *)x)), 7, 1, 1);
    func_02045CAC((struct MsgBank *)z, 1, (void *)r7);
    func_0201F250((struct WordSet *)r6, (void *)r4, (void *)r7);
    func_02190788((u8 *)r5);
    func_02190758(r5, 0, 0, r4);
    func_02045808((struct U16Vec *)r4);
    func_02045C04((struct Rec *)z);
    return 0;
}


int func_021B07E0(u32 a, u32 b)
{
    void *x = func_0201210C(func_0215A5DC((void *)b));
    u32 y = func_02188D48(x);

    if (y != 0) {
        func_02190728((void *)y);
        func_02188D4C(x, 0);
    }
    return 0;
}
