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
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Bmp;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
void func_021BA960(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int buffer=(int)func_02045770((struct Descriptor *)window);
    unsigned short x;
    int text;
    if(expansion) {
        text=(int)func_020457B0(128,heap);
        func_0201F250((struct WordSet *)expansion,(void *)text,(void *)input);
    } else text=input;
    switch(alignment) {
    case 0: x=right; break;
    case 1: {
        unsigned short width=func_0201D304((struct StrObj *)text,font,0);
        x=right-width;
        break;
    }
    case 2: {
        unsigned short width=func_0201D304((struct StrObj *)text,font,0);
        x=(func_020437DC((const struct Bmp *)buffer)-width)/2;
        break;
    }
    }
    func_0201C724(printer,(int)buffer,(short)x,(short)y,(int)text,(int)font,color);
    if(expansion) func_02045808((struct U16Vec *)text);
}
