/*
 * unit: yes
 * function: func_021B66D4, func_021B6804
 * address: 0x021B66D4
 * size: 324
 * packet: pkt_ov093_021B66D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initializer stores first, second, object, state; object-first reallocates all tails.
 * symbols:
 *   func_021B6AAC 0x021B6AAC thumb ov093
 *   func_021B6C5C 0x021B6C5C thumb ov093
 *   func_021B6DD0 0x021B6DD0 thumb ov093
 *   func_021B7050 0x021B7050 thumb ov093
 *   func_021B71D4 0x021B71D4 thumb ov093
 *   func_021B734C 0x021B734C thumb ov093
 *   func_021B73C4 0x021B73C4 thumb ov093
 *   func_021B7518 0x021B7518 thumb ov093
 *   func_021B7488 0x021B7488 thumb ov093
 *   func_021B6C08 0x021B6C08 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { void (*first)(void); u32 second; u8 *object; u32 state; } Callback;
extern void func_021B6AAC(void), func_021B6C5C(void), func_021B6DD0(void), func_021B7050(void);
extern void func_021B71D4(void), func_021B734C(void), func_021B73C4(void), func_021B7518(void), func_021B7488(void), func_021B6C08(void);
static inline void init(Callback *a, u8 *p, void (*f)(void))
{
    a->first = f; a->second = 0; a->object = p; a->state = 0;
}
#define INIT(f) init(a, p, f)
void func_021B66D4(Callback *a, u8 *p, u8 *q)
{
    u32 i;
    for (i = 0; i < 6; i++) p[0x428 + i] = 4;
    if (!q[0x20]) {
        switch (*(u32 *)(q + 4)) {
        case 0: INIT(func_021B6AAC); return;
        case 1:
            if (!q[0x22]) { INIT(func_021B6C5C); return; }
            else { INIT(func_021B6DD0); return; }
        case 2: INIT(func_021B7050); return;
        case 3: INIT(func_021B71D4); return;
        default: INIT(func_021B6AAC); return;
        }
    } else {
        switch (*(u32 *)(q + 4)) {
        case 0: INIT(func_021B734C); return;
        case 1: INIT(func_021B73C4); return;
        case 2: INIT(func_021B7518); return;
        case 3: INIT(func_021B7488); return;
        default: INIT(func_021B6AAC); return;
        }
    }
}
void func_021B6804(Callback *a, u8 *p, u8 *q)
{
    INIT(func_021B6C08);
}
