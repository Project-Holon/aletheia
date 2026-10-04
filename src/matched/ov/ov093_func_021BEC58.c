/*
 * function: func_021BEC58
 * address: 0x021BEC58
 * packet: pkt_ov093_021BEC58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * budget: 2 iteration one; scheduling variant1/2 consumed; no checks/permuter.
 * symbols:
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021BEC2C 0x021BEC2C thumb ov093
 *   func_021BFC08 0x021BFC08 thumb ov093
 *   func_021BEFEC 0x021BEFEC thumb ov093
 *   func_021BEFFC 0x021BEFFC thumb ov093
 *   func_021BF00C 0x021BF00C thumb ov093
 *   func_021BF01C 0x021BF01C thumb ov093
 *   func_021BF02C 0x021BF02C thumb ov093
 *   func_021BF03C 0x021BF03C thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C65A8 0x021C65A8 thumb ov093
 *   func_021BFBD0 0x021BFBD0 thumb ov093
 *   func_021BF04C 0x021BF04C thumb ov093
 *   func_021BF0E4 0x021BF0E4 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021BF83C 0x021BF83C thumb ov093
 *   func_021CC8A0 0x021CC8A0 thumb ov093
 *   func_021BF168 0x021BF168 thumb ov093
 *   func_021BF3D8 0x021BF3D8 thumb ov093
 *   func_021BF4AC 0x021BF4AC thumb ov093
 *   func_021BF8D4 0x021BF8D4 thumb ov093
 *   func_021BF1B4 0x021BF1B4 thumb ov093
 *   func_021BF27C 0x021BF27C thumb ov093
 *   func_021C091C 0x021C091C thumb ov093
 *   func_021C2DC4 0x021C2DC4 thumb ov093
 *   func_021C2488 0x021C2488 thumb ov093
 *   func_021C3184 0x021C3184 thumb ov093
 *   func_021C3438 0x021C3438 thumb ov093
 *   func_021C376C 0x021C376C thumb ov093
 *   func_021C3274 0x021C3274 thumb ov093
 *   func_021C3AA8 0x021C3AA8 thumb ov093
 *   func_021C3D08 0x021C3D08 thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021BF244 0x021BF244 thumb ov093
 *   func_021BF2B4 0x021BF2B4 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *
 * Single action/filter pipeline, with flags initialized at EC74..EC7E.
 * All exit paths and switch table mappings retain their original results.
 * CC8D8 returns the full pre-mutation 32-bit Lock (10+9+9+1+1+1+1).
 * ECFA saves all r0 and ED0E/ED14 forwards all r1 to own CC95C's u32
 * store; preserve line inputs 10A8/10AA under original return-use rule.
 * C5718's own one-input body does not erase the original loaded r1/r2.
 * Veneers EFEC/FFC/00C/01C/02C/03C forward respectively to ov095
 * CB3C/CEE4/CD50/CD50/CD50/D050; own matched records fix their widths.
 * Original ED78 branches onto ED7A: duplicated forced=1 arms retain the
 * cross-jumped break. Original EDB0..EDB4 extracts byte bit4, represented
 * by Bits78A. EE44 branches directly to EE6C, skipping C5718 at EE68;
 * only BF02C's true path performs that call before BF27C.
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u16 f0; u8 f2, f3, f4; u8 a:1, b:1, rest:6; };
struct Bits78A { u8 low:4, skip:1, rest:3; };
struct Buf { u32 wpos, rpos; };
struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };
struct Rec { u32 value; u16 kind; u8 data, flag; };
struct O { u32 pos; struct Rec r[120]; };
extern u32 func_0201C1BC(u16);
extern u32 func_0201BEB8(u16, u32);
extern u8 func_021D5440(u8 *p);
extern int func_021D5B68(void *);
extern void func_021BEC2C(u8 *p, u8 *a, int c);
extern int func_021BFC08(u8 *, u8 *, u8 *, u16);
extern void func_021BEFEC(void *);
extern void func_021BEFFC(struct S *);
extern int func_021BF00C(struct S *);
extern int func_021BF01C(struct S *);
extern int func_021BF02C(struct S *);
extern void func_021BF03C(struct O *);
extern u32 func_021CD4FC(struct Buf *, u32);
extern void func_021BD200(struct State *, u8 *, u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *, u32, int);
extern int func_021C65A8(u8 *, u8 *, u32, u8 *);
extern void func_021BFBD0(u8 *, u32, u8 *, u32);
extern void func_021BF04C(u8 *, u16 *, int, int);
extern void func_021BF0E4(int, u8 *, int, u8 *, int);
extern void func_021C5718(u8 *, u8 *, u32);
extern void func_021BF83C(u8 *, u16 *, u8 *, int);
extern void func_021CC8A0(void *);
extern int func_021BF168(u8 *, u16 *, u8 *);
extern void func_021BF3D8(u8 *, int, u8 *, int, void *);
extern void func_021BF4AC(u8 *, u8 *, u8 *, void *, void *);
extern void func_021BF8D4(u8 *, u16 *, u8 *, int);
extern void func_021BF1B4(int, u16 *, int, int, int);
extern void func_021BF27C(u8 *, u32, u32);
extern void func_021C091C(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern void func_021C2DC4(u8 *, u32, u32, u32);
extern void func_021C2488(u8 *, u16, u8 *, u32);
extern void func_021C3184(u8 *, const u16 *, u32, u32);
extern void func_021C3438(u8 *, u16 *, u8 *, u8 *);
extern void func_021C376C(u8 *, u16, int, int);
extern void func_021C3274(u8 *, u32, u32, u32);
extern void func_021C3AA8(u8 *, u16 *, u8 *);
extern void func_021C3D08(u8 *, u16 *, u8 *, u8 *);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern void func_021BF244(u8 *, u32, u32);
extern void func_021BF2B4(u8 *, u32, u32);
extern int func_021C4F64(u8 *, u8 *);

int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d)
{
    u32 lock;
    u32 action = func_0201C1BC(key);
    u8 id = func_021D5440(a);
    int active = 1;
    int execute = 0;
    int forced = 0;
    u32 pos;
    int result;
    struct State *s;
    func_021BEC2C(p, a, key);
    if (func_0201BEB8(key, 1)) {
        switch (func_021BFC08(p, a, d, key)) {
        case 0: break;
        case 1: return execute;
        case 2: return active;
        case 3: return execute;
        case 4: break;
        }
    }
    func_021BEFEC(((struct Obj00003 *)p)->f860);
    pos = func_021CD4FC(*(struct Buf * *)&((struct Obj00003 *)p)->fC, 0x30);
    func_021BD200(*(struct State * *)&((struct Obj00003 *)p)->f4A8, p, a, (int)d);
    lock = func_021CC8D8(p + 0x1d74, 0x10a8);
    result = func_021C65A8(p, a, key, d);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 0x10aa);
    if (result != 0) {
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a == 0) s->a = 1;
        if (result == 2) {
            func_021BFBD0(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
            return 1;
        }
    }
    switch (action) {
    case 0: case 4: case 6: case 7: case 8:
        execute = 1;
        forced = 1;
        break;
    case 9:
        forced = 1;
        break;
    }
    func_021BEFFC((struct S *)d);
    func_021BF04C(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (int)a, (int)d);
    func_021BF0E4((int)p, a, (int)d, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, execute);
    if (func_021BF00C((struct S *)d)) {
        if (((struct Bits78A *)(p + 0x78a))->skip == 0) func_021C5718(p, a, key);
        active = 0;
    }
    if (active != 0) {
        if (action != 9) func_021BF83C(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, (int)d);
        func_021CC8A0(p + 0x1f88);
        if (forced != 0 || func_021BF168(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a))
            func_021BF3D8(p, *(int *)&((struct Obj00003 *)p)->f1AB0, a, (int)d, p + 0x1f88);
        func_021BF4AC(p, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, a, d, p + 0x1f88);
        if (action != 9) func_021BF8D4(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, (int)d);
        if (func_021BF01C((struct S *)d)) {
            func_021BF27C(p, id, key);
            active = 0;
        } else {
            func_021BF1B4((int)p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (int)a, (int)d, forced);
            if (func_021BF02C((struct S *)d)) {
                func_021C5718(p, a, key);
                func_021BF27C(p, id, key);
                active = 0;
            }
        }
    }
    if (active != 0) {
        if (execute != 0) {
            func_021C091C(p, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, a, d, (u32)(p + 0x1f88), 0);
        } else {
            switch (action) {
            case 2: func_021C2DC4(p, *(u32 *)&((struct Obj00003 *)p)->f1AB0, (u32)a, (u32)d); break;
            case 1: func_021C2488(p, key, a, (u32)d); break;
            case 5: func_021C3184(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (u32)a, (u32)d); break;
            case 9: func_021C3438(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, d); break;
            case 12: func_021C376C(p, key, (int)a, (int)d); break;
            case 3: func_021C3274(p, key, (u32)a, (u32)d); break;
            case 10: func_021C3AA8(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a); break;
            case 11: case 13: func_021C3D08(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, d); break;
            }
        }
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a != 0) {
            if (s->b == 0) func_021BFBD0(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
            func_021BF03C((struct O *)(p + 0x1c));
            if (!func_021D5B68(a) && func_0201BEB8(key, 2)) func_021C60EC(p, a, 12);
            func_021BF244(p, id, key);
        } else {
            func_021BF27C(p, id, key);
            active = 0;
        }
    } else {
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a != 0) func_021BFBD0(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
    }
    func_021BF2B4(p, id, key);
    func_021C4F64(p, a);
    return active;
}
