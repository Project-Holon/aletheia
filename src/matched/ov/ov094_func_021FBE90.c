/*
 * function: func_021FBE90
 * address:  0x021FBE90
 * packet:   pkt_ov094_021FBE90
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj21680.h"
typedef struct {
    unsigned f0_lo : 13;
    unsigned f0_b13 : 1;
    unsigned f0_b14 : 1;
    unsigned f0_b15 : 1;
    unsigned f0_hi : 16;
    char pad[0x244];
    char f248;
    char f249;
    char f24a;
    char f24b;
    int f24c;
    int f250;
    short f254;
    char pad2[0x284 - 0x256];
    int f284;
    char pad3[0x2a0 - 0x288];
    int f2a0;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int func_021FBE90(struct Cursor *a, State *s)
{
    int sel = VM_GetU32(a);
    int v = VM_GetU32(a);

    switch (sel) {
    case 9:
        s->f248 = v;
        break;
    case 10:
        s->f249 = v;
        break;
    case 11:
        s->f24a = v;
        break;
    case 12:
        s->f24b = v;
        break;
    case 13:
        s->f24c = v;
        break;
    case 14:
        s->f250 = v;
        break;
    case 15:
        s->f254 = v;
        break;
    case 0x35:
        s->f0_b13 = v;
        break;
    case 0x36:
        s->f284 = v;
        break;
    case 0x37:
        s->f2a0 = v;
        break;
    case 0x38:
        s->f0_b15 = v;
        break;
    }
    return ((struct Obj21680 *)s)->f23C;
}
