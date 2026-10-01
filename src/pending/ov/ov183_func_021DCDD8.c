/*
 * function: func_021DCDD8
 * address: 0x021DCDD8
 * packet: pkt_ov183_021DCDD8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: unlabelled ov186 0x021FD1C4 has no outside witness; large leaf parked by parent
 * extent: two bytes of zero alignment padding at 0x021DCE26
 * symbols:
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 */
extern void *func_021FD1C4(int,int,int,int,int,unsigned);
void func_021DCDD8(char *p, char *q)
{
    int flag;
    if(*(int *)(p+0x44)==0 && *(int *)(p+0xdc)==0) {
        *(int *)(p+0xdc)=1;
        flag=1;
        if(*(int *)(*(char **)(p+0xd0)+8)==0) flag=0;
        *(void **)(p+0x44)=func_021FD1C4(*(int *)(p+0xc0),*(int *)(q+0x10),*(int *)(q+0x18),*(int *)(p+4),flag,*(unsigned short *)(p+0xb4));
    }
}
