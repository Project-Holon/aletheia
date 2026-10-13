/*
 * function: func_021BDAE4
 * address: 0x021BDAE4
 * packet: pkt_ov204_021BDAE4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFCD0 0x021BFCD0 thumb ov204
 *   func_021BF5E0 0x021BF5E0 thumb ov204
 *   func_021BF9D0 0x021BF9D0 thumb ov204
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021BEF74 0x021BEF74 thumb ov204
 *   func_021BDCF0 0x021BDCF0 thumb ov204
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj03918.h"
struct Rec; struct S020315D4;
extern void func_021BFCD0(char *);
typedef unsigned char  u8;
extern void func_021BF5E0(u8 *p);
extern void func_021BF9D0(char *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021BEF74(u8 *p);
extern void func_021BDCF0(unsigned char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
typedef signed int     s32;
extern void func_02034A5C(s32 handle);
extern const char ov067_id[];
int func_021BDAE4(struct S020315D4 *owner, int unused1, int unused2, char *p)
{
    unsigned short heap;
    func_021BFCD0(*(char * *)&((struct Obj03918 *)p)->f20);
    func_021BF5E0((u8 *)(*(char * *)&((struct Obj03918 *)p)->f18));
    func_021BF9D0(*(char * *)&((struct Obj03918 *)p)->f1C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03918 *)p)->f10);
    GF_FONT_Delete(((struct Obj03918 *)p)->fC);
    func_021BEF74((u8 *)(*(char * *)&((struct Obj03918 *)p)->f14));
    func_021BDCF0(*(unsigned char * *)&((struct Obj03918 *)p)->f8);
    heap = ((struct Obj03918 *)p)->f0;
    func_020315D4(owner);
    func_020306F0((unsigned)heap);
    func_02034A5C((unsigned)ov067_id);
    return 1;
}
