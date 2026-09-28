/*
 * function: func_02160A64
 * address:  0x02160A64
 * packet:   pkt_ov010_02160A64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs the fn1 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */

typedef unsigned int u32;

typedef int (*Hook)(void *ctx, u32 arg);

typedef struct Callbacks {
    Hook fn0;           /* 0x00 */
    Hook fn1;           /* 0x04 */
    Hook fn2;           /* 0x08 */
    u32 arg;            /* 0x0C */
    void *ctx;          /* 0x10 */
} Callbacks;

int func_02160A64(Callbacks *c)
{
    if (c->fn1 != 0)
        return c->fn1(c->ctx, c->arg);
    return 1;
}
