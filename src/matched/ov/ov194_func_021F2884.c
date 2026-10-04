/*
 * function: func_021F2884
 * address: 0x021F2884
 * packet: pkt_ov194_021F2884
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: the original has no else arm: when neither mode is 3 it falls into
 *   the call with r2 (= newmode), r4, r5 and [sp,#4] never assigned
 *   (021F289A bne -> 021F28A6 skips the height store). The C leaves from/to/
 *   width/height unassigned on that path exactly as the image does; the
 *   earlier `else return;` spelling was a guard the original lacks.
 * symbols:
 *   func_021F2F8C 0x021F2F8C thumb ov194
 *   func_021F2F60 0x021F2F60 thumb ov194
 */
typedef struct {int x,y;} Pair;
typedef int (*Conv)(Pair *, Pair *);
extern int func_021F2F8C(Pair *p, Pair *out);
extern int func_021F2F60(const int *p, int *out);
void func_021F2884(Pair *p, int oldmode, int newmode)
{
    Conv from;
    Conv to;
    int width, height, result;
    Pair xy;
    if (oldmode == 3) {
        from = func_021F2F8C;
        to = (Conv)func_021F2F60;
        width = 13;
        height = 5;
    } else if (newmode == 3) {
        from = (Conv)func_021F2F60;
        to = func_021F2F8C;
        width = 11;
        height = 4;
    }
    result = from(p, 0);
    for (xy.y = 0; xy.y <= height; xy.y++)
        for (xy.x = 0; xy.x <= width; xy.x++)
            if (to(&xy, 0) == result) {
                *p = xy;
                return;
            }
}
