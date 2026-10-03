/*
 * function: func_021F879C,func_021F8994
 * unit: yes
 * address: 0x021F879C
 * packet: pkt_ov132_021F879C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 * symbols:
 *   func_021F8EA8 0x021F8EA8 thumb ov132
 *   func_021FA6CC 0x021FA6CC thumb ov132
 *   func_021F9794 0x021F9794 thumb ov132
 *   func_021FABD8 0x021FABD8 thumb ov132
 *   func_021F9ECC 0x021F9ECC thumb ov132
 *   func_021F9374 0x021F9374 thumb ov132
 *   func_021F94F8 0x021F94F8 thumb ov132
 *   func_021FA064 0x021FA064 thumb ov132
 *   func_021F91CC 0x021F91CC thumb ov132
 *   func_021F9ED4 0x021F9ED4 thumb ov132
 *   func_021F9E4C 0x021F9E4C thumb ov132
 *   func_021F90E0 0x021F90E0 thumb ov132
 *   func_021FAD7C 0x021FAD7C thumb ov132
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F6F64 0x021F6F64 thumb ov112
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F6A58 0x021F6A58 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204F7DC 0x0204F7DC arm
 *   func_0204A648 0x0204A648 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 */
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 d_02FFFC3C,d_021FDE80;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void),func_0200FB24(void);
extern int func_02006238(void);
extern void func_021FCDEC(int,int);
struct Board;
struct Camera;
struct Lights;
extern int func_021FCE00(char *p, int id);
extern u8 func_021FAD7C(char *);
extern void func_021F8EA8(u8 *);
extern void func_021FA6CC(u8 *);
extern void func_021F9794(u8 *);
extern void func_021FABD8(u8 *);
extern void func_021F9ECC(u8 *);
extern void func_021F9374(u8 *);
extern void func_021F94F8(u8 *);
extern void func_021FA064(u8 *);
extern void func_021F91CC(u8 *);
extern void func_021F9ED4(u8 *);
extern void func_021F9E4C(u8 *);
extern void func_021F90E0(u8 *);
extern void func_021F6F64(u8 *);
extern void func_021F7160(u8 *);
extern void func_021F6A58(u8 *);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(u8 *);
extern void func_021F6E74(u8 *);
extern void func_021F75A0(u8 *);
extern void func_021F51F4(u8 *);
extern void func_021F718C(u8 *);
extern void func_021F6F8C(u8 *);
extern void func_02047964(void),func_020479D8(void),func_02047970(void),func_0204A600(void),func_0204A648(void);
extern void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights);
int func_021F879C(u8 *p)
{
    u32 tick;
    tick=d_02FFFC3C;
    *(u32 *)(p+0x1E8)=tick-*(u32 *)(p+0x1EC);
    *(u32 *)(p+0x1EC)=tick;
    switch(*(u32 *)(p+0x1C)) {
    case 0:
        func_0202208C(0,1,1,0,6,1,*(u16 *)p);
        *(u32 *)(p+0x1C)=1;
        break;
    case 1:
        if(func_020221A4()==1) {
            if(**(u32 **)(p+0x30)!=0) {
                *(u32 *)(p+0x1C)=7;
                func_021FCDEC(**(int **)(p+0x30),200);
            } else *(u32 *)(p+0x1C)=4;
        }
        break;
    case 2:
        if(func_02006238()==0) {
            func_0202208C(0,0,0,0,6,1,*(u16 *)p);
            *(u32 *)(p+0x1C)=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if((*(u16 *)(p+2))++ >=60) *(u32 *)(p+0x1C)=5;
        break;
    case 5:
        if(*(u32 *)(p+0x164)==0) {
            *(u32 *)(p+0xB4)=*(u32 *)(*(u8 **)(*(u8 **)(p+0x30)+0x18)+0xC);
            func_021F90E0(p);
            *(u32 *)(p+0x1C)=6;
        }
        break;
    case 6:
        if(func_021FAD7C(*(char **)(p+0xB0))==0) {
            *(u32 *)(p+0xB4)=0;
            if(*(u32 *)(p+0x164)==0) *(u32 *)(p+0x1C)=2;
            else *(u32 *)(p+0x1C)=255;
        }
        break;
    case 7:
        if(func_021FCE00(*(void **)*(u8 **)(p+0x30),200)==1)
            *(u32 *)(p+0x1C)=4;
        break;
    }
    func_021F8EA8(p);
    func_021FA6CC(*(u8 **)(p+0xA4));
    func_021F9794(p);
    if(d_021FDE80==0) func_021FABD8(*(u8 **)(p+0xB0));
    func_021F6F64(*(u8 **)(p+0x3C));
    func_021F7160(*(u8 **)(p+0x40));
    func_021F6A58(*(u8 **)(p+0x54));
    func_021F9ECC(*(u8 **)(p+0x6C));
    func_021F9374(p);
    func_021F51E8(*(u8 **)(p+0x34));
    func_021F6CB0(*(u8 **)(p+0x90));
    func_021F94F8(p);
    func_021FA064(*(u8 **)(p+0xB8));
    func_021F91CC(p);
    func_02047964(); func_020479D8();
    func_021F6E74(*(u8 **)(p+0x90));
    func_021F75A0(*(u8 **)(p+0x40));
    func_021F51F4(*(u8 **)(p+0x34));
    func_021F718C(*(u8 **)(p+0x40));
    func_021F6F8C(*(u8 **)(p+0x3C));
    func_0204F7DC(*(void **)(p+0xAC),*(void **)(p+0xA8),0);
    func_021F9ED4(*(u8 **)(p+0x6C));
    func_021F9E4C(p);
    func_02047970(); func_0204A600();
    if(**(u32 **)(p+0x30)!=0 && *(u32 *)(p+0x1C)!=0 &&
       *(u32 *)(p+0x1C)!=1 && *(u32 *)(p+0x1C)!=2 &&
       *(u32 *)(p+0x1C)!=3 && func_0200FB24()!=0)
        *(u32 *)(p+0x1C)=2;
    return 0;
}
void func_021F8994(void) { func_0204A648(); }
