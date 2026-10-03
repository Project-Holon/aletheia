/*
 * function: func_0220BBE4
 * address: 0x0220BBE4
 * packet: pkt_ov197_0220BBE4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CFEC 0x0202CFEC thumb
 *   func_0202CB18 0x0202CB18 thumb
 *   func_02049238 0x02049238 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   d_0220DB44 0x0220DB44 data a4
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct {u16 member;u8 w,h;} Config;
extern const Config d_0220DB44[14];
struct WinMgr;
extern struct WinMgr *func_0202C9B4(u32,u32,u32);
extern void *func_020490F4(u32,u16);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CFEC(void *,u32,u8,u8,s8,s8);
extern void func_0202CB18(struct WinMgr *mgr,u32,void *,u32,u32);
extern void func_02049238(void *);
extern void func_0202CB4C(struct WinMgr *mgr,u32,s8,s8);
void func_0220BBE4(char *p)
{
    void *arc;
    unsigned i;
    *(void **)(p+0x520)=func_0202C9B4(2,14,*(u16 *)(*(char **)p+0xC));
    arc=func_020490F4(99,(*(u16 *)(*(char **)p+0xC)&0x7FFF)|0x8000);
    for(i=0;i<14;i++){
        func_0202CA3C(*(void **)(p+0x520),i,6,d_0220DB44[i].w,d_0220DB44[i].h);
        func_0202CFEC(*(void **)(p+0x520),i,0,64,0,64);
        func_0202CB18(*(void **)(p+0x520),i,arc,d_0220DB44[i].member,1);
    }
    func_02049238(arc);
    func_0202CB4C(*(void **)(p+0x520),0,0,1);
    func_0202CB4C(*(void **)(p+0x520),1,0,10);
    func_0202CB4C(*(void **)(p+0x520),2,16,1);
    func_0202CB4C(*(void **)(p+0x520),3,16,10);
    func_0202CB4C(*(void **)(p+0x520),4,32,1);
    func_0202CB4C(*(void **)(p+0x520),5,48,1);
    func_0202CB4C(*(void **)(p+0x520),6,32,7);
    func_0202CB4C(*(void **)(p+0x520),7,48,7);
    func_0202CB4C(*(void **)(p+0x520),8,32,13);
    func_0202CB4C(*(void **)(p+0x520),9,48,13);
    func_0202CB4C(*(void **)(p+0x520),11,32,19);
    func_0202CB4C(*(void **)(p+0x520),12,37,19);
}
