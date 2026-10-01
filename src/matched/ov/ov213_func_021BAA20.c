/*
 * function: func_021BAA20
 * address: 0x021BAA20
 * packet: pkt_ov213_021BAA20
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BAA8A..021BAA8C is two zero alignment bytes, no follower.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 */
extern unsigned func_0201AA18(void *list);
void func_021BAA20(unsigned char *p)
{
    int i;
    if(*(int *)(p+0x44)==1) {
        int j;
        unsigned char *row;
        for(i=0;i<2;i++) {
            row=p+16*i;
            for(j=0;j<(int)func_0201AA18(*(void **)row);j++) row[10+j]=0;
        }
        return;
    }
    if(*(int *)(p+0x44)==3) {
        unsigned char *row;
        int j;
        for(i=0;i<4;i++) {
            row=p+16*i;
            for(j=0;j<(int)func_0201AA18(*(void **)row);j++) row[10+j]=0;
        }
    }
}
