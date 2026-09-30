/*
 * function: func_021B8408
 * address: 0x021B8408
 * packet: pkt_ov106_021B8408
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8A6C 0x021B8A6C thumb ov106
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern void func_021B8A6C(u8 *,int);
void func_021B8408(u8 *p,s16 delta) {
    int old,next;
    int i;
    old=*(s16 *)(p+0x556);
    next=old+delta;
    if(*(s16 *)(p+0x558)>next) {
        *(s16 *)(p+0x556)=*(s16 *)(p+0x558);
        *(s16 *)(p+0x55e)=0;
    } else if(*(s16 *)(p+0x55a)<next) {
        *(s16 *)(p+0x556)=*(s16 *)(p+0x55a);
        *(s16 *)(p+0x55e)=0;
    } else {
        if(old/24!=next/24 && old%24!=0) {
            if(delta>=0)delta=delta-next%24;
            else delta=delta+(24-next%24);
        }
        *(s16 *)(p+0x556)+=delta;
        *(s16 *)(p+0x55e)=delta;
    }
    for(i=0;i<*(u16 *)(p+0x554);i++)func_021B8A6C(p+0x188+i*32,*(s16 *)(p+0x556));
    *(int *)(p+0x594)=1;
}
