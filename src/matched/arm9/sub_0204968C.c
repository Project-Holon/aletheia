/*
 * unit:     no
 * function: sub_0204968C
 * address:  0x0204968C
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062A4C       0x02062A4C  arm
 *   func_02040B1C       0x02040B1C  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * The write-into-an-existing-slot counterpart of src/matched/sub_0204979C.c:
 * the same func_02062A4C lookup and the same "size of zero means the object's
 * own size at +0x10" rule, but the result goes straight into func_02040B1C
 * instead of coming back as a packed handle, and the caller's handle is
 * released either way. The whole body sits inside the `if`, which is why the
 * failed lookup is a forward branch to the release rather than a shared exit
 * block.
 *
 * `and r0, r6, #0xff` is func_02040B1C's first parameter being `u8`, not a
 * mask written in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204968C.c \
 *       --func sub_0204968C --addr 0x0204968C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Res {
    u8 pad_00[0x10];
    u32 unk_10;
    u32 unk_14;
};

extern s32 func_02062A4C(void *buf, struct Res **out);
extern void func_02040B1C(u8 index, const void *src, u32 size, u32 tile);
extern void ENV_SetResourceSet(void *p);

u32 sub_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused)
{
    struct Res *res;

    if (func_02062A4C(buf, &res) != 0) {
        if (a3 == 0) {
            a3 = res->unk_10;
        }
        func_02040B1C(a1, (const void *)res->unk_14, a3, a2);
    }

    ENV_SetResourceSet(buf);
    return a3;
}
