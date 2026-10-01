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
extern void *func_0201D7EC(unsigned,unsigned,unsigned,unsigned,unsigned);
extern void *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern void *func_0201C440(unsigned);
extern void *func_021E8568(unsigned,unsigned,unsigned,unsigned,void *,void *,unsigned);
void func_0217AF50(char *p)
{
    *(void **)(p+0xc)=func_0201D7EC(0x17,0,0,0,*(unsigned short *)p);
    *(void **)(p+0x10)=func_02045B38(0,2,4,*(unsigned short *)p);
    *(void **)(p+0x14)=func_0201C440(*(unsigned short *)p);
    *(void **)(p+8)=func_021E8568(0,15,14,10,*(void **)(p+0x14),*(void **)(p+0xc),*(unsigned short *)p);
}
