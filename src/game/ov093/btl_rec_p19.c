/*
 * file:     btl_rec_p19.c
 * unit:     yes
 * function: func_021EF988, func_021EF9A8, func_021EF9B0, func_021EF9C0, func_021EF9C8, func_021EF9D0, func_021EF9F4
 * address:  0x021EF988
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EF83C  0x021EF83C  thumb  ov093
 *   func_021EFA84  0x021EFA84  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EFAD8  0x021EFAD8  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S_021EF988;

typedef struct {
    u32 value;
    u32 count;
} Countdown;

typedef unsigned short u16;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    u32 c[8];           /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S_021EF9F4;

extern void func_021EF83C(S_021EF988 *a, u32 i);
extern u32 func_021EFA84(u32 a, int b);
extern u32 func_021E8A98(Slot a);
extern int func_021EFAD8(char *p, u32 i, u32 v);
void func_021EF988(S_021EF988 *p, u32 v);
u8 func_021EF9A8(u32 *p);
int func_021EF9B0(u32 *p);
int *func_021EF9C0(int *p, int a, int b);
void func_021EF9C8(int *p);
u32 func_021EF9D0(Countdown *p);
int func_021EF9F4(S_021EF9F4 *a, u32 b, Slot c, int d);


void func_021EF988(S_021EF988 *p, u32 v)
{
    u32 i;

    for (i = 0; i < 8; i++)
        func_021EF83C(p, i);
    p->pad00[0] = v;
    p->pad00[1] = 0xff;
}

/*
 * Sole blocker of the claimed 021D3D84 follower.
 * Body ends at 021EF9B0; larger unlabelled follower remains outside this leaf.
 */
u8 func_021EF9A8(u32 *p) { return (u8)*p; }


int func_021EF9B0(u32 *p)
{
    if (p[0] != 0)
        return p[1];
    return 0;
}

int *func_021EF9C0(int *p, int a, int b)
{
    p[0] = a;
    p[1] = b;
    return p;
}

void func_021EF9C8(int *p)
{
    p[0] = 0;
    p[1] = 0;
}


/*
 * Unlabelled leaf (witness for func_021EF8B8). Countdown timer: when the
 * value is set and the counter is not 0xff, decrement the counter; when it
 * reaches zero, clear the value and return its low byte.
 */
u32 func_021EF9D0(Countdown *p)
{
    u32 v = p->value;
    if (v != 0 && p->count != 0xff && --p->count == 0) {
        v = (u8)v;
        p->value = 0;
        return v;
    }
    return 0;
}


/*
 * Eight-slot table object: six u32[8] arrays and a u32[8][6] block, all
 * indexed by the slot b.  Written as struct member arrays, the load of
 * used[b] keeps b*4 in its own register while the c/z48/z128 stores
 * recompute a + b*4 (the raw `*(u32 *)(a + K + b * 4)` casts CSE'd b*4 and
 * swapped b and b*4: docs/notes/pkt_ov093_021EF9F4.c.txt).  The third
 * parameter is a one-word struct passed by value (push {r0-r3} frame).
 */
int func_021EF9F4(S_021EF9F4 *a, u32 b, Slot c, int d)
{
    u32 i;
    u32 x;

    if (a->used[b] == 0) {
        if (d != 0) {
            a->t[b] = func_021EFA84(b, 0);
            if (a->t[b] == 0)
                return 0;
        }
        a->used[b] = 1;
        a->c[b] = c.v;
        a->z48[b] = 0;
        a->z128[b] = 0;
        for (i = 0; i < 6; i++)
            a->w[b][i] = 0x1f;
        x = func_021E8A98(c);
        if (x != 0x1f)
            func_021EFAD8((char *)a, b, x);
        return 1;
    }
    return 0;
}
