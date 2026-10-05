/*
 * function: func_021BA6A0
 * address: 0x021BA6A0
 * packet: pkt_ov091_021BA6A0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: arm9 0x0204B09C, unlabelled ARM leaf; no outside witness.
 *   Verified C from pre-wave pkt_ov091_021BB200, reverified by one --arm
 *   without region in scratch blocker4B09C.log:
 *   struct Item { int x; int y; u8 pad_08[0x40]; };
 *   struct Owner { u8 pad_00[0x98]; struct Item *items; };
 *   struct Pt { short x; short y; };
 *   void func_0204B09C(struct Owner *owner, u32 index, struct Pt *in) {
 *       int x = in->x; int y = in->y;
 *       struct Item *it = owner->items; struct Item *p;
 *       it[index].x = x << 12; p = &it[index]; p->y = y << 12;
 *   }
 * lever: u8 coordinate locals delay reloads until after stack arguments;
 *   enum selector keeps its comparison before the temporary offset stores.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`t
 * = x;` before `t = x + 0x10;`). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_021BA954 0x021BA954 thumb ov091
 *   func_021BAA50 0x021BAA50 thumb ov091
 *   func_021BB46C 0x021BB46C thumb ov091
 *   func_021B9A84 0x021B9A84 thumb ov091
 *   func_021BAFA0 0x021BAFA0 thumb ov091
 *   func_021BAAE4 0x021BAAE4 thumb ov091
 *   d_021BED18 0x021BED18 data ov091 a1
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x,y; u16 a,b,c,d; int e,f; } Rect;
struct Bank;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020410D0(u32,u8,u32,u32,u8,void *,u8,u8,u8,u8);
extern void *func_0204B034(void *,u32,u32);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_0204B09C(void *,u32,Rect *);
extern void *func_020450F0(int,u8,int,int,u8,u8,u8);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_021BA954(u8 *,u8 *);
extern void func_021BAA50(u8 *,u8 *);
extern void func_021BB46C(u8 *,u8 *);
extern int func_021B9A84(u8 *);
extern void func_021BAFA0(u8 *,u8 *,int);
extern void func_021BAAE4(u8 *,u8 *,int);
extern const char d_021BED18[];
extern const u8 d_021BEC74[], d_021BEC75[], d_021BEC6C[], d_021BEC6D[];
#define W(k) (*(u32 *)(s+(k)))
u8 *func_021BA6A0(u8 *p, int k, void *mon)
{
    u8 x = d_021BEC74[k*2];
    u8 y = d_021BEC75[k*2];
    u8 i;
    u8 *s;
    int t;
    int zero = 0;
    enum Selector { SEL_ZERO, SEL_ONE } selector;
    Rect r;
    s = func_02030734(*(u16 *)p,0x44,0,d_021BED18,0x9f);
    s[4] = k;
    W(0) = (u32)mon;
    W(0x14) = 0;
    W(0x10) = 0;
    W(0x18) = 0;
    *(u16 *)(s+6) = func_02017E1C(mon,0xa0,0);
    *(u16 *)(s+8) = *(u16 *)(s+6);
    if (k != 0) zero = 1;
    selector = k != 0;
    t = x + 0x10;
    func_020410D0(2,t,y,0x10,6,*(u8 **)(p+0x15c)+0xc,
                 d_021BEC6C[selector*2],d_021BEC6D[zero*2],0x20,0x20);
    W(0xc) = func_02017E1C((void *)W(0),0x4c,0);
    r.a = 0;
    r.b = 0;
    r.c = 0x100;
    r.d = 0xc0;
    r.e = 0;
    r.f = 0;
    W(0x24) = (u32)func_0204B034(&r.a,1,*(u16 *)p);
    W(0x28) = (u32)func_0204B100(6,0,*(u16 *)p);
    func_0204B258((void *)W(0x28),(void *)W(0x24));
    func_021BA954(p,s);
    func_021BAA50(p,s);
    r.x = -x*8;
    r.y = -y*8;
    func_0204B09C((void *)W(0x24),0,&r);
    W(0x20) = (u32)func_020450F0(1,t,y,0x10,6,0xd,1);
    func_021BB46C(p,s);
    if (func_021B9A84(p) == 1) {
        for (i = 0; i < 6; i++) {
            if (s[4] + 1 == *(u8 *)(*(u8 **)(p+0x280)+i+0x49)) W(0x1c) = i;
        }
    }
    func_021BAFA0(p,s,0);
    func_021BAAE4(p,s,0);
    return s;
}
