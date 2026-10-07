/*
 * file:     field_effect_p14.c
 * unit:     yes
 * function: func_021AA304, func_021AA35C
 * address:  0x021AA304
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
 *   func_02012984  0x02012984  thumb
 *   func_02013ED8  0x02013ED8  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021AA69C  0x021AA69C  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB580  0x021AB580  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB100  0x021AB100  thumb
 *   func_021AB140  0x021AB140  thumb
 *   func_021AB29C  0x021AB29C  thumb
 */
struct BigObj;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct RtcTime { u32 hour; u32 minute; u32 second; };

struct Info {
    u32 f00;
    u32 f04;
    u8 f08;
    u8 f09;
    u16 f0A;
    u8 f0C;
    u8 f0D;
};

extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u8 func_02013ED8(u32 id);
extern u32 func_021A30C8(void **ctx);
extern u16 func_021AB0F0(u32 attr);
extern u8 func_021AB580(u16 x);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_021AA69C(void *p);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_02188C98(u8 *p);
extern int func_021AB100(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB140(int x);
extern int func_021AB29C(u16 x);
void func_021AA304(struct Info *out, void *a1, void *a2);
int func_021AA35C(void **ctx, int mode, u8 *out);


/*
 * Addresses are Black-image addresses.
 */
void func_021AA304(struct Info *out, void *a1, void *a2)
{
    struct RtcTime t;
    u16 x = func_02188C9C(a2);
    void *y = func_02188CB4(a2);

    out->f00 = func_02013ED8(x);
    out->f04 = func_021AB580(func_021AB0F0(func_021A30C8(y)));
    out->f0A = x;
    func_0203F4CC(&t);
    out->f0C = t.hour;
    out->f0D = t.minute;
    out->f08 = func_021AA69C(a2);
    out->f09 = func_02012984(a1);
}


int func_021AA35C(void **ctx, int mode, u8 *out)
{
    void *y = func_02188CB4(ctx[0]);
    u32 attr;
    u16 fl;
    u16 t;

    func_02188C98(ctx[0]);
    *out = 0;
    attr = func_021A30C8(y);
    if (func_021AB100(attr) == 0)
        return 0xFF;
    fl = func_021AB0F8(attr);
    if (mode != 1 && (fl & 4) == 0)
        return 0xFF;
    t = func_021AB0F0(attr);
    if (func_021AB140(t))
        *out += 10;
    if (fl & 2) {
        if (mode == 1)
            return 4;
        return 3;
    }
    if (mode == 1)
        return 2;
    if (func_021AB29C(t))
        return 1;
    return 0;
}
