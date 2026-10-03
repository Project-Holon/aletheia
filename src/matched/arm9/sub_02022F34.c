/*
 * function: func_02022F34
 * address:  0x02022F34
 * packet:   pkt_02022EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_02030EAC 0x02030EAC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct WipeSubElem {
    u8 buf1[0xC0];
    u8 buf2[0xC0];
    u32 unk;
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_02022F34(void *p, struct WipeSubElem *elems)
{
    int i;

    for (i = 0; i < 2; i++) {
        MI_CpuCopy8(elems[i].buf2, elems[i].buf1, 0xC0);
    }
    func_02030EAC(p);
}
