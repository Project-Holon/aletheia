/*
 * file:     scrcmd_screeneffects_p06.c
 * unit:     yes
 * function: func_021AEE28, func_021AEE78
 * address:  0x021AEE28
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02029A04  0x02029A04  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028BA0  0x02028BA0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02029A74  0x02029A74  thumb
 */
struct Ctx;
struct Stream;
struct BigObj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u16 func_02011330(struct Stream *s);
extern void *func_02029A04(void *a, u32 b, u16 c);
extern void func_0215897C(void *vm, void *task);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *a);
extern void func_02028BA0(u8 *o, u32 v);
extern void func_02159144(int n);
extern void *func_02029A74(void *a, u16 b);
int func_021AEE28(u32 a, u32 b);
int func_021AEE78(u32 a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
int func_021AEE28(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 z;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    z = (u32)func_02029A04(x, func_02011330((struct Stream *)a), func_02011330((struct Stream *)a));
    func_0215897C(y, (void *)z);
    func_02028BA0((u8 *)func_02012A30((const struct BigObj *)func_020120F4(x)), 2);
    func_02159144(13);
    return 1;
}


int func_021AEE78(u32 a, u32 b)
{
    u32 z;
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    z = (u32)func_02029A74(x, func_02011330((struct Stream *)a));
    func_0215897C(y, (void *)z);
    func_02028BA0((u8 *)func_02012A30((const struct BigObj *)func_020120F4(x)), 2);
    func_02159144(13);
    return 1;
}
