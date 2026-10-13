/*
 * function: EVENT_SHORTCUT_MENU_CallResumeHook
 * address:  0x02160A4C
 * packet:   pkt_ov010_02160A4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs the fn0 hook of the callback record EVENT_SHORTCUT_MENU_InitHooks fills, or
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

int EVENT_SHORTCUT_MENU_CallResumeHook(Callbacks *c)
{
    if (c->fn0 != 0)
        return c->fn0(c->ctx, c->arg);
    return 1;
}
