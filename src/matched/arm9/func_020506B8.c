/*
 * function: func_020506B8
 * address:  0x020506B8
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020473D8  0x020473D8  arm
 *   func_0204F2B4  0x0204F2B4  arm
 *   func_0204F344  0x0204F344  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Owner {
    u32 f00;
    u32 f04;
    void (*f08)(u32 a0, u32 a1, u32 a2, u32 a3);
} Owner;

typedef struct Entry {
    u16 f00;
    u16 f02;
    u32 f04;
} Entry;

extern int func_020473D8(int a0);
extern void func_0204F2B4(int p0, int p1, int p2);
typedef unsigned char  u8;
extern void func_0204F344(void *a0, u32 a1, int a2, int *out, int *in, u8 flag);

void func_020506B8(Owner *o, Entry *e, u32 a2)
{
    u32 s4;
    u32 s3;
    u32 s2;
    u32 base;
    u32 zero;

    base = func_020473D8(e->f04);
    func_0204F2B4(o->f04, e->f00, (int)(&s4));
    zero = 0;
    func_0204F344((void *)o->f04, e->f00, a2, (int *)(&s3), (int *)(&s2), zero);
    if (o->f08 != 0) {
        o->f08(zero, s4, base + s3, s2);
    }
}
