/*
 * function: func_021BA1D0
 * address: 0x021BA1D0
 * packet: pkt_ov100_021BA1D0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_021B967C 0x021B967C thumb ov100
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Template { int heap; u8 count,pad[3]; int ptr,flag; u8 x,y,z,w; };
extern int func_020457B0(unsigned int,unsigned int);
extern void func_02045CAC(int,int,int);
extern int func_02027778(struct Template *,int);
extern void func_02027CD8(int,int),func_02045808(int),func_021B967C(int,int);
void func_021BA1D0(int a) {
 struct Template t;
 int v;
 t.heap=*(u16 *)(a+0x278);
 t.count=2;
 t.ptr=a+0xcc8;
 t.flag=1;
 t.x=32; t.y=13; t.z=13; t.w=3;
 v=func_020457B0(100,t.heap);
 *(int *)(a+0xcc8)=v;
 func_02045CAC(*(int *)(a+0x288),26,v);
 *(u16 *)(a+0xccc)=0x39e3;
 v=func_020457B0(100,*(u16 *)(a+0x278));
 *(int *)(a+0xcd4)=v;
 func_02045CAC(*(int *)(a+0x288),27,v);
 *(u16 *)(a+0xcd8)=0x39e3;
 *(int *)(a+0xcd0)=0;
 *(int *)(a+0xcdc)=0;
 v=func_02027778(&t,*(int *)(a+0xcc4));
 *(int *)(a+0xcc0)=v;
 switch(*(int *)(a+0x24c)) {case 9: case 10: case 11: break; default: func_02027CD8(v,1); break;}
 func_02045808(*(int *)(a+0xcc8));
 func_02045808(*(int *)(a+0xcd4));
 func_021B967C(a,1);
}
