/*
 * function: func_021E0E90
 * address: 0x021E0E90
 * packet: pkt_ov183_021E0E90
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned long u32;
typedef struct {s16 a,b,x,y;} Coords;
extern void func_0204B454(void *,s16 *,u32);
extern void func_0204B404(void *,s16 *,int);
void func_021E0E90(char *p,int animated) {
    int i,group;
    s16 pos;
    char *record,*special;
    Coords coords;
    pos=*(s16 *)((u32)p+*(int *)(p+0x240)*2+0x214);
    group=0;
    for(i=0;i<*(int *)(p+0x23C);i++){
        if(i>=*(int *)(p+0x248)&&i<*(int *)(p+0x24C)){
            if(i==*(int *)(p+0x248))pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=(char *)((u32)p+i*28);
        func_0204B454(*(void **)(record+12),&coords.x,1);
        if(animated==0){
            coords.x=pos;
            func_0204B404(*(void **)(record+12),&coords.x,1);
        }else{
            *(s16 *)(record+20)=(pos-coords.x)/4;
            *(s16 *)(record+22)=0;
            *(u8 *)(record+24)=4;
            *(u8 *)(record+25)=0;
        }
        special=(char *)((u32)p+group*28);
        if(i==*(int *)(special+0x150)&&group!=2){
            func_0204B454(*(void **)(special+0x15C),&coords.a,1);
            if(*(int *)(p+0x248)==*(int *)(p+0x24C))pos+=8;
            else {
                if(i>*(int *)(p+0x248)&&i<*(int *)(p+0x24C))pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                func_0204B404(*(void **)(special+0x15C),&coords.a,1);
            }else{
                *(s16 *)(special+0x164)=(pos-coords.a)/4;
                *(s16 *)(special+0x166)=0;
                *(u8 *)(special+0x168)=4;
            }
            group++;
        }
    }
}
