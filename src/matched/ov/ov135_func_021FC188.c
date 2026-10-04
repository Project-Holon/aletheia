/*
 * function: func_021FC188
 * address: 0x021FC188
 * packet: pkt_ov135_021FC188
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC3D0 0x021FC3D0 thumb ov135
 *   func_021FC568 0x021FC568 thumb ov135
 *   func_021FC4E4 0x021FC4E4 thumb ov135
 *   func_021FC2A4 0x021FC2A4 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_021FC3D0(u8 *p);
extern void func_021FC568(void *);
extern void func_021FC4E4(char *);
extern void func_021FC2A4(void);
extern void func_022000E4(void *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021F4EC8(u8 *p);
int func_021FC188(u8 *p) {func_021FC3D0(p);func_021FC568(p);func_021FC4E4((char *)p);func_021FC2A4();func_022000E4(p);func_0204B3DC(((struct Obj00287 *)p)->fD38,0);func_021F4EC8(p);return 0;}
