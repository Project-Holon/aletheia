/*
 * function: func_021DD4A8
 * address: 0x021DD4A8
 * packet: pkt_ov137_021DD4A8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * symbols:
 * func_02012944 0x02012944 thumb
 * func_02008550 0x02008550 thumb
 * func_020490F4 0x020490F4 arm
 * func_0204A48C 0x0204A48C arm
 * func_0204B100 0x0204B100 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AC18 0x0204AC18 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * d_020A1448 0x020A1448 data a4
 * d_021E1B40 0x021E1B40 data a4
 * d_021E1B20 0x021E1B20 data a4
 * d_021E1B30 0x021E1B30 data a4
 * d_021E1B38 0x021E1B38 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02012944(void *);
struct Bank;
struct Cfg;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern const u32 d_020A1448[],d_021E1B40[],d_021E1B20[],d_021E1B30[],d_021E1B38[];
void func_021DD4A8(const u8 *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=func_02008550((const struct Sub0200852CObj *)func_02012944(*(void **)(*(u8 **)(*(u8 **)(p+12)+20)+4)));
    arc=func_020490F4(31,114);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021E1B40,114);
    *(void **)(p+104)=func_0204B100(30,1,114);
    i=0;
    table=d_021E1B20+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        *(int *)(p+i*4+128)=func_0204A6C8(arc,a,0,0,114);
        *(int *)(p+i*4+108)=func_0204AC18(arc,b,0,(u16)(i*32),0,1,114);
    }
    *(int *)(p+148)=func_0204AF28(arc,d_021E1B30[v],d_021E1B38[v],114);
    func_02049238(arc);
    *(void **)(p+52)=func_020490F4(32,114);
}
