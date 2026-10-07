/*
 * file:     tr_ai_p10.c
 * unit:     yes
 * function: func_021891F4, func_021892D8
 * address:  0x021891F4
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
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021892F8 0x021892F8 thumb ov096
 */
#include "../../matched/include/Obj21959.h"

struct Cursor;
struct QG;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u8 pad[0x4c]; u16 values[8]; u8 pad2[0xb0-0x5c]; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; } Obj_021891F4;

typedef unsigned int   u32;

typedef struct Obj_021892D8 Obj_021892D8;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021D5B68(void *);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_021892F8(int, Obj_021892D8 *, int);
int func_021891F4(struct Cursor *a, Obj_021891F4 *b, int c);
int func_021892D8(int a, Obj_021892D8 * b);

/*
 * Lever: u16 value/result locals plus result binding give the original cmp operand order.
 * Caller-visible return/second arguments override tail-forwarder declarations.
 */
int func_021891F4(struct Cursor *a, Obj_021891F4 *b, int c)
{
    u16 value, t;
    int k, z, r, i;
    u8 *s;
    int y;
    k = func_0201134C(a);
    value = func_0201134C(a);
    z = func_0201134C(a);
    y = func_0218A160((u8 *)b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < func_021D5448((struct QG *)b->fbc); i++) {
            t = func_021D54C0(b->fbc, (u8)i);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 3:
        s = func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3));
        if (func_021D5B68(s) == 0) {
            for (i = 0; i < func_021D5448((struct QG *)s); i++) {
                t = func_021D54C0(s, (u8)i);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] == value) {
                r = 1;
                break;
            }
        }
        break;
    }
    return func_0218A0F4((u8 *)a, c, r, 1, z);
}

int func_021892D8(int a, Obj_021892D8 * b)
{
    func_021892F8(a, b, 2);
    return ((struct Obj21959 *)((unsigned int)b))->fC4;
}
