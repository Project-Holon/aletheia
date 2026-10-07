/*
 * file:     event_field_proclink_p16.c
 * unit:     yes
 * function: func_02160A28, func_02160A4C, func_02160A64, func_02160A7C
 * address:  0x02160A28
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Rect {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 tag;
} Rect;

typedef int (*Hook)(void *ctx, u32 arg);

typedef struct Callbacks {
    Hook fn0;           /* 0x00 */
    Hook fn1;           /* 0x04 */
    Hook fn2;           /* 0x08 */
    u32 arg;            /* 0x0C */
    void *ctx;          /* 0x10 */
} Callbacks;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h);
int func_02160A4C(Callbacks *c);
int func_02160A64(Callbacks *c);
int func_02160A7C(Callbacks *c);


/*
 * Clears a 0x14-byte record and fills it from five arguments.
 */
void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h)
{
    MI_CpuFill8(r, 0, sizeof(Rect));
    r->x = x;
    r->w = w;
    r->y = y;
    r->h = h;
    r->tag = tag;
}


/*
 * Runs the fn0 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */
int func_02160A4C(Callbacks *c)
{
    if (c->fn0 != 0)
        return c->fn0(c->ctx, c->arg);
    return 1;
}


/*
 * Runs the fn1 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */
int func_02160A64(Callbacks *c)
{
    if (c->fn1 != 0)
        return c->fn1(c->ctx, c->arg);
    return 1;
}


int func_02160A7C(Callbacks *c)
{
    if (c->fn2 != 0)
        return c->fn2(c->ctx, c->arg);
    return 1;
}
