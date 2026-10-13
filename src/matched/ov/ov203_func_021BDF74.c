/*
 * function: func_021BDF74
 * address: 0x021BDF74
 * packet: pkt_ov203_021BDF74
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
 * extent: true start 021BDF74 push home area; assigned 021BDF76 is its second label; complete code ends 021BDF88.
 * symbols:
 *   func_02048CDC 0x02048CDC arm
 */
struct LightSlot;
extern void func_02048CDC(struct LightSlot *,unsigned,unsigned short *);
void func_021BDF74(char *p,unsigned i,unsigned short val){func_02048CDC(*(struct LightSlot **)(p+12),i,&val);}
