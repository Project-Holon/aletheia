/*
 * function: GAMESYSTEM_UpdateAutoComm
 * address:  0x0201205C
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120D8     0x020120D8  thumb
 *   func_02012114     0x02012114  thumb
 *   func_0201210C     0x0201210C  thumb
 *   func_02188BE8     0x02188BE8  thumb  ov021
 *   func_020121CC     0x020121CC  thumb
 *
 * Three nested tests sharing one epilogue: the object is driven through
 * func_020121CC only when func_020120D8 returns 0, func_02012114 returns 1
 * and the overlay call returns 1 as well.  That last call's argument is
 * func_0201210C(p)'s result - r0 is not reloaded in between, which is what
 * the source's nesting says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_UpdateAutoComm.c \
 *       --func GAMESYSTEM_UpdateAutoComm --addr 0x0201205C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f8;         /* +0x08 */
    u32 pad0c;      /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 f14;        /* +0x14 */
    u32 pad18;      /* +0x18 */
    u32 f1c;        /* +0x1C */
    u32 f20;        /* +0x20 */
    u32 f24;        /* +0x24 */
    u32 pad28;      /* +0x28 */
    u32 f2c;        /* +0x2C */
};

extern int func_020120D8(char *p);
struct Ctx;
extern u32 func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *v);   /* overlay-resident */
extern u32 func_020121CC(struct IcaAnime *p);

void GAMESYSTEM_UpdateAutoComm(struct IcaAnime *p)
{
    if (func_020120D8((char *)p) == 0) {
        if (func_02012114((const struct Ctx *)p) == 1) {
            if (func_02188BE8(func_0201210C((const struct Ctx *)p)) == 1)
                func_020121CC(p);
        }
    }
}
