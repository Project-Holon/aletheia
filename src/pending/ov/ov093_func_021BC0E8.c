/*
 * function: func_021BC0E8
 * address: 0x021BC0E8
 * packet: pkt_ov093_021BC0E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * residual: 312 of 312 bytes, only a register colour swap remains (original e=r5, entry pointer q=r6; ours e=r6, q=r5), 213 concrete bytes; branch shape, frame (0x24), spill slots and instruction order all match.
 * note 2026-10-05 (lane V10): the old draft (296 B) kept the entry pointer in one register and e spilled. What fixed the frame and the loop: i spilled with a persistent byte offset `off = i * 16` in r7 (first segment `q = &e[i]`, later segments `q = (E *)((u32)e + off)`; an all-`&e[i]` or all-cast spelling merges every sum and loses the persistent offset), line literals 1076, 1079, 1087, 1090 (an `ln` local gave the same bytes, so literals are kept), and pack() written as low | (a | (c | b)) so the result is stored at sp+0x20 and reloaded late. Tried without effect on the swap: E *q declared first, separate q2/q3 per segment, opt_lifetimes off, opt_common_subs off, opt_propagation off, int i, typed entry macro, inline segment helpers. 25 compiles used.
 * recoup 2026-10-05 (lane R9): still DIFF, 213 B. New finding: the original has a 2-byte copy `adds r0,r6,#0; ldr r0,[r0,#4]` at the action() read (ours loads [r5,#4] directly), so our body is 2 B shorter and only the pool padding makes the size equal; the loop branch targets are all 2 B off because of it. Tried, no effect: E *q declared first, q = e before the loop, i as int, off as int, off declared before i, q assigned before off, q = cast form first, no q local at all (ENTRY/cast macros per use), block-local q2/q3, action() with const E *, with B * (&q->b), with u8 * or u32 parameter, as a non-inline static (292 B), as a direct ternary, as a B struct copy, action(ENTRY(i)), result reused for value, pragma opt_dead_assignments off (210 B, copy still absent), pragma peephole off. u8 n shifts every offset and is not the cause. Open: what makes mwcc keep the inline parameter copy of the entry pointer in r0 (q must interfere with the parameter temp), likely the same cause as the e/q colour swap.
 * symbols:
 *   func_021BC948 0x021BC948 thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BC8EC 0x021BC8EC thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C6350 0x021C6350 thumb ov093
 *   func_021BC874 0x021BC874 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a:4; u32 b:3; u32 action:16; u32 rest:9; } B;
typedef struct { u8 *a; B b; u32 c; u8 d,f; u16 pad; } E;
extern u16 func_021BC948(u8 *, u8 *, int);
extern u32 func_021D8454(B *);
extern u32 func_021CC8D8(void *, int);
extern int func_021BC8EC(u8 *, u32, u8 *);
extern void func_021CC95C(void *, u32, int);
extern u8 func_021C6350(u8 *, u8 *);
extern void func_021BC874(E *, u32);
static inline u16 action(E *e)
{
    if (e->b.a == 1) return e->b.action;
    return 0;
}
static inline void set_accuracy(E *e, u16 v)
{
    e->c = (v & 0x1fff) | (e->c & 0xffffe000);
}
static inline u32 pack(u16 low, u8 a, u8 b, u8 c)
{
    return (low & 0x1fff) | (((u16)(a << 13)) | ((((u32)(u16)(c << 13) << 9)) | (((u32)b & 63) << 16)));
}
static inline void update(E *e, int result)
{
    u16 low = (u16)(e->c & 0x1fff);
    u8 a = (e->c >> 13) & 7;
    u8 c = (e->c >> 22) & 7;
    e->c = pack(low, a, result, c);
}
#define ENTRY(i) (&e[i])
void func_021BC0E8(u8 *p, E *e, u32 n)
{
    u32 i;
    u32 off;
    u32 type;
    u16 value;
    u32 lock;
    int result;
    E *q;
    for (i = 0; i < n; i++) {
        off = i * 16;
        q = &e[i];
        set_accuracy(q, func_021BC948(p, ENTRY(i)->a, 1));
        type = func_021D8454(&q->b);
        if (type == 1) {
            value = action(q);
            lock = func_021CC8D8(p + 0x1d74, 1076);
            q = (E *)((u32)e + off);
            result = func_021BC8EC(p, value, q->a);
            update(q, result);
            func_021CC95C(p + 0x1d74, lock, 1079);
        }
        if (type == 1 || type == 5) {
            lock = func_021CC8D8(p + 0x1d74, 1087);
            q = (E *)((u32)e + off);
            q->c = ((func_021C6350(p, q->a) & 7) << 13) | (q->c & 0xffff1fff);
            func_021CC95C(p + 0x1d74, lock, 1090);
        }
    }
    func_021BC874(e, n);
}
