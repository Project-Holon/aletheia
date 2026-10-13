/*
 * unit:     yes
 * function: ICA_ANIME_Delete
 * address:  0x02011558
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle     0x02049238  arm
 *   func_020307B0     0x020307B0  arm
 *
 * ica_anime.c: destroy.  The one field that is a plain pointer (+0x04) goes
 * through the archive/handle call first, and the three heap buffers at
 * +0x1C, +0x20 and +0x24 are released only when the 0x34 flag says they were
 * allocated - all four calls are the same free function, including the last
 * one on the object itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011558.c \
 *       --addr 0x02011558 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */

typedef unsigned char  u8;
typedef signed int     s32;
typedef unsigned int  u32;

struct IcaAnime {
    u8  pad00[0x04];
    u32 f4;         /* +0x04 */
    u8  pad08[0x14];
    s32 f1c;        /* +0x1C */
    s32 f20;        /* +0x20 */
    s32 f24;        /* +0x24 */
    u8  pad28[0x0C];
    u32 f34;        /* +0x34 */
};

extern void ARC_TOOL_DeleteHandle(u32 h);
extern u32 func_020307B0(void *p);

void ICA_ANIME_Delete(struct IcaAnime *p)
{
    ARC_TOOL_DeleteHandle(p->f4);
    if (p->f34 != 0) {
        if (p->f1c != 0)
            func_020307B0((void *)p->f1c);
        if (p->f20 != 0)
            func_020307B0((void *)p->f20);
        if (p->f24 != 0)
            func_020307B0((void *)p->f24);
    }
    func_020307B0(p);
}
