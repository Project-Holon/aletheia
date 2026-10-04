/*
 * function: func_021F1BFC
 * address: 0x021F1BFC
 * packet: pkt_ov194_021F1BFC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF, 33 bytes, size equal (348). Everything matches except the Vec2 temp at
 *   the tail. Original computes `add r4,sp,#0x18` (field accesses) and a second copy `add r7,sp,#0x18`
 *   (kept live in r7, passed as 2nd arg of both func_0204B404 calls, 3rd arg 0 in r2). Ours keeps
 *   `movs r7,#0` and rematerialises `add r1,sp,#0x18` per call. Tried: `struct Vec2 *vp = &v` at top,
 *   vp for the field accesses, s16 v[2] cast, vp assigned between the 0xAE load and the subtract.
 *   Levers that mattered: explicit `case 0: break;`, `d` declared before `c`, `(*(u16 *)(p+0x80))++ > 10`
 *   (two loads), `a = (u16 *)p; a += 0x20;` (reproduces the dead spill pair).
 *   Callee func_021F1D58 (ov194, 208 bytes) has no source yet: prototype guessed from the call.
 * symbols:
 *   func_021F1A1C 0x021F1A1C thumb ov194
 *   func_021F1D58 0x021F1D58 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_02040804 0x02040804 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021F5780 0x021F5780 data a4 ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Rect { int left, top, right, bottom; } Rect;
struct Vec2 { s16 x, y; };
struct Obj;
extern u32 d_021F5780[];
extern void func_021F1A1C(char *p, int mode, const Rect *rect, int flag, int selected);
extern void func_021F1D58(u16 *a, u16 *b, u32 c, u32 d, u8 i, u16 e, u16 f);
extern u8 func_020355C4(void);
extern u32 func_02040804(u32 layer);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021F1BFC(char *p, int sel, const Rect *rect)
{
    struct Vec2 v;
    u32 d, c;
    int i;
    if (*(u32 *)(p + 0x98) != 0) {
        u16 *a, *b;
        switch (*(u32 *)(p + 0x94)) {
        case 0:
            break;
        case 1:
            d = 2;
            c = (u16)d_021F5780[0];
            break;
        case 2:
            d = 3;
            c = 0x1999;
            if ((*(u16 *)(p + 0x80))++ > 10) {
                if (func_020355C4() == 0)
                    func_021F1A1C(p, 1, rect, *(int *)(p + 0x9C), sel);
                else
                    func_021F1A1C(p, 0, rect, *(int *)(p + 0x9C), sel);
            }
            break;
        }
        a = (u16 *)p;
        a += 0x20;
        b = (u16 *)p;
        b += 0x30;
        for (i = 0; i < 16; i++)
            func_021F1D58(a + i, b + i, c, d, i, ((u16 *)p)[i], ((u16 *)p)[i + 0x10]);
    }
    v.x = *(u16 *)(p + 0xAC);
    v.y = *(u16 *)(p + 0xAE);
    v.y = v.y - (s16)(func_02040804(2) << 3);
    func_0204B404(*(struct Obj **)(p + 0xA4), &v, 0);
    v.x = *(u16 *)(p + 0xB0);
    v.y = *(u16 *)(p + 0xB2);
    v.y = v.y - (s16)(func_02040804(2) << 3);
    func_0204B404(*(struct Obj **)(p + 0xA8), &v, 0);
    if (*(int *)(p + 0xA0) != sel) {
        if (func_020355C4() == 0)
            func_021F1A1C(p, 1, (const Rect *)(p + 0x84), *(int *)(p + 0x9C), sel);
        else
            func_021F1A1C(p, 0, (const Rect *)(p + 0x84), *(int *)(p + 0x9C), sel);
    }
}
