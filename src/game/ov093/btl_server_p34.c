/*
 * file:     btl_server_p34.c
 * unit:     yes
 * function: func_021C08CC, func_021C091C
 * address:  0x021C08CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5608  0x021D5608  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D56CC  0x021D56CC  thumb  ov093
 *   func_021C19D8 0x021C19D8 thumb ov093
 *   func_021C0A1C 0x021C0A1C thumb ov093
 *   func_021C71E0 0x021C71E0 thumb ov093
 *   func_021C14E0 0x021C14E0 thumb ov093
 *   func_021C0A2C 0x021C0A2C thumb ov093
 *   func_021C1194 0x021C1194 thumb ov093
 *   func_021C0A3C 0x021C0A3C thumb ov093
 *   func_021C0F24 0x021C0F24 thumb ov093
 *   func_021C0D90 0x021C0D90 thumb ov093
 *   func_021C2048 0x021C2048 thumb ov093
 *   func_021C1A54 0x021C1A54 thumb ov093
 *   func_021BFBD0 0x021BFBD0 thumb ov093
 */
#include "../../matched/include/Obj09966.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj04358.h"

struct UtilWork;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct State { u8 pad[5]; u8 a:1; u8 b:1; };

extern int func_021B911C(void *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021D5608(struct UtilWork *p, int i, u8 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D56CC(struct Work *p, int i);
extern void func_021C19D8(u8 *, u8 *, u8 *);
extern void func_021C0A1C(u8 *);
extern int func_021C71E0(u8 *, u8 *, u32, u8 *);
extern void func_021C14E0(u8 *, u8 *, int, u8 *);
extern int func_021C0A2C(u8 *);
extern u8 func_021C1194(u8 *p);
extern int func_021C0A3C(u8 *);
extern u32 func_021C0F24(u8 *, u8 *, u8 *, u8 *, u32);
extern u32 func_021C0D90(u8 *, u8 *, u8 *, u8 *, u32, u32 *, u32);
extern void func_021C2048(u8 *, u8 *, u32, u32);
extern void func_021C1A54(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern void func_021BFBD0(u8 *, u32, u8 *, u32);
void func_021C08CC(u8 *p, u8 *a, int b, u8 c);
void func_021C091C(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 d);


void func_021C08CC(u8 *p, u8 *a, int b, u8 c)
{
    u32 n;
    if (func_021B911C(((struct Obj09966 *)p)->f4, 5) == 0) {
        n = func_021D5440(a);
        func_021D5608((struct UtilWork *)a, b, c);
        func_021CD4B0(((struct Obj09966 *)p)->fC, 4, n, b, c);
        func_021D56CC((struct Work *)a, b);
        func_021CD4B0(((struct Obj09966 *)p)->fC, 6, n, b);
    }
}

void func_021C091C(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 d)
{
    u32 result = 0;
    int flag = 0;
    u32 out;
    p[0x1fe9] = 0;
    func_021C19D8(p, a, q);
    func_021C0A1C(*(u8 * *)&((struct Obj00003 *)p)->f860);
    func_021C71E0(p, a, ((struct Obj04358 *)q)->f0, *(u8 * *)&((struct Obj00003 *)p)->f4B4);
    func_021C14E0(p, a, (int)q, b);
    if (func_021C0A2C(b) != 0) {
        if (func_021C1194(*(u8 * *)&((struct Obj00003 *)p)->f4B4) != 0 && func_021C0A3C(b) == 1) {
            result = func_021C0F24(p, q, a, b, c);
        } else {
            result = func_021C0D90(p, q, a, b, c, &out, d);
            flag = 1;
        }
        func_021C2048(p, a, ((struct Obj04358 *)q)->f0, result);
    }
    func_021C1A54(p, q, a, *(u8 * *)&((struct Obj00003 *)p)->f860, result, d);
    if (flag != 0) {
        struct State *s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        func_021BFBD0(p, ((struct Obj04358 *)q)->f0, *(u8 * *)&((struct Obj00003 *)p)->f4A8, out);
    }
}
