/*
 * function: BEACON_DETAIL_InitGraphics
 * address: 0x02184558
 * packet: pkt_ov219_02184558
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: heap forwarded full-width without caller truncation to 3F8F4,
 * 46440 and 45088; widen their legacy narrow parameters accordingly.
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   d_02185F18 0x02185F18 data ov219 a4
 */
typedef unsigned short u16;
struct DispConfig {unsigned a,b,c,d;};
extern const struct DispConfig d_02185F18;
extern void BG_SYS_Create(unsigned),BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void G3D_SYSTEM_Init(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void BG_SYS_SetLowBit(unsigned),BMP_WIN_Init(unsigned),BG_SYS_ResetSubDisplay(void);
void BEACON_DETAIL_InitGraphics(unsigned heap)
{
    struct DispConfig cfg=d_02185F18;
    BG_SYS_Create(heap);BG_SYS_SetGraphicsMode(&cfg);
    G3D_SYSTEM_Init(0,3,0,2,0,heap,0);
    BG_SYS_SetLowBit(1);BMP_WIN_Init(heap);BG_SYS_ResetSubDisplay();
}
