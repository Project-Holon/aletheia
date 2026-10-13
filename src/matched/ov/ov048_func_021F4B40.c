/*
 * function: GIMMICK_OBJ_ELBOARD_DeleteLine
 * address: 0x021F4B40
 * packet: pkt_ov048_021F4B40
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02187684 0x02187684 thumb ov020
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02187684(void *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void GIMMICK_OBJ_ELBOARD_DeleteLine(int *p) { func_02187684((void *)p[3]); func_020307B0(p); }
