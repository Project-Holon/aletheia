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
 *   GAMESYSTEM_IsEventActive     0x020120D8  thumb
 *   GAMESYSTEM_IsFieldMapExist     0x02012114  thumb
 *   GAMESYSTEM_GetFieldMap     0x0201210C  thumb
 *   FIELDMAP_IsReady     0x02188BE8  thumb  ov021
 *   GAMESYSTEM_TryStartAutoComm     0x020121CC  thumb
 *
 * Three nested tests sharing one epilogue: the object is driven through
 * GAMESYSTEM_TryStartAutoComm only when GAMESYSTEM_IsEventActive returns 0, GAMESYSTEM_IsFieldMapExist returns 1
 * and the overlay call returns 1 as well.  That last call's argument is
 * GAMESYSTEM_GetFieldMap(p)'s result - r0 is not reloaded in between, which is what
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

extern int GAMESYSTEM_IsEventActive(char *p);
struct Ctx;
extern u32 GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_IsReady(void *v);   /* overlay-resident */
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

void GAMESYSTEM_UpdateAutoComm(struct IcaAnime *p)
{
    if (GAMESYSTEM_IsEventActive((char *)p) == 0) {
        if (GAMESYSTEM_IsFieldMapExist((const struct Ctx *)p) == 1) {
            if (FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap((const struct Ctx *)p)) == 1)
                GAMESYSTEM_TryStartAutoComm(p);
        }
    }
}
