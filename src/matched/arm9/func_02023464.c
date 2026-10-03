/*
 * function: func_02023464
 * address:  0x02023464
 * packet:   pkt_02022F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02023464_File  0x020A7450  data
 *   func_02030734       0x02030734  arm
 *   func_0202350C       0x0202350C  thumb
 *   func_02022E88       0x02022E88  thumb
 *
 * Starts one countdown wipe: allocates the 0x4c-byte object on the heap
 * named by the low half of the task's +0x20 word, parks it at +0x14, hands
 * the task's saved parameters to func_0202350C, opens the display side
 * through func_02022E88 with mode 1 or 2 by the caller's cfg[8], and
 * advances the task's phase.  __FILE__ is "wipe_sub.c" at 0x020A7450,
 * __LINE__ 0xc7c.
 *
 * The notes carried an r4/r6 tie (o against cfg) that 3800 permuter
 * compiles never moved.  It was not an allocation tie: the func_02022E88
 * call is written out in BOTH arms of the cfg[8] test, with 1 and 2 as
 * literals, and mwcc cross-jumps the two calls, leaving `movs r1,#1 / b /
 * movs r1,#2` in front of one shared call.  A `mode` local assigned in
 * the if/else puts the test value in r1 and swaps r4/r6 for the whole
 * function (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char func_02023464_File[];

struct Task {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    void *obj;    /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   heap;   /* 0x20 */
};

struct Obj {
    u8  pad00[0x30];
    u32 f30;      /* 0x30 */
    u8  pad34[0x10];
    u32 f44;      /* 0x44 */
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0202350C(struct Obj *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5);
extern int func_02022E88(int a0, int a1, int a2, int a3);

void func_02023464(struct Task *t, u8 *cfg)
{
    struct Obj *o;

    o = func_02030734((u16)t->heap, 0x4c, 0, func_02023464_File, 0xc7c);
    t->obj = o;

    func_0202350C(o, cfg, t->f04, t->f08, t->f10, t->f18);

    if (cfg[8] == 0) {
        func_02022E88(t->f18, 1, o->f30, o->f44);
    } else {
        func_02022E88(t->f18, 2, o->f30, o->f44);
    }

    t->phase = t->phase + 1;
}


