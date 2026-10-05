/*
 * function: func_021B9920
 * address:  0x021B9920
 * packet:   pkt_ov217_021B9920
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD5 lane19): still DIFF 28 B. Tried: const char * on the second callee argument, u8 first parameter on 020409B4, a ternary-wrapped second 5 (stand-in, not usable). The 5 is still hoisted into the free r6 for block 4.
 *
 * Note 2026-10-04 (wD2 lane12): re-read the listing. Original block 4 loads movs r0,#5 twice (before the 2041090 call after ldr r1,[sp,#8], and again before 20409B4) and keeps 0x20 in r7. We CSE the 5 into r6. No new spelling tried beyond the D1 list; next idea: make the two 5s distinct expressions (different callee parameter types, one callee taking a one-field struct or u16).
 *
 * note 2026-10-02: all but 4 bytes match. Original keeps 0x20 hoisted in r7
 *   but rematerialises the final block's `movs r0,#5` for the 20409B4 call;
 *   we hoist it into r6 (movs r6,#5 before the 2041090 call). Tried separate
 *   handle local, int/u32/u8 first-arg prototypes.
 *
 * Note 2026-10-04 (wD1 lane06): Retried: u8 prototypes for the first argument of 2041090/20409B4, (unsigned char)5, 4+1, local bg, a static inline block helper for blocks 3 and 4. All keep hoisting movs r6,#5 (28 bytes differ). Likely because r6 is free in block 4 (handle lives in r5); block 3 cannot hoist 4 since r6 and r7 are busy.
 *
 * note 2026-10-05 (wD4 lane13): tried a shared int bg local assigned 4 then 5 for both blocks: same 28 bytes (5 hoisted into r6). Original keeps 0x20 in r7 across both blocks (hoisted) but rematerialises 4 and 5 per use, 0x18 per use; our block 4 hoists the 5 into the free r6.
 */

typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(void *arc, u32 idx, u32 heap);
extern void func_02062A98(void *, char **);
extern void func_02062A4C(void *, char **);
extern void func_02062B30(void *, char **);
extern void func_02040E78(int, int, int, int);
extern void func_02040B1C(int, int, int, int);
extern void func_02041090(int, char *, int, int, int, int);
extern void func_020409B4(int);
extern void func_020307B0(void *);
extern void func_02049238(void *);

void func_021B9920(u32 heap)
{
    void *arc = func_020490F4(0xc0, heap);
    void *h, *h4;
    char *p1, *p2, *p3, *p4;

    h = func_02049250(arc, 9, heap);
    func_02062A98(h, &p1);
    func_02040E78(4, *(int *)(p1 + 0xc), 0x200, 0);
    func_020307B0(h);

    h = func_02049250(arc, 0xa, heap);
    func_02062A4C(h, &p2);
    func_02040B1C(4, *(int *)(p2 + 0x14), *(int *)(p2 + 0x10), 0);
    func_020307B0(h);

    h = func_02049250(arc, 0xb, heap);
    func_02062B30(h, &p3);
    func_02041090(4, p3 + 0xc, 0, 0, 0x20, 0x18);
    func_020409B4(4);
    func_020307B0(h);

    h4 = func_02049250(arc, 0xc, heap);
    func_02062B30(h4, &p4);
    func_02041090(5, p4 + 0xc, 0, 0, 0x20, 0x18);
    func_020409B4(5);
    func_020307B0(h4);

    func_02049238(arc);
}
