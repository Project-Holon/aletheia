/*
 * function: func_021BAA08
 * address: 0x021BAA08
 * packet: pkt_ov206_021BAA08
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_021BA960 0x021BA960 thumb ov206
 *   func_02045808 0x02045808 arm
 */
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021BA960(int heap, int window, void *printer, int font, int input, unsigned short right, unsigned short y, unsigned short color, int alignment, int expansion);
extern void func_02045808(struct U16Vec *vec);
void func_021BAA08(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int text=(int)func_02045EC0(bank,message);
    func_021BA960(heap,window,printer,font,text,x,y,color,alignment,expansion);
    func_02045808((struct U16Vec *)text);
}
