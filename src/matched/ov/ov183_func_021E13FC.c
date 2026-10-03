/*
 * function: func_021E13FC
 * address: 0x021E13FC
 * packet: pkt_ov183_021E13FC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 *   func_021E1008 0x021E1008 thumb ov183
 *   func_021E1C14 0x021E1C14 thumb ov183
 *   func_021E1C44 0x021E1C44 thumb ov183
 *   func_021E0D00 0x021E0D00 thumb ov183
 *   func_021E1C00 0x021E1C00 thumb ov183
 *   func_021E1374 0x021E1374 thumb ov183
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef struct {s16 a,b,x,y;} Coords;
typedef struct {u32 x,y;} Pair;
extern const int d_021E3998[],d_021E397C[];
extern void func_0204B454(void *,s16 *,u32);
extern void func_0204B404(void *,s16 *,int);
extern void func_0204B5AC(void *,Pair *);
extern void func_0204B878(void *,u16);
extern int func_021E0E40(int,int);
extern void func_021E0CE8(char *,int,int);
extern void func_021E1008(char *);
extern int func_021E1C14(char *,int);
extern int func_021E1C44(char *,int);
extern void func_021E0D00(char *,int);
extern void func_021E1C00(char *);
extern void func_021E1374(char *,int);
int func_021E13FC(char *p) {
    int i,factor,selected;
    char *record;
    Pair scale;
    Coords coords;
    switch(*(int *)(p+0x234)){
    case 0:
        func_021E0CE8(p,0,0);
        for(i=0;i<*(int *)(p+0x23C);i++){
            record=(char *)((u32)p+i*28);
            if(*(u8 *)(record+24)!=0){
                func_0204B454(*(void **)(record+12),&coords.x,1);
                coords.x+=*(s16 *)(record+20);
                coords.y+=*(s16 *)(record+22);
                func_0204B404(*(void **)(record+12),&coords.x,1);
                --*(u8 *)(record+24);
                if(i>=*(int *)(p+0x248)&&i<*(int *)(p+0x24C)){
                    factor=*(int *)((u32)d_021E3998+*(u8 *)(record+25)*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(*(void **)(record+12),&scale);
                    ++*(u8 *)(record+25);
                }
                if(i>=*(int *)(p+0x250)&&i<*(int *)(p+0x254)){
                    factor=*(int *)((u32)d_021E397C+*(u8 *)(record+25)*4);
                    scale.x=factor;scale.y=factor;
                    func_0204B5AC(*(void **)(record+12),&scale);
                    ++*(u8 *)(record+25);
                }
            }
        }
        for(i=0;i<2;i++){
            record=(char *)((u32)p+i*28);
            if(*(u8 *)(record+0x168)!=0){
                func_0204B454(*(void **)(record+0x15C),&coords.a,1);
                coords.a+=*(s16 *)(record+0x164);
                coords.b+=*(s16 *)(record+0x166);
                func_0204B404(*(void **)(record+0x15C),&coords.a,1);
                --*(u8 *)(record+0x168);
            }
        }
        if(*(u8 *)(p+24)==0){
            for(i=*(int *)(p+0x248);i<*(int *)(p+0x24C);i++){
                record=(char *)((u32)p+i*28);
                func_0204B878(*(void **)(record+12),func_021E0E40(*(int *)record,*(int *)(record+8)));
            }
            for(i=*(int *)(p+0x250);i<*(int *)(p+0x254);i++){
                record=(char *)((u32)p+i*28);
                func_0204B878(*(void **)(record+12),func_021E0E40(*(int *)record,*(int *)(record+8)));
            }
            ++*(int *)(p+0x234);
        }
        ++*(int *)(p+0x238);
        break;
    case 1:
        for(i=*(int *)(p+0x248);i<*(int *)(p+0x24C);i++){
            record=(char *)((u32)p+i*28);
            if(*(u8 *)(record+25)!=6){
                factor=*(int *)((u32)d_021E3998+*(u8 *)(record+25)*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(*(void **)(record+12),&scale);
                ++*(u8 *)(record+25);
            }
        }
        for(i=*(int *)(p+0x250);i<*(int *)(p+0x254);i++){
            record=(char *)((u32)p+i*28);
            if(*(u8 *)(record+25)!=6){
                factor=*(int *)((u32)d_021E397C+*(u8 *)(record+25)*4);
                scale.x=factor;scale.y=factor;
                func_0204B5AC(*(void **)(record+12),&scale);
                ++*(u8 *)(record+25);
            }
        }
        if(++*(int *)(p+0x238)==6)++*(int *)(p+0x234);
        break;
    default:
        func_021E1008(p);
        if(*(int *)(p+0x320)==0)selected=func_021E1C14(p,*(int *)(p+0x31C));
        else selected=func_021E1C44(p,*(int *)(p+0x31C));
        func_021E0D00(p,selected);
        if(*(int *)(p+0x240)!=0)func_021E0CE8(p,0,1);
        func_021E1C00(p);
        func_021E1374(p,1);
        break;
    }
    return 0;
}
