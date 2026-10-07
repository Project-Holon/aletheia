/*
 * file:     field_msgbg_p12.c
 * unit:     yes
 * function: func_0218BC40, func_0218BC6C, func_0218BC8C, func_0218BCAC
 * address:  0x0218BC40
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
 *   func_02046DB8  0x02046DB8  arm
 *   func_0218D0D8  0x0218D0D8  thumb  ov021
 *   func_020470A8  0x020470A8  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 */
#include "../../matched/include/Obj00572.h"
#include "../../matched/include/Obj01114.h"

struct Tagged;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

void *func_02046DB8(u32 a0, u32 a1);
int func_0218D0D8(void *a, void *b);
u32 func_020470A8(void *p);
int func_020470D0(u32 *p);
void func_02046EFC(struct Tagged *p);
/* The trailing guard is the function exit: only its cmp survives. */ void func_0218BC40(unsigned char *p, int a, int b, int c);
void func_0218BC6C(unsigned char *p);
int func_0218BC8C(int *p);
u8 *func_0218BCAC(u8 *p);


/* The trailing guard is the function exit: only its cmp survives. */
void func_0218BC40(unsigned char *p, int a, int b, int c)
{
    ((struct Obj00572 *)p)->f1D0 = (int)func_02046DB8(a, b);
    if (c != 0)
        func_0218D0D8((void *)(((struct Obj00572 *)p)->f1D0), (void *)c);
    if (func_020470A8((void *)(((struct Obj00572 *)p)->f1D0)) == 0)
        return;
}


void func_0218BC6C(unsigned char *p)
{
    if (((struct Obj01114 *)p)->f1D0 != 0) {
        func_020470D0(((struct Obj01114 *)p)->f1D0);
        func_02046EFC(((struct Obj01114 *)p)->f1D0);
        ((struct Obj01114 *)p)->f1D0 = 0;
    }
}

int func_0218BC8C(int *p)
{
    unsigned int i;
    int n;
    for (i = 0, n = 0; i < 4; i++) {
        if (p[i + 1] != -1)
            n++;
    }
    return n;
}


/*
 * Returns the object pointer advanced by 0x10 bytes.
 */
u8 *func_0218BCAC(u8 *p)
{
    return p + 0x10;
}
