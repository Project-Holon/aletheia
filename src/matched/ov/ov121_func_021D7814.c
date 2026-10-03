/*
 * function: func_021D7814
 * address: 0x021D7814
 * packet: pkt_ov121_021D7814
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 * symbols:
 *   func_021D9750 0x021D9750 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021D84D4 0x021D84D4 thumb ov121
 *   func_021D8C1C 0x021D8C1C thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D8D00 0x021D8D00 thumb ov121
 *   func_021D8D18 0x021D8D18 thumb ov121
 *   func_0200A2B8 0x0200A2B8 thumb
 *   func_0200A2D8 0x0200A2D8 thumb
 *   func_021D8CA8 0x021D8CA8 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D9790 0x021D9790 thumb ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCFC8 0x021DCFC8 thumb ov121
 *   func_021DD24C 0x021DD24C thumb ov121
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   func_021DD9CC 0x021DD9CC thumb ov121
 *   func_021DDF5C 0x021DDF5C thumb ov121
 *   func_021DE014 0x021DE014 thumb ov121
 *   func_020362DC 0x020362DC arm
 *   func_021D93F4 0x021D93F4 thumb ov121
 *   func_021D94B8 0x021D94B8 thumb ov121
 *   func_021D9488 0x021D9488 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6DF4 0x021D6DF4 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[12]; } Desc;
extern void func_021D9750(u8 *p);
extern void func_02040588(u32 which, u32 enable);
extern void *func_021D9744(void *);
extern void func_021D84D4(void *,void *,void *,int,void *,void *,void *,u16);
extern void func_021D8C1C(u8 *p, int mode);
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021D8D00(void *);
extern int func_021D8D18(void *);
extern void func_0200A2B8(void *,void *);
extern int func_0200A2D8(void *,void *);
extern void func_021D8CA8(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021D8380(void *);
extern void func_021D9790(char *p);
extern void func_02082BCC(void *,int,int);
extern void *func_021DCFC8(Desc *,u16);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void func_021DE0AC(u8 *p, u32 b);
extern void func_021DD9CC(void *);
extern void func_021DDF5C(u8 *p);
extern int func_021DE014(char *p);
extern u32 func_020362DC(void);
extern void func_021D93F4(u8 *p, const void *q, int n, int k, int x, int y, int z, u16 heap);
extern int func_021D94B8(void *);
extern void func_021D9488(void *);
extern void func_021DA8B0(void *,void *);
extern void func_021D6DF4(void *a, int *state);
void func_021D7814(void *task,u32 *state,u8 *p)
{
    Desc d;
    switch (*state) {
    case 0:
        func_021D9750(*(void **)(p+916));
        func_02040588(1,1);
        func_02040588(3,1);
        func_021D84D4(p+12,func_021D9744(*(void **)(p+916)),p+972,*(int *)(p+952),p+660,p+912,p+312,29);
        func_021D8C1C(p+12,0);
        func_021D9F08(*(void **)(p+644),*(int *)(p+932),113,2);
        *state=1;
        break;
    case 1:
        func_02040588(0,1);
        *state=2;
        break;
    case 2:
        if (func_021D9FF8(*(void **)(p+644))) *state=3;
        break;
    case 3:
        func_021D8D00(p+12);
        if (func_021D8D18(p+12)) *state=4;
        break;
    case 4:
        func_0200A2B8(*(void **)(p+956),*(void **)(p+952));
        *state=5;
        break;
    case 5:
        if (func_0200A2D8(*(void **)(p+956),*(void **)(p+952))==2) *state=6;
        break;
    case 6:
        func_021D8C1C(p+12,1);
        *state=7;
        break;
    case 7:
        func_021D8D00(p+12);
        if (func_021D8D18(p+12)) *state=8;
        break;
    case 8:
        func_021D9F08(*(void **)(p+644),*(int *)(p+932),114,1);
        *state=9;
        break;
    case 9:
        if (func_021D9FF8(*(void **)(p+644))) *state=10;
        break;
    case 10:
        func_021D8CA8(p+12);
        func_021D9E04(*(void **)(p+644));
        *(void **)(p+644)=0;
        func_021D8380(p);
        *(volatile u16 *)0x04000050=0;
        func_021D9790(*(void **)(p+916));
        func_02040588(1,1);
        func_02040588(3,1);
        *state=11;
        break;
    case 11:
        func_02040588(0,1);
        *state=12;
        break;
    case 12:
        func_02040588(1,0);
        func_02082BCC(&d,0,48);
        d.w[0]=2;
        d.w[1]=0;
        d.w[2]=8;
        d.w[3]=15;
        d.w[5]=13;
        d.w[4]=10;
        d.w[6]=(u32)func_021D9744(*(void **)(p+916));
        d.w[7]=*(u32 *)(p+956);
        d.w[8]=*(u32 *)(p+932);
        d.w[9]=*(u32 *)(p+920);
        d.w[10]=*(u32 *)(p+924);
        d.w[11]=*(u32 *)(p+936);
        *(void **)(p+4)=func_021DCFC8(&d,29);
        *(void **)p=func_021DD24C(p+972,*(void **)(p+4),*(void **)(p+952),29);
        func_021DE0AC(*(void **)p,0);
        *state=13;
        break;
    case 13:
        func_021DD9CC(*(void **)p);
        func_021DDF5C(*(void **)p);
        *state=14;
        break;
    case 14:
        func_021DD9CC(*(void **)p);
        if (func_021DE014(*(void **)p)) {
            *(u32 *)(p+964)=0;
            *state=15;
        }
        break;
    case 15:
        if (func_020362DC()&1) *state=18;
        if ((*(u32 *)(p+964))++>240) {
            *(u32 *)(p+964)=0;
            *state=16;
        }
        break;
    case 16:
        func_021D93F4(p+612,p+660,(int)func_021D9744(*(void **)(p+916)),*(int *)(p+924),*(int *)(p+932),155,*(int *)(p+920),29);
        func_021D94B8(p+612);
        *state=17;
        break;
    case 17:
        func_021D94B8(p+612);
        if (func_020362DC()&1) {
            func_021D9488(p+612);
            *state=18;
        }
        break;
    case 18:
        func_021DA8B0(task,func_021D6DF4);
        break;
    }
}
