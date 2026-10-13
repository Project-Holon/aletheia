/*
 * function: func_02183FA0
 * address:  0x02183FA0
 * packet:   pkt_02183FA0
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;

struct Obj;
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_DrawSystem(void);

void func_02183FA0(void **p)
{
    u16 i;

    for (i = 0; i < 7; i++)
        CLACT_AddActorAnimFrame(p[i], 0x1000);
    CLACT_DrawSystem();
}
