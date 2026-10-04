/*
 * function: func_021F8E90
 * address: 0x021F8E90
 * packet: pkt_ov185_021F8E90
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee func_021FD1C4 (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * blocker: ov186021FD1C4 has no outside witness. Complete 1148-byte body
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 */
extern int func_021FC20C(char *);
extern int func_021FC214(char *);
extern int func_021FC4DC(int);
extern void *func_021FD1C4(void *,int,int,int,int,unsigned short);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
void func_021F8E90(char *p,int *source)
{
    if(*(int *)(p+0x10)==0) {
        int a=func_021FC20C((char *)source[3]);
        int b=func_021FC214((char *)source[3]);
        int c=func_021FC4DC(source[2]);
        *(void **)(p+0x10)=func_021FD1C4(((void **)(p+0x40))[*(unsigned short *)(p+0xc)],source[3],c,*(int *)(p+0x2c),1,*(unsigned short *)(p+0x30));
        func_021FC754(*(char **)(p+0x1c),(void *)b,(void *)0x72,(void *)a,0x3da0);
    }
}
