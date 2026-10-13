/*
 * function: BLINK_PALANM_Create
 * address:  0x0202E940
 * packet:   pkt_0202E940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x3c and 0x3d).
 *
 * The mode chain must write `p->w14` in EVERY arm, not into a local read
 * once at the end: with the local the scheduler hoists `movs r0, #0xf`
 * above the `cmp` and saves the branch, and the tail comes out two bytes
 * short (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   blink_palanm_File    0x020A7804  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char blink_palanm_File[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

struct CodeIn {
    u32 w00;      /* 0x00 */
    u32 w04;      /* 0x04 */
    void *buf;    /* 0x08 */
    u16 h0c;      /* 0x0c */
    u16 h0e;      /* 0x0e */
    u16 h10;      /* 0x10 */
    u16 h12;      /* 0x12 */
    u32 w14;      /* 0x14 */
    u16 h18;      /* 0x18 */
};

struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap)
{
    struct CodeIn *p;

    p = func_02030734(heap, sizeof(struct CodeIn), 0, blink_palanm_File, 0x3c);
    p->buf = func_02030734(heap, (u32)a1 * 2, 0, blink_palanm_File, 0x3d);
    p->h0c = a0;
    p->h0e = a1;
    p->h10 = 0;
    p->h12 = 0;
    p->h18 = heap;
    if (a2 == 0xfffe) {
        p->w14 = 0xe;
    } else if (a2 == 0xffff) {
        p->w14 = 0x1e;
    } else if (a2 <= 3) {
        p->w14 = 0xf;
    } else {
        p->w14 = 0x1f;
    }

    return p;
}
