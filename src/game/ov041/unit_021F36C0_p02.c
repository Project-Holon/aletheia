/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3F18, func_021F3F44, func_021F3F70, func_021F3FC0, func_021F3FD8, func_021F3FEC
 * address:  0x021F3F18
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F4080     0x021F4080  data  a1
 *   d_021F4660 0x021F4660 data a1
 */
#include "../../matched/include/Obj20502.h"
#include "../../matched/include/Obj04319.h"

typedef unsigned char u8;

typedef struct {
    u8 b[4];
} T4;

int func_021F3F18(int x);
int func_021F3F44(int x);
int func_021F3F70(int a, int b);
int func_021F3FC0(unsigned int a, int i);
void func_021F3FD8(unsigned char *p);
void func_021F3FEC(unsigned char *p);
extern T4 d_021F4080;
extern const unsigned char d_021F4660[];

/*
 * An unlabelled leaf (no lr save) next to func_021F3F44: maps 0..3 to an even
 * index. Callee of func_021F3884.
 */
int func_021F3F18(int x)
{
    switch (x) {
    case 0: return 0;
    case 1: return 2;
    case 2: return 4;
    case 3: return 6;
    }
    return 0;
}

int func_021F3F44(int x)
{
    switch (x) {
    case 0: return 0;
    case 1: return 1;
    case 3: return 2;
    case 2: return 3;
    }
    return 0;
}


int func_021F3F70(int a, int b)
{
    T4 t = d_021F4080;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++) {
        if (t.b[i] == a) {
            j = (i + b) % 4;
            return t.b[j];
        }
    }
    return a;
}

int func_021F3FC0(unsigned int a, int i)
{
    return func_021F3F70(func_021F3F44(a), d_021F4660[i]);
}

void func_021F3FD8(unsigned char *p)
{
    func_021F3FEC(p + 0x720);
    ((struct Obj20502 *)p)->f720 = 1;
}


/*
 * extent: 18 bytes of code followed by two zero alignment bytes.
 */
void func_021F3FEC(unsigned char *p)
{
    ((struct Obj04319 *)p)->f0 = 0;
    ((struct Obj04319 *)p)->f4 = 0;
    ((struct Obj04319 *)p)->f8 = 0;
    p[13] = 0;
    p[12] = 0;
    p[14] = 0;
    p[15] = 0;
}
