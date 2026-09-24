/*
 * function: func_0216D780
 * address:  0x0216D780
 * packet:   pkt_0216D780
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indirect call through the entry the object's vtable pointer
 * holds, skipped when the slot is empty.
 *
 * symbols:
 *   (none: no relocation site)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_0216D780(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)*(void **)((char *)a0 + 0x90) + 0xC);

    if (fn != 0)
        fn(a0);
}

