/*
 * function: func_0221099C
 * address: 0x0221099C
 * packet: pkt_ov198_0221099C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * remainder: two-byte alignment padding at 02210A4A.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_022107A8 0x022107A8 thumb ov198
 */
typedef unsigned char u8;
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
extern void func_022107A8(u8 *,void *,u8 *);
void func_0221099C(u8 *p)
{
    unsigned i;
    if (*(int *)(*(u8 **)p+0x18)==0) {
        for (i=0;i<6;i++) {
            if (i<func_0201AA18(*(void **)(*(u8 **)p+4)))
                func_022107A8(p,func_0201AB28(*(void **)(*(u8 **)p+4),i),p+4+i*76);
            else func_022107A8(p,0,p+4+i*76);
        }
    } else {
        for (i=0;i<3;i++) {
            if (i<func_0201AA18(*(void **)(*(u8 **)p+4)))
                func_022107A8(p,func_0201AB28(*(void **)(*(u8 **)p+4),i),p+4+i*76);
            else func_022107A8(p,0,p+4+i*76);
            if (i<func_0201AA18(*(void **)(*(u8 **)p+8)))
                func_022107A8(p,func_0201AB28(*(void **)(*(u8 **)p+8),i),p+4+(i+3)*76);
            else func_022107A8(p,0,p+4+(i+3)*76);
        }
    }
}
