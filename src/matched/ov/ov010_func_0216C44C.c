/*
 * function: func_0216C44C
 * address: 0x0216C44C
 * packet: pkt_ov010_0216C44C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0216C2FC 0x0216C2FC thumb ov010
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C58 0x02188C58 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020122C0(void *,void *,void *,unsigned int);
struct Obj;
extern void *func_020124E8(struct Obj *p);
typedef unsigned int u32;
typedef struct Work Work;
extern int func_0216C2FC(void *, u32 *, Work *);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *);
void *func_0216C44C(void *a,void *b) {
    void *t; u8 *p;
    t=func_020122C0(a,0,(void *)func_0216C2FC,0x14); p=func_020124E8(t);
    *(u16 *)p=func_02188C84(b); *(void **)(p+4)=a; *(void **)(p+8)=b;
    *(void **)(p+12)=func_02188C58(b); *(int *)(p+16)=0; return t;
}
