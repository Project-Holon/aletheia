/*
 * function: func_02022D98
 * address:  0x02022D98
 * packet:   pkt_02022D98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02022D88  0x02022D88  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_02030EAC 0x02030EAC  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

struct Container {
    void *base;
    s32 count;
};

extern void *sub_02022D88(struct Container *obj, u32 idx);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_02030EAC(void *p);

void func_02022D98(void *p, struct Container *c)
{
    s32 i;

    for (i = 0; i < c->count; i++) {
        u8 *ptr = (u8 *)sub_02022D88(c, i);
        MI_CpuCopy8(ptr + 0x300, ptr, 0x300);
    }
    func_02030EAC(p);
}
