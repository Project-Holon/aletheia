/*
 * unit:     no
 * function: func_0204932C
 * address:  0x0204932C
 * packet:   pkt_02049250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034734      0x02034734  arm
 *   func_02078B44      0x02078B44  arm
 *   func_02078B70      0x02078B70  arm
 *   func_0204932C_File 0x020A7EE0  data
 *   func_0204932C_Msg  0x020A7F18  data
 *
 * Read one archive member straight into a caller-supplied buffer: the
 * allocating variant is func_02049250 one function above, and the FAT
 * lookup, the image-base offset and the length are identical.
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204932C.c  *       --func func_0204932C --addr 0x0204932C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ArcFile {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

extern const char func_0204932C_File[];
extern const char func_0204932C_Msg[];

extern void func_02034734(const char *file, u32 line, const char *msg, ...);
typedef signed int     s32;
struct FSFile;
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

void func_0204932C(struct ArcFile *arc, u32 member, void *dst)
{
    u32 range[2];

    if (arc->count <= member) {
        func_02034734(func_0204932C_File, 642, func_0204932C_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    func_02078B44((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);
    func_02078B70((struct FSFile *)arc, dst, range[1] - range[0]);
}
