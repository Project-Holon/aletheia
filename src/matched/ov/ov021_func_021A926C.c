/*
 * function: FIELD_MENU_DeleteItem
 * address:  0x021A926C
 * packet:   pkt_ov021_021A926C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
} S;

struct Descriptor;
struct Obj;
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);

void FIELD_MENU_DeleteItem(int a, S *s)
{
    if (s->f0 == 1) {
        BMP_WIN_Delete((struct Descriptor *)s->f4);
        if (s->f18 != 0) {
            CLACT_DeleteActor((struct Obj *)s->f18);
            CLACT_ReleaseCellAnim(s->f10);
            CLACT_ReleaseCharacter(s->fc);
        }
    }
}
