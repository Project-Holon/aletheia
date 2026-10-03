/*
 * function: func_0216E2E8
 * address: 0x0216E2E8
 * packet: pkt_ov010_0216E2E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Direct halfword-aligned 28-byte Record assignments restore ctx=r5/id=r4/out=r6.
 * A named u16 offset and const context parameter restore the last stack store.
 * symbols:
 * func_0216DD1C 0x0216DD1C thumb ov010
 * func_0216D598 0x0216D598 thumb ov010
 * func_0200F128 0x0200F128 thumb
 * func_0204944C 0x0204944C arm
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DD1C(void *c, void **out, u32 *iter);
extern u16 func_0216D598(void *p);
extern u32 func_0200F128(u32 id);
extern void func_0204944C(void *a, int b, u16 c, int d, void *e);

typedef struct Record { u16 fields[14]; } Record;

void func_0216E2E8(const char *ctx, u16 id, Record *out)
{
    u16 offset;
    int i;
    u32 j;
    u16 n;
    u16 *tbl;
    u32 iter;
    void *rec;

    tbl = *(u16 **)(ctx + 0x44);
    n = tbl[0];

    if (n < 0x1a) {
        u16 k = ((n + 1) / 2) * 2;
        char *recs = (char *)tbl + (k + 2) * 2;
        for (i = 0; i < n; i++) {
            if (id == tbl[i + 1]) {
                u16 *src = (u16 *)(recs + i * 0x1c);
                *out = *(Record *)src;
                return;
            }
        }
    }
    iter = 0;
    if (func_0216DD1C((void *)ctx, &rec, &iter)) {
        do {
            if (id == func_0216D598(rec)) {
                u16 *src = (u16 *)((char *)rec + 0xe4);
                *out = *(Record *)src;
                return;
            }
        } while (func_0216DD1C((void *)ctx, &rec, &iter));
    }
    offset = func_0200F128(id) * 0x1c + 4;
    func_0204944C(*(void **)(ctx + 0x14), 0, offset, 0x1c, out);
}
