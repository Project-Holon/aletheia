/*
 * function: FIELD_RAIL_WORK_UpdateStep
 * address:  0x021B810C
 * packet:   pkt_ov021_021B810C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The table byte is also FIELD_RAIL_WORK_Advance's third argument: the callee's
 * matched prototype is (p, dir, d), and the image leaves the ldrb value in
 * r2 untouched up to the call. That extra use keeps the byte live across
 * the f2D update, so its sign extension lands in a fresh register (r3).
 * See docs/idioms/a-byte-kept-live-into-a-call-argument-register-pushes-its-sign-extension-to-a-fresh-register.md.
 *
 * symbols:
 *   FIELD_RAIL_WORK_IsActive  0x021B91AC  thumb  ov021
 *   FIELD_RAIL_WORK_Advance  0x021B88DC  thumb  ov021
 *   FIELD_RAIL_WORK_DebugCheck  0x021B977C  thumb  ov021
 *   FIELD_RAIL_WORK_GetSpotPos  0x021B91F8  thumb  ov021
 *   func_021B9238  0x021B9238  thumb  ov021
 *   gRailStepSizes     0x021DE298  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } V3;
typedef struct { u16 a; u8 t; u8 c; s16 e; u16 d; } Out;
typedef struct { u16 f0; u16 f2; } Owner;

typedef struct Sub {
    u16 f0;
    u16 pad2;
    void *f4;
    u16 f8;
    u16 padA;
    s32 fC;
    u8 pad10[0x1C];
    u8 f2C;
    s8 f2D;
    u16 f2E;
    u16 f30;
    u8 f32;
    u8 f33;
    u8 f34;
    u8 pad35[3];
    V3 f38;
    V3 f44;
    u8 pad50[0xc];
    Out f5C;
    Out f64;
    u8 pad6C[8];
    u8 f74;
    u8 pad75[3];
    Owner *f78;
} Sub;

extern const u8 gRailStepSizes[];

extern int FIELD_RAIL_WORK_IsActive(u32 a);
extern int FIELD_RAIL_WORK_Advance(Sub *p, int dir, int d);
extern void FIELD_RAIL_WORK_DebugCheck(u8 *p);
extern void FIELD_RAIL_WORK_GetSpotPos(Sub *p, V3 *out);
extern void func_021B9238(Sub *p, Out *out);

void FIELD_RAIL_WORK_UpdateStep(Sub *o)
{
    int res;
    u16 prev;
    u16 k;
    u8 d;
    s32 rem;

    if (o->f78->f2 == 0)
        return;
    if (o->f8 == 0)
        return;
    if (FIELD_RAIL_WORK_IsActive((u32)o) == 0)
        return;
    res = 0;
    o->f34 = 0;
    if (o->f2C == 0)
        return;
    prev = o->f0;
    k = o->f2E;
    d = gRailStepSizes[o->f30];
    o->f2D += (s8)d;
    if (prev == 1)
        res = FIELD_RAIL_WORK_Advance(o, k, d);
    if (res != 0) {
        o->f32 = res;
        o->f33 = o->f30;
        o->f34 = 1;
        FIELD_RAIL_WORK_GetSpotPos(o, &o->f38);
    }
    if (prev != o->f0)
        FIELD_RAIL_WORK_DebugCheck((u8 *)o);
    if (o->f2D < 0x10 && res != 0)
        return;
    o->f2C = 0;
    o->f74 = 0;
    o->f64 = o->f5C;
    func_021B9238(o, &o->f5C);
    o->f44 = o->f38;
    rem = o->fC % 16;
    if (rem == 0)
        return;
    if (rem > 8)
        o->fC = o->fC + (16 - rem);
    else
        o->fC = o->fC - rem;
}
