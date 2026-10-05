/*
 * function: func_021B8CC8
 * address:  0x021B8CC8
 * packet:   pkt_ov172_021B8CC8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets up the BG layers and five OBJ sprites of the screen, then clears the state words.
 * 2026-10-05 (wD8 lane06): closed by statement order of the zero stores. mwcc keeps one constant
 *   of the join block in r7; with the zero stores in the order 0, 8, 0xA4 (address-temp store last)
 *   and 0x38, 0x34, 0x8C, 0xC the constant 1 wins r7 as in the image. Earlier lanes found the
 *   0x15/0x16 if/else for rc.z (holds &rc in r7 for the first block).
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BE010 0x021BE010 thumb ov172
 *   func_021BE018 0x021BE018 thumb ov172
 *   func_021BE024 0x021BE024 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
struct Rect { u16 x; u16 y; u16 z; u8 a; u8 b; };
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_020409B4(u32 layer);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *buf, u8 value);
extern void func_02045374(void *cfg);
extern void func_02045334(void *d);
extern u16 func_021BE00C(void *p);
extern u32 func_021BE010(void *p);
extern u32 func_021BE018(void *p, int i);
extern u32 func_021BE024(void *p);
extern u32 func_021BE0B4(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021BE210(void *a, u32 b);
extern int func_021BA270(void *p);

void func_021B8CC8(void *a, char *p)
{
    u16 h;
    void *g;
    struct Rect rc;

    h = func_021BE00C(a);
    g = (void *)func_021BE010(a);
    func_02049658(g, 0xB, 6, 0, 0, 0, h);
    func_020498F4(g, 0x11, 6, 0, 0, 0, h);
    func_02049658(g, 0xB, 5, 0, 0x5000, 0, h);
    func_020498F4(g, 0xF, 5, 0, 0, 0, h);
    func_0207D63C((void *)0x04001050, 2, 0x14, 5, 0xF);
    func_020409B4(6);
    func_020409B4(5);
    rc.x = 0x80;
    rc.y = 0x60;
    rc.z = *(u8 *)(p + 0xD) + 0x19;
    rc.a = 0;
    rc.b = 2;
    *(struct Obj **)(p + 0x90) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x90), 1);
    if (func_021BE0B4(a) == 1)
        rc.z = 0x15;
    else
        rc.z = 0x16;
    *(struct Obj **)(p + 0x94) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x94), 1);
    rc.z = 0x14;
    *(struct Obj **)(p + 0x9C) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x9C), 1);
    rc.z = 0x18;
    *(struct Obj **)(p + 0xA0) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0xA0), 1);
    rc.x = 0xE8;
    rc.y = 0xA8;
    rc.z = 1;
    rc.a = 0;
    rc.b = 0;
    *(struct Obj **)(p + 0x98) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 6), func_021BE018(a, 2), func_021BE018(a, 10), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x98), 1);
    func_0204B92C(*(struct Obj **)(p + 0x98), 1);
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xA4) = 0;
    *(u32 *)(p + 0xA8) = 3;
    *(u32 *)(p + 0x2C) = func_020450F0(4, 8, 3, 0x10, 8, 0xA, 1);
    *(u32 *)(p + 0x7C) = func_020450F0(4, 1, 1, 0x1E, 4, 0xA, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x2C)), 0);
    func_02045374(*(void **)(p + 0x2C));
    func_02045334(*(void **)(p + 0x2C));
    *(u32 *)(p + 0x80) = 0;
    *(u32 *)(p + 0x84) = 0;
    *(u32 *)(p + 0x28) = 0;
    func_020409B4(4);
    *(u8 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x8C) = 0;
    *(u8 *)(p + 0xC) = 0;
    {
        u32 r = func_021B8B68((int)a, (char *)func_021BDFE4(a));
        if (r != 0xFF) {
            func_021BE210(a, r);
            *(u32 *)(p + 0xA4) = 2;
        }
    }
    if (func_021BA270(*(void **)(p + 0x10)) == 0)
        *(u32 *)(p + 0xA4) = 2;
}
