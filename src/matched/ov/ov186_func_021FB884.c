/*
 * function: func_021FB884
 * address: 0x021FB884
 * packet: pkt_ov186_021FB884
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: allocated fields +F4 and +F8 re-read after their stores at 021FB8B0 and 021FB8C0.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021FC148 0x021FC148 thumb ov186
 *   d_02200D3C 0x02200D3C data a1
 */
typedef struct Object {char pad[0xe8];void *a,*b,*c;volatile unsigned flag,mode;} Object;
extern const char d_02200D3C[];
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC74(unsigned,unsigned,unsigned);
extern void func_021FC148(char *,unsigned,unsigned);
void *func_021FB884(unsigned mode,unsigned flag,unsigned heap)
{
    Object *p;
    p=func_02030734(heap,0xfc,0,d_02200D3C,0x60);
    MI_CpuFill8(p,0,0xfc);
    p->flag=flag;
    if(p->flag){p->mode=mode;if(p->mode==1)p->mode=0;}
    else p->mode=1;
    p->a=GF_FONT_Create(0x17,0,0,0,heap);
    p->b=func_02045B38(0,2,5,heap);
    p->c=func_0201EC74(8,0x40,heap);
    func_021FC148((char *)p,0,heap);
    func_021FC148((char *)p,1,heap);
    return p;
}
