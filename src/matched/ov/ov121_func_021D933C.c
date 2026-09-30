/*
 * function: func_021D933C
 * address: 0x021D933C
 * packet: pkt_ov121_021D933C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02041EE4 0x02041EE4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void *func_021D6C58(void *,int);
extern void func_0204B53C(void *,void *);
extern void func_0204B528(void *,void *);
extern void func_0204B3DC(void *,int);
extern void func_02041EE4(int,int,int);
void func_021D933C(u8 *p)
{
    int i;
    u8 *q;
    void *sprite;
    s16 xy[2];
    if(*(int *)(p+16)!=-16384) {
        int base=*(int *)(p+20);
        *(int *)(p+16)=base+((-16384-base)**(u16 *)(p+8))/60;
        if((*(u16 *)(p+8))++>60) *(int *)(p+16)=-16384;
    }
    for(i=0;i<32;i++) {
        q=p+i*4;
        *(int *)(q+24)=*(int *)(q+24)+*(int *)(q+152);
        if(*(int *)(q+24)>=851968) *(int *)(q+24)=-65536;
        sprite=func_021D6C58(*(void **)(p+280),i+1);
        func_0204B53C(sprite,xy);
        xy[1]=*(int *)(q+24)>>12;
        func_0204B528(sprite,xy);
        if(xy[1]>=0 && xy[1]<=208) func_0204B3DC(sprite,1);
        else func_0204B3DC(sprite,0);
    }
    *(int *)(p+12)=*(int *)(p+12)+*(int *)(p+16);
    func_02041EE4(3,3,*(int *)(p+12)>>12);
    func_02041EE4(7,3,*(int *)(p+12)>>12);
}
