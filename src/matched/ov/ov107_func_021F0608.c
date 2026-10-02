/*
 * function: func_021F0608
 * address: 0x021F0608
 * packet: pkt_ov107_021F0608
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_0203630C 0x0203630C arm
 *   func_020124F4 0x020124F4 thumb
 *   func_021EE740 0x021EE740 thumb ov107
 *   d_021F6E0C 0x021F6E0C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0203CDBC(void *,void *);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(void *,u32,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern unsigned int func_0203630C(void);
extern void *func_020124F4(u16);
extern void func_021EE740(void *);
extern const char d_021F6E0C[];
typedef struct {u8 f00;u8 pad[3];void *f04;} Save;
typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;u8 pad1C[160];} Ctx;
int func_021F0608(void *task,void *arg,Save *save){Ctx *p;
if(!func_0203CDBC(task,arg))return 0;
func_0203064C(1,93,0x130000);p=func_0203159C(task,188,93);
if(!save){save=func_02030734(93,8,0,d_021F6E0C,2788);if(func_0203630C()&256)save->f00=1;else{save->f00=0;save->f04=func_020124F4(93);}}
if(save->f00==1)save->f04=func_020124F4(93);
p->f00=93;p->f08=save;p->f10=0;p->f14=0;p->f18=0;func_021EE740(p);return 1;}
