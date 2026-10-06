/*
 * function: func_021DCCC8
 * address: 0x021DCCC8
 * packet: pkt_ov171_021DCCC8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-04 (wD1 lane18): control flow and registers match (r6=p, r7=row offset, p+0xC
 * temp hoisted after the guard). Residue: stack slot order of the spilled locals.
 * Original frame: temp d@0, i@4, o@8, c@0xc, j@0x10; compiled: c@0, o@4, i@8, d@0xc, j@0x10.
 * Declaration order did not change the slot order. Also the p+0xB4 operand: original
 * computes (p+0xB4) fresh then +r; compiled adds r first. Spelling p+0xB4+r hoists p+0xB4
 * into a spill (worse). Callee prototypes guessed (all thumb except func_020457B0).
 * 2026-10-04 (wD2 lane19): original temps by slot (low to high): d(p+0xC+r) @0, e(p+i*0xBC) @4, o @8, c @0xc, j @0x10.
 *   Declaring j,c,o,e,d,i,k at function scope reorders e/o/c but the d temp stays at 0xC; hoisting d before the k loop or
 *   `(u8*)((u32)(p+0xB4)+(u32)r)` grows the frame to 0x18 (worse). Residue: d temp slot and (p+0xB4)+r operand order.
 * 2026-10-05 (wD4 lane 08): DIFF, size now right (352 bytes), 49 diff lines. Found: the inner k loop has an explicit
 *   guard `if (count != 0) { for (...) ...; p[0xC5F]++; }` (original cmp r0,#0; beq past the ++, then the for guard).
 *   Residue: (1) stack slots (original d@0 i@4 o@8 c@0xc j@0x10, draft c@0 o@4 i@8 d@0xc); (2) the original forms
 *   (p+0xB4)+r and (p+0xC)+r (d computed once after the guard), the draft forms p+r first; p+0xB4+r spelling hoists both
 *   out of the j loop (364 bytes); (3) the original loads the 0xC5F pool word once for the ++, the draft twice.
 *   Tried: a Row struct array at p+0xC (stride 0xBC; ents[6] of 0x1c, hdr at +0xA8, cnt +0xB8): one pool load for the
 *   ++ but j*0xBC is computed twice (364 bytes); all accesses through the Row struct is worse (171 lines).
 * 2026-10-05 (wD5 lane 11): MATCH, all 352 bytes equal. Fix: a real struct (Row array at p+0xC, stride 0xBC:
 *   ents[6] of 0x1c, hdr[0x10] at +0xA8, cnt/cnt2 u16 at +0xB8/+0xBA; count byte at 0xC5F). &p->rows[j].hdr gives
 *   (p+0xB4)+r, &p->rows[j].ents[k] gives the hoisted (p+0xC)+r temp in the lowest slot, and locals j,c,o,i,k
 *   in that order give the frame. Only residue: func_0200ED14 (arm9, thumb) had no label. It is now filed EXACT
 *   as src/matched/arm9/func_0200ED14.c; once its shard exists this file should verify EXACT.
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
struct Big;
struct Ctrl;
struct Dst0200EC2C;
struct Out0200EC98;
struct Src0200EC2C;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02012F68(void **h);
extern int func_0200EC14(char *p);
extern void func_0200EC98(const u8 *o, struct Out0200EC98 *out);
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_0200ECD0(void *o, int i);
extern u32 func_0200ECC4(char *o, u32 n);
extern void func_0200ED14(u8 *o, int idx, void *out);
extern void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);

struct S { void *f0; u16 f4; };
struct Ent { void *a; void *b; u8 pad[0x14]; };
struct Row { struct Ent ents[6]; u8 hdr[0x10]; u16 cnt; u16 cnt2; };
struct P { struct S *s; u8 pad[8]; struct Row rows[15]; u8 pad2[0xC5F - 0xB10]; u8 n; };

void func_021DCCC8(struct P *p)
{
    u16 j;
    void *c;
    void *o;
    u16 i;
    u16 k;
    struct S *s;
    for (i = 0; i < 15; i++) {
        for (k = 0; k < 6; k++) {
            p->rows[i].ents[k].a = func_020457B0(0x20, 0x8c);
            p->rows[i].ents[k].b = func_020457B0(0x20, 0x8c);
        }
    }
    s = p->s;
    if (s->f4 == 0) {
        void *h = func_02012F68(s->f0);
        p->rows[0].cnt = func_0200EC14(h);
        func_0200EC98(h, (struct Out0200EC98 *)p->rows[0].hdr);
        for (k = 0; k < p->rows[0].cnt; k++)
            func_0200EC2C(h, k, (struct Dst0200EC2C *)(&p->rows[0].ents[k]));
        p->n = 1;
    } else {
        u32 id;
        c = func_02012EBC(s->f0);
        id = 8;
        if (func_0200725C(c, id, 0x8c) == 1) {
            o = func_020073D8(c, id, 0);
            if (o) {
                for (j = 0; j < 15; j++) {
                    p->rows[j].cnt = func_0200ECD0(o, j);
                    p->rows[j].cnt2 = func_0200ECC4(o, j);
                    func_0200ED14(o, j, p->rows[j].hdr);
                    if (p->rows[j].cnt != 0) {
                        for (k = 0; k < p->rows[j].cnt; k++)
                            func_0200ECF0(o, j, (void *)k, &p->rows[j].ents[k]);
                        p->n++;
                    }
                }
            }
        }
        func_020072A4(c, id);
    }
}
