/*
 * function: func_0220E584
 * address: 0x0220E584
 * packet: pkt_ov198_0220E584
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AC18(void *,unsigned,unsigned,unsigned,u16,u16,u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_0220E584(char *p)
{
    void *owner;
    owner=func_020490F4(11,(*(u16 *)(*(char **)p+0x10)&0x7fff)|0x8000);
    *(int *)(p+0x2504)=func_0204A6C8(owner,119,0,1,*(u16 *)(*(char **)p+0x10));
    *(int *)(p+0x251c)=func_0204AC18(owner,116,1,256,4,1,*(u16 *)(*(char **)p+0x10));
    *(int *)(p+0x2534)=func_0204AF28(owner,120,121,*(u16 *)(*(char **)p+0x10));
    func_02049238(owner);
}
