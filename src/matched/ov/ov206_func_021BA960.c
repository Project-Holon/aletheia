/*
 * function: func_021BA960
 * address: 0x021BA960
 * packet: pkt_ov206_021BA960
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Alignment has the valid values 0 (left), 1 (right), 2 (center).
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
extern int func_02045770(int);
extern int func_020457B0(int,int);
extern void func_0201F250(int,int,int);
extern int func_0201D304(int,int,int);
extern int func_020437DC(int);
extern void func_0201C724(int,int,short,short,int,int,unsigned short);
extern void func_02045808(int);
void func_021BA960(int heap,int window,int printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int buffer=func_02045770(window);
    unsigned short x;
    int text;
    if(expansion) {
        text=func_020457B0(128,heap);
        func_0201F250(expansion,text,input);
    } else text=input;
    switch(alignment) {
    case 0: x=right; break;
    case 1: {
        unsigned short width=func_0201D304(text,font,0);
        x=right-width;
        break;
    }
    case 2: {
        unsigned short width=func_0201D304(text,font,0);
        x=(func_020437DC(buffer)-width)/2;
        break;
    }
    }
    func_0201C724(printer,buffer,x,y,text,font,color);
    if(expansion) func_02045808(text);
}
