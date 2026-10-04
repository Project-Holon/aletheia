/*
 * function: func_0215CC4C
 * address:  0x0215CC4C
 * packet:   pkt_ov010_0215CC4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches func_02154438
 * (ov002) through func_020124AC, parking the result in the script's slot.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_02154438  0x02154438  thumb  ov002
 *   func_0215897C  0x0215897C  thumb  ov010
 *   ov002_id       0x00000002  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Req {
    void *sys;          /* 0x00 */
    u32 one;            /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 kind;           /* 0x0C */
} Req;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern u32 func_02159B10(void *c, void *vm);
typedef signed int     s32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Desc;
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_02154438(s32 a, s32 *b);
extern u8 ov002_id[];
extern void func_0215897C(void *p, void *v);

int func_0215CC4C(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 kind;
    u32 flag;
    u32 k;
    u32 f;
    Req r;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    kind = func_02159B10(c, vm);
    flag = func_02159B10(c, vm);
    switch (kind) {
    case 0xF:
        k = 0;
        break;
    case 0x10:
        k = 1;
        break;
    case 0x11:
        k = 2;
        break;
    case 0x12:
        k = 3;
        break;
    case 0x13:
        k = 4;
        break;
    }
    switch (flag) {
    case 0:
        f = 0;
        break;
    case 1:
        f = 1;
        break;
    }
    r.sys = func_0201210C(sys);
    r.one = 1;
    r.flag = f;
    r.kind = k;
    func_0215897C(slot, func_020124AC(sys, (u32)ov002_id, (void *)func_02154438, (u32)(&r)));
    return 1;
}
