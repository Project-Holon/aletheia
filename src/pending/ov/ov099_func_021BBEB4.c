/*
 * function: func_021BBEB4
 * address: 0x021BBEB4
 * packet: pkt_ov099_021BBEB4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note-2026-10-04: DIFF. Draft structure complete (struct O local with fields dc e0 e8 f0 19c 1334 1344 1348). Residue at the top: original keeps mode in r4 and the 0x19c index in r6 (str r0,[r5,r6] twice), and lays the 12/16 choice as cmp r4,#1; bne; movs 0xc; b; movs 0x10 after the first store; ours puts mode in r6, rematerialises 0x67<<2 and emits movs r0,#0x10; cmp; bne; movs r0,#0xc. Tried: ternary, if/else, != form, local w, u8 param type (adds lsls/lsrs, wrong). Rest of body (second half and the 6-iteration loop) not yet compared past the first 0x70 bytes because of the shift; recheck after the front matches. Original pool: 0x1334, 0x1344 (word 0x1348 is f1348 via r6+0x14).
 * 2026-10-05 (wave D4 lane 04): DIFF, 116 bytes. The 12/16 choice is the func_020450F0 call written in
 * each arm of if (mode == 1); the tail-merged call gives the movs; b; movs shape. Front now matches
 * through +0x130. Residue is the 6-iteration loop: original keeps flags in r7 (lsls r7,r7,#6 after the
 * f19c load), spills i*4 to [sp,#0x10] and y = (base + i*2)*8 to [sp,#0x20], reloads p->f1344 into r6
 * per call; ours spills flags<<6 to [sp,#0x10], keeps y in r6 and i*4 in r7 (frame push r3 + 0x20 vs
 * 0x24). Tried: int flags; a named y declared first (flags then in r7, but y at [sp,#0x14] and i*4 in
 * r6, 127 bytes); flags <<= 6 as a statement; house prototype of func_0201C7D0 (its u16 last parameter
 * adds a lsls/lsrs the original does not have).
 * 2026-10-05 (wave D5 lane 08): DIFF, 116 bytes, unchanged. Reading: the original spills BOTH i*4 and y
 *   while r6 stays free in the loop (r6 only takes the per-call p->f1344 load), so its interference
 *   graph has more loop nodes than ours. Tried: a void **tbl local assigned p->f1344 before each call
 *   (propagated away, identical output), tbl plus a named y declared first (127 bytes, as D4).
 * symbols:
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201A4D4 0x0201A4D4 thumb
 *   func_0200AE3C 0x0200AE3C thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern int func_021BA8BC(void *);
extern u32 func_020450F0(u32,u32,u32,u32,u32,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_020456F8(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_0201F73C(void *,int,int,int);
extern void func_0201DD68(void);
extern void *func_0201A4D4(void *,void *,u32,u32);
extern void *func_0200AE3C(void *,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(void *);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_0201C7D0(void *,int,s16,void *,void *,u32);
extern void func_02045334(struct Descriptor *);
struct O {
    u8 p0[0xdc];
    void *fdc, *fe0, *fe4, *fe8, *fec, *ff0, *ff4;
    u8 pf8[0x19c - 0xf8];
    void *f19c;
    u8 p1a0[0x1334 - 0x1a0];
    u32 f1334;
    u8 p1338[0x1344 - 0x1338];
    void **f1344;
    void **f1348;
};
void func_021BBEB4(struct O *p, u32 mask, u32 a, u32 mode)
{
    int base;
    int i;
    u32 flags;
    void *t;
    u32 w;
    base = 4;
    a = (a == 1) ? 1 : 0;
    p->f19c = (void *)func_021BA8BC(p->f19c);

    if (mode == 1) p->f19c = (void *)func_020450F0(2, 2, 5, 26, 12, 15, 1); else p->f19c = (void *)func_020450F0(2, 2, 5, 26, 16, 15, 1);
    func_02043B5C(func_02045770(p->f19c), 255);
    func_020456F8(p->f19c);
    func_02045374(p->f19c);
    func_0201F73C(p->f19c, 1, (u16)p->f1334, 14);
    func_0201DD68();
    p->f1344 = func_0201A4D4(p->f1348, p->fdc, 33, a);
    if (mode == 0) {
        t = func_0200AE3C(p->f1348, 33);
        func_0201C7A4(func_02045770(p->f19c), 0, 0, t, p->fe8);
        func_02045808(t);
    } else if (mode != 1) {
        func_02045CAC(p->fe0, (mode == 2) ? 0x66 : 0x67, p->ff0);
        func_0201C7A4(func_02045770(p->f19c), 0, 0, p->ff0, p->fe8);
    }
    if (mode == 1) base = 0;
    for (i = 0; i < 6; i++) {
        flags = (mask & (1 << i)) ? 0x41 : 0x11;
        func_0201C7D0(func_02045770(p->f19c), 0, (s16)((base + i * 2) * 8), p->f1344[i + 1], p->fe8, flags << 6);
        func_0201C7D0(func_02045770(p->f19c), 0x70, (s16)((base + i * 2) * 8), p->f1344[i + 7], p->fe8, flags << 6);
    }
    func_02045334(p->f19c);
}
