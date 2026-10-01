/*
 * function: func_021F21FC
 * address: 0x021F21FC
 * packet: pkt_ov194_021F21FC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: shared failure label retains one exit; byte-offset cast +10 inside the loop
 * materialises the added-array base after the entry guard, unlike change.added.
 * symbols:
 *   func_021F4ED8 0x021F4ED8 thumb ov194
 *   func_021F4E18 0x021F4E18 thumb ov194
 *   func_021F4DDC 0x021F4DDC thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F2190 0x021F2190 thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021F4ED8(void *,u16 *);
extern int func_021F4E18(int,int,u16 *,int,u8 *);
extern void func_021F4DDC(void *,u16,u16 *,int,u8 *);
extern int func_021F2150(u8 *);
extern int func_021F2190(char *,u16);
typedef struct { u8 removedCount, addedCount; u16 removed[4],added[4]; } Changes;
int func_021F21FC(u8 *a,int b)
{
    void *p;
    u16 v;
    Changes change;
    int i;
    u16 *tab;
    switch(b) {
    case 0: p=*(void **)(a+132); break;
    case 1: p=*(void **)(a+136); break;
    default:return 0;
    }
    if (*(u16 *)(a+30)==0) goto fail;
    v=func_021F4ED8(p,(u16 *)(a+(*(u16 *)(a+30)-1)*2));
    if(v==65535) goto fail;
    if(!func_021F4E18((int)p,v,change.added,4,&change.addedCount)) goto fail;
    func_021F4DDC(p,v,change.removed,4,&change.removedCount);
    for(i=0;i<change.removedCount;i++) func_021F2150(a);
    for(i=0;i<change.addedCount;i++) {
        tab=(u16 *)((u8 *)&change+10);
        func_021F2190((char *)a,tab[i]);
    }
    return 1;
fail:
    return 0;
}
