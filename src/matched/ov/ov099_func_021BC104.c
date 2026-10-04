/*
 * function: func_021BC104
 * address:  0x021BC104
 * packet:   pkt_ov099_021BC104
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02156BC4  0x02156BC4  thumb  ov009
 *   func_02156330  0x02156330  thumb  ov009
 *   func_021563C0  0x021563C0  thumb  ov009
 *   func_021C24A4  0x021C24A4  thumb  ov099
 *   func_021C2864  0x021C2864  thumb  ov099
 */
#include "../include/Obj00008.h"
#include "../include/Obj13686.h"

typedef unsigned char u8;

extern void func_02156BC4(int);
extern int func_02156330(void);
extern void func_021563C0(int a);
extern void func_021C24A4(void *w, int v);
extern void func_021C2864(void *a, u8 v);

void func_021BC104(char *p)
{
    char *q = *(char * *)&((struct Obj00008 *)p)->f248;

    if (((struct Obj13686 *)q)->f44 != 0 && ((struct Obj13686 *)q)->f45 != 0) {
        func_02156BC4(1);
        func_021563C0(func_02156330());
        func_021C24A4(p, 0x2A);
        func_021C2864(((struct Obj00008 *)p)->f8, 1);
    } else {
        func_021C2864(((struct Obj00008 *)p)->f8, 0);
    }
}
