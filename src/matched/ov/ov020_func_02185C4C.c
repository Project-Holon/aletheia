/*
 * function: func_02185C4C
 * address:  0x02185C4C
 * packet:   pkt_02185C4C
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, copies a seven-word record from the third argument
 * plus two link fields.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02185C8C  0x02185C8C  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_020120F4(void *p);
int func_02185C8C(int a0, int *st, int *p);

void *func_02185C4C(void *p, int a1, S7 *a2)
{
    void *r0v = func_020122C0(p, 0, func_02185C8C, 0x30);
    int *r4 = func_020124E8(r0v);

    *(S7 *)r4 = *a2;
    r4[7] = (int)p;
    r4[8] = func_020120F4(p);
    r4[9] = a1;
    return r0v;
}
