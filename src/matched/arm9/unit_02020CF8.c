/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02020CF8
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02020CF8, func_02020D0C, func_02020D10, func_02020D18
 *
 * symbols:
 *   func_02020D18_File  0x020A73A0  data
 *
 * func_02020D0C and func_02020D10 carry no label in the generated listing:
 * they are a two-instruction word getter and a two-instruction byte setter
 * with no register-saving prologue, so disasm.py's prologue sweep never
 * fires on them and the listing prints them as a run of data between
 * func_02020CF8 and func_02020D18
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * func_02020D18 is a debug-allocator constructor in the
 * `sub_02030734(heap, size, count, file, line)` shape documented for
 * playtime.c: it allocates a 12-byte object tagged with the string at
 * 0x020A73A0 and line 0x3a, zeroing the first word when the allocation
 * succeeds.  0x020A73A0 spells "bmp_cursor.c", the second original source
 * file name this project has recovered (after playtime.c); the functions
 * keep their sub_<address> names because the file identity is attested and
 * the individual entry points are not.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020CF8.c \
 *       --addr 0x02020CF8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8    pad[0x3C];
    void *unk3C;
};

extern void func_02020DC8(void *x, int heap);
extern void func_020206C0(struct Obj *p);

void func_02020CF8(struct Obj *p, int heap)
{
    func_02020DC8(p->unk3C, heap);
    func_020206C0(p);
}

u32 func_02020D0C(u8 *p)
{
    return *(u32 *)(p + 0x1C);
}

void func_02020D10(u8 *p, u8 v)
{
    p[0x4A] = v;
}

extern const char func_02020D18_File[];
extern void *func_02030734(u16 heap, u32 size, u32 count, const char *file,
                            u32 line);

void *func_02020D18(u32 heap)
{
    void *p = func_02030734((u16)heap, 0xc, 1, func_02020D18_File, 0x3a);

    if (p != 0) {
        *(u32 *)p = 0;
    }
    return p;
}
