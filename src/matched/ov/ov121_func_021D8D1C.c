/*
 * function: func_021D8D1C
 * address: 0x021D8D1C
 * packet: pkt_ov121_021D8D1C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware stores at 021D8D9A and 021D8DEC.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D694C 0x021D694C thumb ov121
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   func_021D9254 0x021D9254 thumb ov121
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02040588(u32,u32);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D694C(void *,int);
extern void func_021DAB50(int,void *,u16,int,void *,void *);
extern void func_021D9254(void *,int);
extern void func_0204B49C(void *,s16,u32,u32);
extern void func_0204B3DC(void *,int);
extern void func_020061E4(int);
void func_021D8D1C(u8 *p)
{
    s16 y;
    switch(*(u32 *)(p+32)) {
    case 0:
        func_02040588(2,0);
        func_021D694C(*(void **)(p+36),2);
        *(u32 *)(p+32)=1;
        return;
    case 1:
        func_0207D63C((void *)0x04000050,4,8,0,16);
        func_02040588(2,1);
        *(u32 *)(p+24)=0;
        *(u32 *)(p+32)=2;
        return;
    case 2: {
        u32 n=(*(u32 *)(p+24)*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        *(u16 *)(p+48)=(*(u32 *)(p+24)*32767u)/120u;
        func_021DAB50(15,p+50,*(u16 *)(p+48),0,p+114,p+146);
        func_021DAB50(31,p+82,*(u16 *)(p+48),0,p+114,p+146);
        if((*(u32 *)(p+24))++>120) {
            *(volatile u16 *)0x04000050=0;
            func_021D9254(*(void **)(p+40),1);
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=3;
            return;
        }
        break;
    }
    case 3:
        if((*(u32 *)(p+24))++>180) {
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=4;
            return;
        }
        break;
    case 4:
        y=((214-*(s16 *)(p+296))**(u32 *)(p+24))/60u-96;
        func_0204B49C(*(void **)(p+4),y,0,1);
        if(y>=-48 && y<=192) func_0204B3DC(*(void **)(p+4),1);
        if((*(u32 *)(p+24))++>=60) {
            func_020061E4(1649);
            func_021D9254(*(void **)(p+40),0);
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=5;
            return;
        }
        break;
    case 5:
        if((*(u32 *)(p+24))++>60) {
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=6;
            return;
        }
        break;
    case 6:
        *(u32 *)(p+8)=1;
        break;
    }
}
