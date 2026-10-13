/*
 * function: func_021D9F24
 * address: 0x021D9F24
 * packet: pkt_ov119_021D9F24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: 02035D20 forwards to 02035CD8, which stores both
 * coordinate outputs before returning 1. Full original 021E51A4 stores
 * all five nonnull outputs before returning the hit object; zero exits
 * precede their reads here. Stack words at 9F4A/9F4C are c's address;
 * 9F42/9F46 are a/b. All payloads and object fields stay full-width.
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021E51A4 0x021E51A4 thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_021DBD70 0x021DBD70 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB9B4 0x021DB9B4 thumb ov119
 *   func_021DF708 0x021DF708 thumb ov119
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_021DD0CC 0x021DD0CC thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021DA064 0x021DA064 thumb ov119
 *   func_021D8CCC 0x021D8CCC thumb ov119
 *   func_021D9EA8 0x021D9EA8 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 */
typedef unsigned int   u32;
struct MsgBank;
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021E51A4(char *p, int x, int y, int *outA, int *outB, int *outSlot, int *outColumn, int *outRow);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern int func_021DBD70(char *,int,int);
extern int func_021D8AA8(void *);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021DD0CC(char *,int);
extern void func_020061E4(u32 a);
extern void func_021D8E84(void *,int);
extern void func_021DB9B4(char *p);
extern void func_021DF708(void *p);
extern void func_021D8C84(void *);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E0FF4(void *p, int a, int flag);
extern void func_021DA064(char *p);
extern void func_021D8CCC(void *,int,int,int,int);
extern void func_021D9EA8(char *,int,int);
extern void func_021D8B38(char *p);
#define I(o) (*(int *)(p+(o)))
int func_021D9F24(char *p,int save)
{
 int x,y,a,b,c,hit,e,result=0;
 if(func_02035D20((u32 *)(&x),(u32 *)(&y))==1) {
  hit=func_021E51A4(p,x+12,y+12,(int *)(p+0xf80),(int *)(p+0xf7c),&a,&b,&c);
  if(hit) {
   e=(int)func_021D8DD0((void *)I(0x828),I(0xf80),I(0xf7c),p);
   if(func_021DBD70(p,I(0xf80),I(0xf7c))) {
    func_020061E4(0x626);
    if(!func_021D8AA8(p)) {func_021D8E84(p,(int)func_021DB9B4);return 3;}
    I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);func_021D8E84(p,(int)func_021DF708);return 3;
   }
   func_021D8C84(p);
   if(e && func_02017E88((void *)e,0xa9,0)) {
    if(func_021DD0CC(p,e)) {
     MSGDATA_ReadString((struct MsgBank *)I(0x720),0x8e,(void *)I(0x738));func_021E0FF4(p,1,0);func_021D8E84(p,(int)func_021DA064);return 2;
    }
    func_021D8CCC(p,hit,c,b,e);func_021D9EA8(p,a,b);
    if(save) {I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);}
    func_021D8B38(p);result=1;
   }
  }
 }
 return result;
}
