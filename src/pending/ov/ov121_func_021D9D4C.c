/*
 * function: func_021D9D4C
 * address: 0x021D9D4C
 * packet: pkt_ov121_021D9D4C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wave P13 lane B7): 14 of 184 bytes differ, size equal. Only residue: the entry block. Original
 *   str r3; adds r7,r1; str r2; ldr r5,[sp,#0x28]; ldr r0,=0x1ae; ldr r3,=site; str r0,[sp].
 *   Build hoists ldr r0,=0x1ae above str r3. Body is byte-equal after that.
 *   Needs 0203101C tag parameter declared u32 here (u16 gives an lsls/lsrs pair; heap u8 gives ldrb; heap u16 188 B).
 *   Tried: heap u32/int/local copy; inline allocate wrapper; tag in a u16 local; p declared at first use; a/b widths
 *   (u8 a, u32 b both worse); c,d as u32 or const void *; 02030734 tag u32 or heap u16 (167 B); the six per-function
 *   pragmas (no change). Twin search: grep func_0203101C( in src/matched/ov (ov035 021F0168, ov223 021BAE00, ov111,
 *   ov116 021D7B70 pass heap, heap with int or u16 tag, all EXACT/EXACT*). Callee types: all non-void as matched.
 *   Idioms read: heap-id-passed-unnarrowed (u8 not usable: ldrb), later-parameters-width-reorders-entry-spill-stores,
 *   forwarder-copies-stack-argument, two-long-lived-values, callee-declared-void.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028470 0x02028470 thumb
 *   d_021DFBA0 0x021DFBA0 data a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor; struct CharBuf; struct Cfg; struct Tcbl; struct U16Vec;
extern const char d_021DFBA0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct Tcbl *func_0203101C(u32 heap, u32 tag, u32 count, u32 workSize);
extern void func_02028470(u8 *p, u32 v);
void *func_021D9D4C(u32 a, u8 b, void *c, void *d, u32 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = func_02030734(heap, 0x40, 0, d_021DFBA0, 0x1ae);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    func_02028470(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = func_020457B0(0x200, heap);
    q = (struct Descriptor *)func_020450F0((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    func_02045334(q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730(q));
    *(struct Tcbl **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}
