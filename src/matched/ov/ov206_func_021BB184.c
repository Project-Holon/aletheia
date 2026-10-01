/*
 * function: func_021BB184
 * address: 0x021BB184
 * packet: pkt_ov206_021BB184
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 */
extern int func_0202D81C(int,int,int,int,int,int,int,int,int,unsigned short);
extern int func_0202D7D8(int,int,int,int,int,int,int,int,unsigned short,unsigned short);
extern int func_0202D898(int,int,int,int,int,int,int,int,unsigned short);
void func_021BB184(char *p,int index)
{
    int flag=0;
    int handle;
    if (*(int *)(p+0x1c)) flag=1;
    handle=*(int *)(p+0x1d4);
    *(int *)(p+0x94+index*4)=func_0202D81C(handle,*(unsigned short *)(p+0xc),*(unsigned short *)(p+0xe),*(unsigned short *)(p+0x10),*(unsigned short *)(p+0x12),0,0,*(int *)(p+0x14),flag,*(unsigned short *)p);
    *(int *)(p+0x9c+index*4)=func_0202D7D8(handle,*(unsigned short *)(p+0xc),*(unsigned short *)(p+0xe),*(unsigned short *)(p+0x10),*(unsigned short *)(p+0x12),0,0,flag,index<<5,*(unsigned short *)p);
    *(int *)(p+0xa4+index*4)=func_0202D898(*(unsigned short *)(p+0xc),*(unsigned short *)(p+0xe),*(unsigned short *)(p+0x10),*(unsigned short *)(p+0x12),0,0,2,flag,*(unsigned short *)p);
}
