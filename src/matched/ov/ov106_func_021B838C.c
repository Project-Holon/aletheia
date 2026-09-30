/*
 * function: func_021B838C
 * address: 0x021B838C
 * packet: pkt_ov106_021B838C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021B8524 0x021B8524 thumb ov106
 */
typedef unsigned char u8;
typedef signed short s16;
extern void func_020061E4(int);
extern void func_021B8524(u8 *);
void func_021B838C(u8 *p) {
    int value;
    if(*(int *)(p+0x594)==0)return;
    *(int *)(p+0x594)=0;
    value=*(s16 *)(p+0x556);
    if(value%24==0) {
        if(*(s16 *)(p+0x55c)!=value/24)func_020061E4(1605);
        *(s16 *)(p+0x55c)=*(s16 *)(p+0x556)/24;
        *(s16 *)(p+0x564)=-40;
        *(s16 *)(p+0x566)=24;
        func_021B8524(p);
        *(int *)(p+0x590)=1;
    } else *(int *)(p+0x598)=1;
}
