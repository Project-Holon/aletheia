/*
 * function: BOX2_SEQ_SetActorAffineMode
 * address:  0x021ED108
 * packet:   pkt_ov170_021ED108
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorAffineOrigin 0x0204B588 arm
 */

typedef unsigned int   u32;
struct Actor;
struct Pt;
extern void CLACT_SetActorAffineOrigin(struct Actor *actor, const struct Pt *src);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

#define HND(p) (*(int *)((p) + 0x9E9C))

void BOX2_SEQ_SetActorAffineMode(char *p, int on)
{
    unsigned short s[2];
    if (on == 1) {
        CLACT_SetActorAffineMode((struct Actor *)HND(p), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        CLACT_SetActorAffineOrigin((struct Actor *)HND(p), (const struct Pt *)s);
    } else {
        s[0] = 0;
        s[1] = 0;
        CLACT_SetActorAffineOrigin((struct Actor *)HND(p), (const struct Pt *)s);
        CLACT_SetActorAffineMode((struct Actor *)HND(p), 0);
    }
}
