/*
 * function: BOX2_SEQ_StateCloseZoom
 * address: 0x021E8188
 * packet: pkt_ov170_021E8188
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_StepScroll 0x021DE7C8 thumb ov170
 *   BOX2_SEQ_ShrinkActor 0x021EC994 thumb ov170
 *   BOX2_SEQ_HideActor 0x021ECA24 thumb ov170
 *   BOX2_MAIN_DeleteScroll 0x021DE7B4 thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 */
extern int BOX2_MAIN_StepScroll(unsigned char *p);
extern int BOX2_SEQ_ShrinkActor(char *p);
extern void BOX2_SEQ_HideActor(int *p);
extern void BOX2_MAIN_DeleteScroll(char *p);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
#define WORK(p) (*(char **)((p) + 0x2C))
#define SLOT(p) (*(char **)(WORK(p) + 0xA190))
int BOX2_SEQ_StateCloseZoom(unsigned char *p)
{
    BOX2_MAIN_StepScroll(p);
    if (BOX2_SEQ_ShrinkActor(SLOT(p)) == 0) {
        if (((unsigned char *)SLOT(p))[6] != 0)
            return BOX2_SEQ_ReturnAfterClear((char *)p, 0x5C);
        BOX2_SEQ_HideActor((int *)SLOT(p));
        BOX2_MAIN_DeleteScroll((char *)p);
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x5B);
    }
    return 0x5A;
}
