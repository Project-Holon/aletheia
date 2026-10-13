/*
 * function: IRC_RHYTHM_InitTextSystem
 * address: 0x021B7D28
 * packet: pkt_ov104_021B7D28
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * MI_CpuFill8 0x02082BCC arm
 * func_0201DD60 0x0201DD60 thumb
 * GF_FONT_Create 0x0201D7EC thumb
 * PRINTSYS_QUE_Create 0x0201C440 thumb
 * func_02045B38 0x02045B38 arm
 * func_0201EC64 0x0201EC64 thumb
 * func_02049B40 0x02049B40 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern void MI_CpuFill8(void *,int,unsigned);
extern void func_0201DD60(void);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
void IRC_RHYTHM_InitTextSystem(unsigned *p, int mode, u16 heap) {
 MI_CpuFill8(p,0,0x10);
 func_0201DD60();
 switch (mode) {
 case 0:
  p[0]=(unsigned int)GF_FONT_Create(0x17,0,0,0,heap);
  break;
 case 1:
  p[0]=(unsigned int)GF_FONT_Create(0x17,1,0,0,heap);
  break;
 }
 p[2]=PRINTSYS_QUE_Create((void *)heap);
 p[1]=(unsigned int)func_02045B38(0,2,0x34,heap);
 p[3]=(unsigned int)func_0201EC64(heap);
 func_02049B40(0x17,5,4,0x1C0,0x20,heap);
 func_02049B40(0x17,5,0,0x1C0,0x20,heap);
}
