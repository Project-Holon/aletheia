/*
 * function: func_021F0694
 * address: 0x021F0694
 * packet: pkt_ov107_021F0694
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the epilogue.
 * symbols:
 *   func_021EE824 0x021EE824 thumb ov107
 *   func_02012704 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_02035544 0x02035544 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EE824(void *);extern void func_02012704(void *);extern void func_020307B0(void *);extern void func_020315D4(void *);extern void func_020306F0(u32);extern u32 func_0200FB24(void);extern int func_0200FBB0(void);extern void func_0200F7B8(int);extern void func_0200F83C(void);extern void func_02035544(int);
typedef struct {u8 f00;u8 pad[3];void *f04;} Save;
typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;} Ctx;
int func_021F0694(void *task,int unused,int keep,Ctx *p){int mode;u32 a,b,c;
a=p->f10;mode=0;c=p->f18;b=p->f14;if(p->f08->f00==1)mode=1;func_021EE824(p);
if(!keep){func_02012704(p->f08->f04);func_020307B0(p->f08);}else if(p->f08->f00==1){func_02012704(p->f08->f04);func_020307B0(p->f08);}
func_020315D4(task);func_020306F0(93);
if(a==1){if(mode){if(c==1||func_0200FB24()==1){func_0200FBB0();func_0200F7B8(1);}else func_0200F7B8(0);}else if(c==1){func_0200FBB0();func_0200F7B8(1);}}
if(b==1)func_0200F83C();if(mode==1)func_02035544(0);return 1;}
