/*
 * function: func_021BC160
 * address: 0x021BC160
 * packet: pkt_ov110_021BC160
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * lever: typed two-by-two pointer member retains the inner indexed base.
 * symbols:
 *   func_021BAC50 0x021BAC50 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef short s16;
typedef struct { int a,b,c; } Triple;
typedef struct { void *root; u8 pad[0x18]; void *items[2][2]; } Obj;
extern void func_021BAC50(void *,Triple *,int);
extern void *func_021BAC78(void *,Triple *,s16,s16,int,int);
extern void func_0204B3DC(void *,int);
void func_021BC160(Obj *p)
{
    Triple t;
    int i,j;
    for (i=0;i<2;i++) {
        func_021BAC50(p->root,&t,i);
        for (j=0;j<2;j++) {
            p->items[j][i]=func_021BAC78(p->root,&t,0,0,2,i+1);
            func_0204B3DC(p->items[j][i],0);
        }
    }
}
