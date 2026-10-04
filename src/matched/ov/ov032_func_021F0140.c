/*
 * function: func_021F0140
 * address:  0x021F0140
 * packet:   pkt_ov032_021F0140
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021658D4  0x021658D4  thumb  ov010
 *   func_021F1268  0x021F1268  thumb  ov032
 *   func_02165B5C  0x02165B5C  thumb  ov010
 *   func_02165A10  0x02165A10  thumb  ov010
 *   func_021659F0  0x021659F0  thumb  ov010
 *   func_021F0F44  0x021F0F44  thumb  ov032
 *   func_0200C1E0  0x0200C1E0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk34;
struct Queue;
struct Rec;
extern int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag);
extern void func_021F1268(u8 *p);
extern int func_02165B5C(struct Rec *r);
extern int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag);
extern int func_021659F0(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, int a);
extern u32 func_0200C1E0(struct Blk34 *p);

int func_021F0140(u8 *p)
{
    u8 t;

    if (func_021658D4((struct Queue *)(*(int *)(p + 0x38)), (struct Rec *)(*(int *)(p + 0x4C)), (u16 *)(p + 0x4A)) == 0) {
        func_021F1268(p);
        return 0;
    }
    if (func_02165B5C((struct Rec *)(*(int *)(p + 0x4C))) != 0)
        return 0;
    p[0x54] = func_02165A10((struct Queue *)(*(int *)(p + 0x3C)), (struct Rec *)(*(int *)(p + 0x4C)), *(u16 *)(p + 0x4A), (int *)(p + 0x5C));
    p[0x55] = func_021659F0((u8 *)(*(int *)(p + 0x3C)), p[0x54]);
    if (*(int *)(p + 0x5C) == 0) {
        *(u8 **)(p + 0x50) = func_021F0F44(p, p[0x55]);
    } else {
        *(u8 **)(p + 0x50) = 0;
        *(u32 *)(p + 0x2D4) = func_0200C1E0((struct Blk34 *)(*(int *)(p + 0x14)));
    }
    if (*(u8 **)(p + 0x50) != 0 && *(int *)(*(u8 **)(p + 0x50) + 0x2C) != 0)
        *(int *)(p + 0x6C) = 0;
    else
        *(int *)(p + 0x6C) = 1;
    t = p[0x7B];
    p[0x57] = t;
    if (t < 0x1E) {
        p[0x7B] += (u8)*(int *)(p + 0x5C);
        if (p[0x7B] <= 4)
            p[0x7D] = p[0x7B];
    }
    return 1;
}
