/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020140B4
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_DeleteAreaData, ZONEDATA_GetAreaTexSetId, ZONEDATA_GetAreaItaAnimeId, ZONEDATA_GetAreaItpAnimeId,
 *           ZONEDATA_GetAreaInnerOuter, ZONEDATA_GetAreaLightType, ZONEDATA_GetAreaEdgeMarkType, ZONEDATA_GetAreaBillboardColor
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *
 * alias: ZONEDATA_DeleteAreaData is a bare tail call to the ARM function
 * GFL_HEAP_Free: the compiler cannot tell caller and callee interwork, so
 * it always spends a pool word and `bx` rather than ever emitting a direct
 * branch (docs/idioms/tail-call-is-a-pool-word-and-bx.md), even though the
 * wrapper's own body is otherwise empty.
 *
 * ZONEDATA_GetAreaTexSetId through ZONEDATA_GetAreaBillboardColor are seven more leaf accessors on a
 * small object passed in directly (not through ZONEDATA_GetHeader()), hiding in
 * the same way: none of the seven save `lr`, so disasm.py's prologue sweep
 * never labels them and they print as a run of `.word`s between two
 * literal pools (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Two of them (offsets 0x04 and 0x05) return the sentinel 0xFFFFFFFF in
 * place of a stored byte value of 0xFF, rather than the plain
 * zero-extended byte every other accessor here returns.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020140B4.c \
 *       --addr 0x020140B4 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub020140BCObj {
    u16 f00;
    u16 f02;
    u8  f04;
    u8  f05;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
};

extern u32 GFL_HEAP_Free(void *p);

u32 ZONEDATA_DeleteAreaData(void *a)
{
    return GFL_HEAP_Free(a);
}

u16 ZONEDATA_GetAreaTexSetId(struct Sub020140BCObj *p)
{
    return p->f02;
}

u32 ZONEDATA_GetAreaItaAnimeId(struct Sub020140BCObj *p)
{
    if (p->f04 == 0xFF)
        return (u32)-1;
    return p->f04;
}

u32 ZONEDATA_GetAreaItpAnimeId(struct Sub020140BCObj *p)
{
    if (p->f05 == 0xFF)
        return (u32)-1;
    return p->f05;
}

u8 ZONEDATA_GetAreaInnerOuter(struct Sub020140BCObj *p)
{
    return p->f06;
}

u8 ZONEDATA_GetAreaLightType(struct Sub020140BCObj *p)
{
    return p->f07;
}

u8 ZONEDATA_GetAreaEdgeMarkType(struct Sub020140BCObj *p)
{
    return p->f08;
}

u8 ZONEDATA_GetAreaBillboardColor(struct Sub020140BCObj *p)
{
    return p->f09;
}
