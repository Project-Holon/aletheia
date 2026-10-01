/*
 * function: func_021D9568
 * address: 0x021D9568
 * packet: pkt_ov131_021D9568
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D964A follow the 226-byte body.
 * proof: selector is a byte; selector*8+316 <=2356. Position stores
 * initialize every byte of the eight-byte descriptor before passing it.
 * prototype: 0204B294 leaves 0204CFDC's pointer return live at 0204B318;
 * 021D960E stores it. Keep the own body's u32,u32,u32,u32,u32,u16,u16
 * inputs, and expose the observed r0 result despite its legacy void return.
 * symbols:
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_021DBF2C 0x021DBF2C thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_02041B6C(u32);
extern void *func_020490F4(void *,u32);
extern int func_0204A6C8(u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B6F4(void *,u8,u32);
extern void func_0204B3DC(void *,u32);
extern void func_02040AE0(u32,void *,u32);
extern u32 func_021DBF2C(u32,u32);
void func_021D9568(u8 *a,u8 *p)
{
    void *cell;
    void *archive;
    u8 index;
    ObjPos pos;
    index=(p+p[0x59]*8)[0x13c];
    cell=*(void **)(p+0x20);
    func_02045334(cell);
    func_02045374(cell);
    func_02041B6C(func_02045730(cell));
    cell=*(void **)(p+0x24);
    func_02045334(cell);
    func_02045374(cell);
    func_02041B6C(func_02045730(cell));
    archive=func_020490F4((void *)78,*(u16 *)a);
    *(u32 *)(p+0x18)=func_0204A6C8((u32)archive,func_021DBF2C(index,1),0,1,*(u16 *)a);
    func_02049238(archive);
    pos.x=128;
    pos.y=100;
    pos.priority=10;
    pos.flags=0;
    pos.z=0;
    *(u32 *)(p+0x1c)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(p+0x18),*(u32 *)(a+0xb4),*(u32 *)(a+0x128),(u32)&pos,1,*(u16 *)a);
    func_0204B6F4(*(void **)(p+0x1c),func_021DBF2C(index,2),1);
    func_0204B3DC(*(void **)(p+0x1c),1);
    func_02040AE0(6,*(u8 **)(p+0x38)+12,*(u32 *)(*(u8 **)(p+0x38)+8));
    func_02041B6C(6);
    *(u32 *)(p+4)=1;
}
