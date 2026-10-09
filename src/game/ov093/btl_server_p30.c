/*
 * file:     btl_server_p30.c
 * unit:     yes
 * function: func_021BFE60, func_021BFEAC, func_021BFF60
 * address:  0x021BFE60
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
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021D5C08  0x021D5C08  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C60EC  0x021C60EC  thumb  ov093
 *   func_021C0780  0x021C0780  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C2910  0x021C2910  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C000C  0x021C000C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj00003.h"

struct Unk021D62A8;
struct UtilWork;
struct Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Word;

extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern u32 func_021D5C08(struct UtilWork *p);
extern void func_021C6110(u8 *p, u8 *a, unsigned int n);
extern int func_021D5B68(void *p);
extern u32 func_021D6D7C(u8 *p);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern u8 func_021D5440(u8 *p);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern void func_021C0780(u8 *p, u8 *a, int i, u8 v);
extern Word func_021E899C(u32 a);
extern void func_021C2910(u8 *p, u8 *a, u8 *b, int k, Word e, int f, int g, int h);
extern void func_021CD64C(void *w, u8 id, ...);
extern u8 func_021D69AC(u8 *a, int i);
extern u8 *func_021B9934(char *p, int i);
extern int func_021C000C(u8 *p, int k);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5D88(u8 *p, u8 *a, int b);
void func_021BFE60(u8 *p, u8 *a);
int func_021BFEAC(u8 *p, u8 *a, u8 *b, int *out);
void func_021BFF60(u8 *p, u8 *a, int z);



void func_021BFE60(u8 *p, u8 *a)
{
    int k = 0x1a;
    u32 r;
    if (func_021D62C4((struct Unk021D62A8 *)a, k) != 0) {
        func_021C5620(p, a, k, 0);
        func_021D5FC0((struct UtilWork *)a, 0xb);
    }
    r = func_021D5C08((struct UtilWork *)a);
    while (r != 0x10) {
        func_021C6110(p, a, r);
        r = func_021D5C08((struct UtilWork *)a);
    }
}



int func_021BFEAC(u8 *p, u8 *a, u8 *b, int *out)
{
    u8 n;
    Word t;
    *out = 0;
    if (func_021D5B68(b) == 0 && func_021D6D7C(b) == 0 && func_021D5C30((struct UtilWork *)b) == 0) {
        if (func_021D5BB0((struct UtilWork *)b, 7) == 0) {
            n = func_021D5440(b);
            func_021C60EC(p, a, 3);
            func_021C60EC(p, b, 3);
            func_021C0780(p, a, 4, n + 1);
            t = func_021E899C(func_021D5440(a));
            func_021C2910(p, b, a, 0x21, t, 0, 0, 0);
            return 1;
        }
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x20b, func_021D5440(b), 0xffff0000);
        *out = 1;
    }
    return 0;
}


void func_021BFF60(u8 *p, u8 *a, int z)
{
    u8 k;
    int n;
    u8 *w;
    n = func_021D69AC(a, 4);
    if (n == 0) goto bad;
    k = n - 1;
    if (k < 0x18) goto ok;
bad:
    k = 0x1f;
ok:
    if (k != 0x1f) {
        w = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, k);
        if (func_021D62C4((struct Unk021D62A8 *)w, 0x21) != 0) {
            func_021C5620(p, w, 0x21, 0);
            func_021C6110(p, w, 3);
            if (func_021C000C(p + 0x1ab8, k) != 0) {
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x31, k, 0);
                func_021C5D88(p, w, 0x465);
            }
        }
        func_021C0780(p, a, 4, 0);
        k = 0;
        if (z == 0 && func_021D5B68(a) == 0) {
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x31, func_021D5440(a), k);
        }
    }
}
