/*
 * function: func_0220E82C
 * address: 0x0220E82C
 * packet: pkt_ov198_0220E82C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x020275EC has no witness outside caller; Ilias owns it.
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 d_0209FCF8[];
 * unsigned func_020275EC(u8 index){return d_0209FCF8[index];}
 * symbols: d_0209FCF8 0x0209FCF8 data a1
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(void *,u16);
extern unsigned func_020275F8(u8);
extern void *func_02049E74(unsigned,unsigned,unsigned,unsigned,u16);
struct Sub0204A9D0;
extern void func_0204A9D0(int,struct Sub0204A9D0 *);
extern void func_020307B0(void *);
extern void func_02049238(void *);
extern unsigned func_020275EC(u8);
extern void func_0204B6F4(void *,unsigned,unsigned);
void func_0220E82C(char *p,void *obj,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    owner=func_020490F4((void *)83,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    data=func_02049E74((unsigned)owner,func_020275F8(which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    func_0204A9D0(*(unsigned *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(obj,func_020275EC(which),1);
}
