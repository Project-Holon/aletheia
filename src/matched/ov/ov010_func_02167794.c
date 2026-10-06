/*
 * function: func_02167794
 * address:  0x02167794
 * packet:   pkt_ov010_02167794
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012114  0x02012114  thumb
 *   func_02034714  0x02034714  arm
 *   d_02172A28     0x02172A28  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Slot {
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 pad[0x1B];
} Slot;

typedef struct Work {
    void *sys;
    void *obj;
} Work;

extern u8 d_02172A28[];
struct Ctx;
extern u32 func_02012114(const struct Ctx *p);
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_02167794(Work *w)
{
    Slot *s;
    int i;

    if (func_02012114(w->sys) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->obj != 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    i = 0;
    s = (Slot *)((char *)w + 0x1C);
    for (; i < 4; i++) {
        if (s[i].pend == 1)
            s[i].pend = 0;
    }
}
