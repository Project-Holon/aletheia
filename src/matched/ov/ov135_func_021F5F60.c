/*
 * function: WORLDTRADE_BOX_MoveCursorToSlot
 * address:  0x021F5F60
 * packet:   pkt_021F5F60
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
 * symbols:
 *   tbl_02202D24  0x02202D24  data
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   CLACT_SetActorBgPriority  0x0204B84C  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

extern const Pos tbl_02202D24[];

extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);
extern void CLACT_SetActorBgPriority(u32 obj, int k);

void WORLDTRADE_BOX_MoveCursorToSlot(u32 cursor, int i)
{
    WORLDTRADE_SetActorPos(cursor, tbl_02202D24[i].x, tbl_02202D24[i].y);
    if (i == 0x1F || (i >= 0 && i <= 5)) {
        CLACT_SetActorBgPriority(cursor, 0);
    } else {
        CLACT_SetActorBgPriority(cursor, 1);
    }
}
