/*
 * file:     btl_server_p07.c
 * unit:     yes
 * function: func_021C0898, func_021C08CC, func_021C091C, func_021C0A4C
 * address:  0x021C0898
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
 *   func_021D5584 0x021D5584 thumb ov093
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
 *   func_021C0C04 0x021C0C04 thumb ov093
 *   func_021C0C14 0x021C0C14 thumb ov093
 *   func_021C0C24 0x021C0C24 thumb ov093
 *   func_021C6BF8 0x021C6BF8 thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   func_021C1E74 0x021C1E74 thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021C15D4 0x021C15D4 thumb ov093
 *   func_021C1678 0x021C1678 thumb ov093
 *   func_021C7C24 0x021C7C24 thumb ov093
 */
#include "../../matched/include/Obj09966.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj04358.h"
#include "../../matched/include/Obj21063.h"

struct UtilWork;
struct Work;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct State { u8 pad[5]; u8 a:1; u8 b:1; };

struct Entry { u16 value; u16 id:5; u16 mode:4; u16 type:4; u16 marked:1; u16 special:1; u16 error:1; };

struct List { u8 good, bad, count, pad; struct Entry entries[1]; };

extern u32 func_021D5584(struct UtilWork *p, u32 i);
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
extern void func_021C0C04(u8 *);
extern u8 *func_021C0C14(u8 *);
extern u8 *func_021C0C24(u8 *);
extern int func_021C6BF8(u8 *p, u8 *a, u8 *b, u16 q);
extern u32 func_021CC8B8(u32 *p, u32 i);
extern int func_021C1E74(u8 *, u8 *, u8 *, const u8 *, u32, u16, u32, u32, u16 *);
extern u32 func_021D6D7C(u8 *p);
extern u32 func_021C15D4(void *p, u32 n);
extern int func_021C1678(u8 *, u8 *, u8 *, u32, u16 *);
extern void func_021C7C24(u16 *, int, u8 *, u8 *, int);
int func_021C0898(u8 *p, u8 *a, u32 b, u8 c);
void func_021C08CC(u8 *p, u8 *a, int b, u8 c);
void func_021C091C(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 d);
void func_021C0A4C(u8 *p, u8 *a, u8 *b, const u8 *q, const u32 *c, u16 k, struct List *out);


int func_021C0898(u8 *p, u8 *a, u32 b, u8 c)
{
    u8 limit = func_021D5584((struct UtilWork *)a, b);
    if (c >= limit) c = limit;
    if (c != 0) {
        func_021C08CC(p, a, b, c);
        return 1;
    }
    return 0;
}




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

void func_021C0A4C(u8 *p, u8 *a, u8 *b, const u8 *q, const u32 *c, u16 k, struct List *out)
{
    int i = 0;
    u8 *r;
    struct { u16 x, y; } temp;
    out->good = 0;
    out->bad = 0;
    func_021C0C04(b);
    r = func_021C0C14(b);
    if (r != 0) {
        do {
            out->entries[i].id = func_021D5440(r);
            out->entries[i].marked = (u16)func_021C6BF8(p, a, r, (u32)(((struct Obj21063 *)q)->f0));
            out->entries[i].mode = (u16)(int)func_021CC8B8((u32 *)c, (u8)out->entries[i].id);
            out->entries[i].special = (u16)func_021C1E74(p, a, r, q, out->entries[i].mode, k, out->entries[i].marked, 0, &temp.y);
            out->entries[i].value = temp.y;
            if (out->entries[i].special) {
                out->entries[i].marked = 0;
                out->entries[i].mode = 3;
            }
            out->entries[i].error = (u16)func_021D6D7C(r);
            if (!out->entries[i].error) {
                temp.x = func_021C15D4(r, out->entries[i].value);
                out->entries[i].type = (u16)func_021C1678(p, a, r, 1, &temp.x);
                out->entries[i].value = temp.x;
                out->good++;
            } else {
                out->entries[i].value = temp.y;
                out->entries[i].type = 0;
                out->bad++;
            }
            func_021C7C24((u16 *)(p + 0x1f7c), (int)p, a, r, out->entries[i].mode);
            i++;
            r = func_021C0C24(b);
        } while (r != 0);
    }
    out->count = i;
}
