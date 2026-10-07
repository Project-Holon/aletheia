/*
 * function: func_021850A0
 * address: 0x021850A0
 * packet: pkt_ov023_021850A0
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: the activation tail is an inline returning its flag value;
 * assigning the returned u8 to k recolours the merged flag store to r1.
 * The pointer-out helper and inline assignment stayed DIFF by two bytes.
 * symbols:
 *   d_02186AFC     0x02186AFC  data  ov023  a4
 *   d_02186AB4     0x02186AB4  data  ov023  a4
 *   func_02035C08  0x02035C08  arm
 *   func_02035BA4  0x02035BA4  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035C38  0x02035C38  arm
 *   func_02039338  0x02039338  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021852B4  0x021852B4  thumb  ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_0218506C  0x0218506C  thumb  ov023
 *   func_021864C4  0x021864C4  thumb  ov023
 *   func_02185080  0x02185080  thumb  ov023
 *   func_02186988  0x02186988  thumb  ov023
 *   func_021868C8  0x021868C8  thumb  ov023
 *   func_02186888  0x02186888  thumb  ov023
 */
#include "../../../matched/include/Obj00525.h"
#include "../../../matched/include/Obj01221.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 n;
    u16 a;
    u16 b;
    u16 pad;
} Ent;

typedef struct {
    Ent e[8];
    u16 tail;
} Path;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Rec;

extern char d_02186AFC[];
extern char d_02186AB4[];

extern int  func_02035C08(const void *p);
extern int  func_02035BA4(const void *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int  func_02035C38(void);
extern u16 func_02039338(void);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020061E4(u32 a);
extern void func_021852B4(u32 *p, int n);
extern int  func_02186558(char *p);
extern void func_021861C4(u8 *w, u32 msg, int mode);
extern void func_02186444(char *p, u32 v);
extern void func_021852F4(void *p, int flag);
extern void func_0218506C(void *actor, int x, int y);
extern void func_021864C4(Rec *d, Ent *s, int a, int c);
extern void func_02185080(Rec *d, int a, int c);
extern void func_02186988(Rec *d, char *q, int z);
extern void func_021868C8(char *p);
extern void func_02186888(char *p);

static inline u8 activate(char *p, int value)
{
    func_021861C4((u8 *)p, value, value);
    func_02186444(p, 5);
    func_021852F4((void *)(((struct Obj00525 *)p)->f100), 1);
    func_020061E4(0x551);
    return value;
}

void func_021850A0(char *p)
{
    Path path;
    int tx;
    int ty;
    Rec rec;
    int x;
    int y;
    u8 k;
    int r;
    int i;

    k = 0;
    r = func_02035C08(d_02186AFC);
    if (r != -1) {
        switch (r) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (((struct Obj01221 *)p)->f420A != r) {
                ((struct Obj01221 *)p)->f420A = r;
                func_021852B4((u32 *)(p + 0xd0), r);
                func_020061E4(0x548);
            }
            break;
        case 8:
            if (((struct Obj01221 *)p)->f198 != 4)
                break;
            if (func_02039338() == 0) {
                if (((struct Obj01221 *)p)->f1B0 != func_02186558(p)) {
                    func_020061E4(0x54b);
                } else {
                    ((struct Obj01221 *)p)->f9E6C = 2;
                    k = activate(p, 1);
                }
            } else {
                if (((struct Obj01221 *)p)->f4217 == 2) {
                    func_020061E4(0x54b);
                } else {
                    k = activate(p, 1);
                }
            }
            break;
        case 9:
        case 10:
        case 11:
            for (i = 0; i < 3; i++) {
                if (r - 9 == i)
                    func_0204B878((struct Obj *)(*(u32 *)(p + 0xf4 + i * 4)), i * 2 + 0x1e);
                else
                    func_0204B878((struct Obj *)(*(u32 *)(p + 0xf4 + i * 4)), i * 2 + 0x1d);
            }
            if (((struct Obj01221 *)p)->f420B != r - 9) {
                ((struct Obj01221 *)p)->f420B = r - 9;
                func_020061E4(0x548);
            }
            break;
        }
    }
    r = func_02035BA4(d_02186AB4);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0x60 + func_02039338() * 4), 0);
    if (r != -1) {
        func_02035CB8((u32 *)(&tx), (u32 *)(&ty));
        func_0218506C((void *)(*(int *)(p + 0x60 + func_02039338() * 4)), tx, ty);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x60 + func_02039338() * 4), 1);
    }
    x = 0;
    y = 0;
    if (func_02035C38() == 1) {
        func_02035CB8((u32 *)(&x), (u32 *)(&y));
        path.e[0].n = 2;
        path.e[0].a = ((Path *)(p + 0x4244))->e[1].a;
        path.e[0].b = ((Path *)(p + 0x4244))->e[1].b;
        path.e[1].a = x;
        path.e[1].b = y;
        func_021864C4(&rec, path.e, ((struct Obj01221 *)p)->f420A, ((struct Obj01221 *)p)->f420B);
        if (k == 1)
            rec.mid = 0;
    } else {
        path.e[1].a = 0;
        path.e[1].b = 0;
        func_02185080(&rec, ((struct Obj01221 *)p)->f420A, ((struct Obj01221 *)p)->f420B);
    }
    func_02186988(&rec, p + 0x928c, 0);
    if (func_02039338() == 0)
        func_021868C8(p + 0x928c);
    else
        func_02186888(p + 0x928c);
    *(Path *)(p + 0x4244) = path;
}
