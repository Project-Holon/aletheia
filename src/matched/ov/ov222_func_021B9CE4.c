/*
 * function: func_021B9CE4
 * address: 0x021B9CE4
 * packet: pkt_ov222_021B9CE4
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype evidence: B294 returns live r0 consumed by store/B3DC; BA028 result feeds B294; AF28 heap visibly u16.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021BA028 0x021BA028 thumb ov222
 *   d_021BA1D8 0x021BA1D8 data a4
 */

typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_021BA1D8[];
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u16);
extern void func_02049238(void*);
extern u32 func_021BA028(void*);
extern void* func_0204B294(u32,u32,u32,u32,const void*,u16,u16);
extern void func_0204B3DC(void*,u32);
extern void func_0204B92C(void*,u32);
void func_021B9CE4(char*p)
{
 u32 t;
 void *h;
 h=func_020490F4(0xca,*(u16*)p);
 *(int*)(p+0x4c)=func_0204AC18(h,0,0,0,0,2,*(u16*)p);
 *(int*)(p+0x48)=func_0204A6C8(h,3,0,0,*(u16*)p);
 *(int*)(p+0x50)=func_0204AF28(h,8,9,*(u16*)p);
 func_02049238((void*)h);
 t=func_021BA028(*(void**)(p+8));
 *(void**)(p+0x54)=func_0204B294(t,*(u32*)(p+0x48),*(u32*)(p+0x4c),*(u32*)(p+0x50),d_021BA1D8,0,*(u16*)p);
 func_0204B3DC(*(void**)(p+0x54),1);
 func_0204B92C(*(void**)(p+0x54),1);
}
