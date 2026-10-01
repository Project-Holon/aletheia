/*
 * function: func_021B8464
 * address: 0x021B8464
 * packet: pkt_ov102_021B8464
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Separate fifth object pointer and sixth u16 heap reproduce the incoming pointer home store and halfword slot at +4; byte-correct caller 021B7560 supplies the same two slots. Struct-typed state and const Row input preserve loads across bounds stores.
 * symbols:
 * func_02082BCC 0x02082BCC arm
 * func_02051B84 0x02051B84 arm
 * func_021B8794 0x021B8794 thumb ov102
 * func_020450F0 0x020450F0 arm
 * func_02045770 0x02045770 arm
 * func_02043B5C 0x02043B5C arm
 * func_02045334 0x02045334 arm
 * func_02045374 0x02045374 arm
 * func_02045730 0x02045730 arm
 * func_020409B4 0x020409B4 arm
 * func_021B7CC4 0x021B7CC4 thumb ov102
 * func_02045EC0 0x02045EC0 arm
 * func_0201DD78 0x0201DD78 thumb
 * func_021B7CBC 0x021B7CBC thumb ov102
 * func_0201D304 0x0201D304 thumb
 * func_0201D42C 0x0201D42C thumb
 * func_0201C7A4 0x0201C7A4 thumb
 * func_02045808 0x02045808 arm
 * func_0201DD68 0x0201DD68 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Pair { int object; u16 heap,pad; } Pair;
typedef struct Row { u16 id,x,y,w,h,color; } Row;
typedef struct State { void *bank; u32 windows[4]; u8 bounds[20]; const Row *rows; u16 count,bg,index,done,state,ticks; u32 enable; } State;
extern void func_02082BCC(void *,u8,u32);
extern void *func_02051B84(u8 *,int,int,int);
extern void func_021B8794(u16,int,u8 *);
extern u32 func_020450F0(u32,u8,u8,u8,u8,u8,u8);
extern void *func_02045770(u32);
extern void func_02043B5C(void *,u8);
extern void func_02045334(u32);
extern void func_02045374(u32);
extern u32 func_02045730(u32);
extern void func_020409B4(u32);
extern int func_021B7CC4(void *);
extern void *func_02045EC0(int,u32);
extern void func_0201DD78(u32,u32,u32);
extern int func_021B7CBC(void *);
extern u32 func_0201D304(void *,u32,u32);
extern u32 func_0201D42C(void *,int);
extern void func_0201C7A4(void *,s16,s16,void *,int);
extern void func_02045808(void *);
extern void func_0201DD68(void);
void func_021B8464(State *p,u32 bg,const Row *rows,int count,void *object,u16 heap)
{
    int i;
    const Row *row;
    u32 win,width,height;
    void *text,*target;
    func_02082BCC(p,0,60);
    p->count=count;
    p->rows=rows;
    p->bg=bg;
    p->enable=1;
    for(i=0;i<p->count;i++) {
        row=rows+i;
        p->bounds[i*4]=row->y*8+1;
        p->bounds[i*4+1]=(row->y+row->h)*8-1;
        p->bounds[i*4+2]=row->x*8+1;
        p->bounds[i*4+3]=(row->x+row->w)*8-1;
    }
    p->bounds[i*4]=255;
    p->bank=func_02051B84(p->bounds,(int)func_021B8794,(int)p,heap);
    for(i=0;i<p->count;i++) {
        row=rows+i;
        p->windows[i]=func_020450F0(bg,row->x+4,row->y+1,row->w-8,row->h-2,row->color,1);
        func_02043B5C(func_02045770(p->windows[i]),4);
        win=p->windows[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        text=func_02045EC0(func_021B7CC4(object),rows[i].id);
        func_0201DD78(15,14,4);
        width=func_0201D304(text,func_021B7CBC(object),0);
        height=func_0201D42C(text,func_021B7CBC(object));
        target=func_02045770(p->windows[i]);
        func_0201C7A4(target,(row->w-8)*4-(width>>1),(row->h-2)*4-(height>>1),text,func_021B7CBC(object));
        func_02045808(text);
        func_02045334(p->windows[i]);
    }
    func_0201DD68();
}
