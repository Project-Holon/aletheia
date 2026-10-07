/*
 * function: func_021BC6D8
 * address: 0x021BC6D8
 * packet: pkt_ov216_021BC6D8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC5C4 0x021BC5C4 thumb ov216
 */
struct Descriptor;struct CharBuf;
typedef struct {struct Descriptor *window;struct CharBuf *buffer;struct Descriptor *copy;unsigned char state;} Window;
extern void func_021BC5C4(Window *,unsigned,unsigned char,unsigned,unsigned char,unsigned char,unsigned char);
void func_021BC6D8(char *p){func_021BC5C4((Window *)(p+0x148),1,11,2,22,28,6);}
