/*
 * function: func_02205AB8
 * address: 0x02205AB8
 * packet: pkt_ov094_02205AB8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: entry reads use the indexed aggregate; the zero store uses its raw
 * offset. This avoids retaining a common entry pointer across both frees.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0220684C 0x0220684C thumb ov094
 *   func_02204C48 0x02204C48 thumb ov094
 *   d_0220AEB0 0x0220AEB0 data ov094 a1
 */
typedef unsigned short u16;
typedef struct { void *entry; int extra; } Entry;
typedef struct { char pad[0x1c8]; Entry entries[3]; } Work;
extern void func_0204B3B4(void *p);
extern void func_0204A8D4(unsigned int h);
extern void func_0204AFD8(unsigned int h);
extern void func_0204ADA4(unsigned int h);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern void *func_020056A0(void *cb, void *ctx, int a);
extern void func_0220684C(void *, void *, void *);
extern void func_02204C48(void *, int *);
extern const char d_0220AEB0[];
void func_02205AB8(char *p)
{
    int i;
    int empty = 1;
    int *ctx;
    for (i = 0; i < 3; i++) {
        if (((Work *)p)->entries[i].entry != 0) {
            func_0204B3B4(((Work *)p)->entries[i].entry);
            func_0204A8D4(*(int *)(p + i * 4 + 0x1b0));
            *(void **)(p + i * 8 + 0x1c8) = 0;
            *(int *)(p + i * 4 + 0x1b0) = -1;
            empty = 0;
        }
    }
    if (*(int *)(p + 0x1c0) != -1) {
        func_0204AFD8(*(int *)(p + 0x1c0));
        *(int *)(p + 0x1c0) = -1;
    }
    if (*(int *)(p + 0x1bc) != -1) {
        func_0204ADA4(*(int *)(p + 0x1bc));
        *(int *)(p + 0x1bc) = -1;
    }
    if (!empty) {
        ctx = func_02030734((u16)((*(u16 *)(p + 0x240) & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x11b2);
        ctx[0] = (int)p;
        func_0220684C(p, func_020056A0((void *)func_02204C48, ctx, 0), 0);
    }
}
