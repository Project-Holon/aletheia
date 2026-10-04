/*
 * function: func_021BBE18
 * address: 0x021BBE18
 * packet: pkt_ov216_021BBE18
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3D4 0x021BC3D4 thumb ov216
 *   func_021BC8A8 0x021BC8A8 thumb ov216
 *   func_021BC6B4 0x021BC6B4 thumb ov216
 *   func_021BC56C 0x021BC56C thumb ov216
 *   func_021BC6FC 0x021BC6FC thumb ov216
 *   func_021BC378 0x021BC378 thumb ov216
 *   func_021BC178 0x021BC178 thumb ov216
 *   func_021BC0B4 0x021BC0B4 thumb ov216
 *   func_021BC9D0 0x021BC9D0 thumb ov216
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov072_id 0x00000048 data
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj01437.h"
struct S021BC6B4; struct S020315D4;
extern unsigned char ov072_id[],ov067_id[];
extern void func_021BC3D4(unsigned char *p);
extern void func_021BC8A8(char *);
extern void func_021BC6B4(struct S021BC6B4 *);
extern void func_021BC56C(char *);
extern unsigned func_021BC6FC(unsigned *);
extern void func_021BC378(char *);
extern void func_021BC178(char *);
extern void func_021BC0B4(char *);
extern void func_021BC9D0(unsigned *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
int func_021BBE18(struct S020315D4 *heap,int unused1,int unused2,char *p)
{
    func_021BC3D4(((struct Obj01437 *)p)->f124);
    func_021BC8A8(p);
    func_021BC6B4((struct S021BC6B4 *)p);
    func_021BC56C(p);
    func_021BC6FC((unsigned *)p);
    func_021BC378(p);
    func_021BC178(p);
    func_021BC0B4(p);
    func_021BC9D0(*(unsigned * *)&((struct Obj01437 *)p)->f50);
    func_020315D4(heap);
    func_020306F0(119);
    func_02034A5C((int)ov072_id);
    func_02034A5C((int)ov067_id);
    return 1;
}
