/*
 * function: func_02169800
 * address:  0x02169800
 * packet:   pkt_ov010_02169800
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 */

typedef unsigned int u32;

typedef void (*Cb)(void *a, u32 b, u32 *c, u32 d, u32 e);

extern void func_0207CA00(u32 c, void *p, u32 *out);

void func_02169800(void *a, char *b, u32 c, u32 d)
{
    u32 buf[3];
    u32 e;
    Cb cb;

    *(u32 *)((char *)a + 0x100) = 0;
    if (*(u32 *)(b + 0xd0) != 0) {
        e = *(u32 *)(b + 8);
        func_0207CA00(c, b + 4, buf);
        cb = *(Cb *)(*(char **)(b + 0x28) + *(int *)(b + 0x18) * 16 + 8);
        if (cb != 0)
            cb(a, *(u32 *)(b + 0xd4), buf, d, e);
    }
}
