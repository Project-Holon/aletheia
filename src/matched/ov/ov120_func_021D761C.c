/*
 * function: func_021D761C
 * address: 0x021D761C
 * packet: pkt_ov120_021D761C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D770E.
 * lever: indexed pointer sum before the far field offset preserves the base.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021D6ED8 0x021D6ED8 thumb ov120
 *   func_021D6C64 0x021D6C64 thumb ov120
 *   func_021D7484 0x021D7484 thumb ov120
 *   func_021D6FB4 0x021D6FB4 thumb ov120
 *   func_021D6B5C 0x021D6B5C thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 *   func_021D698C 0x021D698C thumb ov120
 *   func_021D692C 0x021D692C thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_021D6ED8(u8 *);
extern void func_021D6C64(u8 *);
extern void func_021D7484(u8 *);
extern void func_021D6FB4(u8 *);
extern void func_021D6B5C(u8 *);
extern void *func_020490F4(void *,u16);
extern void func_02049990(void *,u32,u32,u32,u16,u32,u32,u16);
extern void func_02049BDC(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_021D698C(u8 *);
extern void func_021D692C(u8 *,int);
extern void func_02040588(u32,u32);
extern void func_02041B6C(u32);
void func_021D761C(u8 *p)
{
    int i;
    void *t;
    for(i=0;i<6;i++) {
        if(*(void **)(p+i*4+0x14c)) {
            func_0204B3DC(*(void **)(p+i*4+0x14c),0);
            func_0204B3B4(*(void **)(p+i*4+0x14c));
            *(u32 *)(p+i*4+0x14c)=0;
        }
    }
    func_021D6ED8(p);
    func_021D6C64(p);
    func_021D7484(p);
    func_021D6FB4(p);
    func_021D6B5C(p);
    t=func_020490F4((void *)144,*(u16 *)(p+0xf4));
    func_02049990(t,12,0,0,*(u32 *)(p+4),0,0,*(u16 *)(p+0xf4));
    func_02049990(t,18,4,0,*(u32 *)p,0,0,*(u16 *)(p+0xf4));
    func_02049BDC(t,2,5,0,0x100,0x100,*(u16 *)(p+0xf4));
    func_02049238(t);
    func_021D698C(p);
    func_021D692C(p,0);
    func_02040588(2,0);
    func_02041B6C(0);
    func_02040588(3,0);
    *(u32 *)(p+0x110)=0;
    *(u32 *)(p+0x114)=0;
}
