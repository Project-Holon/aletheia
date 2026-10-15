/*
 * function: ZUKAN_LIST_InitActorSystem
 * address: 0x021BD984
 * packet: pkt_ov209_021BD984
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gZukanListClactInit 0x021BE9D4 data a4
 *   ZUKAN_LIST_GetVramBankConfig 0x021BC380 thumb ov209
 *   CLACT_InitSystem 0x0204A48C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Template {u32 w[7];} Template;struct Cfg;extern const Template gZukanListClactInit;extern void *ZUKAN_LIST_GetVramBankConfig(void);extern void CLACT_InitSystem(const struct Cfg *,u32,u32);
void ZUKAN_LIST_InitActorSystem(char *p) {Template t;t=gZukanListClactInit;CLACT_InitSystem((const struct Cfg *)&t,(u32)ZUKAN_LIST_GetVramBankConfig(),107);}
