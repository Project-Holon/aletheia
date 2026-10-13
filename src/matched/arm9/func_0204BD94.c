/*
 * function: CLACT_InitRenderer
 * address:  0x0204BD94
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  label -- func_02065AA8 and CLACT_InitSurface, each reached only from
 *           this body (the tool prints "no witness outside 0204BD94..0204BE2C");
 *           CLACT_InitSurface lives in pkt_0204BE84, which is not this lane's.
 *
 * symbols:
 *   s_clact_c       0x020A7F74  data
 *   func_02065AA8   0x02065AA8  arm
 *   func_02030734   0x02030734  arm
 *   CLACT_InitSurface   0x0204BE84  arm
 *   func_02065B64   0x02065B64  arm
 *
 * Byte-identical at 148 bytes; only the two PC24 call fields at +0x14 and
 * +0x68 stay wildcarded.  The 0x020A7F74 pool word is ABS32 into the string
 * area and resolves `literal`, and func_02065B64 resolves `matched`.
 *
 * Spellings that mattered: `for (i = 0; i < count; i++)` with an unsigned `i`
 * and a signed `count` is what gives the single `popls` loop guard and the
 * `blo` back-edge.  Adding an explicit `if (count <= 0) return;` in front of
 * the loop emits BOTH `pople` and `popls` and costs four bytes of layout.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    u8 pad_00[0x80];
    u32 f80;
    u8 pad_84[0x14];
    u32 f98;
    u32 f9c;
};

extern const char s_clact_c[];

extern void func_02065AA8(u8 *o);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  CLACT_InitSurface(void *dst, void *src);
extern void func_02065B64(int p0, void *p1);

void CLACT_InitRenderer(struct Obj *obj, u8 *src, int count, u32 heap)
{
    u32 i;

    func_02065AA8((u8 *)obj);
    obj->f80 = 1;
    obj->f98 = (u32)func_02030734(heap, count * 0x48, 0, s_clact_c, 0xfc7);
    obj->f9c = count;
    for (i = 0; i < count; i++) {
        CLACT_InitSurface((void *)(obj->f98 + i * 0x48), src + i * 0x10);
        func_02065B64((int)obj, (void *)(obj->f98 + i * 0x48));
    }
}
