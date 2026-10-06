/*
 * function: func_021D880C
 * address: 0x021D880C
 * packet: pkt_ov120_021D880C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8784 0x021D8784 thumb ov120
 *   func_021D8684 0x021D8684 thumb ov120
 *   func_021D7F5C 0x021D7F5C thumb ov120
 *   func_021D7FD0 0x021D7FD0 thumb ov120
 *   func_021D7A74 0x021D7A74 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D8784(char *,int);
extern void func_021D8684(char *,int,u32);
extern void func_021D7F5C(char *,u16);
extern void func_021D7FD0(char *,void *);
extern void func_021D7A74(u8 *p, int n);
void func_021D880C(char *p,void *q,u32 n)
{
    func_021D8784(p,(int)q);
    func_021D8684(p,36,n);
    func_021D7F5C(p,41);
    func_021D7FD0(p,q);
    func_021D7A74((u8 *)p,17);
}
