/*
 * function: func_021E6FD4
 * address: 0x021E6FD4
 * packet: pkt_ov119_021E6FD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021E6FC8 0x021E6FC8 thumb ov119
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct { short v; void *p; void (*fn)(void *); } Callback;
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204BA00(int,const Callback *);
extern void func_021E7058(void *);
extern void func_021E6FC8(void *);
void func_021E6FD4(char *p, int x, int y) {
    Callback cb;
    Create c;
    c.x=x+12;c.y=y+12;c.z=24;c.a=0;c.b=0;
    func_021E7058(p);
    *(int *)(p+0xf24)=(int)func_0204B294((void *)*(int *)(p+0x9c4),*(int *)(p+0x894),*(int *)(p+0x880),*(int *)(p+0x8b0),&c,1,*(u16 *)(p+0x5f4));
    func_0204B3DC((struct Obj *)*(int *)(p+0xf24),1);
    func_0204B92C((struct Obj *)*(int *)(p+0xf24),1);
    p[0x11f5]=0;
    cb.v=0;cb.p=p;cb.fn=func_021E6FC8;
    func_0204BA00(*(int *)(p+0xf24),&cb);
}
