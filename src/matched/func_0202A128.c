/*
 * function: func_0202A128
 * address:  0x0202A128
 * packet:   pkt_0202A128
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0204A298  0x0204A298  arm
 *   func_02048F60  0x02048F60  arm
 *   sTpokeData82   0x020A76CC  data
 */

typedef unsigned int u32;

extern void *func_02030734(int heap, int size, int align, const char *file, int line);
extern int   func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void *func_02048F60(int a0, int a1, int a2);
extern const char sTpokeData82[];

typedef struct {
    int   handle;
    void *buf;
    void *buf4;
    u32   count;
} Tpoke;

Tpoke *func_0202A128(int heap)
{
    Tpoke *p;
    u32 size;

    p = (Tpoke *)func_02030734(heap, 0x10, 1, sTpokeData82, 82);
    p->handle = func_0204A298(0xd3, 0, 0, heap, &size);
    p->count = size >> 3;
    p->buf = func_02048F60(0x30, 0, heap);
    p->buf4 = (char *)p->buf + 4;
    return p;
}
