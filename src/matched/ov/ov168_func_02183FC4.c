/*
 * function: func_02183FC4
 * address: 0x02183FC4
 * packet: pkt_ov168_02183FC4
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: ABF0 and B294 results remain live and are stored by this caller; their extern return types reflect that use.
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 *   func_0204B604 0x0204B604 arm
 *   d_02184910 0x02184910 data a4
 *   d_021848AC 0x021848AC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 group,id,config;} Row;
typedef struct {short x,y,id;u8 a,b;} Config;
extern const Row d_02184910[];
extern const Config d_021848AC[];
extern void *func_0204B100(int,u8,u32);
extern void *func_020490F4(u32,u16);
extern u32 func_020275E4(void);
extern u32 func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B92C(void *,u32);
extern void func_0204B3DC(void *,u32);
extern void func_0204B570(void *,u32);
extern void func_0204B604(void *,u32,u32);
void func_02183FC4(char *p,u16 heap)
{
    void *first,*second;
    u16 i;
    const Row *r;
    char *q;
    i=0;
    *(void **)(p+0x1c)=func_0204B100(32,0,heap);
    first=func_020490F4(106,heap);
    second=func_020490F4(func_020275E4(),heap);
    *(u32 *)(p+0x24)=func_0204ABF0(first,6,0,0,heap);
    *(int *)(p+0x20)=func_0204A6C8(first,7,0,0,heap);
    *(int *)(p+0x28)=func_0204AF28(first,8,9,heap);
    *(u32 *)(p+0x30)=func_0204ABF0(first,10,0,32,heap);
    *(int *)(p+0x2c)=func_0204A6C8(first,11,0,0,heap);
    *(int *)(p+0x34)=func_0204AF28(first,12,13,heap);
    *(u32 *)(p+0x3c)=func_0204ABF0(first,14,0,64,heap);
    *(int *)(p+0x38)=func_0204A6C8(first,15,0,0,heap);
    *(int *)(p+0x40)=func_0204AF28(first,16,17,heap);
    *(u32 *)(p+0x48)=func_0204ABF0(second,31,1,0,heap);
    *(int *)(p+0x44)=func_0204A6C8(second,32,0,1,heap);
    *(int *)(p+0x4c)=func_0204AF28(first,18,19,heap);
    func_02049238(second);
    func_02049238(first);
    do{
        r=&d_02184910[i];
        q=p+r->group*4;
        *(void **)(p+i*4)=func_0204B294(*(u32 *)(p+0x1c),*(u32 *)(q+0x20),*(u32 *)(q+0x24),*(u32 *)(q+0x28),(u32)&d_021848AC[r->config],r->id,heap);
        func_0204B92C(*(void **)(p+i*4),1);
        ++i;
    }while(i<7);
    for(i=0;i<3;i++)func_0204B3DC(*(void **)(p+i*4+0x10),0);
    func_0204B570(*(void **)p,0);
    func_0204B604(*(void **)p,1,1);
    *(int *)(p+0xe0)=10;
}
