/*
 * function: func_02027A08
 * address:  0x02027A08
 * packet:   pkt_02027A04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02077B30  0x02077B30  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct TaskMenu {
    u8 type;
    u8 pad[0x17];
    void **table;
    u8 pad2[0x18];
    void *ctx;
};

extern u32 func_02077B30(void *fn, void *ctx, u32 arg);

u32 func_02027A08(struct TaskMenu *tm, u32 arg)
{
    u32 index = tm->type;
    void *fn = tm->table[index];
    void *ctx = tm->ctx;
    return func_02077B30(fn, ctx, arg);
}
