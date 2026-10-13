/*
 * function: BSUBWAY_RECORD_LIST_RunInputState
 * address: 0x021B9E44
 * packet: pkt_ov069_021B9E44
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sInputStateFuncs 0x021BA860 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *);
extern Callback sInputStateFuncs[];
int BSUBWAY_RECORD_LIST_RunInputState(u8 *p) { return sInputStateFuncs[*(int *)(p+0x158)](p); }
