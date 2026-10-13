/*
 * function: OEKAKI_SelectColorButton
 * address:  0x021852B4
 * packet:   pkt_ov023_021852B4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gOekakiButtonLayout  0x02186BEC  data  a2
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u16 a;
    u16 b;
    u16 c;
};

extern struct Ent gOekakiButtonLayout[];
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void OEKAKI_SelectColorButton(u32 *p, int n)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (i == n)
            CLACT_SetActorAnimSeq((struct Obj *)p[i], (u16)(gOekakiButtonLayout[i].c + 1));
        else
            CLACT_SetActorAnimSeq((struct Obj *)p[i], gOekakiButtonLayout[i].c);
    }
}
