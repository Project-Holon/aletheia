/*
 * function: func_021DBA94
 * address: 0x021DBA94
 * packet: pkt_ov121_021DBA94
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040618 0x02040618 arm
 */
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
extern void func_0204B454(void *,void *,u32);
extern void func_0204B404(void *,void *,u32);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02040618(u32,u32,u32);
int func_021DBA94(char *p)
{
    int amount,i;
    s16 xy[4];
    if(*(s8 *)(p+0xadc)==0) goto idle;
    amount=(*(s8 *)(p+0xadc)*256)/16;
    for(i=0;i<8;i++) {
        if(*(void **)(p+i*4+0xb28)) {
            func_0204B454(*(void **)(p+i*4+0xb28),xy+2,0);
            xy[2]-=(s16)amount;
            func_0204B404(*(void **)(p+i*4+0xb28),xy+2,0);
            func_0204B454(*(void **)(p+i*4+0xb28),xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                func_0204B3DC(*(void **)(p+i*4+0xb28),1);
            else func_0204B3DC(*(void **)(p+i*4+0xb28),0);
        }
    }
    if(*(int *)(p+0xae0)) {
        func_0204B454(*(void **)(p+0xaf0),xy+2,0);
        xy[2]-=(s16)amount;
        func_0204B404(*(void **)(p+0xaf0),xy+2,0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            func_0204B3DC(*(void **)(p+0xaf0),1);
        else func_0204B3DC(*(void **)(p+0xaf0),0);
    }
    func_02040618(3,1,amount);
    func_02040618(2,1,amount);
    if((*(u32 *)(p+0xad8))++>=15) {
        *(u32 *)(p+0xad0)^=1;
        *(s8 *)(p+0xadc)=0;
    }
    return 0;
idle:
    return 1;
}
