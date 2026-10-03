/*
 * function: func_02154670
 * address:  0x02154670
 * packet:   pkt_02154670
 * region:   ov000
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Straight-line constructor wrapper over the ARM9 object/service helpers.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021542C0  0x021542C0  thumb  ov000
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_020120F4(void *p);
int func_02012EBC(int p);
void func_021542C0(void);

void *func_02154670(void *p)
{
    void *r7;
    char *r4;
    int q;

    r7 = (void *)func_020122C0(p, 0, func_021542C0, 0x2CC);
    r4 = func_020124E8(r7);
    q = func_020120F4(p);
    *(int *)(r4 + 4) = q;
    *(int *)(r4 + 8) = func_02012EBC(q);
    *(void **)r4 = p;
    *(int *)(r4 + 0x258) = func_020120F4(p);
    *(int *)(r4 + 0x25C) = 1;
    *(int *)(r4 + 0x260) = 0;
    *(int *)(r4 + 0x264) = 0x31;
    return r7;
}
