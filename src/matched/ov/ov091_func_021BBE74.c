/*
 * function: func_021BBE74
 * address: 0x021BBE74
 * packet: pkt_ov091_021BBE74
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 774 bytes of code; final two zero bytes align the next function.
 * symbols:
 *   func_02020F34 0x02020F34 thumb
 *   func_02021014 0x02021014 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int   u32;
struct Rec;
extern void *func_02020F34(u32 item, u32 which, u32 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern void func_020307B0(void *);
#define GET(k) func_02021014(p,(k))
#define DONE(k) {func_020307B0(p);return(k);}
int func_021BBE74(int id)
{
    void *p=func_02020F34(id,0,23);
    int mask;
    int val;
    if(GET(14)!=1) DONE(29);
    if(GET(30)!=0 || GET(31)!=0 || GET(32)!=0 || GET(33)!=0 || GET(34)!=0 || GET(35)!=0 || GET(36)!=0) DONE(0);
    if(GET(27)!=0) DONE(1);
    if(GET(28)!=0) DONE(2);
    mask=GET(18);
    mask+=GET(19)*2;
    mask+=GET(20)*4;
    mask+=GET(21)*8;
    mask+=GET(22)*16;
    mask+=GET(23)*32;
    switch(mask) {
    case 1:DONE(3);
    case 2:DONE(4);
    case 4:DONE(5);
    case 8:DONE(6);
    case 16:DONE(7);
    case 32:DONE(8);
    case 63:
        if(GET(41)!=0) DONE(11);
        DONE(9);
    }
    if(GET(24)!=0) DONE(10);
    if(GET(41)!=0) DONE(11);
    if(GET(26)!=0) DONE(12);
    val=GET(52);
    if(val>0) DONE(13);
    if(val<0) DONE(19);
    val=GET(53);
    if(val>0) DONE(14);
    if(val<0) DONE(20);
    val=GET(54);
    if(val>0) DONE(15);
    if(val<0) DONE(21);
    val=GET(55);
    if(val>0) DONE(16);
    if(val<0) DONE(22);
    val=GET(56);
    if(val>0) DONE(17);
    if(val<0) DONE(23);
    val=GET(57);
    if(val>0) DONE(18);
    if(val<0) DONE(24);
    if(GET(29)!=0) DONE(25);
    if(GET(37)!=0) DONE(26);
    if(GET(38)!=0) DONE(27);
    if(GET(39)!=0 || GET(40)!=0) DONE(28);
    DONE(29);
}
