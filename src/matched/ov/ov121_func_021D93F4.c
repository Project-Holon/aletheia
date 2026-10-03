/*
 * function: func_021D93F4
 * address: 0x021D93F4
 * packet: pkt_ov121_021D93F4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D9486; next function starts 021D9488.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_021DA8CC 0x021DA8CC thumb ov121
 *   func_021DA9EC 0x021DA9EC thumb ov121
 *   func_021DA9F0 0x021DA9F0 thumb ov121
 *   func_021DA994 0x021DA994 thumb ov121
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Pos;
extern void func_02082BCC(void *,int,int);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_021DA8CC(Pos *,int,int,void *,u8,int,void *,int,u16);
typedef unsigned int   u32;
struct Obj;
extern void func_021DA9EC(u8 *p, int a);
extern void func_021DA9F0(u32 *p, u32 a, u32 b, u32 c);
extern void func_021DA994(char *p, int a, int b, int c);
extern void *func_021D6C58(const void *,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021D93F4(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap)
{
    Pos pos;
    func_02082BCC(p,0,12);
    *(const void **)(p+8)=q;
    *(void **)p=func_02025538(heap,(void *)n);
    func_02082BCC(&pos,0,8);
    pos.x=96; pos.y=169; pos.a=0; pos.b=0;
    *(void **)(p+4)=func_021DA8CC(&pos,8,2,*(void *const *)q,3,0,*(void **)p,k,heap);
    func_021DA9EC(*(void **)(p+4),1120);
    func_021DA9F0(*(void **)(p+4),0,0,1);
    func_021DA994(*(void **)(p+4),x,y,z);
    func_0204B3DC(func_021D6C58(q,34),1);
}
