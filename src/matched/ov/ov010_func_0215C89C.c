/*
 * function: func_0215C89C
 * address: 0x0215C89C
 * packet: pkt_ov010_0215C89C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum one assigned immediately before the f19 store in the inline
 * record initializer separates it from the constant return and selects r0.
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0216F948 0x0216F948 thumb ov010
 *   func_0216F918 0x0216F918 thumb ov010
 *   func_02030734 0x02030734 arm
 *   func_02014808 0x02014808 thumb
 *   func_0215897C 0x0215897C thumb ov010
 *   func_0215C870 0x0215C870 thumb ov010
 *   d_021728F0 0x021728F0 data a1
 *   ov173_id 0x000000AD data
 *   d_021B81D0 0x021B81D0 data ov173 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Relearn {
    void *mon;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *sys;          /* 0x0C */
    void *moves;        /* 0x10 */
    u8 pad14[5];
    u8 f19;             /* 0x19 */
} Relearn;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02159B10(void *c, void *vm);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *list, u32 i);
extern u8 *func_02012944(void *p);
extern u16 *func_0216F948(void *mon, u32 heap);
extern void *func_0216F918(u32 heap);
extern void *func_02030734(u32 heap, u32 size, int flags, const char *file, u16 line);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *p, void *v);
extern int func_0215C870(int a0, int a1);
extern const char d_021728F0[];
extern const u8 d_021B81D0[];
extern u8 ov173_id[];

static inline void init_record(Relearn *r, void *mon, void *sess, void *sys, void *moves)
{
    enum One { ONE = 1 } one;
    r->mon = mon;
    r->sess = sess;
    r->f08 = 0;
    r->sys = sys;
    r->moves = moves;
    one = ONE;
    r->f19 = one;
}
int func_0215C89C(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 a;
    u32 idx;
    void *mon;
    void *sess;
    void *moves;
    Relearn *r;
    u32 *h;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = (u32)func_02159AE8(c, vm);
    idx = func_02159B10(c, vm);
    mon = func_0201AB28(func_02012934(w), idx);
    sess = func_02012944(w);
    moves = func_0216F948(mon, 4);
    r = func_0216F918(4);
    init_record(r, mon, sess, sys, moves);
    h = func_02030734(4, 8, 0, d_021728F0, 0x19B);
    h[0] = (u32)r;
    h[1] = a;
    func_0215897C(slot, func_02014808(sys, (int)x, (u32)ov173_id, (int)d_021B81D0, (int)r, (int)((void *)func_0215C870), (int)h));
    return 1;
}
