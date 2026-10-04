/*
 * unit:     no
 * function: func_020493D4
 * address:  0x020493D4
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
 *   func_020493D4_File 0x020A7EE0  data
 *   func_020493D4_Msg  0x020A7F18  data
 *
 * Return the byte length of one archive member without reading it: the
 * FAT entry's two words are fetched and subtracted, and the file cursor is
 * left parked on the FAT rather than on the member's data.
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020493D4.c  *       --func func_020493D4 --addr 0x020493D4 --cc 1.1p1 --arm
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

extern const char func_020493D4_File[];
extern const char func_020493D4_Msg[];

extern void func_02034734(const char *file, u32 line, const char *msg, ...);
typedef signed int     s32;
struct FSFile;
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

u32 func_020493D4(struct ArcFile *arc, u32 member)
{
    u32 range[2];

    if (arc->count <= member) {
        func_02034734(func_020493D4_File, 665, func_020493D4_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    return range[1] - range[0];
}
