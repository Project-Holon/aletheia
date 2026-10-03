/*
 * function: func_02062A4C
 * address:  0x02062A4C
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062B64  0x02062B64  arm
 *   func_02062A88  0x02062A88  arm
 *
 * Finds the 'RAHC' (NCGR character data), second entry point block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A4C.c  *       --func func_02062A4C --addr 0x02062A4C --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct NitroFileHeader;

extern void *func_02062B64(struct NitroFileHeader *file, u32 signature);
extern void func_02062A88(u8 *block);

s32 func_02062A4C(struct NitroFileHeader *file, void **out)
{
    void *block = func_02062B64(file, 0x43484152);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    func_02062A88((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}
