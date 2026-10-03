/*
 * function: func_0215C63C
 * address:  0x0215C63C
 * packet:   pkt_ov010_0215C63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with func_020120B4, parks the record in the
 * script's slot and waits on func_0215C69C.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_0215C69C  0x0215C69C  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ProcHandoff {
    void *work;         /* 0x00 */
    u32 arg1;           /* 0x04 */
    u32 arg0;           /* 0x08 */
} ProcHandoff;

extern void *func_0215A5DC(void *vm);
extern void *func_0215A5F4(void *vm);
extern void *func_02158FB4(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020120B4(void *sys, u32 ovId, const void *proc, void *arg);
extern void func_020113D0(void *c, int (*fn)(void *));
extern int func_0215C69C(void *c);
extern const char d_021728F0[];

void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1)
{
    void *sys;
    void **slot;
    ProcHandoff *h;

    sys = func_0215A5DC(vm);
    slot = func_02158FB4(func_0215A5F4(vm));
    h = func_02030734(4, sizeof(ProcHandoff), 1, d_021728F0, 0x8B);
    h->work = work;
    h->arg1 = arg1;
    h->arg0 = arg0;
    func_020120B4(sys, ovId, proc, work);
    *slot = h;
    func_020113D0(c, func_0215C69C);
}
