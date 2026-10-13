/*
 * function: func_021B9B7C
 * address: 0x021B9B7C
 * packet: pkt_ov100_021B9B7C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9AD8 0x021B9AD8 thumb ov100
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int POKE_REGULATION_GetDataSize(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
struct Link;
extern void func_02039C68(struct Link *,u32,u32);
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9AD8(int a);
void func_021B9B7C(int a)
{
 int k=12;
 if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7e,k)!=0) {
  int p=(int)GFL_NET_HANDLE_GetCurrentHandle();
  int q=POKE_REGULATION_GetDataSize();
  if(GFL_NET_SendData(p,0xff,0xc02,q,(*(int **)(a+0x244))[1],0,0,1)!=0) {
   func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7a,k);
   func_021B95B8((u8 *)a,(u32)func_021B9AD8);
  }
 }
}
