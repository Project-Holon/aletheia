/*
 * function: func_021DA320
 * address: 0x021DA320
 * packet: pkt_ov129_021DA320
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 */
typedef short s16;
typedef unsigned char u8;
typedef struct { s16 x,y; } Pair;
extern void func_0204B454(void *,Pair *,unsigned int);
void func_021DA320(char *p)
{
    int i;
    int x,y;
    Pair s;
    for(i=0;i<*(int *)(p+0x23c);i++){
        if(i>=*(int *)(p+0x248) && i<*(int *)(p+0x24c)){
            x=16;
            y=16;
        }else{
            x=4;
            y=8;
        }
        func_0204B454(*(void **)(p+i*0x1c+12),&s,0);
        (*(u8 **)(p+i*0x1c+16))[0]=s.y-y;
        (*(u8 **)(p+i*0x1c+16))[2]=s.x-x;
        (*(u8 **)(p+i*0x1c+16))[1]=s.y+y;
        (*(u8 **)(p+i*0x1c+16))[3]=s.x+x;
    }
}
