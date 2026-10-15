/*
 * function: BEACON_DETAIL_GRA_CreateInfoWindow
 * address: 0x021BC6D8
 * packet: pkt_ov216_021BC6D8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_CreateWindow 0x021BC5C4 thumb ov216
 */
struct Descriptor;struct CharBuf;
typedef struct {struct Descriptor *window;struct CharBuf *buffer;struct Descriptor *copy;unsigned char state;} Window;
extern void BEACON_DETAIL_GRA_CreateWindow(Window *,unsigned,unsigned char,unsigned,unsigned char,unsigned char,unsigned char);
void BEACON_DETAIL_GRA_CreateInfoWindow(char *p){BEACON_DETAIL_GRA_CreateWindow((Window *)(p+0x148),1,11,2,22,28,6);}
