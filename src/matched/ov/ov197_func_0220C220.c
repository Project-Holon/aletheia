/*
 * function: func_0220C220
 * address: 0x0220C220
 * packet: pkt_ov197_0220C220
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02020F08 0x02020F08 thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_02049B40 0x02049B40 arm
 */
extern unsigned func_02020F08(void);
extern unsigned func_02020E60(unsigned,unsigned);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
void func_0220C220(char *p,unsigned item,unsigned slot)
{
    char *q=*(char **)p;
    unsigned archive;
    if(*(int *)(q+8)==1) {
        archive=func_02020F08();
        func_02049B40(archive,func_02020E60(item,4),5,slot*32,32,*(unsigned short *)(q+0xc));
    } else {
        archive=func_02020F08();
        func_02049B40(archive,func_02020E60(item,2),5,slot*32,32,*(unsigned short *)(q+0xc));
    }
}
