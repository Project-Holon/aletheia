/*
 * function: func_02189684
 * address:  0x02189684
 * packet:   pkt_ov021_02189684
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013FA8  0x02013FA8  thumb
 *   func_02013C80  0x02013C80  thumb
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 */
#include "../include/Obj03105.h"

typedef unsigned short u16;

extern int func_02013FA8(u16 id);
extern int func_02013C80(u16 id);
extern void func_021AB650(void *p);
extern void func_021AB868(void *p);
extern void func_021AB840(void *p, int a, int b, int c);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021AB880(u8 *p);
extern u32 func_021AB884(u8 *p);
extern int func_021AB888(void *p);
extern void func_021AB634(void *p, int a, int b, int c);

void func_02189684(char *p, unsigned int id)
{
    int k;
    int a;
    int b;

    k = func_02013FA8(id);
    if (k != 0xFFFF) {
        func_021AB650(((struct Obj03105 *)p)->f40);
        func_021AB868(((struct Obj03105 *)p)->f44);
        func_021AB840(((struct Obj03105 *)p)->f44, 1, k, 0x96);
        a = func_021AB880(((struct Obj03105 *)p)->f44);
        b = func_021AB884(((struct Obj03105 *)p)->f44);
        func_021AB634(((struct Obj03105 *)p)->f40, a, b, func_021AB888(((struct Obj03105 *)p)->f44));
        return;
    }
    if (func_02013C80(id) == 0) {
        func_021AB650(((struct Obj03105 *)p)->f40);
        func_021AB868(((struct Obj03105 *)p)->f44);
    }
}
