/*
 * function: func_0204E01C
 * address:  0x0204E01C
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   func_0204E01C_File 0x020A7F74 data
 *
 * Allocate the 0x14-byte entry pool and mark every entry free.  The
 * allocation size is `count * sizeof(struct Entry)`, and the `mvn`-free
 * `mov r2, r4` is the alignment argument sharing the zero the loop counter
 * was just materialised into, so `i` must be spelled before the call, not
 * only in the `for` header.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 7494; it is declared as an extern array pinned by address,
 * never as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E01C.c \
 *       --func func_0204E01C --addr 0x0204E01C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Entry {
    u8  pad_00[0x10];
    u32 unk_10;
};

extern const char func_0204E01C_File[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);

struct Entry *func_0204E01C(u32 heap, u32 count)
{
    struct Entry *entries;
    u32 i;

    i = 0;
    entries = (struct Entry *)func_02030734(heap,
                                            count * sizeof(struct Entry), i,
                                            func_0204E01C_File, 7494);

    for (; i < count; i++) {
        entries[i].unk_10 = 1;
    }

    return entries;
}
