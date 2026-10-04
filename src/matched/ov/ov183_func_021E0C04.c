/*
 * function: func_021E0C04
 * address: 0x021E0C04
 * packet: pkt_ov183_021E0C04
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef short s16;
struct Params {s16 x,y,a,b,z;u8 mode,flag;};
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B688(void *,u32),func_0204B404(void *,s16 *,int),func_0204B878(void *,u16);
void func_021E0C04(char *p) {
    struct Params pos;
    u32 manager=*(u32 *)(p+0x25C);
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    *(u32 *)(p+0x1E8)=(u32)func_0204B294((void *)manager,*(u32 *)(p+0x270),*(u32 *)(p+0x264),*(u32 *)(p+0x288),&pos.a,1,*(u16 *)(p+0x34C));
    func_0204B688(*(void **)(p+0x1E8),1);
    pos.z=1;
    *(u32 *)(p+0x204)=(u32)func_0204B294((void *)manager,*(u32 *)(p+0x270),*(u32 *)(p+0x264),*(u32 *)(p+0x288),&pos.a,1,*(u16 *)(p+0x34C));
    func_0204B688(*(void **)(p+0x204),1);
    pos.x=*(u8 *)(p+0x2F2);pos.y=*(u8 *)(p+0x2F0)+16;
    func_0204B404(*(void **)(p+0x1E8),&pos.x,1);
    func_0204B878(*(void **)(p+0x1E8),0);
    pos.x=*(u8 *)(p+0x2F6);pos.y=*(u8 *)(p+0x2F4)+16;
    func_0204B404(*(void **)(p+0x204),&pos.x,1);
    func_0204B878(*(void **)(p+0x204),1);
}
