/*
 * function: func_021B84B4
 * address: 0x021B84B4
 * packet: pkt_ov105_021B84B4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_021B87E8 0x021B87E8 thumb ov105
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *,int,int);
extern int func_021B87E8(unsigned,int *);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_020498F4(void *,int,int,int,int,int,int);
extern void func_02049238(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern void func_020307B0(void *);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021B84B4(u8 *p,int id,int choice,int heap)
{
    void *archive, *data, *raw;
    u8 *pal;
    int i;
    func_02082BCC(p,0,0x60);
    *(u16 *)p=id;
    *(u16 *)(p+0x54)=func_021B87E8(choice,(int *)(p+0x5c));
    if (*(int *)(p+0x5c)) ++*(u16 *)(p+0x54);
    archive=func_020490F4(0x5e,heap);
    func_02049658(archive,15,3,0,0,0,heap);
    func_020498F4(archive,17,3,0,0,0,heap);
    func_02049238(archive);
    data=func_02049F34(0x5e,16,(u32)(&raw),heap);
    pal=*(u8 **)((u8 *)raw+12);
    func_02082D44(pal,p+8,32);
    func_02082D44(pal+0x100,p+8,32);
    func_020307B0(data);
    func_02082D44(p+8,p+0x28,32);
    for(i=0;i<13;++i) *(u16 *)(p+0x28+i*2)=0x7fff;
    for(i=0;i<16;++i) func_02061CA4((void *)15,0x100+i*2,(u32)(p+0x28+i*2),2);
}
