/*
 * function: func_02167810
 * address:  0x02167810
 * packet:   pkt_ov010_02167810
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   d_02172A28     0x02172A28  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

extern u8 d_02172A28[];
extern void func_02034714(void *a, int b, void *c);

u16 func_02167810(Work *w, int i)
{
    if (w == 0 || i >= 4 || w->e[i].used != 1)
        func_02034714(d_02172A28, 0, d_02172A28);
    return w->e[i].f12;
}
