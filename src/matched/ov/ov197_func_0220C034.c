/*
 * function: B_BAG_MAIN_CreateItemGraphics
 * address: 0x0220C034
 * packet: pkt_ov197_0220C034
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   B_BAG_MAIN_ClearHandles 0x0220C06C thumb ov197
 *   B_BAG_MAIN_RegisterItemChars 0x0220C0B4 thumb ov197
 *   B_BAG_MAIN_RegisterCursorGraphics 0x0220C27C thumb ov197
 *   B_BAG_MAIN_RegisterIconGraphics 0x0220C304 thumb ov197
 *   B_BAG_MAIN_CreateItemActors 0x0220C40C thumb ov197
 *   B_BAG_MAIN_CreateToolActors 0x0220C68C thumb ov197
 *   B_BAG_MAIN_CreateFingerCursor 0x0220C6D0 thumb ov197
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void B_BAG_MAIN_ClearHandles(char *),B_BAG_MAIN_RegisterItemChars(char *),B_BAG_MAIN_RegisterCursorGraphics(char *),B_BAG_MAIN_RegisterIconGraphics(char *),B_BAG_MAIN_CreateItemActors(char *),B_BAG_MAIN_CreateToolActors(char *),B_BAG_MAIN_CreateFingerCursor(char *);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
void B_BAG_MAIN_CreateItemGraphics(char *p) { B_BAG_MAIN_ClearHandles(p); B_BAG_MAIN_RegisterItemChars(p); B_BAG_MAIN_RegisterCursorGraphics(p); B_BAG_MAIN_RegisterIconGraphics(p); B_BAG_MAIN_CreateItemActors(p); B_BAG_MAIN_CreateToolActors(p); B_BAG_MAIN_CreateFingerCursor(p); BG_SYS_SetSubPlaneVisible(16,1); }
