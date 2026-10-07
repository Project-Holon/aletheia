/*
 * file:     tr_ai_p07.c
 * unit:     yes
 * function: func_02188CA0, func_02188D48, func_02188D5C, func_02188E00, func_02188E24
 * address:  0x02188CA0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A378  0x0218A378  thumb  ov096
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021E8D04  0x021E8D04  thumb  ov093
 *   func_0201C1D8 0x0201C1D8 thumb
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021C7E14 0x021C7E14 thumb ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021C81C8  0x021C81C8  thumb  ov093
 */
#include "../../matched/include/Obj10177.h"
#include "../../matched/include/Obj13654.h"
#include "../../matched/include/Obj06341.h"

struct Cursor;
struct QG;
struct QL;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xbc - 0x3c];
    u8 *fbc;
    u8 *fc0;
    int fc4;
} Conn;

typedef signed int     s32_02188CA0;

typedef short s16;

typedef signed char s8;

typedef int s32_02188E00;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A378(Conn *, int, int);
extern u16 func_021D57FC(void *p);
extern u8 func_021E8CFC(s32_02188CA0 v);
extern int func_021E8D04(int x);
extern u16 func_0201C1D8(void *p);
extern u8 func_021D5440(u8 *);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
extern u16 func_021D67A8(struct QL *p);
extern int func_0218A0F4(u8 *, int, int, int, int);
extern u16 func_021C81C8(u8 *, u8 *, int);
int func_02188CA0(struct Cursor *a, Conn *b);
int func_02188D48(int a, unsigned char *b);
u32 func_02188D5C(struct Cursor *a, u8 *p);
int func_02188E00(struct Cursor *a, int b);
int func_02188E24(struct Cursor *a, u8 *b);


/*
 * Lever: the source order of the switch arms decides which arm holds the
 *   shared tail and which becomes a stub jump; the original order is
 *   1,0,3,2,4,6,5,8,7 (not ascending).
 */
int func_02188CA0(struct Cursor *a, Conn *b)
{
    u32 k;
    int p;
    int q;

    k = func_0201134C(a);
    p = func_021D57FC(b->fbc);
    q = func_021D57FC(b->fc0);
    switch (k) {
    case 1:
        b->f38 = func_021E8CFC(p);
        break;
    case 0:
        b->f38 = func_021E8CFC(q);
        break;
    case 3:
        b->f38 = func_021E8D04(p);
        break;
    case 2:
        b->f38 = func_021E8D04(q);
        break;
    case 4:
        b->f38 = func_0218A378(b, b->f2, 0);
        break;
    case 6:
        b->f38 = func_021E8CFC(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3))));
        break;
    case 5:
        b->f38 = func_021E8CFC(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 2))));
        break;
    case 8:
        b->f38 = func_021E8D04(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3))));
        break;
    case 7:
        b->f38 = func_021E8D04(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 2))));
        break;
    }
    return b->fc4;
}

int func_02188D48(int a, unsigned char *b) { ((struct Obj10177 *)b)->f38=func_0201C1D8((void *)(((struct Obj10177 *)b)->f2)); return ((struct Obj10177 *)b)->fC4; }

u32 func_02188D5C(struct Cursor *a, u8 *p)
{
    int t = func_0201134C(a);
    u8 x = func_021D5440(*(u8 **)(p + 0xBC));
    u8 y = func_021D5440(*(u8 **)(p + 0xC0));
    u32 best = func_021C7E14(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    int i;
    if (best == 0) {
        *(u32 *)(p + 0x38) = 0;
    } else {
        *(u32 *)(p + 0x38) = 2;
        for (i = 0; i < func_021D5448((struct QG *)(*(u8 **)(p + 0xBC))); i++) {
            u16 c = func_021D54C0(*(u8 **)(p + 0xBC), (u8)i);
            if (i != p[1]) {
                u32 r = func_021C7E14(*(u8 **)(p + 0xB4), x, y, c, 1, t);
                if (r > best) {
                    *(u32 *)(p + 0x38) = 1;
                    break;
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}


int func_02188E00(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D67A8((struct QL *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13654 *)b)->f38 = t;
    return ((struct Obj13654 *)b)->fC4;
}


/*
 * Lever: x is a u16 local from the evidenced u16 callee return. Its word
 * spill reload stays after the outgoing fifth-argument store. All 5
 * relocation sites resolve; trailing two-byte padding is EXACT*.
 */
int func_02188E24(struct Cursor *a, u8 *b)
{
    int k;
    int m;
    u16 x;
    int y;

    k = func_0201134C(a);
    m = func_0201134C(a);
    x = func_021C81C8(*(u8 * *)&((struct Obj06341 *)b)->fB4, *(u8 * *)&((struct Obj06341 *)b)->fBC, 1);
    y = func_021C81C8(*(u8 * *)&((struct Obj06341 *)b)->fB4, *(u8 * *)&((struct Obj06341 *)b)->fC0, 1);
    switch (k) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    }
    func_0218A0F4((u8 *)a, k, x, y, m);
    return ((struct Obj06341 *)b)->fC4;
}
