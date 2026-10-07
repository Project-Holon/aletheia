/*
 * file:     field_palace_sys_p09.c
 * unit:     yes
 * function: func_021D2CE8, func_021D2D24, func_021D2D50
 * address:  0x021D2CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DD718     0x021DD718  data  a4
 *   func_020056EC  0x020056EC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_021DD738     0x021DD738  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021D2D7C  0x021D2D7C  thumb  ov021
 */
struct Big;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Blk021D2D50 {
    u32 w[6];
} Blk021D2D50;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern int func_0200C234(void *p);
extern u32 func_020056EC(u32 v);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern Blk021D2D50 *func_020124E8(void *task);
extern int func_021D2D7C(void *task, int *state);
u32 func_021D2CE8(void *a, int i);
u32 func_021D2D24(void *a, u32 v, int c);
void *func_021D2D50(void *a, Blk021D2D50 *src);
extern u32 d_021DD718[];
extern u32 d_021DD738[];


/*
 * The 0x0C-random-plus-0x5A path returns through its own temporary (an
 * else arm with a local); a direct `return f() + 0x5a` merges into v. The
 * loop index reuses the second parameter's register: v is copied out and the
 * parameter becomes the index, which gives the image's r1/r2/r3 colouring
 * (a fresh int index rotates them by one).
 */
u32 func_021D2CE8(void *a, int i)
{
    u32 v = i;
    void *h = func_0200C0F0(func_02012EBC(a));

    for (i = 0; i < 8; i++) {
        if (v == d_021DD718[i]) {
            if (func_0200C234(h)) {
                return v;
            } else {
                u32 r = func_020056EC(0xc);
                return r + 0x5a;
            }
        }
    }
    return v;
}


u32 func_021D2D24(void *a, u32 v, int c)
{
    int i;

    if (c == 0) {
        for (i = 0; i < 0xf; i++) {
            if (v == d_021DD738[i]) {
                return func_020056EC(0x14) + 0x6e;
            }
        }
    }
    return v;
}


void *func_021D2D50(void *a, Blk021D2D50 *src)
{
    void *task = func_020122C0(a, 0, func_021D2D7C, 0x1c);

    *func_020124E8(task) = *src;
    return task;
}
