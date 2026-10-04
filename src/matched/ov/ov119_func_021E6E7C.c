/*
 * function: func_021E6E7C
 * address: 0x021E6E7C
 * packet: pkt_ov119_021E6E7C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204ABBC 0x0204ABBC arm
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E804 0x0207E804 arm
 *   d_021E7DD8 0x021E7DD8 data a1
 */
typedef unsigned char u8;
typedef struct { u8 v[8]; } Table;
extern const Table d_021E7DD8;
extern char *func_0204ABBC(int,int);
typedef unsigned int   u32;
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *,int);
extern void func_0207E804(const void *,void *,unsigned int);
void func_021E6E7C(int p) {
    Table t=d_021E7DD8;
    int i,j;
    char *dest,*source;
    for(i=0;i<8;i++) {
        dest=func_0204ABBC(*(int *)(p+i*4+0x1114),1);
        source=func_020437D4((const struct Bmp *)(*(int *)(p+i*4+0x10f4)));
        func_020862F0(source,func_020437EC((const struct Bmp *)(*(int *)(p+i*4+0x10f4))));
        for(j=0;j<8;j++) {func_0207E804(source+t.v[j]*256,dest,256);dest+=256;}
    }
}
