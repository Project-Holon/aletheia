/*
 * function: func_0220C180
 * address: 0x0220C180
 * packet: pkt_ov197_0220C180
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: u16 item restores entry spill order without extra truncation; unsigned item differs in eight bytes.
 * symbols:
 *   func_02020F08 0x02020F08 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern unsigned func_02020F08(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern unsigned func_02020E60(unsigned,unsigned);
extern void *func_02049E74(void *,unsigned,unsigned,void **,u16);
struct Sub0204A9D0;
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_020307B0(void *);
extern void func_020216B4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049238(void *);
void func_0220C180(char *p,u16 item,unsigned slot,unsigned offset)
{
    char *q=*(char **)p;
    unsigned first, second;
    void *arc;
    void *data,*buffer;
    if(*(int *)(q+8)==1) {first=3;second=4;} else {first=1;second=2;}
    arc=func_020490F4(func_02020F08(),(*(u16 *)(q+0xc)&0x7fff)|0x8000);
    buffer=func_02049E74(arc,func_02020E60(item,first),0,&data,*(u16 *)(*(char **)p+0xc));
    func_0204A9D0(*(int *)(p+slot*4+0x544),data);
    func_020307B0(buffer);
    func_020216B4(*(void **)(p+8),(unsigned)arc,func_02020E60(item,second),*(u16 *)(*(char **)p+0xc),3,32,offset*16);
    func_02049238(arc);
}
