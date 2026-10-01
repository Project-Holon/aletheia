/*
 * function: func_021C9024
 * address: 0x021C9024
 * packet: pkt_ov212_021C9024
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02031348 legacy void(void) forwards r0-r3 to 020314F4,
 * whose matched body reads all four; this caller sets all four.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02031348 0x02031348 arm
 *   func_021C9348 0x021C9348 thumb ov212
 *   func_021C8F90 0x021C8F90 thumb ov212
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BE794 0x021BE794 data ov209 a4
 *   ov209_id 0x000000D1 data a1
 */
typedef unsigned short u16;
struct Obj020314F4;struct Blk37;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02031348(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern int func_021C9348(struct Blk37 *);
extern int func_021C8F90(char *,int);
extern const char d_021C99A0[];
extern const unsigned d_021BE794[];
extern unsigned char ov209_id[];
void func_021C9024(char *p)
{
    char *q=func_02030734(105,20,0,d_021C99A0,359);
    *(void **)(p+40)=q;
    *(unsigned *)q=**(unsigned **)p;
    *(unsigned *)(q+4)=*(unsigned *)(*(char **)p+4);
    *(u16 *)(q+8)=*(u16 *)(p+18);
    if(*(u16 *)(p+18)==0&&func_021C9348(*(struct Blk37 **)(*(char **)p+4))==0){
        *(u16 **)(q+12)=*(u16 **)(p+12)+1;
        *(u16 *)(q+10)=*(u16 *)(p+16)-1;
    }else{
        *(void **)(q+12)=*(void **)(p+12);
        *(u16 *)(q+10)=*(u16 *)(p+16);
    }
    func_02031348(*(struct Obj020314F4 **)(p+4),(unsigned)ov209_id,(unsigned)d_021BE794,*(unsigned *)(p+40));
    func_021C8F90(p,4);
}
