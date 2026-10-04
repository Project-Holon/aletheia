/*
 * function: func_021D33FC
 * address:  0x021D33FC
 * packet:   pkt_ov021_021D33FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: EXACT.  The prologue and final call-setup residue of the
 * earlier draft was parameter width: a1 and a2 are u16 (a1 is the u16 key
 * func_021D3554 compares, a2 the u16 heap id of func_021D3478), which pins
 * their home stores to the front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 *
 * Recursive MATCH unblocker attempt: non-SDK dep of the matched func_021D33A8
 * (its +0010 branch target in the field_palace_sys.c tree).  Every relocation
 * resolves (0x0215850C / 0x02158468 as EXACT ov010 `matched`, 0x021D3478 as
 * `sole-ref`), the size is exact, and the logic is recovered.  The residue
 * that remained was scheduling, closed by the u16 parameters above.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_0215850C  0x0215850C  thumb  ov010
 *   func_02158468  0x02158468  thumb  ov010
 *   func_021D3478  0x021D3478  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02013D74(u32 key);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021D3554(void *, int);
extern int func_0215850C(int a0, int a1);
extern int func_02158468(int);
extern void func_021D3478(u8 *a, u32 id, int c, int d, u16 heap);

void func_021D33FC(u8 *a0, u16 a1, u16 a2)
{
    int r6;
    int r7;
    void *r4;
    int t;
    int s;

    r6 = (int)func_02012138(*(void **)a0);
    if (func_02013D74(a1) != 1)
        return;
    if (r6 == 0)
        return;
    r4 = func_020120F4(*(void **)a0);
    r7 = func_021D3554(r4, a1);
    t = func_0215850C(r6, (int)r4);
    s = 0xffff;
    if (t == 2) {
        if (r7 == 1)
            s = 1;
        else
            s = 0;
    } else if (t == 1) {
        if (r7 == 1)
            s = 3;
        else
            s = 2;
    }
    if (s == 0xffff)
        return;
    func_021D3478(a0, s, a1, func_02158468(r6), a2);
}
