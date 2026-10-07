/*
 * file:     btl_server_p158.c
 * unit:     yes
 * function: func_021D2930, func_021D2990, func_021D299C
 * address:  0x021D2930
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
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021D7AD4  0x021D7AD4  thumb  ov093
 *   func_021EA1B8  0x021EA1B8  thumb  ov093
 *   func_021EA1F0  0x021EA1F0  thumb  ov093
 *   func_021F878C  0x021F878C  thumb  ov094
 *   func_021EA8E4 0x021EA8E4 thumb ov093
 *   func_021EA8F4 0x021EA8F4 thumb ov093
 */
#include "../../matched/include/Obj13398.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_021CD9E0(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021D7AD4(int a);
extern void func_021EA1B8(struct S *s, u32 a, int b, int c);
extern int func_021EA1F0(struct S *s);
void func_021F878C(u32 a);
extern void func_021EA8E4(u32 *p);
extern int func_021EA8F4(u32 *p);
int func_021D2930(u32 *a, int *b, u32 *c);
int func_021D2990(int a, int b, int *c);
int func_021D299C(char *p, int *state);


int func_021D2930(u32 *a, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) == 0) {
            t = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
            func_021EA1B8((struct S *)a[0x15], (u16)c[2], t, func_021D7AD4(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0((struct S *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D2990(int a, int b, int *c)
{
    func_021F878C(*c);
    return 1;
}

int func_021D299C(char *p, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(((struct Obj13398 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(((struct Obj13398 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}
