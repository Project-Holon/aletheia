/*
 * function: func_021D8EA4
 * address: 0x021D8EA4
 * packet: pkt_ov121_021D8EA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware stores at 021D8F44, 021D8F96, 021D9062, 021D908E, 021D9116.
 * symbols:
 *   func_021D6CF4 0x021D6CF4 thumb ov121
 *   func_021D6D50 0x021D6D50 thumb ov121
 *   func_021D6D6C 0x021D6D6C thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D694C 0x021D694C thumb ov121
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   func_021D9254 0x021D9254 thumb ov121
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 x,y;} Position;
extern void func_021D6CF4(int *,int);
extern void func_021D6D50(int *,int,int,int);
extern int func_021D6D6C(void **,int);
extern void func_02040588(u32,u32);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D694C(u16 *,int);
extern void func_021DAB50(int,void *,u16,int,void *,void *);
struct Obj;
extern void func_021D9254(char *p, int n);
extern void func_0204B404(void *,Position *,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020061E4(u32 a);
void func_021D8EA4(u8 *p)
{
    Position pos;
    switch(*(u32 *)(p+32)) {
    case 0:
        func_021D6CF4((int *)(p+0x118),*(u16 *)p);
        func_021D6D50((int *)(p+0x118),0x22,0x26,*(u16 *)p);
        func_02040588(2,0);
        func_021D694C(*(u16 **)(p+36),2);
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
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=3;
            return;
        }
        break;
    }
    case 3:
        if((*(u32 *)(p+24))++>180) {
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=6;
            func_0207D63C((void *)0x04000050,1,31,0,16);
            func_021D6D6C((void **)(p+0x118),0);
            func_021D6D6C((void **)(p+0x118),1);
            func_021D6D6C((void **)(p+0x118),2);
            func_020061E4(0x794);
            return;
        }
        break;
    case 6:
        if((*(u32 *)(p+24))++>120) {
            func_020061E4(0x795);
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=4;
            func_021D9254(*(void **)(p+40),1);
            return;
        }
        break;
    case 4:
        pos.x=128;
        pos.y=118-*(s16 *)(p+0x128);
        func_0204B404(*(void **)(p+4),&pos,0);
        func_0204B3DC(*(void **)(p+4),1);
        *(u32 *)(p+28)=0;
        *(u32 *)(p+32)=5;
        return;
    case 5: {
        u32 n=(*(u32 *)(p+28)*16u)/10u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        (*(u32 *)(p+24))++;
        if((*(u32 *)(p+28))++>10) {
            *(u32 *)(p+28)=0;
            *(u32 *)(p+32)=7;
            return;
        }
        break;
    }
    case 7:
        if((*(u32 *)(p+24))++>90) {
            *(volatile u16 *)0x04000050=0;
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=8;
            return;
        }
        break;
    case 8:
        if((*(u32 *)(p+24))++>10) {
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=9;
            return;
        }
        break;
    case 9:
        *(u16 *)(p+48)=(*(u32 *)(p+24)*32767u)/120u;
        func_021DAB50(14,p+178,*(u16 *)(p+48),14,p+242,p+210);
        if((*(u32 *)(p+24))++>120) {
            func_021D9254(*(void **)(p+40),0);
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=10;
            return;
        }
        break;
    case 10:
        if((*(u32 *)(p+24))++>60) {
            func_020061E4(0x671);
            *(u32 *)(p+24)=0;
            *(u32 *)(p+32)=11;
            return;
        }
        break;
    case 11:
        *(volatile u16 *)0x04000050=0;
        *(u32 *)(p+8)=1;
        break;
    }
}
