/*
 * function: func_021F9C50
 * address:  0x021F9C50
 * packet:   pkt_021F9C50
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   func_021F9C6C  0x021F9C6C  thumb  ov186
 */
#include "../../../matched/include/Obj24811.h"

typedef struct {
    char  pad_00[0x4c];
    char  unk_4c[0x18];
    int   unk_64;
    void *unk_68;
} S;

extern void func_02082D44(void *, void *, int);
extern void func_021F9C6C(S *);

void func_021F9C50(S *p)
{
    func_02082D44(p->unk_4c, p->unk_68, 0x18);
    ((struct Obj24811 *)((char *)p->unk_68))->f18 = p->unk_64;
    func_021F9C6C(p);
}
