/*
 * function: func_021D4A64
 * address: 0x021D4A64
 * packet: pkt_ov122_021D4A64
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D575C 0x021D575C data a4
 *   d_021D5890 0x021D5890 data a4
 *   d_021D5720 0x021D5720 data a4
 *   d_021D5718 0x021D5718 data a4
 *   d_021D5728 0x021D5728 data a4
 *   func_021D4630 0x021D4630 thumb ov122
 *   func_021D4C50 0x021D4C50 thumb ov122
 *   func_021D4FE4 0x021D4FE4 thumb ov122
 *   func_021D4384 0x021D4384 thumb ov122
 *   func_021D5004 0x021D5004 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   BUTTON_MAN_Create 0x02051B84 arm
 */
#include "../include/Obj10431.h"
typedef struct Pair { int a, b; } Pair;
extern const Pair d_021D575C;
extern int d_021D5890[], d_021D5720[], d_021D5718[], d_021D5728[];
typedef unsigned int   u32;
extern void func_021D4630(int a, int b, u32 *p);
extern int func_021D4C50(int value, char *p);
extern void func_021D4FE4(char *p);
extern void func_021D4384(int, Pair *, void *, void *, void *, void *);
typedef unsigned char  u8;
extern void func_021D5004(char *p);
extern void func_021D4244(void *p, u32 a, int a2);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
void func_021D4A64(char *p)
{
    Pair pair = d_021D575C;
    func_021D4384(2, &pair, p, d_021D5890, d_021D5720, d_021D5718);
    ((struct Obj10431 *)p)->f40 = BUTTON_MAN_Create((u8 *)d_021D5728, (int)func_021D4630, (int)p, ((struct Obj10431 *)p)->fC);
    ((struct Obj10431 *)p)->f4 = func_021D4C50;
    func_021D5004(p);
    func_021D4244(p, (u32)func_021D4FE4, 0x31b);
}
