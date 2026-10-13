/*
 * function: func_021BB42C
 * address:  0x021BB42C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *
 * Guarded release of the four pointers at +0x180, each through its own arm9
 * helper.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;
typedef int BOOL;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

typedef struct {
    char pad[0x180];
    void *f180;
    void *f184;
    void *f188;
    void *f18C;
} S;

void func_021BB42C(S *s)
{
    if (s->f180 != 0) {
        CLACT_DeleteActor(s->f180);
        CLACT_ReleaseCharacter((u32)s->f184);
        CLACT_ReleasePalette((u32)s->f188);
        CLACT_ReleaseCellAnim((u32)s->f18C);
        s->f180 = 0;
    }
}
