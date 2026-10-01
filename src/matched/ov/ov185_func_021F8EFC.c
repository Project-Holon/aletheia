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
extern int func_021FC4DC(int);
extern void *func_021FD12C(void *,int,unsigned);
extern void func_021FD170(void *,void *,int);
extern int func_0200CA1C(int);
extern char *func_021FFBD4(int,int,int,int,int,int,int,unsigned short);
extern void func_021FFE5C(char *);
void func_021F8EFC(char *p,int *source)
{
    if(*(int *)p==0) {
        int c=func_021FC4DC(source[2]);
        char *result;
        if(*(int *)(p+4)==0)
            *(void **)(p+4)=func_021FD12C((void *)source[3],*(int *)(p+0x2c),*(unsigned short *)(p+0x30));
        func_021FD170(*(void **)(p+4),(void *)source[3],0x2c);
        result=func_021FFBD4(func_0200CA1C(source[6]),source[3],c,*(int *)(p+0x28),source[0],*(int *)(p+0x38),*(int *)(p+0x3c),*(unsigned short *)(p+0x30));
        *(char **)p=result;
        func_021FFE5C(result);
    }
}
