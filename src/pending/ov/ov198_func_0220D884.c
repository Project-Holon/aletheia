/*
 * function: func_0220D884
 * address:  0x0220D884
 * packet:   pkt_ov198_0220D884
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-05 (wD5 lane18): re-read only; no new source form found for keeping the 0x4C product live in r7 with q spilled. Unchanged 148 bytes.
 * 2026-10-05 (wD4 lane16): tried the record fields as p+m+K with no e local: identical 148 bytes. The original spills q (p+i*8) and gives m r7, so m is live across a call in the original; no source use of m after a call is visible in the listing.
 * symbols:
 *   func_0220D884  0x0220D884  thumb  ov198
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_022110D4  0x022110D4  thumb  ov198
 *   func_0220BEB8  0x0220BEB8  thumb  ov198
 *   func_0220D920  0x0220D920  thumb  ov198
 *   func_020276C4  0x020276C4  thumb
 *   func_0220D988  0x0220D988  thumb  ov198
 *   func_02211AFE  0x02211AFE  thumb  ov198
 */
/*
 * 2026-10-04 (wave D2 lane03): DIFF, unchanged (148 vs 156). Also tried p+i*8+K at each use with no q
 * local: identical output. Analysis: q (p+i*8) is live from the first load to the strb in one branch, so it
 * interferes with the 0x4C product m. The original gives m a callee-saved register (r7, `adds r7,r0,#0;
 * muls r7,r1,r7`) and spills q; mine gives q r7 and the product a scratch. Something keeps m's live range
 * long or heavy in the original (m used across a call is the likely reason).
 */
/*
 * 2026-10-04 (wave D1 lane07): DIFF, 148 bytes vs 156. Logic believed correct.
 * Residue: the original keeps two stack temps ([sp,#4] = p+i*8, [sp,#8] = 0x1F74-4 hoisted
 * before the loop) and a callee-saved r7 for the idx*0x4C product, so frame is 0xC with no
 * push r3. Mine keeps p+i*8 in r7 and spills only the constant (frame 8, push r3).
 * Tried: q = p+i*8 as a local, m = idx*0x4C as a named local, all 24 declaration orders.
 * Not tried: another live local that holds the product across the calls.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u8 lo:7,hi:1;} Bits;
struct Descriptor;
struct CharBuf;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern int func_022110D4(u8 *, int);
extern void func_0220BEB8(u8 *, int, int, u8, u8);
extern void func_0220D920(u8 *, int);
extern int func_020276C4(void *);
extern void func_0220D988(u8 *, int);
extern void func_02211AFE(void);

void func_0220D884(u8 *p)
{
    s16 i;
    u8 *e;
    u8 *q;
    int m;

    *(void **)(p + 0x253C) = (void *)func_02211AFE;
    for (i = 0; i < 6; i++) {
        q = p + i * 8;
        func_02043B5C((struct CharBuf *)func_02045770(*(struct Descriptor **)(q + 0x1F70)), 0);
        m = func_022110D4(p, i) * 0x4C;
        e = p + m;
        if (*(u16 *)(e + 8) == 0) {
            *(u8 *)(q + 0x1F74) = 1;
        } else {
            func_0220BEB8(p, i, (u16)i, 0x20, 7);
            if (!((Bits *)(e + 0x1B))->hi) {
                func_0220D920(p, (u8)i);
            }
            if (func_020276C4(*(void **)(e + 4)) == 8) {
                func_0220D988(p, (u8)i);
            }
        }
    }
}
