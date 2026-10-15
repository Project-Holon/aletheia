/*
 * function: B_BAG_MAIN_SetDisplayMode
 * address: 0x0220C4EC
 * packet: pkt_ov197_0220C4EC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   B_BAG_MAIN_DeleteFingerCursorActor 0x0220C714 thumb ov197
 *   B_BAG_MAIN_DisplaySingle 0x0220C538 thumb ov197
 *   B_BAG_MAIN_DisplayList 0x0220C574 thumb ov197
 *   B_BAG_MAIN_DisplaySelected 0x0220C618 thumb ov197
 */
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void B_BAG_MAIN_DeleteFingerCursorActor(char *);
extern void B_BAG_MAIN_DisplaySingle(char *);
extern void B_BAG_MAIN_DisplayList(char *);
extern void B_BAG_MAIN_DisplaySelected(char *);
void B_BAG_MAIN_SetDisplayMode(char *p, int mode)
{
    unsigned int i;
    for (i = 0; i < 63; i++) CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x424), 0);
    B_BAG_MAIN_DeleteFingerCursorActor(p);
    switch (mode) {
    case 0: B_BAG_MAIN_DisplaySingle(p); break;
    case 1: B_BAG_MAIN_DisplayList(p); break;
    case 2: B_BAG_MAIN_DisplaySelected(p); break;
    }
}
