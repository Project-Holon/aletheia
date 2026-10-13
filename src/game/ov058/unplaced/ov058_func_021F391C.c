/*
 * function: func_021F391C
 * address:  0x021F391C
 * packet:   pkt_ov058_021F391C
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     places four entries (i, j, i + 2, j + 2) and rotates each by a
 *           (sin, cos) pair of the arm9 table at 0x020A1B38: pair 0x400 for
 *           the first two, pair 0xC00 for the last two (the pool words
 *           0x020A2B38 / 0x020A4B38 are that table plus 0x1000 / 0x3000).
 *           The cos values are separate locals y and y2 (two stack slots)
 *           while the sin value reuses x in r7; y declared before x puts x
 *           in r7 (x first swaps them). The function is 264 bytes, the rest
 *           of the handed 612 is data.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   d_020A1B38     0x020A1B38  data  a2
 */
#include "../unit_021F36C0_types.h"

extern void func_021F391C(Gimmick58Work *work, struct FieldMap *fieldMap, int leadModel, int trailModel);

/*
 * Put the four models of one lane at their start: the eastbound lead and
 * trail (turned by the sine/cosine pair at angle step 0x400) and the
 * westbound lead and trail (pair 0xC00). The cosine values are separate
 * locals (two stack slots) while the sine value reuses one register; the
 * cosine declared before the sine puts the sine in r7.
 */
void func_021F391C(Gimmick58Work *work, struct FieldMap *fieldMap, int leadModel, int trailModel)
{
    FldExpObjCnt *expObj;
    G3dObjectStatus *model;
    int cosEast;
    int sinValue;
    int cosWest;

    func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);

    model = func_021BE480(expObj, 0, (u16)leadModel);
    model->trans.x = GIMMICK58_TRACK_MIN_X;
    model->trans.y = GIMMICK58_TRAIN_Y;
    model->trans.z = GIMMICK58_EAST_TRACK_Z;
    sinValue = d_020A1B38[0x800];
    cosEast = d_020A1B38[0x801];
    func_0207AF1C(&model->rotate, sinValue, cosEast);
    func_021BE4A4(expObj, 0, leadModel, 1);

    model = func_021BE480(expObj, 0, (u16)trailModel);
    model->trans.x = GIMMICK58_TRACK_MIN_X - GIMMICK58_TRAIL_GAP;
    model->trans.y = GIMMICK58_TRAIN_Y;
    model->trans.z = GIMMICK58_EAST_TRACK_Z;
    func_0207AF1C(&model->rotate, sinValue, cosEast);
    func_021BE4A4(expObj, 0, trailModel, 1);

    model = func_021BE480(expObj, 0, (u16)(leadModel + 2));
    model->trans.x = GIMMICK58_TRACK_MAX_X;
    model->trans.y = GIMMICK58_TRAIN_Y;
    model->trans.z = GIMMICK58_WEST_TRACK_Z;
    sinValue = d_020A1B38[0x1800];
    cosWest = d_020A1B38[0x1801];
    func_0207AF1C(&model->rotate, sinValue, cosWest);
    func_021BE4A4(expObj, 0, leadModel + 2, 1);

    model = func_021BE480(expObj, 0, (u16)(trailModel + 2));
    model->trans.x = GIMMICK58_TRACK_MAX_X + GIMMICK58_TRAIL_GAP;
    model->trans.y = GIMMICK58_TRAIN_Y;
    model->trans.z = GIMMICK58_WEST_TRACK_Z;
    func_0207AF1C(&model->rotate, sinValue, cosWest);
    func_021BE4A4(expObj, 0, trailModel + 2, 1);
}
