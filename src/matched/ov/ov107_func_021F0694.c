/*
 * function: MB_COMM_SYS_ProcExit
 * address: 0x021F0694
 * packet: pkt_ov107_021F0694
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the epilogue.
 * symbols:
 *   MB_COMM_SYS_Exit 0x021EE824 thumb ov107
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   UI_SoftReset 0x02035544 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020315D4;
extern void MB_COMM_SYS_Exit(u8 *p);extern void GAME_DATA_Delete(unsigned char *);extern void func_020307B0(void *);extern void func_020315D4(struct S020315D4 *);extern void func_020306F0(u32);extern u32 func_0200FB24(void);extern int func_0200FBB0(void);extern void GFL_NET_ERR_ShowScreen(int);extern void GFL_NET_ERR_ShowSimpleScreen(void);extern void UI_SoftReset(int);
typedef struct {u8 f00;u8 pad[3];void *f04;} Save;
typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;} Ctx;
int MB_COMM_SYS_ProcExit(void *task,int unused,int keep,Ctx *p){int mode;u32 a,b,c;
a=p->f10;mode=0;c=p->f18;b=p->f14;if(p->f08->f00==1)mode=1;MB_COMM_SYS_Exit((u8 *)p);
if(!keep){GAME_DATA_Delete(p->f08->f04);func_020307B0(p->f08);}else if(p->f08->f00==1){GAME_DATA_Delete(p->f08->f04);func_020307B0(p->f08);}
func_020315D4(task);func_020306F0(93);
if(a==1){if(mode){if(c==1||func_0200FB24()==1){func_0200FBB0();GFL_NET_ERR_ShowScreen(1);}else GFL_NET_ERR_ShowScreen(0);}else if(c==1){func_0200FBB0();GFL_NET_ERR_ShowScreen(1);}}
if(b==1)GFL_NET_ERR_ShowSimpleScreen();if(mode==1)UI_SoftReset(0);return 1;}
