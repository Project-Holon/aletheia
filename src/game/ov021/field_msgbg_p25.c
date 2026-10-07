/*
 * file:     field_msgbg_p25.c
 * unit:     yes
 * function: func_0218C69C, func_0218C6D0, func_0218C6F4
 * address:  0x0218C69C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218C530  0x0218C530  thumb  ov021
 *   func_0218C3B0  0x0218C3B0  thumb  ov021
 *   func_02169510  0x02169510  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218C47C  0x0218C47C  thumb  ov021
 */
#include "../../matched/include/Obj12572.h"
#include "../../matched/include/Obj12574.h"

struct V3;
typedef unsigned char  u8;

unsigned char func_0218C530(int b);
void func_0218C3B0(void *p, int i, int c);
void func_02169510(u8 *src, struct V3 *dst);
void func_0207C9D0(unsigned char *a, int *buf, int b);
int func_0218C47C(int *p, int id);
void func_0218C69C(unsigned char *p, int b, int i, int c);
void func_0218C6D0(int *p, int b);
int func_0218C6F4(unsigned char *p, int b, int id);


void func_0218C69C(unsigned char *p, int b, int i, int c)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj12572 *)p)->f1AC)
        v = 0;
    func_0218C3B0(*(unsigned char * *)&((struct Obj12572 *)p)->f1D8 + v * 0x18, i, c);
}


void func_0218C6D0(int *p, int b)
{
    int buf[3];
    func_02169510((u8 *)p[0], (struct V3 *)buf);
    func_0207C9D0((unsigned char *)p[3] + 4, buf, b);
}


int func_0218C6F4(unsigned char *p, int b, int id)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj12574 *)p)->f1AC)
        v = 0;
    return func_0218C47C((int *)(*(unsigned char * *)&((struct Obj12574 *)p)->f1D8 + v * 0x18), id);
}
