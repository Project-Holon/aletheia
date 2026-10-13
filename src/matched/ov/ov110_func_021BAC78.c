/*
 * function: PMS_INPUT_VIEW_CreateActor
 * address: 0x021BAC78
 * packet: pkt_ov110_021BAC78
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD6 lane14): closed by `if (mode == 2) f = 1; else f = z;`:
 * the zero z merges into the u16 flag only in the else arm, so the narrowing
 * is emitted at the join into its own register (r4), as in the original.
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAutoAnimSpeed 0x0204B954 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y, z; u8 a, b; } Position;
struct Obj;
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);
struct Actor;
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
struct Obj *PMS_INPUT_VIEW_CreateActor(char *p, u32 *r, short x, short y, u32 a, int mode)
{
    Position pos;
    struct Obj *o;
    u16 f;
    int z;
    int s;
    pos.x = x;
    pos.y = y;
    pos.a = a;
    z = 0;
    pos.b = z;
    pos.z = z;
    if (mode == 2)
        f = 1;
    else
        f = z;
    s = OS_DisableInterrupts();
    o = CLACT_CreateActor(*(void **)(p + 0x20), r[1], r[0], r[2], &pos, f, 42);
    OS_RestoreInterrupts(s);
    if (o) {
        CLACT_SetActorAutoAnim(o, 1);
        CLACT_SetActorAutoAnimSpeed((struct Actor *)o, 1 << 12);
    }
    return o;
}
