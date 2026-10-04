/*
 * function: func_021DB478
 * address: 0x021DB478
 * packet: pkt_ov121_021DB478
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB54C 0x021DB54C thumb ov121
 *   func_021DBDB8 0x021DBDB8 thumb ov121
 *   func_021D9B28 0x021D9B28 thumb ov121
 *   func_021D9B2C 0x021D9B2C thumb ov121
 *   func_021D9AC8 0x021D9AC8 thumb ov121
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void func_021DB54C(char *,int,int,int,u16,u16);
extern int func_021DBDB8(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void func_021D9B28(u8 *p, unsigned v);
extern void func_021D9B2C(void *,int,int,int);
extern void func_021D9AC8(u8 *p, int a, int b);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_020409B4(u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021DB478(char *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) func_021DB54C(p,a,b,c,(u16)i,heap);
    text=func_020457B0(128,heap);
    other=func_02045EC0(*(void **)(p+28),150);
    func_0201EFA4(*(void **)(p+24),0,c+1,1,1,1);
    func_0201EFA4(*(void **)(p+24),1,func_021DBDB8(p),1,1,1);
    func_0201F250(*(void **)(p+24),text,other);
    func_021D9B28(*(void **)(p+0xab4),0x39ea);
    func_021D9B2C(*(void **)(p+0xab4),0,0,1);
    func_021D9AC8(*(void **)(p+0xab4),(int)text,*(int *)(p+16));
    func_02045808(text);
    func_02045808(other);
    func_020409B4(3);
}
