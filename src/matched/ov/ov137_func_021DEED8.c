/*
 * function: func_021DEED8
 * address: 0x021DEED8
 * packet: pkt_ov137_021DEED8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: follower in owned 021DEE4C extent.
 */
int func_021DEED8(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=*(int *)(p+0x30);
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {*(int *)p=19;return 1;}
    return 0;
}
