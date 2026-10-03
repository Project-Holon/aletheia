/*
 * function: func_021BA128
 * address: 0x021BA128
 * packet: pkt_ov181_021BA128
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 02048AE8, 02048AFC, 02048B30, 02048B44 have no witness.
 *   Ilias owns these accessors. Existing unit_02048AD0.c defines them but
 *   its function header lists only func_02048AD0, so no individual shard entries resolve them.
 * blocker: Verified separately with one --arm (no region), fixed compiler/flags:
 *   typedef unsigned char u8; typedef unsigned int u32;
 *   typedef struct { int x, y, z; } Vec;
 *   struct Light { u32 unk00, unk04, unk08; u8 pad0C[8]; u32 unk14, unk18;
 *     u8 pad1C[4]; Vec unk20, unk2C, unk38; };
 *   0x02048AE8 EXACT 20B: void func_02048AE8(struct Light *l, Vec *out) { *out = l->unk20; }
 *   0x02048AFC EXACT 16B: void func_02048AFC(struct Light *l, const Vec *in) { l->unk20 = *in; }
 *   0x02048B30 EXACT 20B: void func_02048B30(struct Light *l, Vec *out) { *out = l->unk38; }
 *   0x02048B44 EXACT 16B: void func_02048B44(struct Light *l, const Vec *in) { l->unk38 = *in; }
 * symbols:
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_021BA028 0x021BA028 thumb ov181
 *   func_021BA0AC 0x021BA0AC thumb ov181
 *   func_021BA000 0x021BA000 thumb ov181
 *   func_021BA2A8 0x021BA2A8 thumb ov181
 */
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
struct Light;
extern void func_02048AE8(struct Light *, Vec *);
extern void func_02048B30(struct Light *, Vec *);
extern void func_02048AFC(struct Light *, const Vec *);
extern void func_02048B44(struct Light *, const Vec *);
extern void func_02048AD0(struct Light *);
extern void func_021BA028(Vec *, const Vec *, const Vec *, unsigned);
extern void func_021BA0AC(Vec *, const Vec *, const Vec *, unsigned);
extern void func_021BA000(char *);
extern void func_021BA2A8(char *, int);
void func_021BA128(char *p)
{
    Vec a, b, c, d, e;
    char *q;
    q = p + 0x28;
    if (*(int *)(q + 0x7c) == 0) return;
    if (*(u16 *)(q + 0x78) == 0) {
        *(u16 *)(q + 0x7a) = *(u16 *)(q + 0x36);
        func_02048AE8(*(struct Light **)(p + 0xc), &a);
        func_021BA028(&b, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x1c) = b;
        func_02048B30(*(struct Light **)(p + 0xc), &a);
        func_021BA028(&c, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x28) = c;
    }
    if (*(u16 *)(q + 0x78) >= *(u16 *)(q + 0x7a)) {
        *(Vec *)(q + 4) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24);
        *(Vec *)(q + 0x10) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12);
        *(u16 *)(q + 0x76) = *(u16 *)(q + 0x34);
        *(u16 *)(q + 0x78) = 0;
        func_021BA000(q);
        if (*(u16 *)(q + 0x34) == 0xffff) func_021BA2A8(q, 0);
    } else {
        func_021BA0AC(&d, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24), (Vec *)(q + 0x1c), *(u16 *)(q + 0x78));
        *(Vec *)(q + 4) = d;
        func_021BA0AC(&e, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24 + 12), (Vec *)(q + 0x28), *(u16 *)(q + 0x78));
        *(Vec *)(q + 0x10) = e;
        if (*(unsigned char *)(p + 0x2d2) == 1) *(u16 *)(q + 0x78) += 4;
        else ++*(u16 *)(q + 0x78);
    }
    func_02048AFC(*(struct Light **)(p + 0xc), (Vec *)(q + 4));
    func_02048B44(*(struct Light **)(p + 0xc), (Vec *)(q + 0x10));
    func_02048AD0(*(struct Light **)(p + 0xc));
}
