/*
 * function: func_021BDF3C
 * address: 0x021BDF3C
 * packet: pkt_ov203_021BDF3C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02048CDC has no outside witness. Existing src/matched/arm9/unit_02048C58.c defines it but omits it from function:. the integrator owns the unit; no ARM9 source filed.
 * blocker: verified EXACT by one --addr 0x02048CDC --arm without --region, fixed flags/c99; scratch blocker-02048CDC-one.log, exit 0.
 * blocker: typedef struct {unsigned short r,g,b,spare;} LightSlot;
 * blocker: void func_02048CDC(LightSlot *p,unsigned i,unsigned short *v){p[i].spare=*v;}
 * symbols:
 *   func_02048CDC 0x02048CDC arm
 *   func_02048C58 0x02048C58 arm
 */
struct LightSlot;
extern void func_02048CDC(struct LightSlot *,unsigned,unsigned short *);
extern void func_02048C58(struct LightSlot *);
struct Block {int tag;struct LightSlot *slots;};
struct Obj {int a,b;struct Block block;};
void func_021BDF3C(struct Obj *obj, unsigned short *a, int a2){struct Block *p=&obj->block;func_02048CDC(p->slots,0,a);func_02048CDC(p->slots,1,a+1);func_02048CDC(p->slots,2,a+2);func_02048CDC(p->slots,3,a+3);func_02048C58(p->slots);}
