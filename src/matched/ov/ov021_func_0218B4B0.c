/*
 * function: func_0218B4B0
 * address:  0x0218B4B0
 * packet:   pkt_ov021_0218B4B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the object's grid position, and when the tile attribute in front
 * allows it (func_021AB194) steps it one tile in its facing direction, then
 * moves the camera object there (func_0216DDDC).
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb
 *   func_021A3460  0x021A3460  thumb
 *   func_02164294  0x02164294  thumb  ov010
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB194  0x021AB194  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02164240  0x02164240  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

extern void *func_021A3074(u8 *p);
extern void func_021A3460(void *p, s16 *x, s16 *y, s16 *z);
extern void func_02164294(int x, int y, int z, int *out);
extern void *func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB194(u16 id);
extern u16 func_0216D5F8(void *p);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void *func_02188C7C(u8 *p);
extern u32 func_0216D8AC(void *p);
extern int func_0216DDDC(void *p, int x, int z, int h, int a, int b);

int func_0218B4B0(struct FieldCtx *p, u8 *pos)
{
    void *obj = func_021A3074(p->f18);
    s16 v[3];
    int xyz[3];
    void *cam;

    func_021A3460(p->f18, &v[2], &v[1], &v[0]);
    func_02164294(v[2], v[1], v[0], xyz);
    if (func_021AB194(func_021AB0F0(func_021AB0D4(func_02188C98(pos), xyz))) == 1)
        func_02164240(func_0216D5F8(obj), &v[2], &v[0], 1);
    cam = func_02188C7C(pos);
    return func_0216DDDC(cam, v[2], v[0], func_0216D8AC(obj), 0x10000, 0);
}
