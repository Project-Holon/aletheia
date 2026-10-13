/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: CLACT_SetActorDrawEnable, CLACT_GetActorDrawEnable, CLACT_AddActorSurfacePos
 * address:  0x0204B3DC
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetSurfaceOrigin  0x0204CF74  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 *
 * Three consecutive members of one object's interface.  The object carries a
 * handle at +8, a packed flag word at +0x60 and an embedded sub-object at
 * +0x68 that the 0x0204Cxxx/0x0204Dxxx layer operates on.
 *
 *   CLACT_SetActorDrawEnable  set bit 26 of the flag word at +0x60.
 *   CLACT_GetActorDrawEnable  read it back.  Saves no lr, so disasm.py never labels it.
 *   CLACT_AddActorSurfacePos  move by a delta: ask CLACT_GetSurfaceOrigin for the current
 *                 position into a scratch pair, add the caller's s16 x/y
 *                 pair to it in a second scratch pair, and hand that to
 *                 CLACT_SetActorPos.
 *
 * The two 4-byte scratch pairs sit at sp+0 and sp+4; the later declaration
 * takes the lower stack address, so `pos` is declared before `dest`.
 *
 * The range deliberately starts at 0x0204B3DC rather than at this file's
 * real first function, CLACT_DeleteActor: that one's call to CLACT_ExitAnimCtl has
 * no witness anywhere in the image, so including it caps the whole unit at
 * MATCH.  --suggest-split names this exact cut; CLACT_DeleteActor is parked in
 * src/pending/CLACT_DeleteActor.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B3DC.c \
 *       --addr 0x0204B3DC --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed short   s16;

struct Vec2 {
    s16 x;
    s16 y;
};

struct Obj {
    u8   pad_00[8];
    void *unk_08;
    u8   pad_0c[0x54];
    u32  unk_60_0 : 26;
    u32  unk_60_26 : 1;
    u32  unk_60_27 : 5;
    u8   pad_64[4];
    u8   unk_68;
};

typedef unsigned short u16;
struct Actor;
struct Pt;
extern void CLACT_GetSurfaceOrigin(struct Obj *o, u32 id, u16 *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);

void CLACT_SetActorDrawEnable(struct Obj *p, u32 v)
{
    p->unk_60_26 = v;
}

u32 CLACT_GetActorDrawEnable(struct Obj *p)
{
    return p->unk_60_26;
}

void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which)
{
    struct Vec2 pos;
    struct Vec2 dest;

    CLACT_GetSurfaceOrigin(p, which, (u16 *)(&pos));
    dest.x = delta->x + pos.x;
    dest.y = delta->y + pos.y;
    CLACT_SetActorPos((struct Actor *)p, (const struct Pt *)(&dest));
}
