/*
 * file:     unit_021AEB20_p02.c
 * unit:     yes
 * function: func_021AECC4, func_021AED08
 * address:  0x021AECC4
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B2180  0x021B2180  arm  ov013
 *   func_021B0614  0x021B0614  arm  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_021AEDEC 0x021AEDEC thumb ov013
 */
#include "../../matched/include/Obj19303.h"
#include "../../matched/include/G_Work.h"

struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021B2180(int a, int b);
extern int func_021B0614(void *p);
extern void func_021AEDEC(struct Node *p);
int func_021AECC4(int x);
void func_021AED08(int unused,int code,void *p);
extern struct Work *d_021B3C80;


int func_021AECC4(int x)
{
    u8 *p = *(u8 **)(((u8 *)d_021B3C80) + 0x1A1C);
    int r;

    if (p != 0 && ((struct Obj19303 *)p)->fC == 4) {
        r = 0;
        if (func_021B2180((int)p, 0) != 0) {
            return r;
        }
        if (func_021B0614(*(void **)(((u8 *)d_021B3C80) + 0x1A1C)) != 0) {
            r = 1;
        }
        return r;
    }
    return 0;
}

void func_021AED08(int unused,int code,void *p)
{
    switch(code) {
    case 9: func_021AEDEC(p); break;
    case 7: func_021B0614(p); break;
    case 12: func_021AEDEC(p); break;
    }
}
