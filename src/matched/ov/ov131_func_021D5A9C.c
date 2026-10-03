/*
 * function: func_021D5A9C
 * address: 0x021D5A9C
 * packet: pkt_ov131_021D5A9C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D62E4 0x021D62E4 thumb ov131
 */
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021D62E4(char *p);
void func_021D5A9C(char *p,int a)
{
    *(int *)(p+0x44)=a;
    if(a==0){
        func_0204B3DC(*(void **)(p+0x178),0);
        func_0204B3DC(*(void **)(p+0x17c),0);
        func_0204B3DC(*(void **)(p+0x180),0);
        func_0204B3DC(*(void **)(p+0x184),0);
        func_0204B3DC(*(void **)(p+0x188),0);
        func_0204B3DC(*(void **)(p+0x18c),0);
        func_0204B3DC(*(void **)(p+0x190),0);
    }else{
        func_0204B3DC(*(void **)(p+0x178),1);
        func_0204B3DC(*(void **)(p+0x17c),1);
        if(*(int *)(p+0x40)==1) func_0204B3DC(*(void **)(p+0x180),1);
        func_0204B3DC(*(void **)(p+0x188),1);
        func_0204B3DC(*(void **)(p+0x18c),1);
        if(func_021D62E4(p)==1){
            func_0204B3DC(*(void **)(p+0x184),1);
            func_0204B3DC(*(void **)(p+0x190),1);
        }
    }
}
