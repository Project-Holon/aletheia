/*
 * function: func_0220E5FC
 * address: 0x0220E5FC
 * packet: pkt_ov198_0220E5FC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern unsigned func_020275E4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204ABF0(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(void *,unsigned,unsigned,u16);
extern void func_02049238(void *);
void func_0220E5FC(char *p)
{
    void *owner;
    int first;
    owner=func_020490F4(func_020275E4(),(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    *(int *)(p+0x2508)=func_0204A6C8(owner,func_0202775C(0),0,1,*(u16 *)(*(char **)p+16));
    *(int *)(p+0x2520)=func_0204ABF0(owner,func_02027758(),1,0x120,*(u16 *)(*(char **)p+16));
    first=func_02027760(0);
    *(int *)(p+0x2538)=func_0204AF28(owner,first,func_02027764(0),*(u16 *)(*(char **)p+16));
    func_02049238(owner);
}
