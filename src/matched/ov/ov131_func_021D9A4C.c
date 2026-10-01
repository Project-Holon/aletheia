/*
 * function: func_021D9A4C
 * address: 0x021D9A4C
 * packet: pkt_ov131_021D9A4C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D9BD2 follow the 390-byte body.
 * proof: i is byte-wrapped; i*24 <=6120, every descriptor byte initialized.
 * No bound smaller than the ldrb domain is assumed for p[43].
 * prototype: 0204B294 leaves 0204CFDC's pointer result live at 0204B318;
 * this caller stores r0 after every call. Keep all seven own-body inputs.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021DB700 0x021DB700 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B3DC(void *,u32);
extern void func_0204B92C(void *,u32);
extern void func_021DB700(u8 *,void *,u8 *,u8);
void func_021D9A4C(u8 *a,u8 *p)
{
    ObjPos pos;
    u8 i;
    pos.x=159;
    pos.y=52;
    pos.priority=10;
    pos.flags=1;
    i=0;
    pos.z=0;
    *(u32 *)(p+0x90)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(a+0xe4),*(u32 *)(a+0xac),*(u32 *)(a+0x114),(u32)&pos,1,*(u16 *)a);
    func_0204B3DC(*(void **)(p+0x90),0);
    pos.x=172;
    pos.y=56;
    *(u32 *)(p+0x94)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(a+0xd8),*(u32 *)(a+0xa8),*(u32 *)(a+0x10c),(u32)&pos,1,*(u16 *)a);
    func_0204B3DC(*(void **)(p+0x94),0);
    pos.flags=0;
    *(u32 *)(p+0x98)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(a+0xec),*(u32 *)(a+0xc4),*(u32 *)(a+0x11c),(u32)&pos,0,*(u16 *)a);
    func_0204B3DC(*(void **)(p+0x98),0);
    pos.z=5;
    pos.priority=8;
    *(u32 *)(p+0x9c)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(a+0xec),*(u32 *)(a+0xc4),*(u32 *)(a+0x11c),(u32)&pos,0,*(u16 *)a);
    func_0204B3DC(*(void **)(p+0x9c),0);
    func_0204B92C(*(void **)(p+0x9c),1);
    pos.z=2;
    pos.priority=4;
    pos.flags=0;
    *(u32 *)(p+0xa0)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(a+0xec),*(u32 *)(a+0xc4),*(u32 *)(a+0x11c),(u32)&pos,0,*(u16 *)a);
    func_0204B3DC(*(void **)(p+0xa0),0);
    func_0204B92C(*(void **)(p+0xa0),1);
    for(;i<p[0x2b];i++) func_021DB700(a,p,(p+0xb0)+i*24,i);
}
