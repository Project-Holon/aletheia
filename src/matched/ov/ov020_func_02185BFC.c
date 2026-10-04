/*
 * function: func_02185BFC
 * address:  0x02185BFC
 * packet:   pkt_02185BFC
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, copies a seven-word record then fills link fields.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02185D38  0x02185D38  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Ctx;
void *func_020120F4(const struct Ctx *p);
void func_02185D38(void);

void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_02185D38, 0x30);
    char *r4 = func_020124E8(r0v);

    *(S7 *)r4 = *a2;
    *(int *)(r4 + 0x1c) = (int)p;
    *(int *)(r4 + 0x20) = (int)func_020120F4(p);
    *(int *)(r4 + 0x24) = a1;
    *(int *)(r4 + 0x28) = a3;
    *(u8 *)(r4 + 0x2c) = a4;
    return r0v;
}
