/*
 * function: func_0217E378
 * address:  0x0217E378
 * packet:   pkt_ov019_0217E378
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02174E20  0x02174E20  thumb  ov012
 *   func_02174E64  0x02174E64  thumb  ov012
 *   func_020362DC  0x020362DC  arm
 */
#include "../include/Obj19428.h"

typedef unsigned char u8;
typedef unsigned int u32;

int func_0217BB20(char *p);
void func_0217F074(void *p);
int func_0217B8E4(char *p, char v);
void func_0217F210(u8 *p, u8 *a, u32 b);
u32 func_0217F1EC(u8 *p);
u32 func_02174E20(void);
u32 func_02174E64(void);
u32 func_020362DC(void);

int func_0217E378(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;

    p = *(u8 * *)&((struct Obj19428 *)w)->f355C;
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    if (p[0xcb] == 1) {
        func_0217B8E4((char *)w, 0x2f);
        p[0xcb] = 0;
        p[0xdf] = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        func_0217F210(w, a2, 0x116);
        (*state)++;
        break;
    case 1:
        if (func_02174E20() == 1) {
            p[0xdf] = 1;
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 2))
            *state = 100;
        break;
    case 100:
        if (func_02174E64() == 1)
            (*state)++;
        break;
    case 101:
        if (p[0xdf] == 0) {
            func_0217B8E4((char *)w, 0x2c);
            return 1;
        }
        break;
    }
    return 0;
}
