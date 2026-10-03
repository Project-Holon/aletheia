/*
 * function: func_021BA898
 * address: 0x021BA898
 * packet: pkt_ov225_021BA898
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: index before 0x60 keeps field offset in immediate; distinct loop
 * parent local restores r7 parent / r6 destination allocation.
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   func_021BA9D0 0x021BA9D0 thumb ov225
 *   d_021BBF8C 0x021BBF8C data ov225 a2
 *   d_021BBF94 0x021BBF94 data ov225 a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Quad { short x,y,z,w; };
extern const struct Quad d_021BBF8C,d_021BBF94;
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern u32 func_020499D4(void *,u32,u32,u32,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_021B9A08(const u8 *p);
extern void func_021BA9D0(char *);
void func_021BA898(char *p)
{
    struct Quad q[2];
    u8 i;
    char *parent;
    func_02049B68(*(void **)(*(char **)(p+4)+0x24),0,4,0,0x40,*(u16 *)(*(char **)(p+4)+4));
    func_02049658(*(void **)(*(char **)(p+4)+0x24),2,4,0,0,0,*(u16 *)(*(char **)(p+4)+4));
    func_020499D4(*(void **)(*(char **)(p+4)+0x24),5,4,0,0,0,0,*(u16 *)(*(char **)(p+4)+4));
    *(int *)(p+0x54)=func_0204AC18(*(void **)(*(char **)(p+4)+0x24),1,1,0,0,1,*(u16 *)(*(char **)(p+4)+4));
    *(int *)(p+0x50)=func_0204A6C8(*(void **)(*(char **)(p+4)+0x24),3,0,1,*(u16 *)(*(char **)(p+4)+4));
    *(int *)(p+0x58)=func_0204AF28(*(void **)(*(char **)(p+4)+0x24),7,8,*(u16 *)(*(char **)(p+4)+4));
    q[1]=d_021BBF8C;
    parent=*(char **)(p+4);
    *(void **)(p+0x5c)=func_0204B294((u32)func_021B9A08(*(void **)(parent+8)),*(u32 *)(p+0x50),*(u32 *)(p+0x54),*(u32 *)(p+0x58),(u32)&q[1],1,*(u16 *)(parent+4));
    func_0204B3DC(*(void **)(p+0x5c),0);
    func_0204B92C(*(void **)(p+0x5c),1);
    q[0]=d_021BBF94;
    for(i=0;i<8;i++) {
        char *loopparent;
        q[0].y=i*24-8;
        loopparent=*(char **)(p+4);
        *(void **)(p+i*4+0x60)=func_0204B294((u32)func_021B9A08(*(void **)(loopparent+8)),*(u32 *)(p+0x50),*(u32 *)(p+0x54),*(u32 *)(p+0x58),(u32)&q[0],1,*(u16 *)(loopparent+4));
        func_0204B3DC(*(void **)(p+i*4+0x60),0);
        func_0204B92C(*(void **)(p+i*4+0x60),1);
    }
    func_021BA9D0(p);
}
