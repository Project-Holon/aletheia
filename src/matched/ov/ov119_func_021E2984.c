/*
 * function: func_021E2984
 * address: 0x021E2984
 * packet: pkt_ov119_021E2984
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0202800C 0x0202800C thumb
 *   func_02045808 0x02045808 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct Obj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_0202800C(void *,void *,int,int,int,int,int,int,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021B6558(int,int,int);
void *func_021E2984(char *p,int a) {
    void *t;
    t=func_020457B0(100,*(u16 *)(p+0x5f4));
    *(void **)(p+0x650)=t;
    func_02045CAC(*(void **)(p+0x720),a,t);
    *(u16 *)(p+0x654)=0x39e3;
    *(int *)(p+0x658)=0;
    *(void **)(p+0x648)=func_0202800C(*(void **)(p+0x6b0),p+0x650,8,21,16,3,0,1,*(u16 *)(p+0x5f4));
    func_02045808(*(void **)(p+0x650));
    func_0204B3DC(*(void **)(p+0xf04),0);
    func_021B6558(*(int *)(p+0x9c0),8,0);
    return *(void **)(p+0x648);
}
