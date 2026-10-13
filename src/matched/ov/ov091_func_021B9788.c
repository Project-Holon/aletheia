/*
 * function: POKELIST_ShowMessage
 * address:  0x021B9788
 * packet:   pkt_ov091_021B9788
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLIST_MESSAGE_OpenWindow  0x021BB714  thumb  ov091
 *   PLIST_MESSAGE_StartStream  0x021BB860  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void PLIST_MESSAGE_OpenWindow(void *a, u32 *s, u32 k);
extern void PLIST_MESSAGE_StartStream(u8 *a, u32 *s, u32 x, u32 y);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

#define W(o) (*(int *)(p + (o)))

void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3)
{
    p[0xc] = 7;
    W(0x144) = a2;
    W(0x148) = a3;
    PLIST_MESSAGE_OpenWindow(p, (u32 *)W(0x150), 3);
    PLIST_MESSAGE_StartStream(p, (u32 *)W(0x150), a1, a2);
    func_0204B3DC((struct Obj *)W(0x1e0), 0);
    func_0204B3DC((struct Obj *)W(0x1e4), 0);
}
