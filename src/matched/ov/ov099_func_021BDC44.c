/*
 * function: func_021BDC44
 * address: 0x021BDC44
 * packet: pkt_ov099_021BDC44
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   func_021BDDF4 0x021BDDF4 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   d_021C390C 0x021C390C data ov099 a4
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 */
#include "../include/Obj07953.h"
typedef unsigned short u16;
typedef struct { int v[8]; } Table;
extern const Table d_021C390C;
extern int func_021BCBD8(char *, int);
extern int func_021BDDF4(char *);
extern void func_021BAAB8(char *, int, int);
extern void func_021C18C8(char *, int, u16);
extern void func_021C23C8(void *a, void *b);
extern void func_021C23D8(char *, int);
int func_021BDC44(char *p, int v)
{
    Table t;
    func_021BCBD8(p, 1);
    if (func_021BDDF4(p) == 0) {
        func_021BAAB8(p, 0x68, 0);
        ((struct Obj07953 *)p)->f1CC = 0x63;
        return v;
    }
    t = d_021C390C;
    func_021C18C8(p, 2, t.v[((struct Obj07953 *)p)->f134E + ((struct Obj07953 *)p)->f134C * 2]);
    func_021C23C8(p, (void *)(-1));
    ((struct Obj07953 *)p)->f1CC = 0x9e;
    func_021C23D8(p, 1);
    return v;
}
