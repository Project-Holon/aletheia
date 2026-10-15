/*
 * function: DEMO3D_GRAPHIC_SetupLightBlock
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
 * blocker: void G3D_LIGHT_SetSlotFlags(LightSlot *p,unsigned i,unsigned short *v){p[i].spare=*v;}
 * symbols:
 *   G3D_LIGHT_SetSlotFlags 0x02048CDC arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 */
struct LightSlot;
extern void G3D_LIGHT_SetSlotFlags(struct LightSlot *,unsigned,unsigned short *);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *);
struct Block {int tag;struct LightSlot *slots;};
struct Obj {int a,b;struct Block block;};
void DEMO3D_GRAPHIC_SetupLightBlock(struct Obj *obj, unsigned short *a, int a2){struct Block *p=&obj->block;G3D_LIGHT_SetSlotFlags(p->slots,0,a);G3D_LIGHT_SetSlotFlags(p->slots,1,a+1);G3D_LIGHT_SetSlotFlags(p->slots,2,a+2);G3D_LIGHT_SetSlotFlags(p->slots,3,a+3);G3D_LIGHT_ApplySlots(p->slots);}
