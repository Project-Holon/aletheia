/*
 * function: WORLDTRADE_SEARCH_GetSelectedButton
 * address:  0x021FE9B0
 * packet:   pkt_021FE9B0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *
 * Return the current cursor slot of the state block at +0xE00: the +0x28
 * word while the +0x24 flag is clear, else the +0x2C word plus four.
 * A slot of seven or more reports through func_02034714 (the raw-address
 * assert shape; 0x02203E2C is a plain constant, as in WORLDTRADE_ADAPTER_QueueMessagePrint).
 */

typedef unsigned int u32;

typedef struct {
    unsigned char pad0[0x24];
    int f24;
    int f28;
    int f2C;
} State;

typedef struct {
    unsigned char pad0[0xE00];
    State *st;
} Work;

extern void func_02034714(const char *expr, u32 line, const char *file);

int WORLDTRADE_SEARCH_GetSelectedButton(Work *p)
{
    State *s = p->st;
    int r;

    if (s->f24 == 0) {
        r = s->f28;
    } else {
        r = s->f2C + 4;
    }
    if (r >= 7) {
        func_02034714((void *)0x02203E2C, 0, (void *)0x02203E2C);
    }
    return r;
}
