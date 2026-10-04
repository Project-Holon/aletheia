/*
 * function: func_021F8EFC
 * address: 0x021F8EFC
 * packet: pkt_ov185_021F8EFC
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021FC4DC(u8 *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void *func_0200CA1C(void *a);
extern char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern void func_021FFE5C(char *);
void func_021F8EFC(char *p,int *source)
{
    if(*(int *)p==0) {
        int c=func_021FC4DC((u8 *)source[2]);
        char *result;
        if(*(int *)(p+4)==0)
            *(void **)(p+4)=func_021FD12C((int)((void *)source[3]),(void *)(*(int *)(p+0x2c)),*(unsigned short *)(p+0x30));
        func_021FD170(*(void **)(p+4),(void *)source[3],(void *)0x2c);
        result=func_021FFBD4(func_0200CA1C((void *)source[6]),(void *)source[3],c,*(int *)(p+0x28),source[0],*(int *)(p+0x38),*(int *)(p+0x3c),*(unsigned short *)(p+0x30));
        *(char **)p=result;
        func_021FFE5C(result);
    }
}
