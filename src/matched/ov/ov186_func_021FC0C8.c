/*
 * function: func_021FC0C8
 * address: 0x021FC0C8
 * packet: pkt_ov186_021FC0C8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021FC0C8(char *p,unsigned i)
{
    int *r=(int *)(p+8+i*12);
    switch(i){
    case 11: case 12:
        func_0204ADA4(r[2]);
        func_0204A8D4(r[1]);
        func_0204AFD8(r[0]);
        break;
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 13:
        func_0204A8D4(r[1]);
        func_0204AFD8(r[0]);
        break;
    case 4: case 5: break;
    }
    *(int *)(p+0xb0+i*4)=0;
}
