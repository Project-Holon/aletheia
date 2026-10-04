/*
 * packet: pkt_ov186_021FFBD4
 * function: func_021FFBD4
 * address: 0x021FFBD4
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02200228 0x02200228 thumb ov186
 *   func_0220014C 0x0220014C thumb ov186
 *   d_02200D9C 0x02200D9C data a1
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02082BCC(void *, int, unsigned);
extern u32 func_0201C440(void *p);
extern int func_02200228(unsigned short, unsigned *);
extern int func_0220014C(void *p, u32 n, const u16 *ids);
extern const char d_02200D9C[];
char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap)
{
    char *p;
    int i = 0;
    p = func_02030734(heap, 0x90, 0, d_02200D9C, 0x11a);
    func_02082BCC(p, 0, 0x90);
    *(unsigned short *)(p + 0x24) = heap;
    *(void **)(p + 0x7c) = owner;
    *(void **)(p + 0x28) = table;
    *(int *)(p + 0x30) = c;
    *(int *)(p + 0x34) = a;
    *(int *)(p + 0x38) = b;
    *(void **)(p + 0x3c) = (void *)func_0201C440((void *)(*(unsigned short *)(p + 0x24)));
    *(int *)(p + 0x80) = func_02200228((heap & 0x7fff) | 0x8000, (unsigned *)(p + 0x84));
    *(int *)(p + 0x74) = d;
    *(int *)(p + 0x78) = e;
    for (; i < 9; i++) *(unsigned char *)(p + i + 0x14) = func_0220014C(*(void **)(p + 0x7c), i, (const u16 *)(*(unsigned *)(p + 0x80)));
    return p;
}
