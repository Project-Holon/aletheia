/*
 * function: func_021C0C88
 * address:  0x021C0C88
 * packet:   pkt_ov099_021C0C88
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note: 2026-10-05 (wD8 lane05): not changed, 203 bytes. Re-read the image: the 0xb, 0x71 (r4 == 6), 0x76 and 0x37 paths
 *   share one `movs r0,#0x73; lsls; str r1,[r5,r0]` block; the r4 == 5 and DD60 paths have their own stores. No new
 *   source shape found for a 0x24C that is not a CSE candidate. Tried: f24c as a one-word struct member passed
 *   as `(char *)&p->f24c` (same 203 bytes).
 *
 * note: 2026-10-05 (wD7 lane09): not changed, still 203 bytes. New finding: the image never derives 0x1CC from 0x24C, and it rebuilds 0x274 after the shared f1cc store. A value local sel with goto store from the -2 and r4 == 6 paths and one store after the 0x76/0x37 if/else makes the tail rebuild 0x24C fresh (as in the image), but the r4 == 5 path still derives 0x1CC (subs r6,#0x80) and the r7 block derives 0x274 from 0x1CC (212 bytes, not kept). Diagnostic: with r6 forced busy the compiler spills the 0x24C constant to the stack, so it treats p + 0x24C and p + 0x1CC as one CSE family; the image does not. Also tried: DD54 call inside the switch default with break, a static inline accessor for p + 0x24C, an unused end: label, a switch on r4 for the 5/6 tests (234 bytes): no gain. Open question: what makes the DD54 argument 0x24C a non-CSE value in the image.
 *
 * note: 2026-10-05 (wD6 lane13): DIFF 203 bytes, size now 472 (was 468). The f1cc store is written in each arm (no sel local, rule 2); tail merging rebuilds the shared str and the tail no longer derives 0x274 from 0x1CC. Residue: the r4 == 5 path still derives 0x1CC from 0x24C kept in r6 (image: 0x24C in r1, 0x1CC rebuilt). Tried on top: nested ifs for the 5 path, raw offsets, goto to a shared return (146 B worse layout), a static inline store helper, a static inline wrapper for func_021BDD54, a value local in the 5 path: no change.
 *
 * note: DIFF vs 2026-10-04: skeleton matches (switch(r6){case -1 return; case -2 ...} layout, func_021BE2A8(p, index) hidden arg, r6=-2 when func_021BF050 true). Residue ~104 bytes: original rebuilds 0x24C (0x93<<2) and 0x1CC (0x73<<2) constants fresh at each use, ours CSEs them into r6 (subs r6,#0x80) and moves the 0x93 constant into r6 instead of r1. Size 468 vs 472. Tried: struct fields for 0x1CC/0x24C (no change).
 *
 * 2026-10-05 (wave D4 lane 04): DIFF, unchanged. Tried: raw p + 0x24c as the func_021BDD54 argument
 * with the struct f1cc store: no change. Ours puts the 0x24C call-argument constant in r6 (free after
 * the switch) and derives 0x1CC as r6 - 0x80 in the r4 == 5 path; the original builds 0x24C in r1 and
 * rebuilds 0x1CC. r6 is dead there in both, so this is a constant-CSE decision, not a colour swap.
 * 2026-10-05 (wave D5 lane 08): DIFF, 212 bytes (4-byte size shift). Fixed the k/2, k%2 registers:
 *   (r4 - 7) written inline in both stores (a named k swapped r1/r2). Residue: the original rebuilds
 *   0x1CC in the r4 == 5 path and 0x274 in the tail; ours keeps 0x24C in r6 and derives both. Tried: all
 *   struct accesses raw, a local off = 0x274 for the top block, the post-switch code as default:, a
 *   switch on r4 for the 5/6 tests (81 bytes but the wrong compare layout): none stops the derivation.
 * symbols:
 *   func_020200CC  0x020200CC  thumb
 *   func_021BF050  0x021BF050  thumb  ov099
 *   func_021B97F4  0x021B97F4  thumb  ov099
 *   func_021BE2A8  0x021BE2A8  thumb  ov099
 *   func_0203CB00  0x0203CB00  arm
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_021B9AE0  0x021B9AE0  thumb  ov099
 *   func_021BE900  0x021BE900  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_020061E4  0x020061E4  thumb
 *   func_021BDD54  0x021BDD54  thumb  ov099
 *   func_0202EB14  0x0202EB14  thumb
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BDDD0  0x021BDDD0  thumb  ov099
 *   func_021BDD60  0x021BDD60  thumb  ov099
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021C27E0  0x021C27E0  thumb  ov099
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct P { char a[0x1cc]; u32 f1cc; char b[0x7c]; char f24c[4]; };
extern int func_020200CC(u32 a);
extern int func_021BF050(char *p);
extern u8 func_021B97F4(char *p);
extern int func_021BE2A8(char *p, int key);
extern int func_0203CB00(void);
extern u32 func_021BA8BC(u32 a);
extern void func_0202020C(u32 a, int b, int c);
extern void func_0201F868(u32 a);
extern void func_021B9AE0(char *p, int v);
extern void func_021BE900(char *p);
extern void func_021BA8EC(char *p);
extern void func_020061E4(u32 a);
extern int func_021BDD54(char *p, char *s);
extern int func_0202EB14(void);
extern int func_0202EB0C(void);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BDDD0(char *p);
extern int func_021BDD60(int x);
extern void func_021BCC4C(char *p);
extern int func_021BDDF4(char *p);
extern int func_021C27E0(void *p);

int func_021C0C88(char *p, int v)
{
    int r6;
    int r4;
    int r7;

    r6 = func_020200CC(*(u32 *)(p + 0xbc));
    if (func_021BF050(p)) {
        r6 = -2;
    }
    u16 t = func_021B97F4(p + 0x274);
    *(u16 *)(p + 0x242) = t;
    r7 = func_021BE2A8(p, t);
    if (func_0203CB00()) {
        *(u32 *)(p + 0x1a4) = func_021BA8BC(*(u32 *)(p + 0x1a4));
        func_0202020C(*(u32 *)(p + 0xbc), 0, 0);
        func_0201F868(*(u32 *)(p + 0xb8));
        if (r7) {
            func_021B9AE0(p + 0x274, r7);
        }
        func_021BE900(p);
        return v;
    }
    if (r6 != -1) {
        func_021BA8EC(p);
        *(u32 *)(p + 0x1a4) = func_021BA8BC(*(u32 *)(p + 0x1a4));
        func_0202020C(*(u32 *)(p + 0xbc), 0, 0);
        func_0201F868(*(u32 *)(p + 0xb8));
    }
    switch (r6) {
    case -1:
        return v;
    case -2:
        func_020061E4(0x551);
        ((struct P *)p)->f1cc = 0xb;
        goto end;
    }
    func_020061E4(0x54c);
    r4 = func_021BDD54(p, ((struct P *)p)->f24c);
    if (r4 == 5 && !func_0202EB14() && func_0202EB0C()) {
        func_021BAAB8(p, 0x95, 0);
        ((struct P *)p)->f1cc = 0xa2;
        return v;
    }
    if (r4 == 6 && !func_021BDDD0(p)) {
        func_021BAAB8(p, 0x79, 0);
        ((struct P *)p)->f1cc = 0x71;
        goto end;
    }
    if (func_021BDD60(r4)) {
        *(u16 *)(p + 0x134c) = (r4 - 7) / 2;
        *(u16 *)(p + 0x134e) = (r4 - 7) % 2;
        func_021BCC4C(p);
        if (!func_021BDDF4(p)) {
            func_021BAAB8(p, 0x68, 0);
            ((struct P *)p)->f1cc = 0x71;
        }
    }
    *(u32 *)(p + 0x135c) = 2;
    r4 = func_021C27E0(((struct P *)p)->f24c);
    if (r4 == func_021C27E0(*(void **)(p + 8))) {
        ((struct P *)p)->f1cc = 0x76;
    } else {
        if (func_021C27E0(*(void **)(p + 8))) {
            func_021BAAB8(p, 0x49, 0);
        } else {
            func_021BAAB8(p, 0x48, 0);
        }
        ((struct P *)p)->f1cc = 0x37;
    }
end:
    if (r7) {
        func_021B9AE0(p + 0x274, r7);
    }
    return v;
}
