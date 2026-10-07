/*
 * file:     btl_server_p146.c
 * unit:     yes
 * function: func_021D0B6C, func_021D0BB0
 * address:  0x021D0B6C
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
 *   func_021D8394  0x021D8394  thumb  ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B99C0 0x021B99C0 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 */
#include "../../matched/include/Obj13365.h"
#include "../../matched/include/Obj03198.h"

struct Q1;
struct S2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021D8394(void *dst, u8 a, u8 b);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B99C0(void *, int);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
void func_021D0B6C(u8 *g, u8 *s);
void func_021D0BB0(u8 *p);


void func_021D0B6C(u8 *g, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        func_021D8394(g + 0x124 + i * 4, s[i + 3], s[i]);
    *(u8 * *)&((struct Obj13365 *)g)->fD8 = g + 0x124;
    ((struct Obj13365 *)g)->fDC = s[6] << 2;
}

void func_021D0BB0(u8 *p)
{
    u8 pair[2];
    u8 start;
    u8 count;
    u32 n;
    u32 i;
    u32 j;
    count = 0;
    n = func_021B9B94(((struct Obj03198 *)p)->f118);
    start = func_021B99C0(((struct Obj03198 *)p)->f0, p[0x1a6]);
    for (i = 0; i < p[0x1b3]; i++) {
        func_021B8E28(*(u8 * *)&((struct Obj03198 *)p)->f0, p[0x1b5 + i], &pair[1], &pair[0]);
        for (j = start; j < n; j++) {
            if (!func_021D5B68(func_021B9C00(((struct Obj03198 *)p)->f118, (u8)j))) {
                func_021D8394(p + 0x124 + count++ * 4, pair[0], j);
                start = j + 1;
                break;
            }
        }
    }
    ((struct Obj03198 *)p)->fD8 = p + 0x124;
    ((struct Obj03198 *)p)->fDC = count * 4;
}
