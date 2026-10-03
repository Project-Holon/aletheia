/*
 * function: func_021B9C4C
 * address: 0x021B9C4C
 * packet: pkt_ov221_021B9C4C
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: 4B294 forwards CFDC's live r0 object result despite legacy void declaration.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9F90 0x021B9F90 thumb ov221
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BA140 0x021BA140 data a2
 */
typedef unsigned short u16;

struct Obj; struct Vec2 { short x,y; };
extern struct Vec2 d_021BA140;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204AC18(unsigned,unsigned,unsigned,unsigned,unsigned short,unsigned short,unsigned short);
extern int func_0204A6C8(unsigned,unsigned,unsigned,unsigned,unsigned short);
extern int func_0204AF28(unsigned,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
extern unsigned func_021B9F90(char *p);
extern struct Obj *func_0204B294(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
void func_021B9C4C(unsigned char *p)
{
    void *h=func_020490F4(0xCA,*(unsigned short *)p);
    *(int *)(p+0x4C)=func_0204AC18((unsigned)h,0,0,0,0,2,*(unsigned short *)p);
    *(int *)(p+0x48)=func_0204A6C8((unsigned)h,3,0,0,*(unsigned short *)p);
    *(int *)(p+0x50)=func_0204AF28((unsigned)h,8,9,*(unsigned short *)p);
    func_02049238(h);
    *(struct Obj **)(p+0x54)=func_0204B294(func_021B9F90(*(void **)(p+8)),*(unsigned *)(p+0x48),*(unsigned *)(p+0x4C),*(unsigned *)(p+0x50),(unsigned)&d_021BA140,0,*(unsigned short *)p);
    func_0204B3DC(*(struct Obj **)(p+0x54),1);
    func_0204B92C(*(struct Obj **)(p+0x54),1);
}
