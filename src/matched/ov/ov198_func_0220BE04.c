/*
 * unit: no
 * function: B_PLIST_DRAW_DeleteAllWindows
 * address: 0x0220BE04
 * packet: pkt_ov198_0220BE04
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_DRAW_DeleteStateWindows 0x0220BDD4 thumb ov198
 *   BMP_WIN_Delete 0x020452E8 arm
 *   B_PLIST_DRAW_DeleteAuxWindow 0x0220BD84 thumb ov198
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;extern void BMP_WIN_Delete(struct Descriptor *);extern void B_PLIST_DRAW_DeleteStateWindows(char *);extern void B_PLIST_DRAW_DeleteAuxWindow(u8 *);
void B_PLIST_DRAW_DeleteAllWindows(u8 *p){u32 i;B_PLIST_DRAW_DeleteStateWindows((char *)p);for(i=0;i<2;i++)BMP_WIN_Delete(*(struct Descriptor **)(p+i*8+0x1f60));B_PLIST_DRAW_DeleteAuxWindow(p);}
