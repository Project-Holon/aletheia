/*
 * function: BSUBWAY_RECORD_LIST_DeleteWindows
 * address: 0x021B9CD8
 * packet: pkt_ov069_021B9CD8
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding before next labelled function.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void BSUBWAY_RECORD_LIST_DeleteWindows(u8 *p) { int i; for(i=0;i<10;i++) func_020452E8(*(void **)(p+i*4+0x10)); for(i=0;i<8;i++) func_020452E8(*(void **)(p+i*4+0x38)); BMP_WIN_Exit(); }
