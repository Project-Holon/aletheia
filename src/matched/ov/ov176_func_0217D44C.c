/*
 * function: DIGITALCARDCHECK_GetProcResult
 * address: 0x0217D44C
 * packet: pkt_ov176_0217D44C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p);
int DIGITALCARDCHECK_GetProcResult(int *p) {return WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)p[4]);}
