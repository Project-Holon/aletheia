/*
 * function: BOX2_SEQ_UpdateGridCursor
 * address:  0x021EA4DC
 * packet:   pkt_ov170_021EA4DC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_SEQ_CreateB 0x021EA728 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_SEQ_StateMenuMain 0x021E152C thumb
 */

typedef struct {
    unsigned char pad0[0x2C];
    char *work;
} Obj;

typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_SEQ_CreateB(void *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_SEQ_StateMenuMain(unsigned char *p);

#define OBJ(p) (*(void **)((p)->work + 0x70))

int BOX2_SEQ_UpdateGridCursor(Obj *p)
{
    unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
    if (v < 0x24)
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p, v);
    else
        BOX2_MAIN_ResetBoxView((char *)p);
    BOX2_SEQ_CreateB(p);
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_StateMenuMain, 0x43);
}
