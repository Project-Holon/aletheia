/*
 * function: func_02029DBC
 * address:  0x02029DBC
 * packet:   pkt_02029D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029DBC.c \
 *       --func func_02029DBC --addr 0x02029DBC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
struct Obj;
struct SoundSys;
extern u32 func_0202B57C(void *obj);
extern void func_0202B914(struct Obj *o, u32 v);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);

void func_02029DBC(u8 *a, u32 b)
{
    u32 r = func_0202B57C((void *)b);

    func_0202B914((struct Obj *)r, 0);
    func_02028A58((struct SoundSys *)a, 0x40, 6);
}