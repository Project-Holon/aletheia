/*
 * function: func_021BF94C
 * address: 0x021BF94C
 * packet: pkt_ov110_021BF94C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BF9EE.
 * lever: typed items member and z=i preserve indexed base and copied zero.
 * symbols:
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BAC50 0x021BAC50 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Triple;
typedef struct { void *root; void *a; void *b; void *c; void *d; void *first; void *unused; void *second; void *items[10]; } Obj;
extern void func_021BAC64(void *,Triple *,int,int);
extern void *func_021BAC78(void *,Triple *,int,int,int,int);
extern void func_021BAC50(void *,Triple *,int);
extern void func_0204B878(void *,u16);
extern void func_0204B3DC(void *,unsigned);
extern void func_0204B84C(void *,int);
void func_021BF94C(Obj *p) {
    Triple t;
    Triple s;
    int i;
    int z;
    i=0;
    func_021BAC64(p->root,&t,0,0);
    p->first=func_021BAC78(p->root,&t,62,24,4,1);
    func_0204B878(p->first,8);
    func_0204B3DC(p->first,0);
    p->second=func_021BAC78(p->root,&t,244,18,5,1);
    func_0204B878(p->second,18);
    func_0204B3DC(p->second,0);
    z=i;
    for(;i<10;i++) {
        func_021BAC50(p->root,&s,z);
        p->items[i]=func_021BAC78(p->root,&s,z,z,z,1);
        func_0204B878(p->items[i],i);
        func_0204B3DC(p->items[i],z);
        func_0204B84C(p->items[i],1);
    }
}
