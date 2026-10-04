/*
 * function: func_0217AF50
 * address: 0x0217AF50
 * packet: pkt_ov176_0217AF50
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two bytes alignment padding at 0x0217AF9A.
 * symbols:
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021E8568 0x021E8568 thumb ov177
 */
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern void *func_021E8568(unsigned,unsigned,unsigned,unsigned,void *,void *,unsigned);
void func_0217AF50(char *p)
{
    *(void **)(p+0xc)=func_0201D7EC(0x17,0,0,0,*(unsigned short *)p);
    *(void **)(p+0x10)=func_02045B38(0,2,4,*(unsigned short *)p);
    *(void **)(p+0x14)=(void *)func_0201C440((void *)(*(unsigned short *)p));
    *(void **)(p+8)=func_021E8568(0,15,14,10,*(void **)(p+0x14),*(void **)(p+0xc),*(unsigned short *)p);
}
