/*
 * function: func_021D911C
 * address: 0x021D911C
 * packet: pkt_ov131_021D911C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Initialize the count after the clear loop so its zero shares the
 *   clear-store value without a redundant live zero register.
 * proof: Loop indices are initialized u8 values bounded by 80 or 10.
 *   func_021DBF2C field 5 reads byte +12 of immutable d_021DC2F8;
 *   all 80 original records have selector 0..4 (B8/table-proof.log).
 *   count begins with five ROM bytes 1,1,1,1,1 and never exceeds 81.
 *   All scaling and count increments fit int; stores preserve u8 narrowing.
 * interface: func_021D9428 forwards live r1 to func_021D93E4, whose
 *   own matched body consumes target; caller sets r1 despite stale one-arg
 *   declaration in func_021D9428's source.
 * symbols:
 *   d_021DC2B0 0x021DC2B0 data a1
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021DBF2C 0x021DBF2C thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Counts { u8 value[5]; };
extern const struct Counts d_021DC2B0;
extern void *func_021D6064(u8 *);
extern u32 func_021DBF2C(u32,u32);
extern int func_02017E88(void *,int,int);
extern u32 func_021D9428(u8 *,u32);
void func_021D911C(u8 *a,u8 *p)
{
    struct Counts counts = d_021DC2B0;
    void *object;
    u8 i, n, selector;
    object=func_021D6064(a);
    for(i=0;i<80;i++) *(u32 *)(p+0x138+i*8)=0;
    n=0;
    for(i=0;i<80;i++) {
        if(func_02017E88(object,func_021DBF2C(i,0),0)==1) {
            selector=func_021DBF2C(i,5);
            *(u32 *)(p+0x138+n*8)=1;
            p[0x13c+n*8]=i;
            p[0x13d+n*8]=selector;
            p[0x13e + n*8]=counts.value[selector];
            counts.value[selector]++;
            n++;
        }
    }
    p[0x10]=n;
    for(i=0;i<10;i++) *(u16 *)(p+0x70+i*20)=func_021D9428(p,i);
}
