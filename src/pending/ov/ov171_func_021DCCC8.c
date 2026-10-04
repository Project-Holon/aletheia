/*
 * function: func_021DCCC8
 * address: 0x021DCCC8
 * packet: pkt_ov171_021DCCC8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-04 (wD1 lane18): control flow and registers match (r6=p, r7=row offset, p+0xC
 * temp hoisted after the guard). Residue: stack slot order of the spilled locals.
 * Original frame: temp d@0, i@4, o@8, c@0xc, j@0x10; compiled: c@0, o@4, i@8, d@0xc, j@0x10.
 * Declaration order did not change the slot order. Also the p+0xB4 operand: original
 * computes (p+0xB4) fresh then +r; compiled adds r first. Spelling p+0xB4+r hoists p+0xB4
 * into a spill (worse). Callee prototypes guessed (all thumb except func_020457B0).
 * 2026-10-04 (wD2 lane19): original temps by slot (low to high): d(p+0xC+r) @0, e(p+i*0xBC) @4, o @8, c @0xc, j @0x10.
 *   Declaring j,c,o,e,d,i,k at function scope reorders e/o/c but the d temp stays at 0xC; hoisting d before the k loop or
 *   `(u8*)((u32)(p+0xB4)+(u32)r)` grows the frame to 0x18 (worse). Residue: d temp slot and (p+0xB4)+r operand order.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02012F68 0x02012F68 thumb
 *   func_0200EC14 0x0200EC14 thumb
 *   func_0200EC98 0x0200EC98 thumb
 *   func_0200EC2C 0x0200EC2C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200725C 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200ECD0 0x0200ECD0 thumb
 *   func_0200ECC4 0x0200ECC4 thumb
 *   func_0200ED14 0x0200ED14 thumb
 *   func_0200ECF0 0x0200ECF0 thumb
 *   func_020072A4 0x020072A4 thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02012F68(void *a);
extern int func_0200EC14(void *a);
extern void func_0200EC98(void *a, void *b);
extern void func_0200EC2C(void *a, int i, void *dst);
extern void *func_02012EBC(void *a);
extern u32 func_0200725C(void *c, u32 id, u32 heap);
extern void *func_020073D8(void *c, u32 id, u32 v);
extern int func_0200ECD0(void *o, int i);
extern int func_0200ECC4(void *o, int i);
extern void func_0200ED14(void *o, int i, void *dst);
extern void func_0200ECF0(void *o, int i, int k, void *dst);
extern void func_020072A4(void *c, u32 id);

struct S { void *f0; u16 f4; };

void func_021DCCC8(u8 *p)
{
    u16 i, k;
    u16 j;
    u8 *d;
    void *o;
    void *c;
    struct S *s;
    for (i = 0; i < 15; i++) {
        u8 *e = p + i * 0xBC;
        for (k = 0; k < 6; k++) {
            u8 *q = e + k * 0x1c;
            *(void **)(q + 0xC) = func_020457B0(0x20, 0x8c);
            *(void **)(q + 0x10) = func_020457B0(0x20, 0x8c);
        }
    }
    s = *(struct S **)p;
    if (s->f4 == 0) {
        void *h = func_02012F68(s->f0);
        *(u16 *)(p + 0xC4) = func_0200EC14(h);
        func_0200EC98(h, p + 0xB4);
        for (k = 0; k < *(u16 *)(p + 0xC4); k++)
            func_0200EC2C(h, k, p + 0xC + k * 0x1c);
        p[0xC5F] = 1;
    } else {
        c = func_02012EBC(s->f0);
        u32 id = 8;
        if (func_0200725C(c, id, 0x8c) == 1) {
            o = func_020073D8(c, id, 0);
            if (o) {
                for (j = 0; j < 15; j++) {
                    int r = j * 0xBC;
                    *(u16 *)(p + r + 0xC4) = func_0200ECD0(o, j);
                    *(u16 *)(p + r + 0xC6) = func_0200ECC4(o, j);
                    func_0200ED14(o, j, p + r + 0xB4);
                    for (k = 0; k < *(u16 *)(p + r + 0xC4); k++) {
                        d = p + r + 0xC;
                        func_0200ECF0(o, j, k, d + k * 0x1c);
                    }
                    p[0xC5F]++;
                }
            }
        }
        func_020072A4(c, id);
    }
}
