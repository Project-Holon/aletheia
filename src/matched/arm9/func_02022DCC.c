/*
 * function: WIPE_SUB_RequestWindowEnd
 * address:  0x02022DCC
 * packet:   pkt_02022DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SUB_RequestWindowVisible   0x02023CFC  thumb
 *   WIPE_SUB_RequestWindowInside   0x02023D18  thumb
 *   WIPE_SUB_RequestWindowRect   0x02023D60  thumb
 *   WIPE_SUB_RequestWindowOutside   0x02023D40  thumb
 *
 * Open one sprite/OBJ descriptor: a0 == 0 is the "close" spelling (one call
 * with mode 0 and no attribute writes), anything else opens with mode 1, sets
 * the 0x3f field, clears two zero slots through the six-argument entry and
 * finally stamps the 0x20 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_RequestWindowEnd.c \
 *       --func WIPE_SUB_RequestWindowEnd --addr 0x02022DCC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
struct Struct_02023CFC;
extern void WIPE_SUB_RequestWindowVisible(struct Struct_02023CFC *table, void *val, u32 idx);
extern void WIPE_SUB_RequestWindowInside(void *obj, void *val, u32 f4, u32 f8, u32 fC);
extern void WIPE_SUB_RequestWindowRect(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void WIPE_SUB_RequestWindowOutside(void *obj, void *val, u32 f4, u32 f8);

void WIPE_SUB_RequestWindowEnd(u32 a0, void *a1, u32 a2)
{
    if (a0 == 0) {
        WIPE_SUB_RequestWindowVisible(a1, (void *)0, a2);
        return;
    }
    WIPE_SUB_RequestWindowVisible(a1, (void *)1, a2);
    WIPE_SUB_RequestWindowInside(a1, (void *)0x3f, 0, 0, a2);
    WIPE_SUB_RequestWindowRect(a1, 0, 0, 0, 0, 0, a2);
    WIPE_SUB_RequestWindowOutside(a1, (void *)0x20, 0, a2);
}
