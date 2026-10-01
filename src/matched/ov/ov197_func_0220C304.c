/*
 * function: func_0220C304
 * address: 0x0220C304
 * packet: pkt_ov197_0220C304
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   func_020215BC 0x020215BC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern unsigned func_020490F4(unsigned,u16);
extern int func_0204A6C8(unsigned,unsigned,unsigned,unsigned,u16);
extern int func_0204AC18(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(unsigned,unsigned,unsigned,unsigned);
extern void *func_02049F78(unsigned,unsigned,char **,u16);
extern void func_020215BC(void *,const void *,unsigned,unsigned,u16);
extern void func_020307B0(void *);
extern void func_02049238(unsigned);
void func_0220C304(char *p)
{
    unsigned arc=func_020490F4(11,(*(u16 *)(*(char **)p+0xc)&0x7fff)|0x8000);
    char *data;
    void *buf;
    *(int *)(p+0x564)=func_0204A6C8(arc,119,0,1,*(u16 *)(*(char **)p+0xc));
    *(int *)(p+0x588)=func_0204AC18(arc,116,1,256,4,1,*(u16 *)(*(char **)p+0xc));
    *(int *)(p+0x594)=func_0204AF28(arc,120,121,*(u16 *)(*(char **)p+0xc));
    buf=func_02049F78(arc,116,&data,(*(u16 *)(*(char **)p+0xc)&0x7fff)|0x8000);
    func_020215BC(*(void **)(p+8),*(char **)(data+0xc)+128,3,128,32);
    func_020307B0(buf);
    func_02049238(arc);
}
