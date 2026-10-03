/*
 * function: func_021DA8CC
 * address: 0x021DA8CC
 * packet: pkt_ov121_021DA8CC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a and b are u16; the descriptor input pointer is const.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   d_021DFBA0 0x021DFBA0 data a4
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } Desc;
extern char d_021DFBA0[];
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void *func_020457B0(int,u16);
extern void *func_02043678(int,int,int,u16);
extern void *func_020255A0(void *,Desc *);
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    Desc desc;
    char *out=func_02030734(heap,36,0,d_021DFBA0,0x6b1);
    func_02082BCC(out,0,36);
    *(void **)(out+32)=g;
    *(void **)(out+24)=func_020457B0(128,heap);
    *(void **)out=func_02043678(a,b,32,heap);
    func_02082BCC(&desc,0,24);
    desc.win=*(void **)out;
    desc.x=*(s16 *)p;
    desc.y=*(s16 *)(p+2);
    desc.z=c;
    desc.a=*(u8 *)(p+6);
    desc.c=e;
    desc.d=e;
    desc.b=*(u8 *)(p+7);
    desc.pal=d;
    *(void **)(out+28)=func_020255A0(f,&desc);
    return out;
}
