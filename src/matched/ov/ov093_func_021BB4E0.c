/*
 * function: func_021BB4E0
 * address:  0x021BB4E0
 * packet:   pkt_ov093_021BB4E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* only because the listing runs on to the unlabelled `bx lr` stub at
 * 0x021BB56C. The inner copy loop reuses the first loop's counter `i`: a
 * separate `u8 j` gives the same code with count/j/base in r2/r0/r1 instead
 * of r1/r2/r0 (23 bytes). The rotated `while` reproduces the duplicated
 * reader call and the spilled p->rd.
 *
 * symbols:
 *   func_021EE9B4  0x021EE9B4  thumb  ov093
 *   func_021EE9E4  0x021EE9E4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021EE9B4(u8 *, void *, u8);
extern int func_021EE9E4(u8 *, int *, u8 *, u8 *, u32 *);

typedef struct {
    u8 pad0[0x68];
    u8 rd[0x4c];      /* 0x68 */
    u32 tab[4][3];    /* 0xb4 */
    u8 cnt[4];        /* 0xe4 */
} Obj;

void func_021BB4E0(Obj *p, void *src, u8 n)
{
    u8 i;
    u8 type;
    u8 count;
    int idx;
    u32 buf[3];

    idx = 0;
    for (i = 0; i < 4; i++)
        p->cnt[i] = 0;
    func_021EE9B4(p->rd, src, n);
    while (func_021EE9E4(p->rd, &idx, &type, &count, buf) != 0) {
        for (i = 0; i < count; i++)
            p->tab[type][i] = buf[i];
        p->cnt[type] = count;
    }
}
