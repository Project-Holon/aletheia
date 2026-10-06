/*
 * function: func_021BCDE8
 * address:  0x021BCDE8
 * packet:   pkt_ov091_021BCDE8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD1BC  0x021BD1BC  thumb  ov091
 *   func_021BD504  0x021BD504  thumb  ov091
 *   func_021BD634  0x021BD634  thumb  ov091
 *   func_021BA4F8  0x021BA4F8  thumb  ov091
 */
#include "../include/Obj00009.h"
#include "../include/Obj20913.h"
#include "../include/Obj20914.h"
#include "../include/Obj20915.h"
#include "../include/Obj20916.h"
#include "../include/Obj20917.h"
#include "../include/Obj20918.h"

typedef unsigned char u8;

extern void func_021BD1BC(char *a, int *b);
extern void func_021BD504(char *a);
extern void func_021BD634(u8 *p);
extern void func_021BA4F8(u8 *a);

void func_021BCDE8(char *a)
{
    if (((struct Obj20913 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f8C == 1) {
        switch (((struct Obj20914 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64) {
        case 1:
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F4));
            break;
        case 2:
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F0));
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F4));
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F8));
            break;
        }
    }
    if (((struct Obj00009 *)a)->f20C != ((struct Obj20915 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 && ((struct Obj00009 *)a)->fC == 2) {
        func_021BD504(a);
        ((struct Obj00009 *)a)->f20C = ((struct Obj20916 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94;
    }
    if (((struct Obj20917 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f90 == 1)
        func_021BD634((u8 *)a);
    if (((struct Obj20918 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f63 == 1)
        func_021BA4F8((u8 *)a);
}
