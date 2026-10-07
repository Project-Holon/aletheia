/*
 * file:     btl_server_p149.c
 * unit:     yes
 * function: func_021D102C, func_021D1058
 * address:  0x021D102C
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
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021D83FC  0x021D83FC  thumb  ov093
 */
#include "../../matched/include/Obj13368.h"
#include "../../matched/include/Obj13369.h"

struct S2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern unsigned int func_021B8588(void **p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern int func_021B9AB0(int k);
extern void func_021D83FC(u32 *p, u32 sub);
int func_021D102C(char *p);
int func_021D1058(u8 *s, void *q);

/*
 * extent: compiled 42 bytes followed by two zero alignment bytes.
 */
int func_021D102C(char *p)
{
    if (func_021B8588(((struct Obj13368 *)p)->f0) == 3 && func_021D5B68(func_021B9C00(((struct Obj13368 *)p)->f118, 0)) != 0) return 1;
    return 0;
}


int func_021D1058(u8 *s, void *q)
{
    int k;

    k = 2;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)func_021B9AB0(2))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    k = 3;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)func_021B9AB0(3))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    return 0;
}
