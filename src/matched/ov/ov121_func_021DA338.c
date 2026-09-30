/*
 * function: func_021DA338
 * address: 0x021DA338
 * packet: pkt_ov121_021DA338
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: heap is u16 in this function and the two callees receiving it.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_02043994 0x02043994 arm
 *   func_02043678 0x02043678 arm
 *   d_021DFBA0 0x021DFBA0 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern char d_021DFBA0[];
extern void *func_02030734(u16,int,int,const char *,int);
extern void func_02082BCC(void *,int,int);
extern void *func_02045770(void *);
extern u32 func_020437DC(void *);
extern u32 func_020437E4(void *);
extern u32 func_02043994(void *);
extern void *func_02043678(u32,u32,u32,u16);
void *func_021DA338(char *p,u16 heap)
{
    u32 i;
    int size=*(u32 *)(p+4)*4+8;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x42e);
    func_02082BCC(out,0,size);
    *(char **)(out+4)=p;
    *(u16 *)out=heap;
    for(i=0;i<*(u32 *)(p+4);i++) {
        void *win=func_02045770(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=func_020437DC(win);
        u32 y=func_020437E4(win);
        u32 type=func_02043994(win);
        *(void **)(out+i*4+8)=func_02043678(x/8,y/8,type,heap);
    }
    return out;
}
