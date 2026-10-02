/*
 * function: func_021D9AB0
 * address: 0x021D9AB0
 * packet: pkt_ov129_021D9AB0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DA158 0x021DA158 thumb ov129
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x,y,frame; u8 speed,flag; } Params;
extern int func_0204B294(int,int,int,int,void *,int,int);
extern void func_0204B3DC(int,int);
extern unsigned func_021DA158(int,int);
void func_021D9AB0(char *p)
{
    Params s;
    int j=0;
    int h=*(int *)(p+0x25c);
    int i,k=0;
    unsigned q;
    s.x=0; s.y=0; s.frame=0; s.speed=10; s.flag=0;
    for(i=0;i<(int)((unsigned)*(int *)(p+0x23c)+2);i++) {
        q=(unsigned)p+(unsigned)k*28;
        if(i==(int)((unsigned)k+(unsigned)*(int *)(q+0x150)+1)) {
            s.x=76+(unsigned)i*8; s.y=24; s.frame=22;
            *(int *)(q+0x15c)=func_0204B294(h,*(int *)(p+0x26c),*(int *)(p+0x260),*(int *)(p+0x284),&s,0,50);
            k++;
        } else {
            s.x=76+(unsigned)i*8; s.y=24;
            q=(unsigned)p+(unsigned)j*28;
            s.frame=func_021DA158(*(int *)q,*(int *)(q+8));
            *(int *)(q+12)=func_0204B294(h,*(int *)(p+0x26c),*(int *)(p+0x260),*(int *)(p+0x284),&s,0,50);
            j++;
        }
    }
    if(*(int *)(p+0x334)==0 && *(int *)(p+0x338)==0) {
        func_0204B3DC(*(int *)(p+0x15c),0);
        func_0204B3DC(*(int *)(p+0x178),0);
    }
}
