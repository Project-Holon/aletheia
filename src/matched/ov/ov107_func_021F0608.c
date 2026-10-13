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
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   KEY_GetCont 0x0203630C arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   func_021EE740 0x021EE740 thumb ov107
 *   d_021F6E0C 0x021F6E0C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GFL_NET_IsSessionNull(void);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern unsigned int KEY_GetCont(void);
extern void *GAME_DATA_Create(u16);
extern void func_021EE740(u8 *p);
extern const char d_021F6E0C[];
typedef struct {u8 f00;u8 pad[3];void *f04;} Save;
typedef struct {u16 f00,pad02;u32 f04;Save *f08;u32 f0C,f10,f14,f18;u8 pad1C[160];} Ctx;
int func_021F0608(void *task,void *arg,Save *save){Ctx *p;
if(!GFL_NET_IsSessionNull())return 0;
GFL_HEAP_CreateChildHeap(1,93,0x130000);p=PROCSYS_AllocProcWork(task,188,93);
if(!save){save=func_02030734(93,8,0,d_021F6E0C,2788);if(KEY_GetCont()&256)save->f00=1;else{save->f00=0;save->f04=GAME_DATA_Create(93);}}
if(save->f00==1)save->f04=GAME_DATA_Create(93);
p->f00=93;p->f08=save;p->f10=0;p->f14=0;p->f18=0;func_021EE740((u8 *)p);return 1;}
