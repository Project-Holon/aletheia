/*
 * unit: yes
 * function: func_021E2BD0, func_021E2C34
 * address: 0x021E2BD0
 * packet: pkt_ov119_021E2BD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B20 0x02048B20 arm
 *   func_021E3A40 0x021E3A40 thumb ov119
 */
typedef struct {int x,y,z;} Vec;
extern void func_02048AFC(void *,Vec *);
extern void func_02048B44(void *,Vec *);
extern void func_02048B60(void *,int *);
extern void func_02048B6C(void *,int *);
extern void func_02048B20(void *,Vec *);
void func_021E2BD0(char *p) {
    Vec a;
    Vec b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    func_02048AFC(*(void **)(p+0x83c),&a);
    func_02048B44(*(void **)(p+0x83c),&b);
    func_02048B60(*(void **)(p+0x83c),&d);
    func_02048B6C(*(void **)(p+0x83c),&c);
    b.x=0; b.y=0x10000; b.z=0x1000;
    func_02048B20(*(void **)(p+0x83c),&b);
}
extern void func_021E3A40(char *);
void func_021E2C34(char *p) {func_021E3A40(p);}
