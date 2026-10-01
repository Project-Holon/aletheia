/*
 * function: func_021BA8D0
 * address: 0x021BA8D0
 * packet: pkt_ov223_021BA8D0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
extern void func_0204B3DC(void *,unsigned);
extern void func_0204B688(void *,unsigned);
extern void func_0207D63C(unsigned,int,int,int,int);
void func_021BA8D0(char *p)
{
    u8 i;
    switch(*(int *)(p+532)) {
    case 1:
        for(i=0;i<3;i++) func_0204B3DC(*(void **)(p+i*148+108),1);
        *(int *)(p+532)=2;
        break;
    case 2:
        if(*(int *)(p+528)<16) {
            ++*(int *)(p+528);
            if(*(int *)(p+528)==16) {
                for(i=0;i<3;i++) func_0204B688(*(void **)(p+i*148+108),0);
                *(int *)(p+532)=3;
            }
            func_0207D63C(0x04001050,0,63,*(int *)(p+528),16-*(int *)(p+528));
        } else *(int *)(p+532)=3;
        break;
    case 3:
        func_0207D63C(0x04001050,4,63,8,8);
        *(int *)(p+532)=0;
        break;
    }
}
