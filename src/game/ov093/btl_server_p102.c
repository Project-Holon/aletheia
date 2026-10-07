/*
 * file:     btl_server_p102.c
 * unit:     yes
 * function: func_021C9728, func_021C9750, func_021C9778, func_021C97A4
 * address:  0x021C9728
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C6110 0x021C6110 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *);
extern void func_021D5FC0(struct UtilWork *, u32);
extern void func_021D6440(u8 *p, u32 n);
extern void func_021C60EC(u8 *, u8 *, u32);
extern void func_021C6110(u8 *, u8 *, u32);
int func_021C9728(u8 *p, u8 *q);
int func_021C9750(u8 *p, u8 *q);
int func_021C9778(u8 *p, u8 *q);
int func_021C97A4(u8 *p, u8 *q);

/*
 * extent: two bytes of trailing alignment padding.
 */
int func_021C9728(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D5FC0((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}

int func_021C9750(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D6440(a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}

int func_021C9778(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C60EC(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}

int func_021C97A4(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C6110(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}
