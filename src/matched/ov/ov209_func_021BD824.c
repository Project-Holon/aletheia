/*
 * function: ZUKAN_LIST_ExitActors
 * address:  0x021BD824
 * packet:   pkt_021BD824
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_LIST_DeleteActorUnit 0x021BDD5C thumb
 *   ZUKAN_LIST_ReleaseActorResources 0x021BDBA8 thumb
 *   CLACT_ExitSystem 0x0204A5AC arm
 */

extern void ZUKAN_LIST_DeleteActorUnit(char *p);
extern void ZUKAN_LIST_ReleaseActorResources(char *p);
extern void CLACT_ExitSystem(void);

void ZUKAN_LIST_ExitActors(char *a)
{
    ZUKAN_LIST_DeleteActorUnit(a);
    ZUKAN_LIST_ReleaseActorResources(a);
    CLACT_ExitSystem();
}