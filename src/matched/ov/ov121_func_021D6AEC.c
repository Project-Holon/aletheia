/*
 * function: func_021D6AEC
 * address: 0x021D6AEC
 * packet: pkt_ov121_021D6AEC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D6C26.
 * lever: spell the object slot as p+i*4+16; data precedes allocation in local declarations.
 * interfaces: ABF0 and B294 leave r0 live and this caller consumes it despite legacy void definitions.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02005728 0x02005728 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 x,y,z; u8 a,b; } Record;
struct Obj;
extern void *func_020490F4(u32 id, u16 heap);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_02049F78(void *,int,void **,u16);
extern void func_02082D44(const void *,void *,int);
extern void func_020307B0(void *);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,int);
extern void *func_0204B294(u32,u32,u32,u32,Record *,u16,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_02005728(u32 range);
void func_021D6AEC(char *p,u32 owner,u16 heap)
{
    void *res;
    Record point;
    int bound;
    char *data;
    void *allocation;
    void *arc;
    int i;
    arc=func_020490F4(34,heap);
    *(int *)p=func_0204ABF0(arc,8,2,0,heap);
    *(int *)(p+8)=func_0204AF28(arc,34,37,heap);
    *(int *)(p+4)=func_0204A6C8(arc,16,0,2,heap);
    allocation=func_02049F78(arc,8,&res,heap);
    data=*(char **)((char *)res+12);
    func_02082D44(data,p+0xda,32);
    data+=32;
    func_02082D44(data,p+0xba,32);
    func_020307B0(allocation);
    func_02049238(arc);
    func_02082BCC(&point,0,8);
    *(void **)(p+12)=func_0204B294(owner,*(u32 *)(p+4),*(u32 *)p,*(u32 *)(p+8),&point,0,heap);
    func_0204B3DC(*(void **)(p+12),0);
    bound=256;
    bound+=16;
    for (i=0;i<32;i++) {
        point.x=func_02005728(256);
        point.y=func_02005728(256)-bound;
        point.b=3;
        point.z=func_02005728(6)+3;
        *(void **)(p+i*4+16)=func_0204B294(owner,*(u32 *)(p+4),*(u32 *)p,*(u32 *)(p+8),&point,0,heap);
        func_0204B3DC(*(void **)(p+i*4+16),0);
    }
    point.x=128;
    point.y=177;
    point.b=0;
    point.a=1;
    point.z=9;
    *(void **)(p+148)=func_0204B294(owner,*(u32 *)(p+4),*(u32 *)p,*(u32 *)(p+8),&point,0,heap);
    func_0204B3DC(*(void **)(p+148),0);
}
