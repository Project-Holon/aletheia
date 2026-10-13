/*
 * function: POKELIST_MoveCursorToPlate
 * address:  0x021B8F68
 * packet:   pkt_ov091_021B8F68
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_PLATE_GetCenterPos  0x021BB3D4  thumb  ov091
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */

typedef unsigned char u8;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void PLIST_PLATE_GetCenterPos(void *a, u8 *s, u16 *out);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void CLACT_SetActorBgPriority(int h, int f);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

#define W(o) (*(int *)(p + (o)))

void POKELIST_MoveCursorToPlate(u8 *p, int idx)
{
    int buf;

    PLIST_PLATE_GetCenterPos(p, (u8 *)(*(int *)(p + idx * 4 + 0x160)), (u16 *)(&buf));
    func_0204B404((struct Obj *)W(0x1d8), (const struct Vec2 *)(&buf), 0);
    func_0204B3DC((struct Obj *)W(0x1d8), 1);
    CLACT_SetActorBgPriority(W(0x1d8), 3);
    if (idx == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)W(0x1d8), 0);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)W(0x1d8), 1);
    }
}
