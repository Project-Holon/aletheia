/*
 * function: func_0220B1D4
 * address: 0x0220B1D4
 * packet: pkt_ov197_0220B1D4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned short u16;
typedef short s16;
extern int func_02045EC0(int,int);
extern int func_0201D304(int,int,int);
extern int func_02045738(int);
extern int func_02045770(int);
extern void func_0201C724(int,int,s16,s16,int,int,u16);
extern void func_02045808(int);
void func_0220B1D4(char *p,int i,int id,int y,u16 colour)
{
    int handle=*(int *)(p+0x28+i*8);
    int text=func_02045EC0(*(int *)(p+0xc),id);
    int width=func_0201D304(text,*(int *)(*(char **)p+4),0);
    int x=(func_02045738(handle)*8-width)>>1;
    int font=*(int *)(p+0x18);
    int surface=func_02045770(*(int *)(p+0x28+i*8));
    func_0201C724(font,surface,x,y,text,*(int *)(*(char **)p+4),colour);
    (p+i*8)[0x2c]=1;
    func_02045808(text);
}
